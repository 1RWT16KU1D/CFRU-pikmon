#include "defines.h"
#include "defines_battle.h"
#include "../include/dynamic_placeholder_text_util.h"
#include "../include/event_object_movement.h"
#include "../include/field_effect_helpers.h"
#include "../include/field_player_avatar.h"
#include "../include/link.h"
#include "../include/random.h"
#include "../include/sprite.h"
#include "../include/trainer_pokemon_sprites.h"
#include "../include/constants/character_customization.h"
#include "../include/constants/event_object_movement_constants.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/trainers.h"

#include "../include/new/character_customization.h"
#include "../include/new/follow_me.h"
#include "../include/new/frontier.h"
#include "../include/new/multi.h"
#include "../include/new/util.h"

/*
character_customization.c
	functions for altering the player's sprite based on the current sprite/palette selections

tables to edit:
	gOverworldTableSwitcher
	sPlayerAvatarGfxIds

*/

#ifdef UNBOUND
//extern const u16 MalePlayer_Trainer_Outfit_RedPal[];
extern const u16 MalePlayer_Trainer_Outfit_BlackPal[];
extern const u16 MalePlayer_Trainer_Outfit_BluePal[];
extern const u16 MalePlayer_Trainer_Outfit_GrayPal[];
extern const u16 MalePlayer_Trainer_Outfit_PurplePal[];
extern const u16 MalePlayer_Trainer_Outfit_YellowPal[];
extern const u16 MalePlayer_Trainer_Outfit_GreenPal[];
extern const u16 MalePlayer_Trainer_Outfit_TealPal[];
extern const u16 MalePlayer_Trainer_Outfit_BrownPal[];
extern const u16 MalePlayer_Trainer_Outfit_OrangePal[];
extern const u16 MalePlayer_Trainer_Outfit_PinkPal[];

//extern const u16 MalePlayer_Trainer_Trim_GoldPal[];
extern const u16 MalePlayer_Trainer_Trim_BlackPal[];
extern const u16 MalePlayer_Trainer_Trim_BluePal[];
extern const u16 MalePlayer_Trainer_Trim_BrownPal[];
extern const u16 MalePlayer_Trainer_Trim_BrownOrangePal[];
extern const u16 MalePlayer_Trainer_Trim_GreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightBluePal[];
extern const u16 MalePlayer_Trainer_Trim_LightGreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightPinkPal[];
extern const u16 MalePlayer_Trainer_Trim_LightRedPal[];
extern const u16 MalePlayer_Trainer_Trim_OrangePal[];
extern const u16 MalePlayer_Trainer_Trim_PinkPal[];
extern const u16 MalePlayer_Trainer_Trim_PurplePal[];
extern const u16 MalePlayer_Trainer_Trim_Purple2Pal[];
extern const u16 MalePlayer_Trainer_Trim_RedPal[];
extern const u16 MalePlayer_Trainer_Trim_TealPal[];
extern const u16 MalePlayer_Trainer_Trim_WhitePal[];
extern const u16 MalePlayer_Trainer_Trim_YellowPal[];

//extern const u16 MalePlayer_Trainer_Hair_BrownPal[];
extern const u16 MalePlayer_Trainer_Hair_BlondePal[];
extern const u16 MalePlayer_Trainer_Hair_LBlondePal[];
extern const u16 MalePlayer_Trainer_Hair_BlackPal[];
extern const u16 MalePlayer_Trainer_Hair_RedPal[];
extern const u16 MalePlayer_Trainer_Hair_GreenPal[];
extern const u16 MalePlayer_Trainer_Hair_PurplePal[];
extern const u16 MalePlayer_Trainer_Hair_BluePal[];
extern const u16 MalePlayer_Trainer_Hair_TealPal[];
extern const u16 MalePlayer_Trainer_Hair_PinkPal[];
extern const u16 MalePlayer_Trainer_Hair_SilverPal[];
extern const u16 MalePlayer_Trainer_Hair_GreyPal[];
extern const u16 MalePlayer_Trainer_Hair_WhitePal[];
extern const u16 MalePlayer_Trainer_Hair_OrangePal[];
extern const u16 MalePlayer_Trainer_Hair_LightBrownPal[];
extern const u16 MalePlayer_Trainer_Hair_DarkBrownPal[];

//extern const u16 MalePlayer_Trainer_Skin_LightPal[];
extern const u16 MalePlayer_Trainer_Skin_LBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_BrownPal[];
extern const u16 MalePlayer_Trainer_Skin_DarkBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_YellowPal[];

//extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_BluePal[];
extern const u16 MalePlayer_Champion_TealPal[];
extern const u16 MalePlayer_Champion_LimePal[];
extern const u16 MalePlayer_Champion_GreenPal[];
extern const u16 MalePlayer_Champion_YellowPal[];
extern const u16 MalePlayer_Champion_BlackPal[];
extern const u16 MalePlayer_Champion_GrayPal[];
extern const u16 MalePlayer_Champion_WhitePal[];
extern const u16 MalePlayer_Champion_PurplePal[];
extern const u16 MalePlayer_Champion_PinkPal[];
extern const u16 MalePlayer_Champion_BrownPal[];
extern const u16 MalePlayer_Champion_OrangePal[];

//extern const u16 MalePlayer_Champion_Trim_LightOrangePal[];
extern const u16 MalePlayer_Champion_Trim_RedPal[];
extern const u16 MalePlayer_Champion_Trim_BluePal[];
extern const u16 MalePlayer_Champion_Trim_TealPal[];
extern const u16 MalePlayer_Champion_Trim_LimePal[];
extern const u16 MalePlayer_Champion_Trim_GreenPal[];
extern const u16 MalePlayer_Champion_Trim_YellowPal[];
extern const u16 MalePlayer_Champion_Trim_BlackPal[];
extern const u16 MalePlayer_Champion_Trim_GrayPal[];
extern const u16 MalePlayer_Champion_Trim_WhitePal[];
extern const u16 MalePlayer_Champion_Trim_PurplePal[];
extern const u16 MalePlayer_Champion_Trim_PinkPal[];
extern const u16 MalePlayer_Champion_Trim_BrownPal[];
extern const u16 MalePlayer_Champion_Trim_OrangePal[];

//extern const u16 MalePlayer_Marlon_RedPal[];
extern const u16 MalePlayer_Marlon_BluePal[];
extern const u16 MalePlayer_Marlon_TealPal[];
extern const u16 MalePlayer_Marlon_GreenPal[];
extern const u16 MalePlayer_Marlon_LimePal[];
extern const u16 MalePlayer_Marlon_YellowPal[];
extern const u16 MalePlayer_Marlon_BlackPal[];
extern const u16 MalePlayer_Marlon_WhitePal[];
extern const u16 MalePlayer_Marlon_PurplePal[];
extern const u16 MalePlayer_Marlon_PinkPal[];
extern const u16 MalePlayer_Marlon_BrownPal[];
extern const u16 MalePlayer_Marlon_OrangePal[];
extern const u16 MalePlayer_Marlon_BrightRedPal[];
	
static const u16* sPlayerOutfitColours[] =
{
	NULL /*MalePlayer_Trainer_Outfit_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Trainer_Outfit_BlackPal,
	MalePlayer_Trainer_Outfit_BluePal,
	MalePlayer_Trainer_Outfit_TealPal,
	MalePlayer_Trainer_Outfit_GrayPal,
	MalePlayer_Trainer_Outfit_GreenPal,
	MalePlayer_Trainer_Outfit_YellowPal,
	MalePlayer_Trainer_Outfit_OrangePal,
	MalePlayer_Trainer_Outfit_BrownPal,
	MalePlayer_Trainer_Outfit_PurplePal,
	MalePlayer_Trainer_Outfit_PinkPal,
};

static const u16* sPlayerTrimColours[] =
{
	NULL /*MalePlayer_Trainer_Trim_GoldPal*/,
	MalePlayer_Trainer_Trim_RedPal,
	MalePlayer_Trainer_Trim_LightRedPal,
	MalePlayer_Trainer_Trim_OrangePal,
	MalePlayer_Trainer_Trim_YellowPal,
	MalePlayer_Trainer_Trim_GreenPal,
	MalePlayer_Trainer_Trim_LightGreenPal,
	MalePlayer_Trainer_Trim_BrownPal,
	MalePlayer_Trainer_Trim_BrownOrangePal,
	MalePlayer_Trainer_Trim_BlackPal,
	MalePlayer_Trainer_Trim_WhitePal,
	MalePlayer_Trainer_Trim_BluePal,
	MalePlayer_Trainer_Trim_TealPal,
	MalePlayer_Trainer_Trim_LightBluePal,
	MalePlayer_Trainer_Trim_PinkPal,
	MalePlayer_Trainer_Trim_LightPinkPal,
	MalePlayer_Trainer_Trim_Purple2Pal,
	MalePlayer_Trainer_Trim_PurplePal,
};

static const u16* sPlayerHairColours[] =
{
	NULL /*MalePlayer_Trainer_Hair_BrownPal*/,
	MalePlayer_Trainer_Hair_LBlondePal,
	MalePlayer_Trainer_Hair_BlondePal,
	MalePlayer_Trainer_Hair_BlackPal,
	MalePlayer_Trainer_Hair_RedPal,
	MalePlayer_Trainer_Hair_GreenPal,
	MalePlayer_Trainer_Hair_PurplePal,
	MalePlayer_Trainer_Hair_BluePal,
	MalePlayer_Trainer_Hair_PinkPal,
	MalePlayer_Trainer_Hair_SilverPal,
	MalePlayer_Trainer_Hair_GreyPal,
	MalePlayer_Trainer_Hair_WhitePal,
	MalePlayer_Trainer_Hair_TealPal,
	MalePlayer_Trainer_Hair_OrangePal,
	MalePlayer_Trainer_Hair_LightBrownPal,
	MalePlayer_Trainer_Hair_DarkBrownPal,
};

static const u16* sPlayerSkinColours[] =
{
    NULL /*MalePlayer_Trainer_Skin_LightPal*/,
    MalePlayer_Trainer_Skin_LBrownPal,
    MalePlayer_Trainer_Skin_BrownPal,
    MalePlayer_Trainer_Skin_DarkBrownPal,
    MalePlayer_Trainer_Skin_YellowPal,
};

static const u16* sPlayerChampionOutfitColours[] =
{
	NULL /*MalePlayer_Champion_ReddishOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_RedPal,
	MalePlayer_Champion_BluePal,
	MalePlayer_Champion_TealPal,
	MalePlayer_Champion_LimePal,
	MalePlayer_Champion_GreenPal,
	MalePlayer_Champion_YellowPal,
	MalePlayer_Champion_BlackPal,
	MalePlayer_Champion_GrayPal,
	MalePlayer_Champion_WhitePal,
	MalePlayer_Champion_PinkPal,
	MalePlayer_Champion_PurplePal,
	MalePlayer_Champion_BrownPal,
	MalePlayer_Champion_OrangePal,
};

static const u16* sPlayerChampionTrimColours[] =
{
	NULL /*MalePlayer_Champion_Trim_LightOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_Trim_RedPal,
	MalePlayer_Champion_Trim_BluePal,
	MalePlayer_Champion_Trim_TealPal,
	MalePlayer_Champion_Trim_LimePal,
	MalePlayer_Champion_Trim_GreenPal,
	MalePlayer_Champion_Trim_YellowPal,
	MalePlayer_Champion_Trim_BlackPal,
	MalePlayer_Champion_Trim_GrayPal,
	MalePlayer_Champion_Trim_WhitePal,
	MalePlayer_Champion_Trim_PinkPal,
	MalePlayer_Champion_Trim_PurplePal,
	MalePlayer_Champion_Trim_BrownPal,
	MalePlayer_Champion_Trim_OrangePal,
};

static const u16* sPlayerMarlonOutfitColours[] =
{
	NULL /*MalePlayer_Marlon_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Marlon_BluePal,
	MalePlayer_Marlon_TealPal,
	MalePlayer_Marlon_LimePal,
	MalePlayer_Marlon_GreenPal,
	MalePlayer_Marlon_YellowPal,
	MalePlayer_Marlon_BlackPal,
	MalePlayer_Marlon_WhitePal,
	MalePlayer_Marlon_PurplePal,
	MalePlayer_Marlon_PinkPal,
	MalePlayer_Marlon_BrownPal,
	MalePlayer_Marlon_OrangePal,
	MalePlayer_Marlon_BrightRedPal,
};
#endif

#ifdef EXISTING_OW_TABLE_ADDRESS
	#define gOverworldTableSwitcher ((struct EventObjectGraphicsInfo***) EXISTING_OW_TABLE_ADDRESS)
#elif defined UNBOUND //For Pokemon Unbound
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[] =
	{
		(NPCPtr*) 0x88110E0,
		(NPCPtr*) 0x88B2720,
		(NPCPtr*) 0x88B2B20,
	};

#else //Modify this

extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[];

static NPCPtr sOverworldTable2[] =
{
	&gFollowerMonGfxTable0[0],
    &gFollowerMonGfxTable0[1],
    &gFollowerMonGfxTable0[2],
    &gFollowerMonGfxTable0[3],
    &gFollowerMonGfxTable0[4],
    &gFollowerMonGfxTable0[5],
    &gFollowerMonGfxTable0[6],
    &gFollowerMonGfxTable0[7],
    &gFollowerMonGfxTable0[8],
    &gFollowerMonGfxTable0[9],
	&gFollowerMonGfxTable0[10],
    &gFollowerMonGfxTable0[11],
    &gFollowerMonGfxTable0[12],
    &gFollowerMonGfxTable0[13],
    &gFollowerMonGfxTable0[14],
    &gFollowerMonGfxTable0[15],
    &gFollowerMonGfxTable0[16],
    &gFollowerMonGfxTable0[17],
    &gFollowerMonGfxTable0[18],
    &gFollowerMonGfxTable0[19],
	&gFollowerMonGfxTable0[20],
    &gFollowerMonGfxTable0[21],
    &gFollowerMonGfxTable0[22],
    &gFollowerMonGfxTable0[23],
    &gFollowerMonGfxTable0[24],
    &gFollowerMonGfxTable0[25],
    &gFollowerMonGfxTable0[26],
    &gFollowerMonGfxTable0[27],
    &gFollowerMonGfxTable0[28],
    &gFollowerMonGfxTable0[29],
	&gFollowerMonGfxTable0[30],
    &gFollowerMonGfxTable0[31],
    &gFollowerMonGfxTable0[32],
    &gFollowerMonGfxTable0[33],
    &gFollowerMonGfxTable0[34],
    &gFollowerMonGfxTable0[35],
    &gFollowerMonGfxTable0[36],
    &gFollowerMonGfxTable0[37],
    &gFollowerMonGfxTable0[38],
    &gFollowerMonGfxTable0[39],
	&gFollowerMonGfxTable0[40],
    &gFollowerMonGfxTable0[41],
    &gFollowerMonGfxTable0[42],
    &gFollowerMonGfxTable0[43],
    &gFollowerMonGfxTable0[44],
    &gFollowerMonGfxTable0[45],
    &gFollowerMonGfxTable0[46],
    &gFollowerMonGfxTable0[47],
    &gFollowerMonGfxTable0[48],
    &gFollowerMonGfxTable0[49],
	&gFollowerMonGfxTable0[50],
    &gFollowerMonGfxTable0[51],
    &gFollowerMonGfxTable0[52],
    &gFollowerMonGfxTable0[53],
    &gFollowerMonGfxTable0[54],
    &gFollowerMonGfxTable0[55],
    &gFollowerMonGfxTable0[56],
    &gFollowerMonGfxTable0[57],
    &gFollowerMonGfxTable0[58],
    &gFollowerMonGfxTable0[59],
	&gFollowerMonGfxTable0[60],
    &gFollowerMonGfxTable0[61],
    &gFollowerMonGfxTable0[62],
    &gFollowerMonGfxTable0[63],
    &gFollowerMonGfxTable0[64],
    &gFollowerMonGfxTable0[65],
    &gFollowerMonGfxTable0[66],
    &gFollowerMonGfxTable0[67],
    &gFollowerMonGfxTable0[68],
    &gFollowerMonGfxTable0[69],
	&gFollowerMonGfxTable0[70],
    &gFollowerMonGfxTable0[71],
    &gFollowerMonGfxTable0[72],
    &gFollowerMonGfxTable0[73],
    &gFollowerMonGfxTable0[74],
    &gFollowerMonGfxTable0[75],
    &gFollowerMonGfxTable0[76],
    &gFollowerMonGfxTable0[77],
    &gFollowerMonGfxTable0[78],
    &gFollowerMonGfxTable0[79],
	&gFollowerMonGfxTable0[80],
    &gFollowerMonGfxTable0[81],
    &gFollowerMonGfxTable0[82],
    &gFollowerMonGfxTable0[83],
    &gFollowerMonGfxTable0[84],
    &gFollowerMonGfxTable0[85],
    &gFollowerMonGfxTable0[86],
    &gFollowerMonGfxTable0[87],
    &gFollowerMonGfxTable0[88],
    &gFollowerMonGfxTable0[89],
	&gFollowerMonGfxTable0[90],
    &gFollowerMonGfxTable0[91],
    &gFollowerMonGfxTable0[92],
    &gFollowerMonGfxTable0[93],
    &gFollowerMonGfxTable0[94],
    &gFollowerMonGfxTable0[95],
    &gFollowerMonGfxTable0[96],
    &gFollowerMonGfxTable0[97],
    &gFollowerMonGfxTable0[98],
    &gFollowerMonGfxTable0[99],
	&gFollowerMonGfxTable0[100],
    &gFollowerMonGfxTable0[101],
    &gFollowerMonGfxTable0[102],
    &gFollowerMonGfxTable0[103],
    &gFollowerMonGfxTable0[104],
    &gFollowerMonGfxTable0[105],
    &gFollowerMonGfxTable0[106],
    &gFollowerMonGfxTable0[107],
    &gFollowerMonGfxTable0[108],
    &gFollowerMonGfxTable0[109],
	&gFollowerMonGfxTable0[110],
    &gFollowerMonGfxTable0[111],
    &gFollowerMonGfxTable0[112],
    &gFollowerMonGfxTable0[113],
    &gFollowerMonGfxTable0[114],
    &gFollowerMonGfxTable0[115],
    &gFollowerMonGfxTable0[116],
    &gFollowerMonGfxTable0[117],
    &gFollowerMonGfxTable0[118],
    &gFollowerMonGfxTable0[119],
	&gFollowerMonGfxTable0[120],
    &gFollowerMonGfxTable0[121],
    &gFollowerMonGfxTable0[122],
    &gFollowerMonGfxTable0[123],
    &gFollowerMonGfxTable0[124],
    &gFollowerMonGfxTable0[125],
    &gFollowerMonGfxTable0[126],
    &gFollowerMonGfxTable0[127],
    &gFollowerMonGfxTable0[128],
    &gFollowerMonGfxTable0[129],
	&gFollowerMonGfxTable0[130],
    &gFollowerMonGfxTable0[131],
    &gFollowerMonGfxTable0[132],
    &gFollowerMonGfxTable0[133],
    &gFollowerMonGfxTable0[134],
    &gFollowerMonGfxTable0[135],
    &gFollowerMonGfxTable0[136],
    &gFollowerMonGfxTable0[137],
    &gFollowerMonGfxTable0[138],
    &gFollowerMonGfxTable0[139],
	&gFollowerMonGfxTable0[140],
    &gFollowerMonGfxTable0[141],
    &gFollowerMonGfxTable0[142],
    &gFollowerMonGfxTable0[143],
    &gFollowerMonGfxTable0[144],
    &gFollowerMonGfxTable0[145],
    &gFollowerMonGfxTable0[146],
    &gFollowerMonGfxTable0[147],
    &gFollowerMonGfxTable0[148],
    &gFollowerMonGfxTable0[149],
	&gFollowerMonGfxTable0[150],
    &gFollowerMonGfxTable0[151],
    &gFollowerMonGfxTable0[152],
    &gFollowerMonGfxTable0[153],
    &gFollowerMonGfxTable0[154],
    &gFollowerMonGfxTable0[155],
    &gFollowerMonGfxTable0[156],
    &gFollowerMonGfxTable0[157],
    &gFollowerMonGfxTable0[158],
    &gFollowerMonGfxTable0[159],
	&gFollowerMonGfxTable0[160],
    &gFollowerMonGfxTable0[161],
    &gFollowerMonGfxTable0[162],
    &gFollowerMonGfxTable0[163],
    &gFollowerMonGfxTable0[164],
    &gFollowerMonGfxTable0[165],
    &gFollowerMonGfxTable0[166],
    &gFollowerMonGfxTable0[167],
    &gFollowerMonGfxTable0[168],
    &gFollowerMonGfxTable0[169],
	&gFollowerMonGfxTable0[170],
    &gFollowerMonGfxTable0[171],
    &gFollowerMonGfxTable0[172],
    &gFollowerMonGfxTable0[173],
    &gFollowerMonGfxTable0[174],
    &gFollowerMonGfxTable0[175],
    &gFollowerMonGfxTable0[176],
    &gFollowerMonGfxTable0[177],
    &gFollowerMonGfxTable0[178],
    &gFollowerMonGfxTable0[179],
	&gFollowerMonGfxTable0[180],
    &gFollowerMonGfxTable0[181],
    &gFollowerMonGfxTable0[182],
    &gFollowerMonGfxTable0[183],
    &gFollowerMonGfxTable0[184],
    &gFollowerMonGfxTable0[185],
    &gFollowerMonGfxTable0[186],
    &gFollowerMonGfxTable0[187],
    &gFollowerMonGfxTable0[188],
    &gFollowerMonGfxTable0[189],
	&gFollowerMonGfxTable0[190],
    &gFollowerMonGfxTable0[191],
    &gFollowerMonGfxTable0[192],
    &gFollowerMonGfxTable0[193],
    &gFollowerMonGfxTable0[194],
    &gFollowerMonGfxTable0[195],
    &gFollowerMonGfxTable0[196],
    &gFollowerMonGfxTable0[197],
    &gFollowerMonGfxTable0[198],
    &gFollowerMonGfxTable0[199],
	&gFollowerMonGfxTable0[200],
    &gFollowerMonGfxTable0[201],
    &gFollowerMonGfxTable0[202],
    &gFollowerMonGfxTable0[203],
    &gFollowerMonGfxTable0[204],
    &gFollowerMonGfxTable0[205],
    &gFollowerMonGfxTable0[206],
    &gFollowerMonGfxTable0[207],
    &gFollowerMonGfxTable0[208],
    &gFollowerMonGfxTable0[209],
	&gFollowerMonGfxTable0[210],
    &gFollowerMonGfxTable0[211],
    &gFollowerMonGfxTable0[212],
    &gFollowerMonGfxTable0[213],
    &gFollowerMonGfxTable0[214],
    &gFollowerMonGfxTable0[215],
    &gFollowerMonGfxTable0[216],
    &gFollowerMonGfxTable0[217],
    &gFollowerMonGfxTable0[218],
    &gFollowerMonGfxTable0[219],
	&gFollowerMonGfxTable0[220],
    &gFollowerMonGfxTable0[221],
    &gFollowerMonGfxTable0[222],
    &gFollowerMonGfxTable0[223],
    &gFollowerMonGfxTable0[224],
    &gFollowerMonGfxTable0[225],
    &gFollowerMonGfxTable0[226],
    &gFollowerMonGfxTable0[227],
    &gFollowerMonGfxTable0[228],
    &gFollowerMonGfxTable0[229],
	&gFollowerMonGfxTable0[230],
    &gFollowerMonGfxTable0[231],
    &gFollowerMonGfxTable0[232],
    &gFollowerMonGfxTable0[233],
    &gFollowerMonGfxTable0[234],
    &gFollowerMonGfxTable0[235],
    &gFollowerMonGfxTable0[236],
    &gFollowerMonGfxTable0[237],
    &gFollowerMonGfxTable0[238],
    &gFollowerMonGfxTable0[239],
	&gFollowerMonGfxTable0[240],
    &gFollowerMonGfxTable0[241],
    &gFollowerMonGfxTable0[242],
    &gFollowerMonGfxTable0[243],
    &gFollowerMonGfxTable0[244],
    &gFollowerMonGfxTable0[245],
    &gFollowerMonGfxTable0[246],
    &gFollowerMonGfxTable0[247],
    &gFollowerMonGfxTable0[248],
    &gFollowerMonGfxTable0[249],
	&gFollowerMonGfxTable0[250],
    &gFollowerMonGfxTable0[251],
    &gFollowerMonGfxTable0[252],
    &gFollowerMonGfxTable0[253],
    &gFollowerMonGfxTable0[254],
    &gFollowerMonGfxTable0[255],
    &gFollowerMonGfxTable0[256],
    &gFollowerMonGfxTable0[257],
    &gFollowerMonGfxTable0[258],
    &gFollowerMonGfxTable0[259],
	&gFollowerMonGfxTable0[260],
    &gFollowerMonGfxTable0[261],
    &gFollowerMonGfxTable0[262],
    &gFollowerMonGfxTable0[263],
    &gFollowerMonGfxTable0[264],
    &gFollowerMonGfxTable0[265],
    &gFollowerMonGfxTable0[266],
    &gFollowerMonGfxTable0[267],
    &gFollowerMonGfxTable0[268],
    &gFollowerMonGfxTable0[269],
	&gFollowerMonGfxTable0[270],
    &gFollowerMonGfxTable0[271],
    &gFollowerMonGfxTable0[272],
    &gFollowerMonGfxTable0[273],
    &gFollowerMonGfxTable0[274],
    &gFollowerMonGfxTable0[275],
    &gFollowerMonGfxTable0[276],
    &gFollowerMonGfxTable0[277],
    &gFollowerMonGfxTable0[278],
    &gFollowerMonGfxTable0[279],
	&gFollowerMonGfxTable0[280],
    &gFollowerMonGfxTable0[281],
    &gFollowerMonGfxTable0[282],
    &gFollowerMonGfxTable0[283],
    &gFollowerMonGfxTable0[284],
    &gFollowerMonGfxTable0[285],
    &gFollowerMonGfxTable0[286],
    &gFollowerMonGfxTable0[287],
    &gFollowerMonGfxTable0[288],
    &gFollowerMonGfxTable0[289],
	&gFollowerMonGfxTable0[290],
    &gFollowerMonGfxTable0[291],
    &gFollowerMonGfxTable0[292],
    &gFollowerMonGfxTable0[293],
    &gFollowerMonGfxTable0[294],
    &gFollowerMonGfxTable0[295],
    &gFollowerMonGfxTable0[296],
    &gFollowerMonGfxTable0[297],
    &gFollowerMonGfxTable0[298],
    &gFollowerMonGfxTable0[299],
	&gFollowerMonGfxTable0[300],
    &gFollowerMonGfxTable0[301],
    &gFollowerMonGfxTable0[302],
    &gFollowerMonGfxTable0[303],
    &gFollowerMonGfxTable0[304],
    &gFollowerMonGfxTable0[305],
    &gFollowerMonGfxTable0[306],
    &gFollowerMonGfxTable0[307],
    &gFollowerMonGfxTable0[308],
    &gFollowerMonGfxTable0[309],
	&gFollowerMonGfxTable0[310],
    &gFollowerMonGfxTable0[311],
    &gFollowerMonGfxTable0[312],
    &gFollowerMonGfxTable0[313],
    &gFollowerMonGfxTable0[314],
    &gFollowerMonGfxTable0[315],
    &gFollowerMonGfxTable0[316],
    &gFollowerMonGfxTable0[317],
    &gFollowerMonGfxTable0[318],
    &gFollowerMonGfxTable0[319],
	&gFollowerMonGfxTable0[320],
    &gFollowerMonGfxTable0[321],
    &gFollowerMonGfxTable0[322],
    &gFollowerMonGfxTable0[323],
    &gFollowerMonGfxTable0[324],
    &gFollowerMonGfxTable0[325],
    &gFollowerMonGfxTable0[326],
    &gFollowerMonGfxTable0[327],
    &gFollowerMonGfxTable0[328],
    &gFollowerMonGfxTable0[329],
	&gFollowerMonGfxTable0[330],
    &gFollowerMonGfxTable0[331],
    &gFollowerMonGfxTable0[332],
    &gFollowerMonGfxTable0[333],
    &gFollowerMonGfxTable0[334],
    &gFollowerMonGfxTable0[335],
    &gFollowerMonGfxTable0[336],
    &gFollowerMonGfxTable0[337],
    &gFollowerMonGfxTable0[338],
    &gFollowerMonGfxTable0[339],
	&gFollowerMonGfxTable0[340],
    &gFollowerMonGfxTable0[341],
    &gFollowerMonGfxTable0[342],
    &gFollowerMonGfxTable0[343],
    &gFollowerMonGfxTable0[344],
    &gFollowerMonGfxTable0[345],
    &gFollowerMonGfxTable0[346],
    &gFollowerMonGfxTable0[347],
    &gFollowerMonGfxTable0[348],
    &gFollowerMonGfxTable0[349],
	&gFollowerMonGfxTable0[350],
    &gFollowerMonGfxTable0[351],
    &gFollowerMonGfxTable0[352],
    &gFollowerMonGfxTable0[353],
    &gFollowerMonGfxTable0[354],
    &gFollowerMonGfxTable0[355],
    &gFollowerMonGfxTable0[356],
    &gFollowerMonGfxTable0[357],
    &gFollowerMonGfxTable0[358],
    &gFollowerMonGfxTable0[359],
	&gFollowerMonGfxTable0[360],
    &gFollowerMonGfxTable0[361],
    &gFollowerMonGfxTable0[362],
    &gFollowerMonGfxTable0[363],
    &gFollowerMonGfxTable0[364],
    &gFollowerMonGfxTable0[365],
    &gFollowerMonGfxTable0[366],
    &gFollowerMonGfxTable0[367],
    &gFollowerMonGfxTable0[368],
    &gFollowerMonGfxTable0[369],
	&gFollowerMonGfxTable0[370],
    &gFollowerMonGfxTable0[371],
    &gFollowerMonGfxTable0[372],
    &gFollowerMonGfxTable0[373],
    &gFollowerMonGfxTable0[374],
    &gFollowerMonGfxTable0[375],
    &gFollowerMonGfxTable0[376],
    &gFollowerMonGfxTable0[377],
    &gFollowerMonGfxTable0[378],
    &gFollowerMonGfxTable0[379],
	&gFollowerMonGfxTable0[380],
    &gFollowerMonGfxTable0[381],
    &gFollowerMonGfxTable0[382],
    &gFollowerMonGfxTable0[383],
    &gFollowerMonGfxTable0[384],
    &gFollowerMonGfxTable0[385],
    &gFollowerMonGfxTable0[386],
    &gFollowerMonGfxTable0[387],
    &gFollowerMonGfxTable0[388],
    &gFollowerMonGfxTable0[389],
	&gFollowerMonGfxTable0[390],
    &gFollowerMonGfxTable0[391],
    &gFollowerMonGfxTable0[392],
    &gFollowerMonGfxTable0[393],
    &gFollowerMonGfxTable0[394],
    &gFollowerMonGfxTable0[395],
    &gFollowerMonGfxTable0[396],
    &gFollowerMonGfxTable0[397],
    &gFollowerMonGfxTable0[398],
    &gFollowerMonGfxTable0[399],
	&gFollowerMonGfxTable0[400],
    &gFollowerMonGfxTable0[401],
    &gFollowerMonGfxTable0[402],
    &gFollowerMonGfxTable0[403],
    &gFollowerMonGfxTable0[404],
    &gFollowerMonGfxTable0[405],
    &gFollowerMonGfxTable0[406],
    &gFollowerMonGfxTable0[407],
};
#endif

	// create 255 OW tables
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] =
	{
		(NPCPtr*) 0x839FDB0,
		sOverworldTable2,
		// etc...
		// please note that this method makes compatability with OW Manager challenging
	};
	
	static const struct SpritePalette gObjectEventSpritePalettes11[] = {
		{gObjectEventPallete_1, 0x1100},
		{gObjectEventPallete_2, 0x1101},
		{gObjectEventPallete_3, 0x1102},
		{gObjectEventPallete_4, 0x1103},
		{gObjectEventPallete_5, 0x1104},
		{gObjectEventPallete_6, 0x1105},
		{gObjectEventPallete_7, 0x1106},
		{gObjectEventPallete_8, 0x1107},
		{gObjectEventPallete_9, 0x1108},
		{gObjectEventPallete_10, 0x1109},
		{gObjectEventPallete_11, 0x110A},
		{gObjectEventPallete_12, 0x110B},
		{gObjectEventPallete_13, 0x110C},
		{gObjectEventPallete_14, 0x1110},
		{gObjectEventPallete_15, 0x1111},
		{gObjectEventPallete_16, 0x1113},
		{gObjectEventPallete_17, 0x1115},
		{gObjectEventPallete_18, 0x1114},
		{gObjectEventPallete_19, 0x1116},
		{gObjectEventPallete_20, 0x1117},
		{gObjectEventPallete_21, 0x1118},
		{gObjectEventPallete_22, 0x1119},
		{gObjectEventPallete_23, 0x111A},
		{gObjectEventPallete_24, 0x111B},
		{gObjectEventPallete_25, 0x111C},
		{gObjectEventPallete_26, 0x111D},
		{gObjectEventPallete_27, 0x111E},
		{gObjectEventPallete_28, 0x111F},
		{gObjectEventPallete_29, 0x1120},
		{gObjectEventPallete_30, 0x1121},
		{gObjectEventPallete_31, 0x1122},
		{gObjectEventPallete_32, 0x1123},
		{gObjectEventPallete_33, 0x1124},
		{gObjectEventPallete_34, 0x1125},
		{gObjectEventPallete_35, 0x1126},
		{gObjectEventPallete_36, 0x1127},
		{gObjectEventPallete_37, 0x1128},
		{gObjectEventPallete_38, 0x1129},
		{gObjectEventPallete_39, 0x112A},
		{gObjectEventPallete_40, 0x112B},
		{gObjectEventPallete_41, 0x112C},
		{gObjectEventPallete_42, 0x112D},
		{gObjectEventPallete_43, 0x112E},
		{gObjectEventPallete_44, 0x112F},
		{gObjectEventPallete_45, 0x1130},
		{gObjectEventPallete_46, 0x1131},
		{gObjectEventPallete_47, 0x1132},
		{gObjectEventPallete_48, 0x1133},
		{gObjectEventPallete_49, 0x1134},
		{gObjectEventPallete_50, 0x1135},
		{gObjectEventPallete_51, 0x1136},
		{gObjectEventPallete_52, 0x1137},
		{gObjectEventPallete_53, 0x1138},
		{gObjectEventPallete_54, 0x1139},
		{gObjectEventPallete_55, 0x113A},
		{gObjectEventPallete_56, 0x113B},
		{gObjectEventPallete_57, 0x113C},
		{gObjectEventPallete_58, 0x113D},
		{gObjectEventPallete_59, 0x113E},
		{gObjectEventPallete_60, 0x113F},
		{gObjectEventPallete_61, 0x1140},
		{gObjectEventPallete_62, 0x1141},
		{gObjectEventPallete_63, 0x1142},
		{gObjectEventPallete_64, 0x1143},
		{gObjectEventPallete_65, 0x1144},
		{gObjectEventPallete_66, 0x1145},
		{gObjectEventPallete_67, 0x1146},
		{gObjectEventPallete_68, 0x1147},
		{gObjectEventPallete_69, 0x1148},
		{gObjectEventPallete_70, 0x1149},
		{gObjectEventPallete_71, 0x114A},
		{gObjectEventPallete_72, 0x114B},
		{gObjectEventPallete_73, 0x114C},
		{gObjectEventPallete_74, 0x114D},
		{gObjectEventPallete_75, 0x114E},
		{NULL, 0x11FF}
	};

	const struct SpritePalette gObjectEventSpritePalettes12[] = {
		{gFollowingMonPic_0001_BulborbLarvaPal, OBJ_EVENT_PAL_TAG_BULBORBLARVA},
        {gFollowingMonPic_0002_BulborbPal, OBJ_EVENT_PAL_TAG_BULBORB},
        {gFollowingMonPic_0003_JumboBulborbPal, OBJ_EVENT_PAL_TAG_JUMBOBULBORB},
        {gFollowingMonPic_0004_FieryBlowletPal, OBJ_EVENT_PAL_TAG_FIERYBLOWLET},
        {gFollowingMonPic_0005_FieryBlowhogPal, OBJ_EVENT_PAL_TAG_FIERYBLOWHOG},
        {gFollowingMonPic_0006_TitanBlowhogPal, OBJ_EVENT_PAL_TAG_TITANBLOWHOG},
        {gFollowingMonPic_0007_WolpolePal, OBJ_EVENT_PAL_TAG_WOLPOLE},
        {gFollowingMonPic_0008_YellowWollyhopPal, OBJ_EVENT_PAL_TAG_YELLOWWOLLYHOP},
        {gFollowingMonPic_0009_MasterhopPal, OBJ_EVENT_PAL_TAG_MASTERHOP},
		{gFollowingMonPic_0010_FlintBeetlePal, OBJ_EVENT_PAL_TAG_FLINTBEETLE },
		{gFollowingMonPic_0011_DoodlebugPal, OBJ_EVENT_PAL_TAG_DOODLEBUG },
		{gFollowingMonPic_0012_GlintBeetlePal, OBJ_EVENT_PAL_TAG_GLINTBEETLE },
		{gFollowingMonPic_0013_SwoopingSnitchbugPal, OBJ_EVENT_PAL_TAG_SWOOPINGSNITCHBUG },
		{gFollowingMonPic_0014_BumblingSnitchbugPal, OBJ_EVENT_PAL_TAG_BUMBLINGSNITCHBUG },
		{gFollowingMonPic_0015_DirigibugPal, OBJ_EVENT_PAL_TAG_DIRIGIBUG },
		{gFollowingMonPic_0016_SnowBulborbPal, OBJ_EVENT_PAL_TAG_SNOWBULBORB },
		{gFollowingMonPic_0017_DwarfFrostyBulborbPal, OBJ_EVENT_PAL_TAG_DWARFFROSTYBULBORB },
		{gFollowingMonPic_0018_FrostyBulborbPal, OBJ_EVENT_PAL_TAG_FROSTYBULBORB },
		{gFollowingMonPic_0019_CrumbugPal, OBJ_EVENT_PAL_TAG_CRUMBUG },
		{gFollowingMonPic_0020_BreadbugPal, OBJ_EVENT_PAL_TAG_BREADBUG },
		{gFollowingMonPic_0021_GiantBreadbugPal, OBJ_EVENT_PAL_TAG_GIANTBREADBUG },
		{gFollowingMonPic_0022_EmperorBulblaxPal, OBJ_EVENT_PAL_TAG_EMPERORBULBLAX },
		{gFollowingMonPic_0023_SovreignBulblaxPal, OBJ_EVENT_PAL_TAG_SOVREIGNBULBLAX },
		{gFollowingMonPic_0024_DwarfBulbearPal, OBJ_EVENT_PAL_TAG_DWARFBULBEAR },
		{gFollowingMonPic_0025_BulbearPal, OBJ_EVENT_PAL_TAG_SPOTTYBULBEAR },
		{gFollowingMonPic_0026_HoneywispPal, OBJ_EVENT_PAL_TAG_HONEYWISP },
		{gFollowingMonPic_0027_DandelflyPal, OBJ_EVENT_PAL_TAG_DANDELFLY },
		{gFollowingMonPic_0028_DownySnagretPal, OBJ_EVENT_PAL_TAG_DOWNYSNAGRET },
		{gFollowingMonPic_0029_BurrowingSnagretPal, OBJ_EVENT_PAL_TAG_BURROWINGSNAGRET },
		{gFollowingMonPic_0030_PileatedSnagretPal, OBJ_EVENT_PAL_TAG_PILEATEDSNAGRET },
		{gFollowingMonPic_0031_FemaleSheargrubPal, OBJ_EVENT_PAL_TAG_FEMALESHEARGRUB },
		{gFollowingMonPic_0032_SwarmingSheargrubPal, OBJ_EVENT_PAL_TAG_SWARMINGSHEARGRUB },
		{gFollowingMonPic_0033_MamaSheargrubPal, OBJ_EVENT_PAL_TAG_MAMASHEARGRUB },
		{gFollowingMonPic_0034_MaleSheargrubPal, OBJ_EVENT_PAL_TAG_MALESHEARGRUB },
		{gFollowingMonPic_0035_ShearwigPal, OBJ_EVENT_PAL_TAG_SHEARWIG },
		{gFollowingMonPic_0036_QueenShearwigPal, OBJ_EVENT_PAL_TAG_QUEENSHEARWIG },
		{gFollowingMonPic_0037_AristocrabOffspringPal, OBJ_EVENT_PAL_TAG_ARISTOCRABOFFSPRING },
		{gFollowingMonPic_0038_PeckishAristocrabPal, OBJ_EVENT_PAL_TAG_ARISTOCRAB },
		{gFollowingMonPic_0039_GoolixPal, OBJ_EVENT_PAL_TAG_GOOLIX },
		{gFollowingMonPic_0040_FoolixPal, OBJ_EVENT_PAL_TAG_FOOLIX },
		{gFollowingMonPic_0041_ArcticCannonLarvaPal, OBJ_EVENT_PAL_TAG_ARCTICCANNONLARVA },
		{gFollowingMonPic_0042_ArcticCannonBeetlePal, OBJ_EVENT_PAL_TAG_ARCTICCANNONBEETLE },
		{gFollowingMonPic_0043_SkitterleafPal, OBJ_EVENT_PAL_TAG_SKITTERLEAF },
		{gFollowingMonPic_0044_DesiccatedSkitterleafPal, OBJ_EVENT_PAL_TAG_DESICCATEDSKITTERLEAF },
		{gFollowingMonPic_0045_ArmoredCannonLarvaPal, OBJ_EVENT_PAL_TAG_ARMOREDCANNONLARVA },
		{gFollowingMonPic_0046_ArmoredCannonBeetlePal, OBJ_EVENT_PAL_TAG_ARMOREDCANNONBEETLE },
		{gFollowingMonPic_0047_HornedCannonBeetlePal, OBJ_EVENT_PAL_TAG_HORNEDCANNONBEETLE },
		{gFollowingMonPic_0048_CreepingChrysanthemumPal, OBJ_EVENT_PAL_TAG_CREEPINGCHRYSANTHEMUM },
		{gFollowingMonPic_0049_StartleSporePal, OBJ_EVENT_PAL_TAG_STARTLESPORE },
		{gFollowingMonPic_0050_HermitCrawmadPal, OBJ_EVENT_PAL_TAG_HERMITCRAWMAD },
		{gFollowingMonPic_0051_BugEyedCrawmadPal, OBJ_EVENT_PAL_TAG_BUGEYEDCRAWMAD },
		{gFollowingMonPic_0052_DwarfBulborbPal, OBJ_EVENT_PAL_TAG_DWARFBULBORB },
		{gFollowingMonPic_0053_DwarfOrangeBulborbPal, OBJ_EVENT_PAL_TAG_DWARFORANGEBULBORB },
		{gFollowingMonPic_0054_BeadyLonLegsPal, OBJ_EVENT_PAL_TAG_BEADYLONGLEGS },
		{gFollowingMonPic_0055_RagingLongLegsPal, OBJ_EVENT_PAL_TAG_RAGINGLONGLEGS },
		{gFollowingMonPic_0056_BaldyLongLegsPal, OBJ_EVENT_PAL_TAG_BALDYLONGLEGS },
		{gFollowingMonPic_0057_ShaggyLongLegsPal, OBJ_EVENT_PAL_TAG_SHAGGYLONGLEGS },
		{gFollowingMonPic_0058_BulbminPal, OBJ_EVENT_PAL_TAG_BULBMIN },
		{gFollowingMonPic_0059_AdultBulbminPal, OBJ_EVENT_PAL_TAG_ADULTBULBMIN },
		{gFollowingMonPic_0060_ScornetPal, OBJ_EVENT_PAL_TAG_SCORNET },
		{gFollowingMonPic_0061_ScornetMaestroPal, OBJ_EVENT_PAL_TAG_SCORNETMAESTRO },
		{gFollowingMonPic_0062_BurrowNitPal, OBJ_EVENT_PAL_TAG_BURROWNIT },
		{gFollowingMonPic_0063_JoustmitePal, OBJ_EVENT_PAL_TAG_JOUSTMITE },
		{gFollowingMonPic_0064_FlightyJoustmitePal, OBJ_EVENT_PAL_TAG_FLIGHTYJOUSTMITE },
		{gFollowingMonPic_0065_VolatileDweevilPal, OBJ_EVENT_PAL_TAG_VOLATILEDWEEVIL },
		{gFollowingMonPic_0066_ManAtLegsPal, OBJ_EVENT_PAL_TAG_MANATLEGS },
		{gFollowingMonPic_0067_SkutterchuckPal, OBJ_EVENT_PAL_TAG_SKUTTERCHUCK },
		{gFollowingMonPic_0068_CalcifiedCrushblatPal, OBJ_EVENT_PAL_TAG_CALCIFIEDCRUSHBLAT },
		{gFollowingMonPic_0069_ArachnodePal, OBJ_EVENT_PAL_TAG_ARACHNODE },
		{gFollowingMonPic_0070_MoldyDwarfBulborbPal, OBJ_EVENT_PAL_TAG_MOLDYDWARFBULBORB },
		{gFollowingMonPic_0071_MoldySloochPal, OBJ_EVENT_PAL_TAG_MOLDYSLOOCH },
		{gFollowingMonPic_0072_ToxstoolPal, OBJ_EVENT_PAL_TAG_TOXSTOOL },
		{gFollowingMonPic_0073_PhosbatPal, OBJ_EVENT_PAL_TAG_PHOSBAT },
		{gFollowingMonPic_0074_VeheamothPhosbatPal, OBJ_EVENT_PAL_TAG_VEHEAMOTHPHOSBAT },
		{gFollowingMonPic_0075_PuckeringBlinnowPal, OBJ_EVENT_PAL_TAG_PUCKERINGBLINNOW },
		{gFollowingMonPic_0076_SputtlefishPal, OBJ_EVENT_PAL_TAG_SPUTTLEFISH },
		{gFollowingMonPic_0077_PricklepuffPal, OBJ_EVENT_PAL_TAG_PRICKLEPUFF },
		{gFollowingMonPic_0078_UjadaniPal, OBJ_EVENT_PAL_TAG_UJADANI },
		{gFollowingMonPic_0079_MititePal, OBJ_EVENT_PAL_TAG_MITITE },
		{gFollowingMonPic_0080_WitheringBlowhogPal, OBJ_EVENT_PAL_TAG_WITHERINGBLOWHOG },
		{gFollowingMonPic_0081_PuffyBlowhogPal, OBJ_EVENT_PAL_TAG_PUFFYBLOWHOG },
		{gFollowingMonPic_0082_MiniatureSnootwhackerPal, OBJ_EVENT_PAL_TAG_MINIATURESNOOTWHACKER },
		{gFollowingMonPic_0083_MammothSnootwhackerPal, OBJ_EVENT_PAL_TAG_MAMMOTHSNOOTWHACKER },
		{gFollowingMonPic_0084_PyroclasticSloochPal, OBJ_EVENT_PAL_TAG_PYROCLASTICSLOOCH },
		{gFollowingMonPic_0085_LesserSpottedJellyfloatPal, OBJ_EVENT_PAL_TAG_LESSERSPOTTEDJELLYFLOAT },
		{gFollowingMonPic_0086_GreaterSpottedJellyfloatPal, OBJ_EVENT_PAL_TAG_GREATERSPOTTEDJELLYFLOAT },
		{gFollowingMonPic_0087_ToadyBloysterPal, OBJ_EVENT_PAL_TAG_TOADYBLOYSTER },
		{gFollowingMonPic_0088_RangingBloysterPal, OBJ_EVENT_PAL_TAG_RANGINGBLOYSTER },
		{gFollowingMonPic_0089_SnowyBlowhogPal, OBJ_EVENT_PAL_TAG_SNOWYBLOWHOG },
		{gFollowingMonPic_0090_BlizzardingBlowhogPal, OBJ_EVENT_PAL_TAG_BLIZZARDINGBLOWHOG },
		{gFollowingMonPic_0091_GildemandweePal, OBJ_EVENT_PAL_TAG_GILDEMANDWEE },
		{gFollowingMonPic_0092_GildemanderPal, OBJ_EVENT_PAL_TAG_GILDEMANDER },
		{gFollowingMonPic_0093_WaddlequaffPal, OBJ_EVENT_PAL_TAG_WADDLEQUAFF },
		{gFollowingMonPic_0094_GrubchuckerPal, OBJ_EVENT_PAL_TAG_GRUBCHUCKER },
		{gFollowingMonPic_0095_PearlyClamclampPal, OBJ_EVENT_PAL_TAG_PEARLYCLAMCLAMP },
		{gFollowingMonPic_0096_SunsquishPal, OBJ_EVENT_PAL_TAG_SUNQUISH },
		{gFollowingMonPic_0097_PorquillionPal, OBJ_EVENT_PAL_TAG_PROQUILLION },
		{gFollowingMonPic_0098_TuskedBlowhogPal, OBJ_EVENT_PAL_TAG_TUSKEDBLOWHOG },
		{gFollowingMonPic_0099_SnowflakeFluttertailPal, OBJ_EVENT_PAL_TAG_SNOWFLAKEFLUTTERTAIL },
		{gFollowingMonPic_0100_BogswallowPal, OBJ_EVENT_PAL_TAG_BOGSWALLOW },
		{gFollowingMonPic_0101_PuffminPal, OBJ_EVENT_PAL_TAG_PUFFMIN },
		{gFollowingMonPic_0102_WollyhopPal, OBJ_EVENT_PAL_TAG_WOLLYHOP },
		{gFollowingMonPic_0103_ChillyhopPal, OBJ_EVENT_PAL_TAG_CHILLYHOP },
		{gFollowingMonPic_0104_BloomcapBloysterPal, OBJ_EVENT_PAL_TAG_BLOOMCAPBLOYSTER },
		{gFollowingMonPic_0105_ScorchcakePal, OBJ_EVENT_PAL_TAG_SCORCHCAKE },
		{gFollowingMonPic_0106_WaterDumplePal, OBJ_EVENT_PAL_TAG_WATERDUMPLE },
		{gFollowingMonPic_0107_LongWaterDumplePal, OBJ_EVENT_PAL_TAG_LONGWATERDUMPLE },
		{gFollowingMonPic_0108_MockiwiPal, OBJ_EVENT_PAL_TAG_MOCKIWI },
		{gFollowingMonPic_0109_CrestedMockiwiPal, OBJ_EVENT_PAL_TAG_CRESTEDMOCKIWI },
		{gFollowingMonPic_0110_ElongatedCrushblatPal, OBJ_EVENT_PAL_TAG_ELONGATEDCRUSHBLAT },
		{gFollowingMonPic_0111_PuffstalkPal, OBJ_EVENT_PAL_TAG_PUFFSTALK },
		{gFollowingMonPic_0112_PuffstoolPal, OBJ_EVENT_PAL_TAG_PUFFSTOOL },
		{gFollowingMonPic_0113_AnodeBeetlePal, OBJ_EVENT_PAL_TAG_ANODEBEETLE },
		{gFollowingMonPic_0114_EmpressBulblaxPal, OBJ_EVENT_PAL_TAG_EMPRESSBULBLAX },
		{gFollowingMonPic_0115_SkeeterskatePal, OBJ_EVENT_PAL_TAG_SKEETERSKATE },
		{gFollowingMonPic_0116_MuckerskatePal, OBJ_EVENT_PAL_TAG_MUCKERSKATE },
		{gFollowingMonPic_0117_GroovyLongLegsPal, OBJ_EVENT_PAL_TAG_GROOVYLONGLEGS },
		{gFollowingMonPic_0118_CrustedRumpupPal, OBJ_EVENT_PAL_TAG_CRUSTEDRUMPUP },
		{gFollowingMonPic_0119_BeardedAmpratPal, OBJ_EVENT_PAL_TAG_BEARDEDAMPRAT },
		{gFollowingMonPic_0120_FieryBulblaxPal, OBJ_EVENT_PAL_TAG_FIERYBULBLAX },
		{gFollowingMonPic_0121_GattlingGroinkPal, OBJ_EVENT_PAL_TAG_GATTLINGGROINK },
		{gFollowingMonPic_0122_ArmurkPal, OBJ_EVENT_PAL_TAG_ARMURK },
		{gFollowingMonPic_0123_SegmentedCrawbsterPal, OBJ_EVENT_PAL_TAG_SEGMENTEDCRAWBSTER },
		{gFollowingMonPic_0124_ArmoredMawdadPal, OBJ_EVENT_PAL_TAG_ARMOREDMAWDAD },
		{gFollowingMonPic_0125_SandbelchingMeerslugPal, OBJ_EVENT_PAL_TAG_SANDBELCHINGMEERSLUG },
		{gFollowingMonPic_0126_ClickingSlurkerPal, OBJ_EVENT_PAL_TAG_CLICKINGSLURKER },
		{gFollowingMonPic_0127_LuringSlurkerPal, OBJ_EVENT_PAL_TAG_LURINGSLURKER },
		{gFollowingMonPic_0128_MedusalSlurkerPal, OBJ_EVENT_PAL_TAG_MEDUSALSLURKER },
		{gFollowingMonPic_0129_PelletPosyPal, OBJ_EVENT_PAL_TAG_PELLETPOSY },
		{gFollowingMonPic_0130_MasterOnionPal, OBJ_EVENT_PAL_TAG_MASTERONION },
		{gFollowingMonPic_0131_OatchiPal, OBJ_EVENT_PAL_TAG_OATCHI },
		{gFollowingMonPic_0132_QuaggledMireclopsPal, OBJ_EVENT_PAL_TAG_QUAGGLEDMIRECLOPS },
		{gFollowingMonPic_0133_AlbinoDwarfBulborbPal, OBJ_EVENT_PAL_TAG_ALBINODWARFBULBORB },
		{gFollowingMonPic_0134_HairyBulborbPal, OBJ_EVENT_PAL_TAG_HAIRYBULBORB },
		{gFollowingMonPic_0135_WhiptongueBulborbPal, OBJ_EVENT_PAL_TAG_WHIPTONGUEBULBORB },
		{gFollowingMonPic_0136_OrangeBulborbPal, OBJ_EVENT_PAL_TAG_ORANGEBULBORB },
		{gFollowingMonPic_0137_WhitePikminPal, OBJ_EVENT_PAL_TAG_WHITEPIKMIN },
		{gFollowingMonPic_0138_BluePikminPal, OBJ_EVENT_PAL_TAG_BLUEPIKMIN },
		{gFollowingMonPic_0139_RockPikminPal, OBJ_EVENT_PAL_TAG_ROCKPIKMIN },
		{gFollowingMonPic_0140_YellowPikminPal, OBJ_EVENT_PAL_TAG_YELLOWPIKMIN },
		{gFollowingMonPic_0141_WingedPikminPal, OBJ_EVENT_PAL_TAG_WINGEDPIKMIN },
		{gFollowingMonPic_0142_RedPikminPal, OBJ_EVENT_PAL_TAG_REDPIKMIN },
		{gFollowingMonPic_0143_PurplePikminPal, OBJ_EVENT_PAL_TAG_PURPLEPIKMIN },
		{gFollowingMonPic_0144_WaterWraithPal, OBJ_EVENT_PAL_TAG_WATERWRAITH },
		{gFollowingMonPic_0145_TitanDweevilPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL },
		{gFollowingMonPic_0146_PlasmWraithPal, OBJ_EVENT_PAL_TAG_PLASMWRAITH },
		{gFollowingMonPic_0147_IcePikminPal, OBJ_EVENT_PAL_TAG_ICEPIKMIN },
		{gFollowingMonPic_0148_GlowSeedPal, OBJ_EVENT_PAL_TAG_GLOWSEED },
		{gFollowingMonPic_0149_GlowPikminPal, OBJ_EVENT_PAL_TAG_GLOWPIKMIN },
		{gFollowingMonPic_0150_SmokyProggPal, OBJ_EVENT_PAL_TAG_SMOKYPROGG },
		{gFollowingMonPic_0151_MamutaPal, OBJ_EVENT_PAL_TAG_MAMUTA },
		{gFollowingMonPic_0152_MossPal, OBJ_EVENT_PAL_TAG_MOSS },
		{gFollowingMonPic_0153_ToyBorbPal, OBJ_EVENT_PAL_TAG_TOYBORB },
		{gFollowingMonPic_0154_BulblordPal, OBJ_EVENT_PAL_TAG_BULBLORD },
		{gFollowingMonPic_0155_PinchipedePal, OBJ_EVENT_PAL_TAG_PINCHIPEDE },
		{gFollowingMonPic_0156_LargeMothWollyhopPal, OBJ_EVENT_PAL_TAG_LARGEMOUTHWOLLYHOP },
		{gFollowingMonPic_0157_ToyBlowhogPal, OBJ_EVENT_PAL_TAG_TOYBLOWHOG },
		{gFollowingMonPic_0158_TelescopingPumphogPal, OBJ_EVENT_PAL_TAG_TELESCOPINGPUMPHOG },
		{gFollowingMonPic_0159_BeebPal, OBJ_EVENT_PAL_TAG_BEEB },
		{gFollowingMonPic_0160_BladedBeebPal, OBJ_EVENT_PAL_TAG_BLADEDBEEB },
		{gFollowingMonPic_0161_StuddedBeebPal, OBJ_EVENT_PAL_TAG_STUDDEDBEEB },
		{gFollowingMonPic_0162_FireflapBulborbPal, OBJ_EVENT_PAL_TAG_FIREFLAPBULBORB },
		{gFollowingMonPic_0163_IceblownDweevilPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL },
		{gFollowingMonPic_0164_SpectralidPal, OBJ_EVENT_PAL_TAG_SPECTRALID },
		{gFollowingMonPic_0165_BlubbugPal, OBJ_EVENT_PAL_TAG_BLUBBUG },
		{gFollowingMonPic_0166_PuffyBlubbugPal, OBJ_EVENT_PAL_TAG_PUFFYBLUBBUG },
		{gFollowingMonPic_0167_StuffedBellbloomPal, OBJ_EVENT_PAL_TAG_STUFFEDBELLBLOOM },
		{gFollowingMonPic_0168_CentiparePal, OBJ_EVENT_PAL_TAG_CENTIPARE },
		{gFollowingMonPic_0169_AdultCentiparePal, OBJ_EVENT_PAL_TAG_ADULTCENTIPARE },
		{gFollowingMonPic_0170_WateryBlowhogPal, OBJ_EVENT_PAL_TAG_WATERYBLOWHOG },
		{gFollowingMonPic_0171_GrabbitPal, OBJ_EVENT_PAL_TAG_GRABBIT },
		{gFollowingMonPic_0172_CoppellerPal, OBJ_EVENT_PAL_TAG_COPPELLER },
		{gFollowingMonPic_0173_MuggonflyPal, OBJ_EVENT_PAL_TAG_MUGGONFLY },
		{gFollowingMonPic_0174_ElectricCottonadePal, OBJ_EVENT_PAL_TAG_ELECTRICCOTTONADE },
		{gFollowingMonPic_0175_WaddlepusPal, OBJ_EVENT_PAL_TAG_WADDLEPUS },
		{gFollowingMonPic_0176_CrammedWraithPal, OBJ_EVENT_PAL_TAG_CRAMMEDWRAITH },
		{gFollowingMonPic_0177_BerserkLeechHydroePal, OBJ_EVENT_PAL_TAG_BERSERKLEECHHYDROE },
		{gFollowingMonPic_0178_PebblePitcherPal, OBJ_EVENT_PAL_TAG_PEBBLEPITCHER },
		{gFollowingMonPic_0189_AncientSirehoundPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND },
		{gFollowingMonPic_0180_CourageReactorPal, OBJ_EVENT_PAL_TAG_COURAGEREACTOR },
		{gFollowingMonPic_0181_AssembledCouragePal, OBJ_EVENT_PAL_TAG_ASSEMBLEDCOURAGE },
		{gFollowingMonPic_0182_RememberedOldBuddyPal, OBJ_EVENT_PAL_TAG_REMEMBEREDOLDBUDDY },
		{gFollowingMonPic_0183_BulborbWithAGunPal, OBJ_EVENT_PAL_TAG_BULBORBWITHAGUN },
		{gFollowingMonPic_0184_KirbyPal, OBJ_EVENT_PAL_TAG_KIRBY },
		{gFollowingMonPic_0185_SoulPal, OBJ_EVENT_PAL_TAG_SOUL },
		{gFollowingMonPic_0000_PlaceholderLarvaPal, OBJ_EVENT_PAL_TAG_PLACEHOLDERLARVA },
		{gFollowingMonPic_0186_Demo77Pal, OBJ_EVENT_PAL_TAG_DEMO77 },
		{gFollowingMonPic_0187_UsubaPal, OBJ_EVENT_PAL_TAG_USUBA },
		{gFollowingMonPic_0188_KakureimoPal, OBJ_EVENT_PAL_TAG_KAKUREIMO },
		{gFollowingMonPic_0189_PikutabePal, OBJ_EVENT_PAL_TAG_PIKUTABE },
		{gFollowingMonPic_0190_NamaPongashiPal, OBJ_EVENT_PAL_TAG_NAMAPONGASHI },
		{gFollowingMonPic_0191_ChappyProtoPal, OBJ_EVENT_PAL_TAG_CHAPPYPROTO },
		{gFollowingMonPic_0412_EggPal, OBJ_EVENT_PAL_TAG_EGG },
		{gFollowingMonPic_0192_RedBubblimpPal, OBJ_EVENT_PAL_TAG_REDBUBBLIMP },
		{gFollowingMonPic_0193_StarnaclePal, OBJ_EVENT_PAL_TAG_STARNACLE },
		{gFollowingMonPic_0194_ShearfleaPal, OBJ_EVENT_PAL_TAG_SHEARFLEA },
		{gFollowingMonPic_0195_WhiskerPillarPal, OBJ_EVENT_PAL_TAG_WHISKERPILLAR },
		{gFollowingMonPic_0196_IcyBlowhogPal, OBJ_EVENT_PAL_TAG_ICYBLOWHOG },
		{gFollowingMonPic_0212_FreezecakePal, OBJ_EVENT_PAL_TAG_FREEZECAKE },
		{gFollowingMonPic_0213_ShockcakePal, OBJ_EVENT_PAL_TAG_SHOCKCAKE },
		{gFollowingMonPic_0214_WideMouthedAnodeBeetlePal, OBJ_EVENT_PAL_TAG_WIDEMOUTHEDANODEBEETLE },
		{gFollowingMonPic_0215_DecoratedCannonBeetlePal, OBJ_EVENT_PAL_TAG_DECORATEDCANNONBEETLE },
		{gFollowingMonPic_0208_AntennaBeetlePal, OBJ_EVENT_PAL_TAG_ANTENNABEETLE },
		{gFollowingMonPic_0142_RedPikminVeteranPal, OBJ_EVENT_PAL_TAG_REDPIKMIN_VETERAN },
		{gFollowingMonPic_0145_TitanDweevilElectricPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_ELECTRIC },
		{gFollowingMonPic_0145_TitanDweevilFirePal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_FIRE },
		{gFollowingMonPic_0145_TitanDweevilPoisonPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_POISON },
		{gFollowingMonPic_0145_TitanDweevilWaterPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_WATER },
		{gFollowingMonPic_0165_SpectralidRedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_RED },
		{gFollowingMonPic_0165_SpectralidYellowPal, OBJ_EVENT_PAL_TAG_SPECTRALID_YELLOW },
		{gFollowingMonPic_0165_SpectralidUnmarkedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKED },
		{gFollowingMonPic_0165_SpectralidUnmarkedRedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKEDRED },
		{gFollowingMonPic_0165_SpectralidUnmarkedPurplePal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKEDPURPLE },
		{gFollowingMonPic_0165_SpectralidElectricPal, OBJ_EVENT_PAL_TAG_SPECTRALID_ELECTRIC },
		{gFollowingMonPic_0165_SpectralidHey0Pal, OBJ_EVENT_PAL_TAG_SPECTRALID_HEY0 },
		{gFollowingMonPic_0165_SpectralidHey1Pal, OBJ_EVENT_PAL_TAG_SPECTRALID_HEY1 },
		{gFollowingMonPic_0179_AncientSirehoundIcePal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_ICE },
		{gFollowingMonPic_0179_AncientSirehoundElectricPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_ELECTRIC },
		{gFollowingMonPic_0179_AncientSirehoundFirePal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_FIRE },
		{gFollowingMonPic_0179_AncientSirehoundGloomPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_GLOOM },
		{gFollowingMonPic_0184_KirbyFlyingPal, OBJ_EVENT_PAL_TAG_KIRBY_FLYING },
		{gFollowingMonPic_0184_KirbyGrassPal, OBJ_EVENT_PAL_TAG_KIRBY_GRASS },
		{gFollowingMonPic_0184_KirbyBugPal, OBJ_EVENT_PAL_TAG_KIRBY_BUG },
		{gFollowingMonPic_0184_KirbyPoisonPal, OBJ_EVENT_PAL_TAG_KIRBY_POISON },
		{gFollowingMonPic_0184_KirbyWaterPal, OBJ_EVENT_PAL_TAG_KIRBY_WATER },
		{gFollowingMonPic_0184_KirbyIcePal, OBJ_EVENT_PAL_TAG_KIRBY_ICE },
		{gFollowingMonPic_0184_KirbyFirePal, OBJ_EVENT_PAL_TAG_KIRBY_FIRE },
		{gFollowingMonPic_0184_KirbyElectricPal, OBJ_EVENT_PAL_TAG_KIRBY_ELECTRIC },
		{gFollowingMonPic_0184_KirbyFightingPal, OBJ_EVENT_PAL_TAG_KIRBY_FIGHTING },
		{gFollowingMonPic_0184_KirbyRockPal, OBJ_EVENT_PAL_TAG_KIRBY_ROCK },
		{gFollowingMonPic_0184_KirbyGroundPal, OBJ_EVENT_PAL_TAG_KIRBY_GROUND },
		{gFollowingMonPic_0184_KirbyPsychicPal, OBJ_EVENT_PAL_TAG_KIRBY_PSYCHIC },
		{gFollowingMonPic_0184_KirbyGhostPal, OBJ_EVENT_PAL_TAG_KIRBY_GHOST },
		{gFollowingMonPic_0184_KirbyDragonPal, OBJ_EVENT_PAL_TAG_KIRBY_DRAGON },
		{gFollowingMonPic_0184_KirbyDarkPal, OBJ_EVENT_PAL_TAG_KIRBY_DARK },
		{gFollowingMonPic_0184_KirbySteelPal, OBJ_EVENT_PAL_TAG_KIRBY_STEEL },
		{gFollowingMonPic_0184_KirbyFairyPal, OBJ_EVENT_PAL_TAG_KIRBY_FAIRY },
		{gFollowingMonPic_0185_SoulRedPal, OBJ_EVENT_PAL_TAG_SOUL_RED },
		{gFollowingMonPic_0185_SoulYellowPal, OBJ_EVENT_PAL_TAG_SOUL_YELLOW },
		{gFollowingMonPic_0185_SoulBluePal, OBJ_EVENT_PAL_TAG_SOUL_BLUE },
		{gFollowingMonPic_0185_SoulPurplePal, OBJ_EVENT_PAL_TAG_SOUL_PURPLE },
		{gFollowingMonPic_0185_SoulWhitePal, OBJ_EVENT_PAL_TAG_SOUL_WHITE },
		{gFollowingMonPic_0185_SoulRockPal, OBJ_EVENT_PAL_TAG_SOUL_ROCK },
		{gFollowingMonPic_0185_SoulWingedPal, OBJ_EVENT_PAL_TAG_SOUL_WINGED },
		{gFollowingMonPic_0185_SoulIcePal, OBJ_EVENT_PAL_TAG_SOUL_ICE },
		{gFollowingMonPic_0164_IceblownDweevilFirePal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_F },
		{gFollowingMonPic_0164_IceblownDweevilElectricPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_E },
		{gFollowingMonPic_0164_IceblownDweevilWaterPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_W },
		{gFollowingMonPic_0164_IceblownDweevilPoisonPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_P },
		{gFollowingMonPic_0197_MysteriousLifeFormPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM },
		{gFollowingMonPic_0197_MysteriousLifeFormBulborbPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_BULBORB },
		{gFollowingMonPic_0197_MysteriousLifeFormAmpratPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_AMPRAT },
		{gFollowingMonPic_0197_MysteriousLifeFormDandelflyPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_DANDELFLY },
		{gFollowingMonPic_0197_MysteriousLifeFormArachnodePal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_ARACHNODE },
		{gFollowingMonPic_0197_MysteriousLifeFormBlowhogPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_BLOWHOG },
		{gFollowingMonPic_0198_PeteyPirannhaPal, OBJ_EVENT_PAL_TAG_PETEYPIRANNHA },
		{gFollowingMonPic_0199_ToyPikminRedPal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_RED },
		{gFollowingMonPic_0199_ToyPikminYellowPal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_YELLOW },
		{gFollowingMonPic_0199_ToyPikminBluePal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_BLUE },
		{gFollowingMonPic_0200_PikiMalePal, OBJ_EVENT_PAL_TAG_PIKI_MALE },
		{gFollowingMonPic_0200_PikiFemalePal, OBJ_EVENT_PAL_TAG_PIKI_FEMALE },
		{gFollowingMonPic_0201_DemoFPal, OBJ_EVENT_PAL_TAG_DEMOF },
		{gFollowingMonPic_0202_DemoGPal, OBJ_EVENT_PAL_TAG_DEMOG },
		{gFollowingMonPic_0203_DemoIPal, OBJ_EVENT_PAL_TAG_DEMOI },
		{gFollowingMonPic_0204_DemoWPal, OBJ_EVENT_PAL_TAG_DEMOW },
		{gFollowingMonPic_0205_UsualSuspectPal, OBJ_EVENT_PAL_TAG_USUALSUSPECT },
		{gFollowingMonPic_0206_MeteorPal, OBJ_EVENT_PAL_TAG_METEOR },
		{gFollowingMonPic_0207_CherryPal, OBJ_EVENT_PAL_TAG_CHERRY },
		{gFollowingMonPic_0209_FieryYoungYellowWollyhopPal, OBJ_EVENT_PAL_TAG_FIERYYOUNGYELLOWWOLLYHOP },
		{gFollowingMonPic_0210_HotelTransylvaniaPal, OBJ_EVENT_PAL_TAG_HOTELTRANSYLVANIA },
		{gFollowingMonPic_0211_CalyrexPal, OBJ_EVENT_PAL_TAG_CALYREX },
		{gFollowingMonPic_0216_SkeleminPal, OBJ_EVENT_PAL_TAG_SKELEMIN },
		{gFollowingMonPic_0217_MoyaiminPal, OBJ_EVENT_PAL_TAG_MOYAIMIN },
		{gFollowingMonPic_0218_CockatricePal, OBJ_EVENT_PAL_TAG_COCKATRICE },
		{gFollowingMonPic_0219_BupborbPal, OBJ_EVENT_PAL_TAG_BUPBORB },
		{gFollowingMonPic_0220_DwarfKermitPal, OBJ_EVENT_PAL_TAG_DWARFKERMIT },
		{gFollowingMonPic_0221_BulblaxLarvaPal, OBJ_EVENT_PAL_TAG_BULBLAXLARVA },
		{gFollowingMonPic_0222_CoalBeetlePal, OBJ_EVENT_PAL_TAG_COALBEETLE },
		{gFollowingMonPic_0223_HeavyCannonLarvaPal, OBJ_EVENT_PAL_TAG_HEAVYCANNONLARVA },
		{gFollowingMonPic_0224_CrewmatePal, OBJ_EVENT_PAL_TAG_CREWMATE },
		{gFollowingMonPic_0225_ImposterPal, OBJ_EVENT_PAL_TAG_IMPOSTER },
		{gFollowingMonPic_0226_ApachePal, OBJ_EVENT_PAL_TAG_APACHE },
		{gFollowingMonPic_0227_MorshubugPal, OBJ_EVENT_PAL_TAG_MORSHUBUG },
		{gFollowingMonPic_0228_SkitterjuanaPal, OBJ_EVENT_PAL_TAG_SKITTERJUANA },
		{gFollowingMonPic_0229_WahpolePal, OBJ_EVENT_PAL_TAG_WAHPOLE },
		{gFollowingMonPic_0230_WaluigiwogPal, OBJ_EVENT_PAL_TAG_WALUIGIWOG },
		{gFollowingMonPic_0231_StephanPal, OBJ_EVENT_PAL_TAG_STEPHAN },
		{gFollowingMonPic_0232_LinkgretPal, OBJ_EVENT_PAL_TAG_LINKGRET },
		{gFollowingMonPic_0233_OliManAtLegsPal, OBJ_EVENT_PAL_TAG_OLIMANATLEGS },
		{gFollowingMonPic_0234_BulbeelPal, OBJ_EVENT_PAL_TAG_BULBEEL },
		{gFollowingMonPic_0235_IwagenPal, OBJ_EVENT_PAL_TAG_IWAGEN },
		{gFollowingMonPic_0236_128MariosPal, OBJ_EVENT_PAL_TAG_128MARIOS },
		{gFollowingMonPic_0237_FiddleheadPal, OBJ_EVENT_PAL_TAG_FIDDLEHEAD },
		{gFollowingMonPic_0238_HorsetailPal, OBJ_EVENT_PAL_TAG_HORSETAIL },
		{gFollowingMonPic_0239_SpotcapPal, OBJ_EVENT_PAL_TAG_SPOTCAP },
		{gFollowingMonPic_0240_KingcapPal, OBJ_EVENT_PAL_TAG_KINGCAP },
		{gFollowingMonPic_0241_BulbiePal, OBJ_EVENT_PAL_TAG_BULBIE },
		{gFollowingMonPic_0242_SlugcatPal, OBJ_EVENT_PAL_TAG_SLUGCAT },
		{gFollowingMonPic_0243_PinkElebitPal, OBJ_EVENT_PAL_TAG_PINKELEBIT },
		{gFollowingMonPic_0244_PrimalAspidPal, OBJ_EVENT_PAL_TAG_PRIMALASPID },
		{gFollowingMonPic_0245_ChibiRoboPal, OBJ_EVENT_PAL_TAG_CHIBIROBO },
		{gFollowingMonPic_0246_PikachuPal, OBJ_EVENT_PAL_TAG_PIKACHU },
		{gFollowingMonPic_0150_SmokyProgMasterPal, OBJ_EVENT_PAL_TAG_SMOKYPROG_MASTER },

        // Shiny Palettes
		{gShinyFollowingMonPic_0001_BulborbLarvaPal, OBJ_EVENT_PAL_TAG_BULBORBLARVA_SHINY},
        {gShinyFollowingMonPic_0002_BulborbPal, OBJ_EVENT_PAL_TAG_BULBORB_SHINY},
        {gShinyFollowingMonPic_0003_JumboBulborbPal, OBJ_EVENT_PAL_TAG_JUMBOBULBORB_SHINY},
        {gShinyFollowingMonPic_0004_FieryBlowletPal, OBJ_EVENT_PAL_TAG_FIERYBLOWLET},
        {gShinyFollowingMonPic_0005_FieryBlowhogPal, OBJ_EVENT_PAL_TAG_FIERYBLOWHOG},
        {gShinyFollowingMonPic_0006_TitanBlowhogPal, OBJ_EVENT_PAL_TAG_TITANBLOWHOG},
        {gShinyFollowingMonPic_0007_WolpolePal, OBJ_EVENT_PAL_TAG_WOLPOLE_SHINY},
        {gShinyFollowingMonPic_0008_YellowWollyhopPal, OBJ_EVENT_PAL_TAG_YELLOWWOLLYHOP_SHINY},
        {gShinyFollowingMonPic_0009_MasterhopPal, OBJ_EVENT_PAL_TAG_MASTERHOP_SHINY},
		{gShinyFollowingMonPic_0010_FlintBeetlePal, OBJ_EVENT_PAL_TAG_FLINTBEETLE_SHINY},
		{gShinyFollowingMonPic_0011_DoodlebugPal, OBJ_EVENT_PAL_TAG_DOODLEBUG_SHINY},
		{gShinyFollowingMonPic_0012_GlintBeetlePal, OBJ_EVENT_PAL_TAG_GLINTBEETLE_SHINY},
		{gShinyFollowingMonPic_0013_SwoopingSnitchbugPal, OBJ_EVENT_PAL_TAG_SWOOPINGSNITCHBUG_SHINY},
		{gShinyFollowingMonPic_0014_BumblingSnitchbugPal, OBJ_EVENT_PAL_TAG_BUMBLINGSNITCHBUG_SHINY},
		{gShinyFollowingMonPic_0015_DirigibugPal, OBJ_EVENT_PAL_TAG_DIRIGIBUG_SHINY},
		{gShinyFollowingMonPic_0016_SnowBulborbPal, OBJ_EVENT_PAL_TAG_SNOWBULBORB_SHINY},
		{gShinyFollowingMonPic_0017_DwarfFrostyBulborbPal, OBJ_EVENT_PAL_TAG_DWARFFROSTYBULBORB_SHINY},
		{gShinyFollowingMonPic_0018_FrostyBulborbPal, OBJ_EVENT_PAL_TAG_FROSTYBULBORB_SHINY},
		{gShinyFollowingMonPic_0019_CrumbugPal, OBJ_EVENT_PAL_TAG_CRUMBUG_SHINY},
		{gShinyFollowingMonPic_0020_BreadbugPal, OBJ_EVENT_PAL_TAG_BREADBUG_SHINY},
		{gShinyFollowingMonPic_0021_GiantBreadbugPal, OBJ_EVENT_PAL_TAG_GIANTBREADBUG_SHINY},
		{gShinyFollowingMonPic_0022_EmperorBulblaxPal, OBJ_EVENT_PAL_TAG_EMPERORBULBLAX_SHINY},
		{gShinyFollowingMonPic_0023_SovreignBulblaxPal, OBJ_EVENT_PAL_TAG_SOVREIGNBULBLAX_SHINY},
		{gShinyFollowingMonPic_0024_DwarfBulbearPal, OBJ_EVENT_PAL_TAG_DWARFBULBEAR_SHINY},
		{gShinyFollowingMonPic_0025_BulbearPal, OBJ_EVENT_PAL_TAG_SPOTTYBULBEAR_SHINY},
		{gShinyFollowingMonPic_0026_HoneywispPal, OBJ_EVENT_PAL_TAG_HONEYWISP_SHINY},
		{gShinyFollowingMonPic_0027_DandelflyPal, OBJ_EVENT_PAL_TAG_DANDELFLY_SHINY},
		{gShinyFollowingMonPic_0028_DownySnagretPal, OBJ_EVENT_PAL_TAG_DOWNYSNAGRET_SHINY},
		{gShinyFollowingMonPic_0029_BurrowingSnagretPal, OBJ_EVENT_PAL_TAG_BURROWINGSNAGRET_SHINY},
		{gShinyFollowingMonPic_0030_PileatedSnagretPal, OBJ_EVENT_PAL_TAG_PILEATEDSNAGRET_SHINY},
		{gShinyFollowingMonPic_0031_FemaleSheargrubPal, OBJ_EVENT_PAL_TAG_FEMALESHEARGRUB_SHINY},
		{gShinyFollowingMonPic_0032_SwarmingSheargrubPal, OBJ_EVENT_PAL_TAG_SWARMINGSHEARGRUB_SHINY},
		{gShinyFollowingMonPic_0033_MamaSheargrubPal, OBJ_EVENT_PAL_TAG_MAMASHEARGRUB_SHINY},
		{gShinyFollowingMonPic_0034_MaleSheargrubPal, OBJ_EVENT_PAL_TAG_MALESHEARGRUB_SHINY},
		{gShinyFollowingMonPic_0035_ShearwigPal, OBJ_EVENT_PAL_TAG_SHEARWIG_SHINY},
		{gShinyFollowingMonPic_0036_QueenShearwigPal, OBJ_EVENT_PAL_TAG_QUEENSHEARWIG_SHINY},
		{gShinyFollowingMonPic_0037_AristocrabOffspringPal, OBJ_EVENT_PAL_TAG_ARISTOCRABOFFSPRING_SHINY},
		{gShinyFollowingMonPic_0038_PeckishAristocrabPal, OBJ_EVENT_PAL_TAG_ARISTOCRAB_SHINY},
		{gShinyFollowingMonPic_0039_GoolixPal, OBJ_EVENT_PAL_TAG_GOOLIX_SHINY},
		{gShinyFollowingMonPic_0040_FoolixPal, OBJ_EVENT_PAL_TAG_FOOLIX_SHINY},
		{gShinyFollowingMonPic_0041_ArcticCannonLarvaPal, OBJ_EVENT_PAL_TAG_ARCTICCANNONLARVA_SHINY},
		{gShinyFollowingMonPic_0042_ArcticCannonBeetlePal, OBJ_EVENT_PAL_TAG_ARCTICCANNONBEETLE_SHINY},
		{gShinyFollowingMonPic_0043_SkitterleafPal, OBJ_EVENT_PAL_TAG_SKITTERLEAF_SHINY},
		{gShinyFollowingMonPic_0044_DesiccatedSkitterleafPal, OBJ_EVENT_PAL_TAG_DESICCATEDSKITTERLEAF_SHINY},
		{gShinyFollowingMonPic_0045_ArmoredCannonLarvaPal, OBJ_EVENT_PAL_TAG_ARMOREDCANNONLARVA_SHINY},
		{gShinyFollowingMonPic_0046_ArmoredCannonBeetlePal, OBJ_EVENT_PAL_TAG_ARMOREDCANNONBEETLE_SHINY},
		{gShinyFollowingMonPic_0047_HornedCannonBeetlePal, OBJ_EVENT_PAL_TAG_HORNEDCANNONBEETLE_SHINY},
		{gShinyFollowingMonPic_0048_CreepingChrysanthemumPal, OBJ_EVENT_PAL_TAG_CREEPINGCHRYSANTHEMUM_SHINY},
		{gShinyFollowingMonPic_0049_StartleSporePal, OBJ_EVENT_PAL_TAG_STARTLESPORE_SHINY},
		{gShinyFollowingMonPic_0050_HermitCrawmadPal, OBJ_EVENT_PAL_TAG_HERMITCRAWMAD_SHINY},
		{gShinyFollowingMonPic_0051_BugEyedCrawmadPal, OBJ_EVENT_PAL_TAG_BUGEYEDCRAWMAD_SHINY},
		{gShinyFollowingMonPic_0052_DwarfBulborbPal, OBJ_EVENT_PAL_TAG_DWARFBULBORB_SHINY},
		{gShinyFollowingMonPic_0053_DwarfOrangeBulborbPal, OBJ_EVENT_PAL_TAG_DWARFORANGEBULBORB_SHINY},
		{gShinyFollowingMonPic_0054_BeadyLonLegsPal, OBJ_EVENT_PAL_TAG_BEADYLONGLEGS_SHINY},
		{gShinyFollowingMonPic_0055_RagingLongLegsPal, OBJ_EVENT_PAL_TAG_RAGINGLONGLEGS_SHINY},
		{gShinyFollowingMonPic_0056_BaldyLongLegsPal, OBJ_EVENT_PAL_TAG_BALDYLONGLEGS_SHINY},
		{gShinyFollowingMonPic_0057_ShaggyLongLegsPal, OBJ_EVENT_PAL_TAG_SHAGGYLONGLEGS_SHINY},
		{gShinyFollowingMonPic_0058_BulbminPal, OBJ_EVENT_PAL_TAG_BULBMIN_SHINY},
		{gShinyFollowingMonPic_0059_AdultBulbminPal, OBJ_EVENT_PAL_TAG_ADULTBULBMIN_SHINY},
		{gShinyFollowingMonPic_0060_ScornetPal, OBJ_EVENT_PAL_TAG_SCORNET_SHINY},
		{gShinyFollowingMonPic_0061_ScornetMaestroPal, OBJ_EVENT_PAL_TAG_SCORNETMAESTRO_SHINY},
		{gShinyFollowingMonPic_0062_BurrowNitPal, OBJ_EVENT_PAL_TAG_BURROWNIT_SHINY},
		{gShinyFollowingMonPic_0063_JoustmitePal, OBJ_EVENT_PAL_TAG_JOUSTMITE_SHINY},
		{gShinyFollowingMonPic_0064_FlightyJoustmitePal, OBJ_EVENT_PAL_TAG_FLIGHTYJOUSTMITE_SHINY},
		{gShinyFollowingMonPic_0065_VolatileDweevilPal, OBJ_EVENT_PAL_TAG_VOLATILEDWEEVIL_SHINY},
		{gShinyFollowingMonPic_0066_ManAtLegsPal, OBJ_EVENT_PAL_TAG_MANATLEGS_SHINY},
		{gShinyFollowingMonPic_0067_SkutterchuckPal, OBJ_EVENT_PAL_TAG_SKUTTERCHUCK_SHINY},
		{gShinyFollowingMonPic_0068_CalcifiedCrushblatPal, OBJ_EVENT_PAL_TAG_CALCIFIEDCRUSHBLAT_SHINY},
		{gShinyFollowingMonPic_0069_ArachnodePal, OBJ_EVENT_PAL_TAG_ARACHNODE_SHINY},
		{gShinyFollowingMonPic_0070_MoldyDwarfBulborbPal, OBJ_EVENT_PAL_TAG_MOLDYDWARFBULBORB_SHINY},
		{gShinyFollowingMonPic_0071_MoldySloochPal, OBJ_EVENT_PAL_TAG_MOLDYSLOOCH_SHINY},
		{gShinyFollowingMonPic_0072_ToxstoolPal, OBJ_EVENT_PAL_TAG_TOXSTOOL_SHINY},
		{gShinyFollowingMonPic_0073_PhosbatPal, OBJ_EVENT_PAL_TAG_PHOSBAT_SHINY},
		{gShinyFollowingMonPic_0074_VeheamothPhosbatPal, OBJ_EVENT_PAL_TAG_VEHEAMOTHPHOSBAT_SHINY},
		{gShinyFollowingMonPic_0075_PuckeringBlinnowPal, OBJ_EVENT_PAL_TAG_PUCKERINGBLINNOW_SHINY},
		{gShinyFollowingMonPic_0076_SputtlefishPal, OBJ_EVENT_PAL_TAG_SPUTTLEFISH_SHINY},
		{gShinyFollowingMonPic_0077_PricklepuffPal, OBJ_EVENT_PAL_TAG_PRICKLEPUFF_SHINY},
		{gShinyFollowingMonPic_0078_UjadaniPal, OBJ_EVENT_PAL_TAG_UJADANI_SHINY},
		{gShinyFollowingMonPic_0079_MititePal, OBJ_EVENT_PAL_TAG_MITITE_SHINY},
		{gShinyFollowingMonPic_0080_WitheringBlowhogPal, OBJ_EVENT_PAL_TAG_WITHERINGBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0081_PuffyBlowhogPal, OBJ_EVENT_PAL_TAG_PUFFYBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0082_MiniatureSnootwhackerPal, OBJ_EVENT_PAL_TAG_MINIATURESNOOTWHACKER_SHINY},
		{gShinyFollowingMonPic_0083_MammothSnootwhackerPal, OBJ_EVENT_PAL_TAG_MAMMOTHSNOOTWHACKER_SHINY},
		{gShinyFollowingMonPic_0084_PyroclasticSloochPal, OBJ_EVENT_PAL_TAG_PYROCLASTICSLOOCH_SHINY},
		{gShinyFollowingMonPic_0085_LesserSpottedJellyfloatPal, OBJ_EVENT_PAL_TAG_LESSERSPOTTEDJELLYFLOAT_SHINY},
		{gShinyFollowingMonPic_0086_GreaterSpottedJellyfloatPal, OBJ_EVENT_PAL_TAG_GREATERSPOTTEDJELLYFLOAT_SHINY},
		{gShinyFollowingMonPic_0087_ToadyBloysterPal, OBJ_EVENT_PAL_TAG_TOADYBLOYSTER_SHINY},
		{gShinyFollowingMonPic_0088_RangingBloysterPal, OBJ_EVENT_PAL_TAG_RANGINGBLOYSTER_SHINY},
		{gShinyFollowingMonPic_0089_SnowyBlowhogPal, OBJ_EVENT_PAL_TAG_SNOWYBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0090_BlizzardingBlowhogPal, OBJ_EVENT_PAL_TAG_BLIZZARDINGBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0091_GildemandweePal, OBJ_EVENT_PAL_TAG_GILDEMANDWEE_SHINY},
		{gShinyFollowingMonPic_0092_GildemanderPal, OBJ_EVENT_PAL_TAG_GILDEMANDER_SHINY},
		{gShinyFollowingMonPic_0093_WaddlequaffPal, OBJ_EVENT_PAL_TAG_WADDLEQUAFF_SHINY},
		{gShinyFollowingMonPic_0094_GrubchuckerPal, OBJ_EVENT_PAL_TAG_GRUBCHUCKER_SHINY},
		{gShinyFollowingMonPic_0095_PearlyClamclampPal, OBJ_EVENT_PAL_TAG_PEARLYCLAMCLAMP_SHINY},
		{gShinyFollowingMonPic_0096_SunsquishPal, OBJ_EVENT_PAL_TAG_SUNQUISH_SHINY},
		{gShinyFollowingMonPic_0097_PorquillionPal, OBJ_EVENT_PAL_TAG_PROQUILLION_SHINY},
		{gShinyFollowingMonPic_0098_TuskedBlowhogPal, OBJ_EVENT_PAL_TAG_TUSKEDBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0099_SnowflakeFluttertailPal, OBJ_EVENT_PAL_TAG_SNOWFLAKEFLUTTERTAIL_SHINY},
		{gShinyFollowingMonPic_0100_BogswallowPal, OBJ_EVENT_PAL_TAG_BOGSWALLOW_SHINY},
		{gShinyFollowingMonPic_0101_PuffminPal, OBJ_EVENT_PAL_TAG_PUFFMIN_SHINY},
		{gShinyFollowingMonPic_0102_WollyhopPal, OBJ_EVENT_PAL_TAG_WOLLYHOP_SHINY},
		{gShinyFollowingMonPic_0103_ChillyhopPal, OBJ_EVENT_PAL_TAG_CHILLYHOP_SHINY},
		{gShinyFollowingMonPic_0104_BloomcapBloysterPal, OBJ_EVENT_PAL_TAG_BLOOMCAPBLOYSTER_SHINY},
		{gShinyFollowingMonPic_0105_ScorchcakePal, OBJ_EVENT_PAL_TAG_SCORCHCAKE_SHINY},
		{gShinyFollowingMonPic_0106_WaterDumplePal, OBJ_EVENT_PAL_TAG_WATERDUMPLE_SHINY},
		{gShinyFollowingMonPic_0107_LongWaterDumplePal, OBJ_EVENT_PAL_TAG_LONGWATERDUMPLE_SHINY},
		{gShinyFollowingMonPic_0108_MockiwiPal, OBJ_EVENT_PAL_TAG_MOCKIWI_SHINY},
		{gShinyFollowingMonPic_0109_CrestedMockiwiPal, OBJ_EVENT_PAL_TAG_CRESTEDMOCKIWI_SHINY},
		{gShinyFollowingMonPic_0110_ElongatedCrushblatPal, OBJ_EVENT_PAL_TAG_ELONGATEDCRUSHBLAT_SHINY},
		{gShinyFollowingMonPic_0111_PuffstalkPal, OBJ_EVENT_PAL_TAG_PUFFSTALK_SHINY},
		{gShinyFollowingMonPic_0112_PuffstoolPal, OBJ_EVENT_PAL_TAG_PUFFSTOOL_SHINY},
		{gShinyFollowingMonPic_0113_AnodeBeetlePal, OBJ_EVENT_PAL_TAG_ANODEBEETLE_SHINY},
		{gShinyFollowingMonPic_0114_EmpressBulblaxPal, OBJ_EVENT_PAL_TAG_EMPRESSBULBLAX_SHINY},
		{gShinyFollowingMonPic_0115_SkeeterskatePal, OBJ_EVENT_PAL_TAG_SKEETERSKATE_SHINY},
		{gShinyFollowingMonPic_0116_MuckerskatePal, OBJ_EVENT_PAL_TAG_MUCKERSKATE_SHINY},
		{gShinyFollowingMonPic_0117_GroovyLongLegsPal, OBJ_EVENT_PAL_TAG_GROOVYLONGLEGS_SHINY},
		{gShinyFollowingMonPic_0118_CrustedRumpupPal, OBJ_EVENT_PAL_TAG_CRUSTEDRUMPUP_SHINY},
		{gShinyFollowingMonPic_0119_BeardedAmpratPal, OBJ_EVENT_PAL_TAG_BEARDEDAMPRAT_SHINY},
		{gShinyFollowingMonPic_0120_FieryBulblaxPal, OBJ_EVENT_PAL_TAG_FIERYBULBLAX_SHINY},
		{gShinyFollowingMonPic_0121_GattlingGroinkPal, OBJ_EVENT_PAL_TAG_GATTLINGGROINK_SHINY},
		{gShinyFollowingMonPic_0122_ArmurkPal, OBJ_EVENT_PAL_TAG_ARMURK_SHINY},
		{gShinyFollowingMonPic_0123_SegmentedCrawbsterPal, OBJ_EVENT_PAL_TAG_SEGMENTEDCRAWBSTER_SHINY},
		{gShinyFollowingMonPic_0124_ArmoredMawdadPal, OBJ_EVENT_PAL_TAG_ARMOREDMAWDAD_SHINY},
		{gShinyFollowingMonPic_0125_SandbelchingMeerslugPal, OBJ_EVENT_PAL_TAG_SANDBELCHINGMEERSLUG_SHINY},
		{gShinyFollowingMonPic_0126_ClickingSlurkerPal, OBJ_EVENT_PAL_TAG_CLICKINGSLURKER_SHINY},
		{gShinyFollowingMonPic_0127_LuringSlurkerPal, OBJ_EVENT_PAL_TAG_LURINGSLURKER_SHINY},
		{gShinyFollowingMonPic_0128_MedusalSlurkerPal, OBJ_EVENT_PAL_TAG_MEDUSALSLURKER_SHINY},
		{gShinyFollowingMonPic_0129_PelletPosyPal, OBJ_EVENT_PAL_TAG_PELLETPOSY_SHINY},
		{gShinyFollowingMonPic_0130_MasterOnionPal, OBJ_EVENT_PAL_TAG_MASTERONION_SHINY},
		{gShinyFollowingMonPic_0131_OatchiPal, OBJ_EVENT_PAL_TAG_OATCHI_SHINY},
		{gShinyFollowingMonPic_0132_QuaggledMireclopsPal, OBJ_EVENT_PAL_TAG_QUAGGLEDMIRECLOPS_SHINY},
		{gShinyFollowingMonPic_0133_AlbinoDwarfBulborbPal, OBJ_EVENT_PAL_TAG_ALBINODWARFBULBORB_SHINY},
		{gShinyFollowingMonPic_0134_HairyBulborbPal, OBJ_EVENT_PAL_TAG_HAIRYBULBORB_SHINY},
		{gShinyFollowingMonPic_0135_WhiptongueBulborbPal, OBJ_EVENT_PAL_TAG_WHIPTONGUEBULBORB_SHINY},
		{gShinyFollowingMonPic_0136_OrangeBulborbPal, OBJ_EVENT_PAL_TAG_ORANGEBULBORB_SHINY},
		{gShinyFollowingMonPic_0137_WhitePikminPal, OBJ_EVENT_PAL_TAG_WHITEPIKMIN_SHINY},
		{gShinyFollowingMonPic_0138_BluePikminPal, OBJ_EVENT_PAL_TAG_BLUEPIKMIN_SHINY},
		{gShinyFollowingMonPic_0139_RockPikminPal, OBJ_EVENT_PAL_TAG_ROCKPIKMIN_SHINY},
		{gShinyFollowingMonPic_0140_YellowPikminPal, OBJ_EVENT_PAL_TAG_YELLOWPIKMIN_SHINY},
		{gShinyFollowingMonPic_0141_WingedPikminPal, OBJ_EVENT_PAL_TAG_WINGEDPIKMIN_SHINY},
		{gShinyFollowingMonPic_0142_RedPikminPal, OBJ_EVENT_PAL_TAG_REDPIKMIN_SHINY},
		{gShinyFollowingMonPic_0143_PurplePikminPal, OBJ_EVENT_PAL_TAG_PURPLEPIKMIN_SHINY},
		{gShinyFollowingMonPic_0144_WaterWraithPal, OBJ_EVENT_PAL_TAG_WATERWRAITH_SHINY},
		{gShinyFollowingMonPic_0145_TitanDweevilPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_SHINY},
		{gShinyFollowingMonPic_0146_PlasmWraithPal, OBJ_EVENT_PAL_TAG_PLASMWRAITH_SHINY},
		{gShinyFollowingMonPic_0147_IcePikminPal, OBJ_EVENT_PAL_TAG_ICEPIKMIN_SHINY},
		{gShinyFollowingMonPic_0148_GlowSeedPal, OBJ_EVENT_PAL_TAG_GLOWSEED_SHINY},
		{gShinyFollowingMonPic_0149_GlowPikminPal, OBJ_EVENT_PAL_TAG_GLOWPIKMIN_SHINY},
		{gShinyFollowingMonPic_0150_SmokyProggPal, OBJ_EVENT_PAL_TAG_SMOKYPROGG_SHINY},
		{gShinyFollowingMonPic_0151_MamutaPal, OBJ_EVENT_PAL_TAG_MAMUTA_SHINY},
		{gShinyFollowingMonPic_0152_MossPal, OBJ_EVENT_PAL_TAG_MOSS_SHINY},
		{gShinyFollowingMonPic_0153_ToyBorbPal, OBJ_EVENT_PAL_TAG_TOYBORB_SHINY},
		{gShinyFollowingMonPic_0154_BulblordPal, OBJ_EVENT_PAL_TAG_BULBLORD_SHINY},
		{gShinyFollowingMonPic_0155_PinchipedePal, OBJ_EVENT_PAL_TAG_PINCHIPEDE_SHINY},
		{gShinyFollowingMonPic_0156_LargeMothWollyhopPal, OBJ_EVENT_PAL_TAG_LARGEMOUTHWOLLYHOP_SHINY},
		{gShinyFollowingMonPic_0157_ToyBlowhogPal, OBJ_EVENT_PAL_TAG_TOYBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0158_TelescopingPumphogPal, OBJ_EVENT_PAL_TAG_TELESCOPINGPUMPHOG_SHINY},
		{gShinyFollowingMonPic_0159_BeebPal, OBJ_EVENT_PAL_TAG_BEEB_SHINY},
		{gShinyFollowingMonPic_0160_BladedBeebPal, OBJ_EVENT_PAL_TAG_BLADEDBEEB_SHINY},
		{gShinyFollowingMonPic_0161_StuddedBeebPal, OBJ_EVENT_PAL_TAG_STUDDEDBEEB_SHINY},
		{gShinyFollowingMonPic_0162_FireflapBulborbPal, OBJ_EVENT_PAL_TAG_FIREFLAPBULBORB_SHINY},
		{gShinyFollowingMonPic_0163_IceblownDweevilPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_SHINY},
		{gShinyFollowingMonPic_0164_SpectralidPal, OBJ_EVENT_PAL_TAG_SPECTRALID_SHINY},
		{gShinyFollowingMonPic_0165_BlubbugPal, OBJ_EVENT_PAL_TAG_BLUBBUG_SHINY},
		{gShinyFollowingMonPic_0166_PuffyBlubbugPal, OBJ_EVENT_PAL_TAG_PUFFYBLUBBUG_SHINY},
		{gShinyFollowingMonPic_0167_StuffedBellbloomPal, OBJ_EVENT_PAL_TAG_STUFFEDBELLBLOOM_SHINY},
		{gShinyFollowingMonPic_0168_CentiparePal, OBJ_EVENT_PAL_TAG_CENTIPARE_SHINY},
		{gShinyFollowingMonPic_0169_AdultCentiparePal, OBJ_EVENT_PAL_TAG_ADULTCENTIPARE_SHINY},
		{gShinyFollowingMonPic_0170_WateryBlowhogPal, OBJ_EVENT_PAL_TAG_WATERYBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0171_GrabbitPal, OBJ_EVENT_PAL_TAG_GRABBIT_SHINY},
		{gShinyFollowingMonPic_0172_CoppellerPal, OBJ_EVENT_PAL_TAG_COPPELLER_SHINY},
		{gShinyFollowingMonPic_0173_MuggonflyPal, OBJ_EVENT_PAL_TAG_MUGGONFLY_SHINY},
		{gShinyFollowingMonPic_0174_ElectricCottonadePal, OBJ_EVENT_PAL_TAG_ELECTRICCOTTONADE_SHINY},
		{gShinyFollowingMonPic_0175_WaddlepusPal, OBJ_EVENT_PAL_TAG_WADDLEPUS_SHINY},
		{gShinyFollowingMonPic_0176_CrammedWraithPal, OBJ_EVENT_PAL_TAG_CRAMMEDWRAITH_SHINY},
		{gShinyFollowingMonPic_0177_BerserkLeechHydroePal, OBJ_EVENT_PAL_TAG_BERSERKLEECHHYDROE_SHINY},
		{gShinyFollowingMonPic_0178_PebblePitcherPal, OBJ_EVENT_PAL_TAG_PEBBLEPITCHER_SHINY},
		{gShinyFollowingMonPic_0189_AncientSirehoundPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_SHINY},
		{gShinyFollowingMonPic_0180_CourageReactorPal, OBJ_EVENT_PAL_TAG_COURAGEREACTOR_SHINY},
		{gShinyFollowingMonPic_0181_AssembledCouragePal, OBJ_EVENT_PAL_TAG_ASSEMBLEDCOURAGE_SHINY},
		{gShinyFollowingMonPic_0182_RememberedOldBuddyPal, OBJ_EVENT_PAL_TAG_REMEMBEREDOLDBUDDY_SHINY},
		{gShinyFollowingMonPic_0183_BulborbWithAGunPal, OBJ_EVENT_PAL_TAG_BULBORBWITHAGUN_SHINY},
		{gShinyFollowingMonPic_0184_KirbyPal, OBJ_EVENT_PAL_TAG_KIRBY_SHINY},
		{gShinyFollowingMonPic_0185_SoulPal, OBJ_EVENT_PAL_TAG_SOUL_SHINY},
		{gShinyFollowingMonPic_0000_PlaceholderLarvaPal, OBJ_EVENT_PAL_TAG_PLACEHOLDERLARVA_SHINY},
		{gShinyFollowingMonPic_0186_Demo77Pal, OBJ_EVENT_PAL_TAG_DEMO77_SHINY},
		{gShinyFollowingMonPic_0187_UsubaPal, OBJ_EVENT_PAL_TAG_USUBA_SHINY},
		{gShinyFollowingMonPic_0188_KakureimoPal, OBJ_EVENT_PAL_TAG_KAKUREIMO_SHINY},
		{gShinyFollowingMonPic_0189_PikutabePal, OBJ_EVENT_PAL_TAG_PIKUTABE_SHINY},
		{gShinyFollowingMonPic_0190_NamaPongashiPal, OBJ_EVENT_PAL_TAG_NAMAPONGASHI_SHINY},
		{gShinyFollowingMonPic_0191_ChappyProtoPal, OBJ_EVENT_PAL_TAG_CHAPPYPROTO_SHINY},
		{gShinyFollowingMonPic_0412_EggPal, OBJ_EVENT_PAL_TAG_EGG_SHINY },
		{gShinyFollowingMonPic_0192_RedBubblimpPal, OBJ_EVENT_PAL_TAG_REDBUBBLIMP_SHINY},
		{gShinyFollowingMonPic_0193_StarnaclePal, OBJ_EVENT_PAL_TAG_STARNACLE_SHINY},
		{gShinyFollowingMonPic_0194_ShearfleaPal, OBJ_EVENT_PAL_TAG_SHEARFLEA_SHINY},
		{gShinyFollowingMonPic_0195_WhiskerPillarPal, OBJ_EVENT_PAL_TAG_WHISKERPILLAR_SHINY},
		{gShinyFollowingMonPic_0196_IcyBlowhogPal, OBJ_EVENT_PAL_TAG_ICYBLOWHOG_SHINY},
		{gShinyFollowingMonPic_0212_FreezecakePal, OBJ_EVENT_PAL_TAG_FREEZECAKE_SHINY},
		{gShinyFollowingMonPic_0213_ShockcakePal, OBJ_EVENT_PAL_TAG_SHOCKCAKE_SHINY},
		{gShinyFollowingMonPic_0214_WideMouthedAnodeBeetlePal, OBJ_EVENT_PAL_TAG_WIDEMOUTHEDANODEBEETLE_SHINY},
		{gShinyFollowingMonPic_0215_DecoratedCannonBeetlePal, OBJ_EVENT_PAL_TAG_DECORATEDCANNONBEETLE_SHINY},
		{gShinyFollowingMonPic_0208_AntennaBeetlePal, OBJ_EVENT_PAL_TAG_ANTENNABEETLE_SHINY},
		{gShinyFollowingMonPic_0142_RedPikminVeteranPal, OBJ_EVENT_PAL_TAG_REDPIKMIN_VETERAN_SHINY},
		{gShinyFollowingMonPic_0145_TitanDweevilElectricPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_ELECTRIC_SHINY},
		{gShinyFollowingMonPic_0145_TitanDweevilFirePal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_FIRE_SHINY},
		{gShinyFollowingMonPic_0145_TitanDweevilPoisonPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_POISON_SHINY},
		{gShinyFollowingMonPic_0145_TitanDweevilWaterPal, OBJ_EVENT_PAL_TAG_TITANDWEEVIL_WATER_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidRedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_RED_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidYellowPal, OBJ_EVENT_PAL_TAG_SPECTRALID_YELLOW_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidUnmarkedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKED_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidUnmarkedRedPal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKEDRED_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidUnmarkedPurplePal, OBJ_EVENT_PAL_TAG_SPECTRALID_UNMARKEDPURPLE_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidElectricPal, OBJ_EVENT_PAL_TAG_SPECTRALID_ELECTRIC_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidHey0Pal, OBJ_EVENT_PAL_TAG_SPECTRALID_HEY0_SHINY},
		{gShinyFollowingMonPic_0165_SpectralidHey1Pal, OBJ_EVENT_PAL_TAG_SPECTRALID_HEY1_SHINY},
		{gShinyFollowingMonPic_0179_AncientSirehoundIcePal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_ICE_SHINY},
		{gShinyFollowingMonPic_0179_AncientSirehoundElectricPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_ELECTRIC_SHINY},
		{gShinyFollowingMonPic_0179_AncientSirehoundFirePal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_FIRE_SHINY},
		{gShinyFollowingMonPic_0179_AncientSirehoundGloomPal, OBJ_EVENT_PAL_TAG_ANCIENTSIREHOUND_GLOOM_SHINY},
		{gShinyFollowingMonPic_0184_KirbyFlyingPal, OBJ_EVENT_PAL_TAG_KIRBY_FLYING_SHINY},
		{gShinyFollowingMonPic_0184_KirbyGrassPal, OBJ_EVENT_PAL_TAG_KIRBY_GRASS_SHINY},
		{gShinyFollowingMonPic_0184_KirbyBugPal, OBJ_EVENT_PAL_TAG_KIRBY_BUG_SHINY},
		{gShinyFollowingMonPic_0184_KirbyPoisonPal, OBJ_EVENT_PAL_TAG_KIRBY_POISON_SHINY},
		{gShinyFollowingMonPic_0184_KirbyWaterPal, OBJ_EVENT_PAL_TAG_KIRBY_WATER_SHINY},
		{gShinyFollowingMonPic_0184_KirbyIcePal, OBJ_EVENT_PAL_TAG_KIRBY_ICE_SHINY},
		{gShinyFollowingMonPic_0184_KirbyFirePal, OBJ_EVENT_PAL_TAG_KIRBY_FIRE_SHINY},
		{gShinyFollowingMonPic_0184_KirbyElectricPal, OBJ_EVENT_PAL_TAG_KIRBY_ELECTRIC_SHINY},
		{gShinyFollowingMonPic_0184_KirbyFightingPal, OBJ_EVENT_PAL_TAG_KIRBY_FIGHTING_SHINY},
		{gShinyFollowingMonPic_0184_KirbyRockPal, OBJ_EVENT_PAL_TAG_KIRBY_ROCK_SHINY},
		{gShinyFollowingMonPic_0184_KirbyGroundPal, OBJ_EVENT_PAL_TAG_KIRBY_GROUND_SHINY},
		{gShinyFollowingMonPic_0184_KirbyPsychicPal, OBJ_EVENT_PAL_TAG_KIRBY_PSYCHIC_SHINY},
		{gShinyFollowingMonPic_0184_KirbyGhostPal, OBJ_EVENT_PAL_TAG_KIRBY_GHOST_SHINY},
		{gShinyFollowingMonPic_0184_KirbyDragonPal, OBJ_EVENT_PAL_TAG_KIRBY_DRAGON_SHINY},
		{gShinyFollowingMonPic_0184_KirbyDarkPal, OBJ_EVENT_PAL_TAG_KIRBY_DARK_SHINY },
		{gShinyFollowingMonPic_0184_KirbySteelPal, OBJ_EVENT_PAL_TAG_KIRBY_STEEL_SHINY},
		{gShinyFollowingMonPic_0184_KirbyFairyPal, OBJ_EVENT_PAL_TAG_KIRBY_FAIRY_SHINY},
		{gShinyFollowingMonPic_0185_SoulRedPal, OBJ_EVENT_PAL_TAG_SOUL_RED_SHINY},
		{gShinyFollowingMonPic_0185_SoulYellowPal, OBJ_EVENT_PAL_TAG_SOUL_YELLOW_SHINY},
		{gShinyFollowingMonPic_0185_SoulBluePal, OBJ_EVENT_PAL_TAG_SOUL_BLUE_SHINY},
		{gShinyFollowingMonPic_0185_SoulPurplePal, OBJ_EVENT_PAL_TAG_SOUL_PURPLE_SHINY},
		{gShinyFollowingMonPic_0185_SoulWhitePal, OBJ_EVENT_PAL_TAG_SOUL_WHITE_SHINY},
		{gShinyFollowingMonPic_0185_SoulRockPal, OBJ_EVENT_PAL_TAG_SOUL_ROCK_SHINY},
		{gShinyFollowingMonPic_0185_SoulWingedPal, OBJ_EVENT_PAL_TAG_SOUL_WINGED_SHINY},
		{gShinyFollowingMonPic_0185_SoulIcePal, OBJ_EVENT_PAL_TAG_SOUL_ICE_SHINY},
		{gShinyFollowingMonPic_0164_IceblownDweevilFirePal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_F_SHINY},
		{gShinyFollowingMonPic_0164_IceblownDweevilElectricPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_E_SHINY},
		{gShinyFollowingMonPic_0164_IceblownDweevilWaterPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_W_SHINY},
		{gShinyFollowingMonPic_0164_IceblownDweevilPoisonPal, OBJ_EVENT_PAL_TAG_ICEBLOWNDWEEVIL_P_SHINY},
		{gShinyFollowingMonPic_0197_MysteriousLifeFormPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_SHINY},
		{gShinyFollowingMonPic_0197_MysteriousLifeFormBulborbPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_BULBORB_SHINY },
		{gShinyFollowingMonPic_0197_MysteriousLifeFormAmpratPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_AMPRAT_SHINY },
		{gShinyFollowingMonPic_0197_MysteriousLifeFormDandelflyPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_DANDELFLY_SHINY },
		{gShinyFollowingMonPic_0197_MysteriousLifeFormArachnodePal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_ARACHNODE_SHINY },
		{gShinyFollowingMonPic_0197_MysteriousLifeFormBlowhogPal, OBJ_EVENT_PAL_TAG_MYSTERIOUSLIFEFORM_BLOWHOG_SHINY },
		{gShinyFollowingMonPic_0198_PeteyPirannhaPal, OBJ_EVENT_PAL_TAG_PETEYPIRANNHA_SHINY},
		{gShinyFollowingMonPic_0199_ToyPikminRedPal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_RED_SHINY},
		{gShinyFollowingMonPic_0199_ToyPikminYellowPal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_YELLOW_SHINY},
		{gShinyFollowingMonPic_0199_ToyPikminBluePal, OBJ_EVENT_PAL_TAG_TOYPIKMIN_BLUE_SHINY},
		{gShinyFollowingMonPic_0200_PikiMalePal, OBJ_EVENT_PAL_TAG_PIKI_MALE_SHINY},
		{gShinyFollowingMonPic_0200_PikiFemalePal, OBJ_EVENT_PAL_TAG_PIKI_FEMALE_SHINY},
		{gShinyFollowingMonPic_0201_DemoFPal, OBJ_EVENT_PAL_TAG_DEMOF_SHINY},
		{gShinyFollowingMonPic_0202_DemoGPal, OBJ_EVENT_PAL_TAG_DEMOG_SHINY},
		{gShinyFollowingMonPic_0203_DemoIPal, OBJ_EVENT_PAL_TAG_DEMOI_SHINY},
		{gShinyFollowingMonPic_0204_DemoWPal, OBJ_EVENT_PAL_TAG_DEMOW_SHINY},
		{gShinyFollowingMonPic_0205_UsualSuspectPal, OBJ_EVENT_PAL_TAG_USUALSUSPECT_SHINY},
		{gShinyFollowingMonPic_0206_MeteorPal, OBJ_EVENT_PAL_TAG_METEOR_SHINY},
		{gShinyFollowingMonPic_0207_CherryPal, OBJ_EVENT_PAL_TAG_CHERRY_SHINY},
		{gShinyFollowingMonPic_0209_FieryYoungYellowWollyhopPal, OBJ_EVENT_PAL_TAG_FIERYYOUNGYELLOWWOLLYHOP_SHINY},
		{gShinyFollowingMonPic_0210_HotelTransylvaniaPal, OBJ_EVENT_PAL_TAG_HOTELTRANSYLVANIA_SHINY},
		{gShinyFollowingMonPic_0211_CalyrexPal, OBJ_EVENT_PAL_TAG_CALYREX_SHINY},
		{gShinyFollowingMonPic_0216_SkeleminPal, OBJ_EVENT_PAL_TAG_SKELEMIN_SHINY},
		{gShinyFollowingMonPic_0217_MoyaiminPal, OBJ_EVENT_PAL_TAG_MOYAIMIN_SHINY},
		{gShinyFollowingMonPic_0218_CockatricePal, OBJ_EVENT_PAL_TAG_COCKATRICE_SHINY},
		{gShinyFollowingMonPic_0219_BupborbPal, OBJ_EVENT_PAL_TAG_BUPBORB_SHINY},
		{gShinyFollowingMonPic_0220_DwarfKermitPal, OBJ_EVENT_PAL_TAG_DWARFKERMIT_SHINY},
		{gShinyFollowingMonPic_0221_BulblaxLarvaPal, OBJ_EVENT_PAL_TAG_BULBLAXLARVA_SHINY},
		{gShinyFollowingMonPic_0222_CoalBeetlePal, OBJ_EVENT_PAL_TAG_COALBEETLE_SHINY},
		{gShinyFollowingMonPic_0223_HeavyCannonLarvaPal, OBJ_EVENT_PAL_TAG_HEAVYCANNONLARVA_SHINY},
		{gShinyFollowingMonPic_0224_CrewmatePal, OBJ_EVENT_PAL_TAG_CREWMATE_SHINY},
		{gShinyFollowingMonPic_0225_ImposterPal, OBJ_EVENT_PAL_TAG_IMPOSTER_SHINY},
		{gShinyFollowingMonPic_0226_ApachePal, OBJ_EVENT_PAL_TAG_APACHE_SHINY},
		{gShinyFollowingMonPic_0227_MorshubugPal, OBJ_EVENT_PAL_TAG_MORSHUBUG_SHINY},
		{gShinyFollowingMonPic_0228_SkitterjuanaPal, OBJ_EVENT_PAL_TAG_SKITTERJUANA_SHINY},
		{gShinyFollowingMonPic_0229_WahpolePal, OBJ_EVENT_PAL_TAG_WAHPOLE_SHINY},
		{gShinyFollowingMonPic_0230_WaluigiwogPal, OBJ_EVENT_PAL_TAG_WALUIGIWOG_SHINY},
		{gShinyFollowingMonPic_0231_StephanPal, OBJ_EVENT_PAL_TAG_STEPHAN_SHINY},
		{gShinyFollowingMonPic_0232_LinkgretPal, OBJ_EVENT_PAL_TAG_LINKGRET_SHINY},
		{gShinyFollowingMonPic_0233_OliManAtLegsPal, OBJ_EVENT_PAL_TAG_OLIMANATLEGS_SHINY},
		{gShinyFollowingMonPic_0234_BulbeelPal, OBJ_EVENT_PAL_TAG_BULBEEL_SHINY},
		{gShinyFollowingMonPic_0235_IwagenPal, OBJ_EVENT_PAL_TAG_IWAGEN_SHINY},
		{gShinyFollowingMonPic_0236_128MariosPal, OBJ_EVENT_PAL_TAG_128MARIOS_SHINY},
		{gShinyFollowingMonPic_0237_FiddleheadPal, OBJ_EVENT_PAL_TAG_FIDDLEHEAD_SHINY},
		{gShinyFollowingMonPic_0238_HorsetailPal, OBJ_EVENT_PAL_TAG_HORSETAIL_SHINY},
		{gShinyFollowingMonPic_0239_SpotcapPal, OBJ_EVENT_PAL_TAG_SPOTCAP_SHINY},
		{gShinyFollowingMonPic_0240_KingcapPal, OBJ_EVENT_PAL_TAG_KINGCAP_SHINY},
		{gShinyFollowingMonPic_0241_BulbiePal, OBJ_EVENT_PAL_TAG_BULBIE_SHINY},
		{gShinyFollowingMonPic_0242_SlugcatPal, OBJ_EVENT_PAL_TAG_SLUGCAT_SHINY},
		{gShinyFollowingMonPic_0243_PinkElebitPal, OBJ_EVENT_PAL_TAG_PINKELEBIT_SHINY},
		{gShinyFollowingMonPic_0244_PrimalAspidPal, OBJ_EVENT_PAL_TAG_PRIMALASPID_SHINY},
		{gShinyFollowingMonPic_0245_ChibiRoboPal, OBJ_EVENT_PAL_TAG_CHIBIROBO_SHINY},
		{gShinyFollowingMonPic_0246_PikachuPal, OBJ_EVENT_PAL_TAG_PIKACHU_SHINY},
		{gShinyFollowingMonPic_0150_SmokyProgMasterPal, OBJ_EVENT_PAL_TAG_SMOKYPROG_MASTER_SHINY },
};

#ifdef PALETTE_SWAPPER
	const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] =
	{
		[0x11] = gObjectEventSpritePalettes11,
		[0x12] = gObjectEventSpritePalettes12,
	};
#endif

struct PlayerGraphics
{
	u16 graphicsId;
	u8 stateFlag;
};

static const struct PlayerGraphics sPlayerAvatarGfxIds[][2] =
{
	[PLAYER_AVATAR_STATE_NORMAL] =     {{EVENT_OBJ_GFX_RED_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT},          {EVENT_OBJ_GFX_LEAF_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT}},
	[PLAYER_AVATAR_STATE_BIKE] =       {{EVENT_OBJ_GFX_RED_BIKE, PLAYER_AVATAR_FLAG_BIKE},               {EVENT_OBJ_GFX_LEAF_BIKE, PLAYER_AVATAR_FLAG_BIKE}},
	[PLAYER_AVATAR_STATE_SURFING] =    {{EVENT_OBJ_GFX_RED_SURFING, PLAYER_AVATAR_FLAG_SURFING},         {EVENT_OBJ_GFX_LEAF_SURFING, PLAYER_AVATAR_FLAG_SURFING}},
	[PLAYER_AVATAR_STATE_FIELD_MOVE] = {{EVENT_OBJ_GFX_RED_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE},   {EVENT_OBJ_GFX_LEAF_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE}},
	[PLAYER_AVATAR_STATE_FISHING] =    {{EVENT_OBJ_GFX_RED_FISHING, 0},                                  {EVENT_OBJ_GFX_LEAF_FISHING, 0}},
	[PLAYER_AVATAR_STATE_VS_SEEKER] =  {{EVENT_OBJ_GFX_RED_VS_SEEKER, 0},                                {EVENT_OBJ_GFX_LEAF_VS_SEEKER, 0}},
	[PLAYER_AVATAR_STATE_UNDERWATER] = {{EVENT_OBJ_GFX_RED_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},   {EVENT_OBJ_GFX_LEAF_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER}},
};

//npc_get_type hack for character customization
//hook at 0805F2C8 via r1
NPCPtr GetEventObjectGraphicsInfo(u16 graphicsId)
{
	u16 newId;
	u8 tableId = (graphicsId >> 8) & 0xFF;	// upper byte
	u8 spriteId = graphicsId & 0xFF;		// lower byte

	//Check runtime changeable OWs
	if (tableId == 0xFF && spriteId <= 0xF)
	{
		//Runtime changeable
		newId = VarGet(VAR_RUNTIME_CHANGEABLE + spriteId);
		tableId = (newId >> 8) & 0xFF;	// upper byte
		spriteId = (newId & 0xFF);		// lower byte
	}
	else
	{
		switch (spriteId) {
			case EVENT_OBJ_GFX_RED_BIKE_VS_SEEKER:
			case EVENT_OBJ_GFX_LEAF_BIKE_VS_SEEKER:
				if (tableId == 0) //Actually the Vs. Seeker sprites
				{
					newId = VarGet(VAR_PLAYER_VS_SEEKER_ON_BIKE);
					if (newId != 0) //Actually set to something different
					{
						tableId = (newId >> 8) & 0xFF;	// upper byte
						spriteId = (newId & 0xFF);		// lower byte
					}
				}
				break;
		}

		#ifndef UNBOUND
		if (spriteId > 239 && tableId == 0)
		{
			newId = VarGetEventObjectGraphicsId(spriteId + 16);
			tableId = (newId >> 8) & 0xFF;	// upper byte
			spriteId = (newId & 0xFF);		// lower byte
		}
		#endif
	}

	NPCPtr spriteAddr;
	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (tableId >= NELEMS(gOverworldTableSwitcher)
	|| gOverworldTableSwitcher[tableId] == 0)
		spriteAddr = gOverworldTableSwitcher[0][spriteId];
	else
	#endif
		spriteAddr = gOverworldTableSwitcher[tableId][spriteId];

	if (spriteAddr == NULL)
		spriteAddr = gOverworldTableSwitcher[0][EVENT_OBJ_GFX_LITTLE_BOY];	// first non-player sprite in first table default

	return spriteAddr;
};

NPCPtr GetEventObjectGraphicsInfoByEventObj(struct EventObject* eventObj)
{
	return GetEventObjectGraphicsInfo(GetEventObjectGraphicsId(eventObj));
}

static u16 GetCustomGraphicsIdByState(u8 state)
{
	u16 gfxId = 0;

	switch (state) {
		case PLAYER_AVATAR_STATE_NORMAL:
			gfxId = VarGet(VAR_PLAYER_WALKRUN);
			break;
		case PLAYER_AVATAR_STATE_BIKE:
			gfxId = VarGet(VAR_PLAYER_BIKING);
			break;
		case PLAYER_AVATAR_STATE_SURFING:
			gfxId = VarGet(VAR_PLAYER_SURFING);
			break;
		case PLAYER_AVATAR_STATE_FIELD_MOVE: //HM Use
			gfxId = VarGet(VAR_PLAYER_HM_USE);
			break;
		case PLAYER_AVATAR_STATE_VS_SEEKER:
			gfxId = VarGet(VAR_PLAYER_VS_SEEKER);
			break;
		case PLAYER_AVATAR_STATE_FISHING:
			gfxId = VarGet(VAR_PLAYER_FISHING);
			break;
		case PLAYER_AVATAR_STATE_UNDERWATER:
			gfxId = VarGet(VAR_PLAYER_UNDERWATER);
			break;
	}

	return gfxId;
}

u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
	u16 graphicsId = GetCustomGraphicsIdByState(state);
	if (graphicsId != 0)
		return graphicsId;

	return sPlayerAvatarGfxIds[state][gender].graphicsId;
}

u16 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
	return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar->gender);
}

u8 GetPlayerAvatarStateTransitionByGraphicsId(u16 graphicsId, u8 gender)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		u16 customGraphicsId = GetCustomGraphicsIdByState(state);
		if (customGraphicsId == graphicsId)
			graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;

        if (sPlayerAvatarGfxIds[state][gender].graphicsId == graphicsId)
            return sPlayerAvatarGfxIds[state][gender].stateFlag;
    }

    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u16 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
	u8 state = 0;
	u8 gender = gPlayerAvatar->gender;
    u8 flags = gPlayerAvatar->flags;

    for (; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
        if (sPlayerAvatarGfxIds[state][gender].stateFlag & flags)
		{
			u16 graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;
			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0)
				graphicsId = customGraphicsId;

			return graphicsId;
		}
    }

    return sPlayerAvatarGfxIds[0][0].graphicsId;
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		for (u8 gender = 0; gender < NELEMS(sPlayerAvatarGfxIds[0]); ++gender)
		{
			if (sPlayerAvatarGfxIds[state][gender].graphicsId == gfxId)
				return gender;

			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0 && customGraphicsId == gfxId)
				return gSaveBlock2->playerGender;
		}
	}

	return MALE;
}

static void SetPlayerAvatarExtraStateTransition(u16 graphicsId, u8 b)
{
    u8 unk = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar->gender);
	SetPlayerAvatarTransitionFlags(unk | b);
}

u16 GetEventObjectGraphicsId(struct EventObject* eventObj)
{
	u8 lowerByte = eventObj->graphicsIdLowerByte;
	u8 upperByte = eventObj->graphicsIdUpperByte;

	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (upperByte >= NELEMS(gOverworldTableSwitcher)
	&& upperByte != 0xFF) //Dynamic OW table
		return lowerByte;
	#endif

	if (upperByte == 0xFF && lowerByte <= 0xF)
		return VarGet(VAR_RUNTIME_CHANGEABLE + lowerByte); //Runtime changeable

	return lowerByte | (upperByte << 8);
}

void SetPlayerAvatarEventObjectIdAndObjectId(u8 eventObjectId, u8 spriteId)
{
    gPlayerAvatar->eventObjectId = eventObjectId;
    gPlayerAvatar->spriteId = spriteId;
    gPlayerAvatar->gender = GetPlayerAvatarGenderByGraphicsId(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]));
    SetPlayerAvatarExtraStateTransition(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]), 0x20);
}

static u8 GetColorFromTextColorTableNew(u16 gfxId)
{
	#ifdef UNBOUND
	u8 gender = GetEventObjectGraphicsInfo(gfxId)->gender;
	return gender == MALE ? 0 : gender == FEMALE ? 1 : 2; //Blue, Red, Black
	#else
	return GetColorFromTextColorTable(gfxId);
	#endif
}

u8 ContextNpcGetTextColor(void)
{
	u16 gfxId;

	if (gSpecialVar_TextColor != 0xFF)
	{
		return gSpecialVar_TextColor;
	}
	else if (gSelectedEventObject == 0)
	{
		return 3;
	}
	else
	{
		gfxId = GetEventObjectGraphicsId(&gEventObjects[gSelectedEventObject]);

		#ifndef UNBOUND
		if (gfxId >= EVENT_OBJ_GFX_VAR_0 && gfxId <= 0xFF) //Vanilla dynamic id
			gfxId = VarGetEventObjectGraphicsId(gfxId - EVENT_OBJ_GFX_VAR_0);
		#endif

		return GetColorFromTextColorTableNew(gfxId);
	}
}

// load trainer card sprite based on variables
// 	hook at 810c374 via r2
u8 PlayerGenderToFrontTrainerPicId(u8 gender, bool8 modify)
{
	if (modify != TRUE)
		return gender;

	u16 trainerId = VarGet(VAR_TRAINERCARD_MALE + gender);
	if (trainerId == 0)
		trainerId = TRAINER_PIC_PLAYER_M + gender;

	return trainerId;
};

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
	u8 eventObjectId;
	struct EventObject* eventObject;
	struct EventObjectTemplate playerEventObjTemplate = {0};
	u16 graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);

	playerEventObjTemplate.localId = EVENT_OBJ_ID_PLAYER;
	playerEventObjTemplate.graphicsIdLowerByte = graphicsId & 0xFF;
	playerEventObjTemplate.graphicsIdUpperByte = graphicsId >> 8;
	playerEventObjTemplate.x = x - 7;
	playerEventObjTemplate.y = y - 7;
	playerEventObjTemplate.movementType = MOVEMENT_TYPE_PLAYER;

	eventObjectId = SpawnSpecialEventObject(&playerEventObjTemplate);
	eventObject = &gEventObjects[eventObjectId];
	eventObject->isPlayer = 1;
	eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
	EventObjectTurn(eventObject, direction);
	ClearPlayerAvatarInfo();

	gPlayerAvatar->runningState = NOT_MOVING;
	gPlayerAvatar->tileTransitionState = T_NOT_MOVING;
	gPlayerAvatar->eventObjectId = eventObjectId;
	gPlayerAvatar->spriteId = eventObject->spriteId;
	gPlayerAvatar->gender = gender;
	SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_FIELD_MOVE | PLAYER_AVATAR_FLAG_ON_FOOT);
	CreateFollowerAvatar();
	if (FlagGet(FLAG_SPAWN_INVISIBLE))
    {
        FlagClear(FLAG_SPAWN_INVISIBLE);
        eventObject->invisible = TRUE;
    }
}

void PlayerHandleDrawTrainerPic(void)
{
	s16 xPos, yPos;
	u32 trainerPicId = GetBackspriteId();

	if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
	{
		if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
			xPos = 90;
		else // First mon, on the left.
			xPos = 32;

		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	else
	{
		xPos = 80;
		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0; //So it appears above enemy healthbars

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = 240;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -3; //-2; //Speed scrolling in
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn; //sub_805D7AC in Emerald

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy;
}

void PlayerHandleTrainerSlide(void)
{
	u32 trainerPicId = GetBackspriteId();

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], 80, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, 30);

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0;

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = -96;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 2;
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy2;
}

u16 GetBackspriteId(void)
{
	u16 trainerPicId;

	if (gBattleTypeFlags & BATTLE_TYPE_LINK)
	{
		if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
		|| (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
		else
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_BRENDAN;
	}
	else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gActiveBattler == 2)
	{
		trainerPicId = LoadPartnerBackspriteIndex();
	}
	else if (IsAIControlledBattle())
	{
		trainerPicId = LoadPartnerBackspriteIndex(); //The trainer's backsprite for the Battle Sands is stored in the multi partner var
	}
	else
	{
		if (VarGet(VAR_BACKSPRITE_SWITCH))
			trainerPicId = VarGet(VAR_BACKSPRITE_SWITCH);
		else
			trainerPicId = gSaveBlock2->playerGender;
	}

	return trainerPicId;
}

#ifdef UNBOUND
bool8 IsPaletteTagAffectedByCharacterCustomization(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
		case EVENT_OBJ_PAL_TAG_MOM:
		case EVENT_OBJ_PAL_TAG_AROS:
		case EVENT_OBJ_PAL_TAG_RED_PLAYER:
		case EVENT_OBJ_PAL_TAG_LEAF_PLAYER:
		case EVENT_OBJ_PAL_TAG_ETHAN_PLAYER:
		case EVENT_OBJ_PAL_TAG_LYRA_PLAYER:
		case EVENT_OBJ_PAL_TAG_LUCAS_PLAYER:
		case EVENT_OBJ_PAL_TAG_DAWN_PLAYER:
		case EVENT_OBJ_PAL_TAG_SHADOW_GRUNT_PLAYER:
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return TRUE;
		default:
			return FALSE;
	}
}

static bool8 IsPaletteTagAffectedBySkinCharacterCustomization(unusedArg u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static bool8 IsPaletteTagAffectedByHairCharacterCustomization(u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_AROS
		&& tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static u8 GetOutfitStyleByEventObjTag(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
			return OUTFIT_STYLE_DEFAULT;
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return OUTFIT_STYLE_CHAMPION;
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
			return OUTFIT_STYLE_MARLON;
		default:
			return OUTFIT_STYLE_NONE;
	}
}

#define SKIN_TONE_OFFSET 1
#define HAIR_COLOUR_OFFSET 4
#define OUTFIT_OFFSET 7
#define DEFAULT_TRIM_OFFSET (OUTFIT_OFFSET + 2)
static void ChangePlayerPaletteByPaletteAndOffset(u16 paletteOffset, bool8 changeSkin, bool8 changeHair, u8 outfitStyle)
{
	u16 skinTone = VarGet(VAR_PLAYER_SKIN_TONE);
	u16 hairColour = VarGet(VAR_PLAYER_HAIR_COLOUR);

	if (changeSkin && skinTone > 0 && skinTone < NELEMS(sPlayerSkinColours))
	{
		u16 skinOffset = paletteOffset + SKIN_TONE_OFFSET;
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferUnfaded + skinOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferFaded + skinOffset, 3 * sizeof(u16));
	}

	if (changeHair && hairColour > 0 && hairColour < NELEMS(sPlayerHairColours))
	{
		u16 hairOffset = paletteOffset + HAIR_COLOUR_OFFSET;
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferUnfaded + hairOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferFaded + hairOffset, 3 * sizeof(u16));
	}

	if (outfitStyle != OUTFIT_STYLE_NONE)
	{
		const u16* const* outfitPals;
		const u16* const* trimPals;
		u16 outfitColour, trimColour;
		u32 outfitPalCount, trimPalCount, copyAmount;
		trimColour = 0;

		if (outfitStyle == OUTFIT_STYLE_CHAMPION)
		{
			outfitColour = VarGet(VAR_PLAYER_CHAMPION_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_CHAMPION_TRIM_COLOUR);
			outfitPals = sPlayerChampionOutfitColours;
			outfitPalCount = NELEMS(sPlayerChampionOutfitColours);
			trimPals = sPlayerChampionTrimColours;
			trimPalCount = NELEMS(sPlayerChampionTrimColours);
			copyAmount = 3;
		}
		else if (outfitStyle == OUTFIT_STYLE_MARLON)
		{
			outfitColour = VarGet(VAR_PLAYER_MARLON_OUTFIT_COLOUR);
			outfitPals = sPlayerMarlonOutfitColours;
			outfitPalCount = NELEMS(sPlayerMarlonOutfitColours);
			copyAmount = 3;
		}
		else
		{
			//Default outfit
			outfitColour = VarGet(VAR_PLAYER_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_TRIM_COLOUR);
			outfitPals = sPlayerOutfitColours;
			outfitPalCount = NELEMS(sPlayerOutfitColours);
			trimPals = sPlayerTrimColours;
			trimPalCount = NELEMS(sPlayerTrimColours);
			copyAmount = 2;
		}

		if (outfitColour > 0 && outfitColour < outfitPalCount)
		{
			u16 outfitOffset = paletteOffset + OUTFIT_OFFSET;
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferUnfaded + outfitOffset, copyAmount * sizeof(u16));
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferFaded + outfitOffset, copyAmount * sizeof(u16));
		}

		if (trimColour > 0 && trimColour < trimPalCount)
		{
			u8 baseTrimOffset = OUTFIT_OFFSET + copyAmount;
			u16 trimOffset = paletteOffset + baseTrimOffset;
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferUnfaded + trimOffset, 2 * sizeof(u16));
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferFaded + trimOffset, 2 * sizeof(u16));
		}
	}
}
#endif

void ChangeEventObjPal(unusedArg u16 paletteOffset, unusedArg u16 palTag)
{
	#ifdef UNBOUND
	ChangePlayerPaletteByPaletteAndOffset(paletteOffset, IsPaletteTagAffectedBySkinCharacterCustomization(palTag),
	                                                     IsPaletteTagAffectedByHairCharacterCustomization(palTag),
	                                                     GetOutfitStyleByEventObjTag(palTag));
	#endif
}

void ChangeTrainerPicPal(unusedArg u16 paletteOffset, unusedArg u8 outfitStyle)
{
	#ifdef UNBOUND
	if (outfitStyle == OUTFIT_STYLE_MARLON)
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, FALSE, FALSE, outfitStyle); //Just outfit, no skin and hair
	else
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, TRUE, TRUE, outfitStyle);
	#endif
}

void ChangeTrainerBackPal(unusedArg u16 backPicId, unusedArg u8 palSot)
{
	#ifdef UNBOUND
	//Dynamically changes the palette of the player character in Unbound
	switch (backPicId)
	{
		case TRAINER_BACK_PIC_RED: //Player M
		case TRAINER_BACK_PIC_LEAF: //Player F
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_DEFAULT); //All colours
			break;
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_M:
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_F:
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_CHAMPION); //All colours
			break;
		case TRAINER_BACK_PIC_MARLON_PLAYER_M:
		case TRAINER_BACK_PIC_MARLON_PLAYER_F:
		case TRAINER_BACK_PIC_IVORY_PLAYER_M:
		case TRAINER_BACK_PIC_IVORY_PLAYER_F:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, FALSE, OUTFIT_STYLE_MARLON); //Just skin and outfit - no hair
			break;
		case TRAINER_BACK_PIC_RED_PLAYER:
		case TRAINER_BACK_PIC_LEAF_PLAYER:
		case TRAINER_BACK_PIC_ETHAN_PLAYER:
		case TRAINER_BACK_PIC_LYRA_PLAYER:
		case TRAINER_BACK_PIC_LUCAS_PLAYER:
		case TRAINER_BACK_PIC_DAWN_PLAYER:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, TRUE, OUTFIT_STYLE_NONE); //Just skin & hair
			break;
	}
	#endif
}

void LoadTrainerBackPal(u16 backPicId, u8 battlerId)
{
	DecompressTrainerBackPalette(backPicId, battlerId);
	ChangeTrainerBackPal(backPicId, battlerId);
}

const u8* GetTrainerSpritePal(u16 trainerPicId)
{
	return gTrainerFrontPicPaletteTable[trainerPicId].data;
}

#ifdef UNBOUND
static bool8 IsTrainerPicAffectedByCustomization(u16 trainerPicId)
{
	return trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F
		|| trainerPicId == TRAINER_PIC_PLAYER_RED
		|| trainerPicId == TRAINER_PIC_PLAYER_LEAF
		|| trainerPicId == TRAINER_PIC_PLAYER_ETHAN
		|| trainerPicId == TRAINER_PIC_PLAYER_LYRA;
}

u8 GetOutfitStyleByTrainerPic(u16 trainerPicId)
{
	if (trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
	|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F)
	{
		return OUTFIT_STYLE_CHAMPION;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F)
	{
		return OUTFIT_STYLE_DEFAULT;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
	|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F)
	{
		return OUTFIT_STYLE_MARLON;
	}

	return OUTFIT_STYLE_NONE;
}
#endif

void TryUpdateTrainerPicPalTrainerCard(u16 trainerPicId, u16 palOffset)
{
	LoadCompressedPalette(GetTrainerSpritePal(trainerPicId), palOffset * 16, 0x20);
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId))
	{
		u32 offset = palOffset * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
	}
	#endif
}

u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u16 spriteId = CreatePicSprite_HandleDeoxys(species, 0, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
	#ifdef UNBOUND
	if (isFrontPic && IsTrainerPicAffectedByCustomization(species))
	{
		u32 offset = 0x100 + gSprites[spriteId].oam.paletteNum * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(species));
	}
	#endif
	return spriteId;
}

void TryModifyMugshotTrainerPicPal(unusedArg u16 trainerPicId, unusedArg u8 index)
{
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId)) //Is player sprite
	{
		if (index != 0xFF)
		{
			u32 offset = 0x100 + index * 16;
			ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
		}
	}
	#endif
}

void TryUpdateRegionMapIconPal(void)
{
	#ifdef UNBOUND
	u8 paletteSlot = IndexOfSpritePaletteTag(1);
	if (paletteSlot != 0xFF)
		ChangeEventObjPal(0x100 + paletteSlot * 16, EVENT_OBJ_PAL_TAG_DEFAULT);
	#endif
}
