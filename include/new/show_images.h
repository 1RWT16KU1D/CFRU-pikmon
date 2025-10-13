#pragma once

#include "../global.h"

// Important defines and constants
#define BG_MAP_BYTES 0x800
#define tilemapbuffer (*((u8**) 0x203E038))
#define BG_BACKGROUND 3
#define MAX_INDEX 3

#define VAR_IMAGE_INDEX Var8000  // Script-use var, default VAR_8000

struct ImageData
{
    const u8 *tiles;
    const u8 *tilemap;
    const u16 *pal;
};

extern u8 Image0Tiles[];
extern u8 Image0Map[];
extern u16 Image0Pal[];

extern struct ImageData ImageDataTable[]; // Defined in image_viewer.c

void ShowImageFromVar(void);     // For scripts (uses VAR_8000)
void ShowImageDirect(u8 index);  // For code calls (pass index directly

