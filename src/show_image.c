#include "../include/new/ShowImg.h" 
#include "../include/bg.h"
#include "../include/decompress.h"
#include "../include/event_data.h"
#include "../include/gpu_regs.h"
#include "../include/graphics.h"
#include "../include/item.h"
#include "../include/list_menu.h"
#include "../include/international_string_util.h"
#include "../include/main.h"
#include "../include/malloc.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h" 
#include "../include/overworld.h"
#include "../include/palette.h"
#include "../include/scanline_effect.h"
#include "../include/script.h"

#include "../include/constants/field_weather.h"

#include "../include/new/ram_locs.h"
#include "../include/new/Vanilla_functions.h"

#define VAR_FULL_IMAGE Var8000
#define tilemapbuffer (*((u8**) 0x203E038)) 
#define BG_MAP_BYTES 0x800
#define BG_BACKGROUND 0

struct ImageData
{
    u8 *tiles;
    u8 *tilemap; 
    u16 *pal;
};

const struct ImageData ImageDataTable[] =
{
    {
        .tiles = Image_01Tiles,
        .tilemap = Image_01Map,
        .pal = Image_01Pal
    }
};

static const struct BgTemplate sImageBgTemplate =
{
    .bg = BG_BACKGROUND,
    .charBaseIndex = 0,
    .mapBaseIndex  = 31,
    .screenSize    = 2,
    .paletteMode   = 0,
    .priority      = 0,
    .baseTile      = 0,
};

static void VBlankCB_Image(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_Image(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// This file's functions
static void Task_ImageFadeIn(u8 taskId);
static void Task_ImageWaitForKeyPress(u8 taskId);
static void Task_ImageFadeOut(u8 taskId);

static void LoadFullscreenImage(void)
{
    u16 idx = VarGet(VAR_FULL_IMAGE);
    const struct ImageData *img = &ImageDataTable[idx];
    CpuFastFill16(0, (void*)BG_CHAR_ADDR(0), BG_CHAR_SIZE * 4);
    CpuFastFill16(0, tilemapbuffer, BG_MAP_BYTES);

    // Tiles
    DecompressAndCopyTileDataToVram(0, img->tiles, 0, 0, 0);

    // Map
    LZDecompressWram(img->tilemap, tilemapbuffer);

    // Palette
    LoadPalette(img->pal, 0, 0x20);
}

static void CB2_FullImage(void)
{
    switch (gMain.state)
    {
        case 0:
            SetVBlankCallback(NULL);
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            DmaFill32(3, 0, OAM, OAM_SIZE);
            DmaFill16(3, 0, PLTT, PLTT_SIZE);
            gMain.state++;
            break;

        case 1:
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetTempTileDataBuffers();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            gMain.state++;
            break;

        case 2:
            tilemapbuffer = Calloc(BG_MAP_BYTES);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, &sImageBgTemplate, 1);
            SetBgTilemapBuffer(BG_BACKGROUND, tilemapbuffer);
            gMain.state++;
            break;

        case 3:
            LoadFullscreenImage();
            gMain.state++;
            break;

        case 4:
            if (!free_temp_tile_data_buffers_if_possible())
            {
                CopyBgTilemapBufferToVram(BG_BACKGROUND);
                ShowBg(BG_BACKGROUND);

                BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);

                SetVBlankCallback(VBlankCB_Image);
                CreateTask(Task_ImageFadeIn, 0);
                SetMainCallback2(MainCB2_Image);

                gMain.state = 0;
            }
            break;
    }
}

static void Task_ImageFadeIn(u8 taskId)
{
    if (!gPaletteFade->active)
        gTasks[taskId].func = Task_ImageWaitForKeyPress;
}

static void Task_ImageWaitForKeyPress(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ImageFadeOut;
    }
}

// Free the tilemap buffer and return to the previous CB
static void Task_ImageFadeOut(u8 taskId)
{
    if (!gPaletteFade->active)
    {
        Free(tilemapbuffer);
        tilemapbuffer = NULL;

        ScriptContext2_Disable();
        gMain.state = 0;
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        DestroyTask(taskId);
    }
}

void ShowImage(void)
{
    ScriptContext2_Enable();
    gMain.state = 0;
    SetMainCallback2(CB2_FullImage);
}
