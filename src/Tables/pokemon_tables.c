#include "../defines_battle.h"
#include "../../include/pokedex.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
/*
pokemon_tables.c
	set up tables for pokemon species including:
		-Alternate species sizes
		-Banned moves, abilities, and items for battle facilities
		-etc...

tables to edit:
	gAlternateSpeciesSizeTable
	gSkyBattleBannedSpeciesList
	gUltraBeastList
	gDeerlingForms
	gSawsbuckForms
	gVivillonForms
	gFlabebeForms
	gFloetteForms
	gFlorgesForms
	gFurfrouForms
	gSpottyBulbearCapForms
	gAlcremieForms

	gSmogonOU_AbilityBanList
	gSmogonOUDoubles_AbilityBanList
	gBattleTowerStandard_ItemBanList
	gSmogonOU_ItemBanList
	gSmogonNationalDexOU_ItemBanList
	gSmogonOUDoubles_ItemBanList
	gSmogonOUDoubles_MoveBanList
	gSmogon_MoveBanList
	gSmogonLittleCup_MoveBanList
	gSmogonLittleCup_ItemBanList
	gMiddleCup_AbilityBanList
	gMiddleCup_ItemBanList
	gSmogonMonotype_AbilityBanList
	gSmogonMonotype_ItemBanList
	gSmogonAverageMons_ItemBanList
	gSmogonAverageMons_MoveBanList
	gSmogonAverageMons_AbilityBanList
	gSmogon350Cup_ItemBanList
	gSmogon350Cup_AbilityBanList
	gSmogonScalemons_ItemBanList
	gSmogonScalemons_AbilityBanList
	gSmogonUU_ItemBanList
	gSmogonUU_AbilityBanList
	gSmogonRU_ItemBanList
	gSmogonRU_AbilityBanList
	gSmogonNU_ItemBanList
*/

#define ALTERNATE_SIZE(species, height, weight) {species, height * 10, weight * 10}

const struct AlternateSize gAlternateSpeciesSizeTable[] =
{
	ALTERNATE_SIZE(SPECIES_TABLES_TERMIN, 0, 0),
};

const species_t gSkyBattleBannedSpeciesList[] =
{
/*
#ifndef UNBOUND
	SPECIES_GIANTBREADBUG,
	SPECIES_FARFETCHD,
	SPECIES_HOOTHOOT,
	SPECIES_NATU,
	SPECIES_MURKROW,
	SPECIES_DELIBIRD,
	SPECIES_TAILLOW,
#endif
	SPECIES_GENGAR,
	SPECIES_PYROCLASTICSLOOCH,
	SPECIES_LESSERSPOTTEDJELLYFLOAT,
*/
	SPECIES_TABLES_TERMIN
};

//For the purposes of the Beast Ball
const species_t gUltraBeastList[] =
{
	SPECIES_TABLES_TERMIN
};

const species_t gDeerlingForms[] =
{
	//No termin here
};

const u8 gNumDeerlingForms = NELEMS(gDeerlingForms);

const species_t gSawsbuckForms[] =
{
	//No termin here
};

const u8 gNumSawsbuckForms = NELEMS(gSawsbuckForms);

const species_t gVivillonForms[] =
{
	//No termin here
};

const u8 gNumVivillonForms = NELEMS(gVivillonForms);

const species_t gFlabebeForms[] =
{
	//No termin here
};

const u8 gNumFlabebeForms = NELEMS(gFlabebeForms);

const species_t gFloetteForms[] =
{
	//No termin here
};

const u8 gNumFloetteForms = NELEMS(gFloetteForms);

const species_t gFlorgesForms[] =
{
	//No termin here
};

const u8 gNumFlorgesForms = NELEMS(gFlorgesForms);

const species_t gFurfrouForms[] =
{
	//No termin here
};

const u8 gNumFurfrouForms = NELEMS(gFurfrouForms);

const species_t gSpottyBulbearCapForms[] =
{
	//No termin here
};

const u8 gNumSpottyBulbearCapForms = NELEMS(gSpottyBulbearCapForms);

const species_t gAlcremieForms[] =
{
	//No termin here
};

const u8 gNumAlcremieForms = NELEMS(gAlcremieForms);

const ability_t gSmogonOU_AbilityBanList[] =
{
	ABILITY_ARENATRAP,
	ABILITY_SHADOWTAG,
	ABILITY_POWERCONSTRUCT,
	ABILITY_MOODY,
	ABILITY_TABLES_TERMIN
};

const ability_t gSmogonOUDoubles_AbilityBanList[] =
{
	ABILITY_POWERCONSTRUCT,
	ABILITY_MOODY,
	ABILITY_TABLES_TERMIN
};

const item_t gBattleTowerStandard_ItemBanList[] =
{
	#ifdef OLD_SOUL_DEW_EFFECT
	ITEM_SOUL_DEW,
	#endif
	ITEM_TABLES_TERMIN
};

const move_t gRingChallenge_MoveBanList[] =
{
	MOVE_SELFDESTRUCT,
	MOVE_EXPLOSION,
	MOVE_MISTYEXPLOSION,
	MOVE_PERISHSONG,
	MOVE_DESTINYBOND,
};

const item_t gSmogonOU_ItemBanList[] =
{
	ITEM_RED_ORB,
	ITEM_BLUE_ORB,
	#ifdef OLD_SOUL_DEW_EFFECT
	ITEM_SOUL_DEW,
	#endif
	ITEM_TABLES_TERMIN
};

const item_t gSmogonNationalDexOU_ItemBanList[] =
{
	ITEM_RED_ORB,
	ITEM_BLUE_ORB,
	#ifdef OLD_SOUL_DEW_EFFECT
	ITEM_SOUL_DEW,
	#endif
	ITEM_TABLES_TERMIN
};

const item_t gSmogonOUDoubles_ItemBanList[] =
{
	ITEM_EEVIUM_Z,
	ITEM_RED_ORB,
	ITEM_BLUE_ORB,
	#ifdef OLD_SOUL_DEW_EFFECT
	ITEM_SOUL_DEW,
	#endif
	ITEM_TABLES_TERMIN
};

const move_t gSmogonOUDoubles_MoveBanList[] =
{
	MOVE_DARKVOID,
	MOVE_SWAGGER,
	MOVE_TABLES_TERMIN
};

const move_t gSmogon_MoveBanList[] =
{
	MOVE_DOUBLETEAM,
	MOVE_MINIMIZE,
	MOVE_FISSURE,
	MOVE_GUILLOTINE,
	MOVE_HORNDRILL,
	MOVE_SHEERCOLD,
	MOVE_TABLES_TERMIN
};

const move_t gSmogonLittleCup_MoveBanList[] =
{
	MOVE_DRAGONRAGE,
	MOVE_SONICBOOM,
	MOVE_SWAGGER,
	MOVE_TABLES_TERMIN
};

const item_t gSmogonLittleCup_ItemBanList[] =
{
	ITEM_EEVIUM_Z,
	ITEM_TABLES_TERMIN
};

const ability_t gMiddleCup_AbilityBanList[] =
{
	ABILITY_CONTRARY,
	ABILITY_PROTEAN,
	ABILITY_TABLES_TERMIN
};

const species_t gMiddleCup_ItemBanList[] =
{
	ITEM_LIGHT_BALL,
	ITEM_EVIOLITE,
	ITEM_TABLES_TERMIN
};

const ability_t gSmogonMonotype_AbilityBanList[] =
{
	ABILITY_BATTLEBOND,
	ABILITY_SHADOWTAG,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonMonotype_ItemBanList[] =
{
	ITEM_DAMP_ROCK,
	ITEM_SMOOTH_ROCK,
	ITEM_TERRAIN_EXTENDER,
	ITEM_RED_ORB,
	ITEM_BLUE_ORB,
	#ifdef OLD_SOUL_DEW_EFFECT
	ITEM_SOUL_DEW,
	#endif
	ITEM_TABLES_TERMIN
};

const item_t gSmogonAverageMons_ItemBanList[] =
{
	ITEM_THICK_CLUB,
	ITEM_DEEP_SEA_TOOTH,
	ITEM_LIGHT_BALL,
	ITEM_EVIOLITE,
	ITEM_TABLES_TERMIN
};

const move_t gSmogonAverageMons_MoveBanList[] =
{
	MOVE_CHATTER,
	MOVE_BATONPASS,
	MOVE_TABLES_TERMIN
};

const u8 gSmogonAverageMons_AbilityBanList[] =
{
	ABILITY_HUGEPOWER,
	#ifdef ABILITY_PUREPOWER
	ABILITY_PUREPOWER,
	#endif
	ABILITY_SHADOWTAG,
	ABILITY_ARENATRAP,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogon350Cup_ItemBanList[] =
{
	ITEM_DEEP_SEA_TOOTH,
	ITEM_LIGHT_BALL,
	ITEM_EVIOLITE,
	ITEM_EEVIUM_Z,
	ITEM_TABLES_TERMIN
};

const u8 gSmogon350Cup_AbilityBanList[] =
{
	ABILITY_SHADOWTAG,
	ABILITY_ARENATRAP,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonScalemons_ItemBanList[] =
{
	ITEM_DEEP_SEA_SCALE,
	ITEM_DEEP_SEA_TOOTH,
	ITEM_EEVIUM_Z,
	ITEM_EVIOLITE,
	ITEM_LIGHT_BALL,
	ITEM_THICK_CLUB,
	ITEM_TABLES_TERMIN
};

const u8 gSmogonScalemons_AbilityBanList[] =
{
	ABILITY_ARENATRAP,
	ABILITY_SHADOWTAG,
	ABILITY_HUGEPOWER,
	ABILITY_MOODY,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonMetronome_ItemBanList[] =
{
	ITEM_AGUAV_BERRY,
	ITEM_ASSAULT_VEST,
	ITEM_BERRY_JUICE,
	ITEM_BLACK_SLUDGE,
	ITEM_ENIGMA_BERRY,
	ITEM_FIGY_BERRY,
	ITEM_IAPAPA_BERRY,
	ITEM_LEFTOVERS,
	ITEM_MAGO_BERRY,
	ITEM_ORAN_BERRY,
	ITEM_ROCKY_HELMET,
	ITEM_SHELL_BELL,
	ITEM_SITRUS_BERRY,
	ITEM_WIKI_BERRY,
};

const ability_t gSmogonMetronome_AbilityBanList[] =
{
	ABILITY_BATTLEBOND,
	ABILITY_CHEEKPOUCH,
	ABILITY_CURSEDBODY,
	ABILITY_DESOLATELAND,
	ABILITY_DRYSKIN,
	ABILITY_FLUFFY,
	ABILITY_FURCOAT,
	ABILITY_GORILLATACTICS,
	ABILITY_GRASSYSURGE,
	ABILITY_HUGEPOWER,
	ABILITY_ICEBODY,
	#ifdef ABILITY_IRONBARBS
	ABILITY_IRONBARBS,
	#endif
	#ifdef ABILITY_LIBERO
	ABILITY_LIBERO,
	#endif
	ABILITY_MOODY,
	ABILITY_PARENTALBOND,
	ABILITY_PERISHBODY,
	ABILITY_POISONHEAL,
	ABILITY_POWERCONSTRUCT,
	ABILITY_PRESSURE,
	ABILITY_PRIMORDIALSEA,
	ABILITY_PROTEAN,
	#ifdef ABILITY_PUREPOWER
	ABILITY_PUREPOWER,
	#endif
	ABILITY_RAINDISH,
	ABILITY_ROUGHSKIN,
	ABILITY_SANDSPIT,
	ABILITY_SANDSTREAM,
	ABILITY_SNOWWARNING,
	ABILITY_STAMINA,
	ABILITY_VOLTABSORB,
	ABILITY_WATERABSORB,
	ABILITY_WONDERGUARD,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonUU_ItemBanList[] =
{
	ITEM_KOMMONIUM_Z,
	ITEM_MEWNIUM_Z,
	ITEM_TABLES_TERMIN
};

const ability_t gSmogonUU_AbilityBanList[] =
{
	ABILITY_DRIZZLE,
	ABILITY_DROUGHT,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonRU_ItemBanList[] =
{

	ITEM_TABLES_TERMIN
};

const ability_t gSmogonRU_AbilityBanList[] =
{
	ABILITY_DRIZZLE,
	ABILITY_TABLES_TERMIN
};

const item_t gSmogonNU_ItemBanList[] =
{
	ITEM_TABLES_TERMIN
};
