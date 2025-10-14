#ifndef GUARD_SHOW_IMAGE_H
#define GUARD_SHOW_IMAGE_H

#include "../global.h"

extern u8 Image0Tiles[];
extern u8 Image0Map[];
extern u16 Image0Pal[];

typedef struct
{
    u8 *tiles;
    u8 *map;
    u16 *pal;
} Image;

const Image sImageDataTable[] =
{
    {
        .tiles = Image0Tiles,
        .map = Image0Map,
        .pal = Image0Pal
    }
};

#define MAP_SIZE 0x800

enum BGs
{
    BG_INTERFACE,
    BG_UNUSED,
    BG_UNUSED2,
    BG_BACKGROUND
};

#define IMAGE_VAR Var8000
#define sImagePtr (*((Image**) 0x203E038))

#endif // GUARD_SHOW_IMAGE_H
