#include "../include/global.h"
#include "../include/bg.h"
#include "../include/decompress.h"
#include "../include/event_data.h"
#include "../include/gpu_regs.h"
#include "../include/graphics.h"
#include "../include/main.h"
#include "../include/malloc.h"
#include "../include/menu.h"
#include "../include/overworld.h"
#include "../include/palette.h"
#include "../include/scanline_effect.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/task.h"
#include "../include/constants/songs.h"

#include "../include/new/dns.h"
#include "../include/new/show_images.h"
#include "../include/new/Vanilla_functions.h"

#define gPaletteFade ((struct PaletteFadeControl*) 0x2037AB8)
#define ALBUM_BG          3
#define ALBUM_BG_MAP_BASE 31
#define ALBUM_BG_CHAR     0
#define BG_MAP_BYTES      0x800

static void ClearTasksAndGraphicalStructs(void);
static void ClearVramOamPlttRegs(void);
static void LoadAlbumImage(u16 imageIndex);
static void CB2_ImageViewer(void);
static void VBlankCB_ImageViewer(void);
static void MainCB2_ImageViewer(void);
static void Task_WaitForFadeToBlack(u8 taskId);
static void Task_ImageFadeIn(u8 taskId);
static void Task_ImageWaitForExit(u8 taskId);
static void Task_ImageFadeOut(u8 taskId);

static EWRAM_DATA u8 *sImageTilemapBuffer = NULL;
static EWRAM_DATA MainCallback sReturnCallback = NULL;
static EWRAM_DATA u16 sImageIndex = 0;

const struct ImageData ImageDataTable[] =
{
    {
        .tiles = Image0Tiles,
        .tilemap = Image0Map,
        .pal = Image0Pal,
    }
};

const u16 gImageDataTableCount = ARRAY_COUNT(ImageDataTable);
static const struct BgTemplate sImageBgTemplate =
{
    .bg = ALBUM_BG,
    .charBaseIndex = ALBUM_BG_CHAR,
    .mapBaseIndex = ALBUM_BG_MAP_BASE,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0,
};

void ShowImageFromVar(void)
{
    ShowImageDirect(VarGet(VAR_IMAGE_INDEX));
}

void ShowImageDirect(u8 index)
{
    if (index >= gImageDataTableCount)
        return;

    sImageIndex = index;
    sReturnCallback = gMain.callback2;

    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    if (!FuncIsActiveTask(Task_WaitForFadeToBlack))
        CreateTask(Task_WaitForFadeToBlack, 0);
}

static void Task_WaitForFadeToBlack(u8 taskId)
{
    if (!gPaletteFade->active)
    {
        gMain.state = 0;
        SetMainCallback2(CB2_ImageViewer);
        DestroyTask(taskId);
    }
}

static void CB2_ImageViewer(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPlttRegs();
        gMain.state++;
        break;
    case 1:
        ClearTasksAndGraphicalStructs();
        ResetBgsAndClearDma3BusyFlags(0);
        sImageTilemapBuffer = AllocZeroed(BG_MAP_BYTES);
        InitBgsFromTemplates(0, &sImageBgTemplate, 1);
        SetBgTilemapBuffer(ALBUM_BG, sImageTilemapBuffer);
        gMain.state++;
        break;
    case 2:
        LoadAlbumImage(sImageIndex);
        gMain.state++;
        break;
    case 3:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            CopyBgTilemapBufferToVram(ALBUM_BG);
            ShowBg(ALBUM_BG);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB_ImageViewer);
            CreateTask(Task_ImageFadeIn, 0);
            SetMainCallback2(MainCB2_ImageViewer);
            gMain.state = 0;
        }
        break;
    }
}

static void LoadAlbumImage(u16 imageIndex)
{
    if (sImageTilemapBuffer == NULL)
        return;

    const struct ImageData *image = &ImageDataTable[imageIndex];

    CpuFastFill16(0, (void *)BG_CHAR_ADDR(0), BG_CHAR_SIZE * 4);
    CpuFastFill16(0, sImageTilemapBuffer, BG_MAP_BYTES);
    decompress_and_copy_tile_data_to_vram(ALBUM_BG, image->tiles, 0, 0, 0);
    LZDecompressWram(image->tilemap, sImageTilemapBuffer);
    LoadPalette(image->pal, 0, 0x20);
}

static void VBlankCB_ImageViewer(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_ImageViewer(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_ImageFadeIn(u8 taskId)
{
    if (!gPaletteFade->active)
        gTasks[taskId].func = Task_ImageWaitForExit;
}

static void Task_ImageWaitForExit(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ImageFadeOut;
    }
}

static void Task_ImageFadeOut(u8 taskId)
{
    if (!gPaletteFade->active)
    {
        if (sImageTilemapBuffer != NULL)
        {
            Free(sImageTilemapBuffer);
            sImageTilemapBuffer = NULL;
        }

        gMain.state = 0;
        SetMainCallback2(sReturnCallback != NULL
                          ? sReturnCallback
                          : CB2_ReturnToFieldContinueScriptPlayMapMusic);
        sReturnCallback = NULL;
        DestroyTask(taskId);
    }
}

static void ClearTasksAndGraphicalStructs(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetTempTileDataBuffers();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void ClearVramOamPlttRegs(void)
{
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
}
