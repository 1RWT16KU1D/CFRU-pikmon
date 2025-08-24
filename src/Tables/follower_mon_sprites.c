#include "../defines.h"
#include "../../include/follower_mon_sprites.h"
#include "../../include/new/character_customization.h"

// Add Followers Frames Here
MON_OW_TEMPLATE_32x32_FRAMES(0001, BulborbLarva)
MON_OW_TEMPLATE_32x32_FRAMES(0002, Bulborb)
MON_OW_TEMPLATE_32x32_FRAMES(0003, JumboBulborb)
MON_OW_TEMPLATE_32x32_FRAMES(0004, FieryBlowlet)
MON_OW_TEMPLATE_32x32_FRAMES(0005, FieryBlowhog)
MON_OW_TEMPLATE_32x32_FRAMES(0006, TitanBlowhog)
MON_OW_TEMPLATE_32x32_FRAMES(0007, Wolpole)
MON_OW_TEMPLATE_32x32_FRAMES(0008, YellowWollyhop)
MON_OW_TEMPLATE_32x32_FRAMES(0009, Masterhop)

// Add Followers Graphics Info Here
const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[] =
{
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_BULBORBLARVA, BulborbLarva) // 0
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_BULBORB, Bulborb)     // 1
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_JUMBOBULBORB, JumboBulborb) // 2
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_FIERYBLOWLET, FieryBlowlet)     // 3
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_FIERYBLOWHOG, FieryBlowhog)     // 4
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_TITANBLOWHOG, TitanBlowhog) // 5
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_WOLPOLE, Wolpole)     // 6
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_YELLOWWOLLYHOP, YellowWollyhop) // 7
    MON_OW_OBJECT_GRAPHICS(OBJ_EVENT_PAL_TAG_MASTERHOP, Masterhop) // 8
};

// Link Species with Overworld Sprites
const u16 gFollowerMonSpriteIdTable[] =
{
    [SPECIES_BULBORBLARVA]  = EVENT_OBJ_GFX_BULBORBLARVA,
    [SPECIES_BULBORB]    = EVENT_OBJ_GFX_BULBORB,
    [SPECIES_JUMBOBULBORB]  = EVENT_OBJ_GFX_JUMBOBULBORB,
    [SPECIES_FIERYBLOWLET]    = EVENT_OBJ_GFX_FIERYBLOWLET,
    [SPECIES_FIERYBLOWHOG]    = EVENT_OBJ_GFX_FIERYBLOWHOG,
    [SPECIES_TITANBLOWHOG]  = EVENT_OBJ_GFX_TITANBLOWHOG,
    [SPECIES_WOLPOLE]    = EVENT_OBJ_GFX_WOLPOLE,
    [SPECIES_YELLOWWOLLYHOP]  = EVENT_OBJ_GFX_YELLOWWOLLYHOP,
    [SPECIES_MASTERHOP]  = EVENT_OBJ_GFX_MASTERHOP,
};

static const union AnimCmd sMonAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceWest[] =
{
    ANIMCMD_FRAME(4, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_FaceEast[] =
{
    ANIMCMD_FRAME(4, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoSouth[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoNorth[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoWest[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoEast[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMonAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gFollowerMonAnimTable[] =
{
    [ANIM_STD_FACE_SOUTH]       = sMonAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH]       = sMonAnim_FaceNorth,
    [ANIM_STD_FACE_WEST]        = sMonAnim_FaceWest,
    [ANIM_STD_FACE_EAST]        = sMonAnim_FaceEast,
    [ANIM_STD_GO_SOUTH]         = sMonAnim_GoSouth,
    [ANIM_STD_GO_NORTH]         = sMonAnim_GoNorth,
    [ANIM_STD_GO_WEST]          = sMonAnim_GoWest,
    [ANIM_STD_GO_EAST]          = sMonAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH]    = sMonAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH]    = sMonAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST]     = sMonAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST]     = sMonAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH]  = sMonAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH]  = sMonAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST]   = sMonAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST]   = sMonAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sMonAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sMonAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST]  = sMonAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST]  = sMonAnim_GoFastestEast,
    [ANIM_RAISE_HAND]           = sMonAnim_FaceSouth,
};

