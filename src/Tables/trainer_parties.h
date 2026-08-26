#include "../../include/battle.h"
#include "../../include/global.h"

#include "../../include/constants/items.h"
#include "../../include/constants/moves.h"
#include "../../include/constants/species.h"
#include "../../include/constants/trainer_classes.h"
#include "../../include/new/build_pokemon_2.h"
#include "../../src/config.h"

#include "trainer_defines.h"

#ifdef EXPAND_TRAINERS

#define DUMMY_TRAINER_MON           \
    {                               \
        .lvl = 5,                   \
        .species = SPECIES_GATTLINGGROINK,   \
    }

#define DUMMY_TRAINER_MON_IV        \
    {                               \
        .iv = 100,                  \
        .lvl = 5,                   \
        .species = SPECIES_GATTLINGGROINK,   \
    }

// Copy of Swimmer Male Finn's party
#define DUMMY_TRAINER_GATTLINGGROINK       \
    {                               \
        .lvl = 38,                  \
        .species = SPECIES_GATTLINGGROINK, \
    }

struct TrainerMonNoItemDefaultMoves sParty_BobEntry[] =  {
    {
        .iv = 0,
        .lvl = 4,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_FLINTBEETLE,
    },
};

struct TrainerMonItemDefaultMoves sParty_BobEntryR[] = {
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_GIANTBREADBUG,
        .heldItem = ITEM_LEFTOVERS
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_GLINTBEETLE,
        .heldItem = ITEM_BITTER_GLINT_BERRY
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BobExit[] =  {
    {
        .iv = 0,
        .lvl = 4,
        .species = SPECIES_MALESHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_FEMALESHEARGRUB,
    },
};
struct TrainerMonNoItemDefaultMoves sParty_BobExitR[] =  {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_QUEENSHEARWIG,
    },
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_SHEARFLEA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2Flowers1[] =  {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SKITTERLEAF,
    },
};
struct TrainerMonItemDefaultMoves sParty_R2Flowers1R[] =  {
    {
        .iv = 0,
        .lvl = 51,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_MIRACLE_SEED,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_POWER_HERB,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_WHITE_HERB,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_MENTAL_HERB,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_BITTER_DESICCATED_BERRY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2HallLeft[] =  {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_WADDLEQUAFF,
    },
};
struct TrainerMonItemDefaultMoves sParty_R2HallLeftR[] =  {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_PILEATEDSNAGRET,
        .heldItem = ITEM_BITTER_PILEATED_BERRY,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_WADDLEQUAFF,
        .heldItem = ITEM_BIG_ROOT
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2HallRight[] =  {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_TOADYBLOYSTER,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_TOADYBLOYSTER,
    },
};
struct TrainerMonItemDefaultMoves sParty_R2HallRightR[] =  {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_RANGINGBLOYSTER,
        .heldItem = ITEM_LEFTOVERS,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_BLOOMCAPBLOYSTER,
        .heldItem = ITEM_KINGS_ROCK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2NorthWest[] =  {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
    {
        .iv = 0,
        .lvl = 4,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 4,
        .species = SPECIES_SKITTERLEAF,
    },
};
struct TrainerMonNoItemDefaultMoves sParty_R2NorthWestR[] =  {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_STARTLESPORE,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 53,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2Flowers2[] =  {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_CRUMBUG,
    },
};
struct TrainerMonItemDefaultMoves sParty_R2Flowers2R[] =  {
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_GIANTBREADBUG,
        .heldItem = ITEM_BITTER_BREAD_BERRY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_R2Exit[] =  {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_SUNQUISH,
    },
};
struct TrainerMonNoItemDefaultMoves sParty_R2ExitR[] =  {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_DGRing[] =  {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_HONEYWISP,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_FLINTBEETLE,
    },
};
struct TrainerMonNoItemDefaultMoves sParty_DGRingR[] =  {
    {
        .iv = 0,
        .lvl = 62,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_GLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_DGCross[] =  {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SCORCHCAKE,
    },
};
struct TrainerMonItemDefaultMoves sParty_DGCrossR[] =  {
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_SCORCHCAKE,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DIRIGIBUG,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BITTER_MAN_AT_BERRY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_DGFloor2[] =  {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
};
struct TrainerMonItemDefaultMoves sParty_DGFloor2R[] =  {
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_DIRIGIBUG,
        .heldItem = ITEM_BITTER_DIRIGI_BERRY,
    },
    {
        .iv = 0,
        .lvl = 63,
        .species = SPECIES_GREATERSPOTTEDJELLYFLOAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Gym1RedStatue[] =  {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_DOWNYSNAGRET,
    },
};
struct TrainerMonNoItemDefaultMoves sParty_Gym1RedStatueR[] =  {
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_GLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_BUGEYEDCRAWMAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Gym1WhiteStatue[] =  {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_DOODLEBUG,
    },
};
struct TrainerMonItemDefaultMoves sParty_Gym1WhiteStatueR[] =  {
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_GLINTBEETLE,
        .heldItem = ITEM_BITTER_GLINT_BERRY,
    },
    {
        .iv = 0,
        .lvl = 60,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Gym1RockStatue[] =  {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_CRUMBUG,
    },
};
struct TrainerMonItemDefaultMoves sParty_Gym1RockStatueR[] =  {
    {
        .iv = 0,
        .lvl = 56,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 57,
        .species = SPECIES_TUSKEDBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 55,
        .species = SPECIES_MUCKERSKATE,
        .heldItem = ITEM_BITTER_MUCK_BERRY,
    },
    {
        .iv = 0,
        .lvl = 58,
        .species = SPECIES_MAMMOTHSNOOTWHACKER,
    },
};

struct TrainerMonItemCustomMoves sParty_Gym1Dingo[] =  {
    {
        .iv = 255,
        .lvl = 14,
        .species = SPECIES_DOODLEBUG,
        .ability = 2,
        .moves = {MOVE_PAYDAY, MOVE_ROCKPOLISH, MOVE_ACCELEROCK, MOVE_MUDSLAP},
        .heldItem = ITEM_SCOPE_LENS,
        .evSpread = {0,252,6,0,0,252},
        .nature = NATURE_ADAMANT
    },
    {
        .iv = 128,
        .lvl = 14,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_PECK, MOVE_ROCKSMASH, MOVE_DETECT, MOVE_MUDSLAP}
    },
    {
        .iv = 128,
        .lvl = 16,
        .species = SPECIES_BREADBUG,
        .ability = 1,
        .moves = {MOVE_COVET, MOVE_DEFENSECURL, MOVE_TACKLE, MOVE_MUDSLAP}
    }
};

struct TrainerMonNoItemDefaultMoves sParty_Gym1DingoR[] =  {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_GATTLINGGROINK,
    }
};

struct TrainerMonNoItemDefaultMoves sParty_SchoolKidF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_SrAndJr[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PokefanM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PokefanF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_ExpertM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_ExpertF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSYoungster[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSChampion[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSFisherman[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_CyclingTriathleteM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_CyclingTriathleteF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RunningTriathleteM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RunningTriathleteF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_SwimmingTriathleteM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_SwimmingTriathleteF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_DragonTamer[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSBirdKeeper[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_NinjaBoy[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BattleGirl[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_ArmoredCannonBeetleolLady[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSSwimmerF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSPicnicker[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSTwins[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSSailor[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BoarderM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BoarderF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_Collector[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_Wally[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_Brendan[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_Brendan2[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_Brendan3[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_May[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_May2[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_May3[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSPkmnBreederM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSPkmnBreederF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSPkmnRangerM[] = {DUMMY_TRAINER_MON_IV};
struct TrainerMonNoItemDefaultMoves sParty_RSPkmnRangerF[] = {DUMMY_TRAINER_MON_IV};
struct TrainerMonNoItemDefaultMoves sParty_MagmaLeader[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_MagmaGruntM[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_MagmaGruntF[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSLass[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSBugCatcher[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSHiker[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSYoungCouple[] = {DUMMY_TRAINER_MON, DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_OldCouple[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_RSSisAndBro[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_AquaAdminMatt[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_AquaAdminShelly[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_MagmaAdminTabitha[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_MagmaAdminCourtney[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_LeaderWattson[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_LeaderFlannery[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_LeaderNorman[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_LeaderWinona[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_LeaderWallace[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_EliteFourGlacia[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_EliteFourDrake[] = {DUMMY_TRAINER_MON};

// Start of actual trainer data
struct TrainerMonNoItemDefaultMoves sParty_YoungsterBen[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterCalvin[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GIANTBREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterJosh[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmy[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterJoey[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_GIANTBREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterDan[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_ARMOREDMAWDAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterChad[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterTyler[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterEddie[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterDillon[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasu[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterDave[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_MAMASHEARGRUB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterBen2[] = {
    {
        .iv = 20,
        .lvl = 17,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 20,
        .lvl = 17,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherRick[] = {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_FLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherDoug[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherSammy[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColton[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_FLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherGreg[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_DOODLEBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherJames[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_DOODLEBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherKent[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherRobby[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_DOODLEBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_FLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherCale[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_DOODLEBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherKeigo[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherElijah[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_GLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcher2[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_DOODLEBUG,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherBrent[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DIRIGIBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DIRIGIBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherConner[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassJanice[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_SNOWBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassSally[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassRobin[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GOOLIX,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassCrissy[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_ARMOREDCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_ARMOREDCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_HORNEDCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassMiriam[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassIris[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassReli[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassAli[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Lass2[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassHaley[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_SKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassAnn[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassDawn[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassPaige[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_BURROWINGSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassAndrea[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassMegan[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassJulia[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassKay[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassLisa[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorEdmond[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorTrevor[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_TOXSTOOL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorLeonard[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorDuncan[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_TOXSTOOL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorHuey[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorDylan[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorPhillip[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SailorDwayne[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemCustomMoves sParty_CamperLiam[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_TACKLE, MOVE_DEFENSECURL, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_DANDELFLY,
        .moves = {MOVE_SCRATCH, MOVE_DEFENSECURL, MOVE_SANDATTACK, MOVE_NONE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperShane[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperEthan[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BALDYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperRicky[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperJeff[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Camper2[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_CamperChris[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_FIERYBLOWLET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperDrew[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerDiana[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerNancy[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelle[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_SNOWBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelsey[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlicia[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerCaitlin[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerHeidi[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerCarol[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerSofia[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_GOOLIX,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerMartha[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_BULBORBLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerTina[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BULBORBLARVA,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerHannah[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMark[] = {
    {
        .iv = 30,
        .lvl = 29,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 30,
        .lvl = 29,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHerman[] = {
    {
        .iv = 30,
        .lvl = 20,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 30,
        .lvl = 20,
        .species = SPECIES_ARMOREDMAWDAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacCooper[] = {
    {
        .iv = 30,
        .lvl = 20,
        .species = SPECIES_ARMOREDMAWDAD,
    },
    {
        .iv = 30,
        .lvl = 20,
        .species = SPECIES_ARMOREDMAWDAD,
    },
    {
        .iv = 30,
        .lvl = 20,
        .species = SPECIES_ARMOREDMAWDAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacSteve[] = {
    {
        .iv = 30,
        .lvl = 22,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 30,
        .lvl = 22,
        .species = SPECIES_SOUL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacWinston[] = {
    {
        .iv = 30,
        .lvl = 25,
        .species = SPECIES_ARMOREDMAWDAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacDawson[] = {
    {
        .iv = 30,
        .lvl = 40,
        .species = SPECIES_FIERYBLOWHOG,
    },
    {
        .iv = 30,
        .lvl = 40,
        .species = SPECIES_OATCHI,
    },
    {
        .iv = 30,
        .lvl = 40,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacAshton[] = {
    {
        .iv = 30,
        .lvl = 23,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 30,
        .lvl = 23,
        .species = SPECIES_ARMOREDMAWDAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdJovan[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_BOGSWALLOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdMiguel[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemCustomMoves sParty_SuperNerdAidan[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SONICBOOM, MOVE_SCREECH, MOVE_TACKLE, MOVE_CHARGE},
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS},
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SONICBOOM, MOVE_SCREECH, MOVE_TACKLE, MOVE_CHARGE},
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFYBLOWHOG,
        .moves = {MOVE_SONICBOOM, MOVE_SUPERSONIC, MOVE_THUNDERSHOCK, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdGlenn[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemCustomMoves sParty_SuperNerdLeslie[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_SMOG, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerd1[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFSTOOL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerd2[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerd3[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BOGSWALLOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdErik[] = {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ARISTOCRAB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdAvery[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PRICKLEPUFF,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_BULBMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdDerek[] = {
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_SCORCHCAKE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdZac[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerMarcos[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerFranklin[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerNob[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerWayne[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemCustomMoves sParty_HikerAlan[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_HARDEN, MOVE_ROCKTHROW, MOVE_BIND, MOVE_SCREECH},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerBrice[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
};

struct TrainerMonNoItemCustomMoves sParty_HikerClark[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_HARDEN, MOVE_ROCKTHROW, MOVE_BIND, MOVE_SCREECH},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerTrent[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemCustomMoves sParty_HikerDudley[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
};

struct TrainerMonNoItemCustomMoves sParty_HikerAllen[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerEric[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerLenny[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerOliver[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
    },
};

struct TrainerMonNoItemCustomMoves sParty_HikerLucas[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerJared[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_POISONGAS},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerMalik[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerErnest[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE, MOVE_POUND},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerAlex[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerLao[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Biker1[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_BikerHideo[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PUFFSTOOL,
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerRuben[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerBilly[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerNikolas[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerJaxon[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SNOWYBLOWHOG,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerWilliam[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SELFDESTRUCT, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerLukas[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerIsaac[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerGerald[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SNOWYBLOWHOG,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Burglar1[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Burglar2[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_BULBMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Burglar3[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarQuinn[] = {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_ARISTOCRAB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarRamon[] = {
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarDusty[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_BULBMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarArnie[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Burglar4[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarSimon[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_ARISTOCRAB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BurglarLewis[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_EngineerBaily[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUFFYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_EngineerBraxton[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUFFYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_EngineerBernie[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ANODEBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanDale[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanBarny[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanNed[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanChip[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanHank[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanElliot[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanRonald[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanClaude[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_PEARLYCLAMCLAMP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanWade[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PELLETPOSY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanNolan[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanAndrew[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_PELLETPOSY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleLuis[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleRichard[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleReece[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMatthew[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_WATERDUMPLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDouglas[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDavid[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleTony[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleAxle[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_PHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleBarry[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_PEARLYCLAMCLAMP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDean[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDarrin[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSpencer[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJack[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJerome[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleRoland[] = {
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallKoji[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallLuke[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallCamron[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallRaul[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SHAGGYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallIsaiah[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallZeek[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallJamal[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_BALDYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_BEADYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallCorey[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SHAGGYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallChase[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_PHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerHugo[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerJasper[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerDirk[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PUFFYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerDarian[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerStan[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WATERDUMPLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Gamer1[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_GamerRich[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyBridget[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyTamia[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyLori[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyLola[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_CRUMBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautySheila[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleTiffany[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNora[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PEARLYCLAMCLAMP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMelissa[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyGrace[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_FOOLIX,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyOlivia[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BULBORBLARVA,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyLauren[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAnya[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SCORNET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAlice[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleConnie[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleShirley[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PsychicJohan[] = {
    {
        .iv = 50,
        .lvl = 31,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 50,
        .lvl = 31,
        .species = SPECIES_ARMOREDMAWDAD,
    },
    {
        .iv = 50,
        .lvl = 31,
        .species = SPECIES_REDBUBBLIMP,
    },
    {
        .iv = 50,
        .lvl = 31,
        .species = SPECIES_LURINGSLURKER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PsychicTyron[] = {
    {
        .iv = 50,
        .lvl = 34,
        .species = SPECIES_REDBUBBLIMP,
    },
    {
        .iv = 50,
        .lvl = 34,
        .species = SPECIES_LURINGSLURKER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PsychicCameron[] = {
    {
        .iv = 50,
        .lvl = 33,
        .species = SPECIES_ARMOREDMAWDAD,
    },
    {
        .iv = 50,
        .lvl = 33,
        .species = SPECIES_ARMOREDMAWDAD,
    },
    {
        .iv = 50,
        .lvl = 33,
        .species = SPECIES_WADDLEPUS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PsychicPreston[] = {
    {
        .iv = 50,
        .lvl = 38,
        .species = SPECIES_WADDLEPUS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RockerRandall[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BOGSWALLOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RockerLuca[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerDalton[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_REDBUBBLIMP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerNelson[] = {
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_PROQUILLION,
    },
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 0,
        .lvl = 41,
        .species = SPECIES_LURINGSLURKER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerKirk[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerShawn[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PROQUILLION,
    },
};

struct TrainerMonNoItemCustomMoves sParty_JugglerGregory[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_REDBUBBLIMP,
        .moves = {MOVE_PSYCHIC, MOVE_ROLEPLAY, MOVE_DOUBLESLAP, MOVE_ENCORE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_JugglerEdward[] = {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SWIFT, MOVE_SPARK, MOVE_SELFDESTRUCT, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_REDBUBBLIMP,
        .moves = {MOVE_PSYCHIC, MOVE_ROLEPLAY, MOVE_REFLECT, MOVE_ENCORE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerKayden[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_PROQUILLION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerNate[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_LURINGSLURKER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerPhil[] = {
    {
        .iv = 40,
        .lvl = 34,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 40,
        .lvl = 34,
        .species = SPECIES_DWARFBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerEdgar[] = {
    {
        .iv = 40,
        .lvl = 33,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 40,
        .lvl = 33,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 40,
        .lvl = 33,
        .species = SPECIES_DWARFBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerJason[] = {
    {
        .iv = 40,
        .lvl = 43,
        .species = SPECIES_EMPERORBULBLAX,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerCole[] = {
    {
        .iv = 40,
        .lvl = 39,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 40,
        .lvl = 39,
        .species = SPECIES_TUSKEDBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerVincent[] = {
    {
        .iv = 40,
        .lvl = 44,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 40,
        .lvl = 44,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerJohn[] = {
    {
        .iv = 40,
        .lvl = 42,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 40,
        .lvl = 42,
        .species = SPECIES_SHAGGYLONGLEGS,
    },
    {
        .iv = 40,
        .lvl = 42,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 40,
        .lvl = 42,
        .species = SPECIES_TUSKEDBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperSebastian[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperPerry[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_GIANTBREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobert[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperDonald[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBenny[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperEdwin[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SNOWBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChester[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperWilton[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRamiro[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacob[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GIANTBREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRoger[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperReed[] = {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperKeith[] = {
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperCarter[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMitch[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBeck[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlon[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltKoichi[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltMike[] = {
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_BALDYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_BALDYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltHideki[] = {
    {
        .iv = 100,
        .lvl = 32,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 32,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltAaron[] = {
    {
        .iv = 100,
        .lvl = 36,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltHitoshi[] = {
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_BALDYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 31,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltAtsushi[] = {
    {
        .iv = 100,
        .lvl = 40,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 40,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltKiyo[] = {
    {
        .iv = 100,
        .lvl = 43,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltTakashi[] = {
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltDaisuke[] = {
    {
        .iv = 100,
        .lvl = 43,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 43,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 43,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabWolpole[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabBulborbLarva[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_BULBORBLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabFieryBlowlet[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_FIERYBLOWLET,
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlyWolpole[] = {
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_SNOWBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_WOLPOLE,
        .moves = {MOVE_TACKLE, MOVE_TAILWHIP, MOVE_NONE, MOVE_NONE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlyBulborbLarva[] = {
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_SNOWBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_BULBORBLARVA,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_NONE, MOVE_NONE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlyFieryBlowlet[] = {
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_SNOWBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 9,
        .species = SPECIES_FIERYBLOWLET,
        .moves = {MOVE_SCRATCH, MOVE_GROWL, MOVE_NONE, MOVE_NONE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanWolpole[] = {
    {
        .iv = 50,
        .lvl = 17,
        .species = SPECIES_DWARFFROSTYBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_CLICKINGSLURKER,
        .moves = {MOVE_TELEPORT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 15,
        .species = SPECIES_CRUMBUG,
        .moves = {MOVE_TACKLE, MOVE_TAILWHIP, MOVE_QUICKATTACK, MOVE_NONE},
    },
    {
        .iv = 100,
        .lvl = 18,
        .species = SPECIES_WOLPOLE,
        .moves = {MOVE_TACKLE, MOVE_TAILWHIP, MOVE_WITHDRAW, MOVE_WATERGUN},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanBulborbLarva[] = {
    {
        .iv = 50,
        .lvl = 17,
        .species = SPECIES_DWARFFROSTYBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_CLICKINGSLURKER,
        .moves = {MOVE_TELEPORT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 15,
        .species = SPECIES_CRUMBUG,
        .moves = {MOVE_TACKLE, MOVE_TAILWHIP, MOVE_QUICKATTACK, MOVE_NONE},
    },
    {
        .iv = 100,
        .lvl = 18,
        .species = SPECIES_BULBORBLARVA,
        .moves = {MOVE_SLEEPPOWDER, MOVE_POISONPOWDER, MOVE_VINEWHIP, MOVE_LEECHSEED},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanFieryBlowlet[] = {
    {
        .iv = 50,
        .lvl = 17,
        .species = SPECIES_DWARFFROSTYBULBORB,
        .moves = {MOVE_TACKLE, MOVE_SANDATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_CLICKINGSLURKER,
        .moves = {MOVE_TELEPORT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 50,
        .lvl = 15,
        .species = SPECIES_CRUMBUG,
        .moves = {MOVE_TACKLE, MOVE_TAILWHIP, MOVE_QUICKATTACK, MOVE_NONE},
    },
    {
        .iv = 100,
        .lvl = 18,
        .species = SPECIES_FIERYBLOWLET,
        .moves = {MOVE_METALCLAW, MOVE_EMBER, MOVE_GROWL, MOVE_SCRATCH},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistTed[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFSTOOL,
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistConnor[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_SELFDESTRUCT},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistJerry[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BOGSWALLOW,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ANODEBEETLE,
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistJose[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistRodney[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistBeau[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_ANODEBEETLE,
        .moves = {MOVE_SPARK, MOVE_THUNDERWAVE, MOVE_SONICBOOM, MOVE_SUPERSONIC},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFYBLOWHOG,
        .moves = {MOVE_SPARK, MOVE_THUNDERWAVE, MOVE_SONICBOOM, MOVE_SUPERSONIC},
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistTaylor[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ANODEBEETLE,
        .moves = {MOVE_THUNDERWAVE, MOVE_SONICBOOM, MOVE_SUPERSONIC, MOVE_THUNDERSHOCK},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFYBLOWHOG,
        .moves = {MOVE_THUNDERWAVE, MOVE_SONICBOOM, MOVE_SUPERSONIC, MOVE_THUNDERSHOCK},
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistJoshua[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistParker[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistEd[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_TACKLE, MOVE_SMOG},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ANODEBEETLE,
        .moves = {MOVE_SPARK, MOVE_THUNDERWAVE, MOVE_SONICBOOM, MOVE_SUPERSONIC},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistTravis[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistBraydon[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_ANODEBEETLE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_BOGSWALLOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ScientistIvan[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PUFFYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BossGiovanni[] = {
    {
        .iv = 250,
        .lvl = 25,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 250,
        .lvl = 24,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 250,
        .lvl = 29,
        .species = SPECIES_ADULTBULBMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BossGiovanni2[] = {
    {
        .iv = 250,
        .lvl = 37,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 250,
        .lvl = 35,
        .species = SPECIES_ADULTBULBMIN,
    },
    {
        .iv = 250,
        .lvl = 37,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 250,
        .lvl = 41,
        .species = SPECIES_FEMALESHEARGRUB,
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderGiovanni[] = {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_EARTHQUAKE},
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_BUGEYEDCRAWMAD,
        .moves = {MOVE_SLASH, MOVE_SANDTOMB, MOVE_MUDSLAP, MOVE_EARTHQUAKE},
    },
    {
        .iv = 0,
        .lvl = 44,
        .species = SPECIES_FEMALESHEARGRUB,
        .moves = {MOVE_BODYSLAM, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_EARTHQUAKE},
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_MALESHEARGRUB,
        .moves = {MOVE_THRASH, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_EARTHQUAKE},
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_EARTHQUAKE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt2[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt3[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt4[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt5[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt6[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt7[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt8[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt9[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt10[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE, MOVE_HARDEN},
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS, MOVE_NONE},
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS, MOVE_NONE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt11[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt12[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE, MOVE_HARDEN},
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS},
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt13[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_ARCTICCANNONLARVA,
        .moves = {MOVE_BITE, MOVE_ASTONISH, MOVE_SUPERSONIC, MOVE_LEECHLIFE},
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS, MOVE_NONE},
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_SLUDGE, MOVE_DISABLE, MOVE_HARDEN, MOVE_POUND},
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_ARCTICCANNONLARVA,
        .moves = {MOVE_BITE, MOVE_ASTONISH, MOVE_SUPERSONIC, MOVE_LEECHLIFE},
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BREADBUG,
        .moves = {MOVE_HYPERFANG, MOVE_QUICKATTACK, MOVE_TAILWHIP, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt14[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt15[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt16[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt17[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_DWARFBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt18[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt19[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt20[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt21[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt22[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt23[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt24[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt25[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PROQUILLION,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt26[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SUNQUISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt27[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SOUL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt28[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_DWARFBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt29[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_PROQUILLION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt30[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt31[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt32[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_BREADBUG,
        .moves = {MOVE_SCARYFACE, MOVE_HYPERFANG, MOVE_QUICKATTACK, MOVE_TAILWHIP},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_DWARFBULBEAR,
        .moves = {MOVE_GLARE, MOVE_BITE, MOVE_POISONSTING, MOVE_LEER},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_ARCTICCANNONBEETLE,
        .moves = {MOVE_WINGATTACK, MOVE_BITE, MOVE_ASTONISH, MOVE_SUPERSONIC},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt33[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SOUL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt34[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt35[] = {
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 26,
        .species = SPECIES_CRUMBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt36[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt37[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_MANATLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt38[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PROQUILLION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt39[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt40[] = {
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 25,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt41[] = {
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 32,
        .species = SPECIES_SCORCHCAKE,
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerSamuel[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_SLASH, MOVE_SWIFT, MOVE_SANDATTACK, MOVE_POISONSTING},
    },
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_SLASH, MOVE_SWIFT, MOVE_SANDATTACK, MOVE_POISONSTING},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_ROCKBLAST, MOVE_FURYATTACK, MOVE_SCARYFACE},
    },
    {
        .iv = 100,
        .lvl = 39,
        .species = SPECIES_MAMASHEARGRUB,
        .moves = {MOVE_FURYATTACK, MOVE_HORNATTACK, MOVE_POISONSTING, MOVE_DOUBLEKICK},
    },
    {
        .iv = 100,
        .lvl = 39,
        .species = SPECIES_MALESHEARGRUB,
        .moves = {MOVE_THRASH, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_FOCUSENERGY},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerGeorge[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_EGGBOMB, MOVE_CONFUSION, MOVE_STUNSPORE, MOVE_SLEEPPOWDER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_FURYSWIPES, MOVE_SWIFT, MOVE_POISONSTING, MOVE_SANDATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PEARLYCLAMCLAMP,
        .moves = {MOVE_SPIKECANNON, MOVE_SPIKES, MOVE_AURORABEAM, MOVE_SUPERSONIC},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_LIGHTSCREEN},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ADULTBULBMIN,
        .moves = {MOVE_FLAMEWHEEL, MOVE_ROAR, MOVE_BITE, MOVE_TAKEDOWN},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerColby[] = {
    {
        .iv = 100,
        .lvl = 41,
        .species = SPECIES_SNOWFLAKEFLUTTERTAIL,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUDSHOT, MOVE_BUBBLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_WATERDUMPLE,
        .moves = {MOVE_BODYSLAM, MOVE_DOUBLESLAP, MOVE_WATERGUN, MOVE_HYPNOSIS},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PHOSBAT,
        .moves = {MOVE_BARRIER, MOVE_WRAP, MOVE_BUBBLEBEAM, MOVE_ACID},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SPUTTLEFISH,
        .moves = {MOVE_WATERGUN, MOVE_SMOKESCREEN, MOVE_TWISTER, MOVE_LEER},
    },
    {
        .iv = 100,
        .lvl = 43,
        .species = SPECIES_MASTERHOP,
        .moves = {MOVE_WATERGUN, MOVE_BITE, MOVE_RAPIDSPIN, MOVE_RAINDANCE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerPaul[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARMOREDMAWDAD,
        .moves = {MOVE_HEADBUTT, MOVE_CONFUSION, MOVE_WATERGUN, MOVE_DISABLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
        .moves = {MOVE_AURORABEAM, MOVE_CLAMP, MOVE_SUPERSONIC, MOVE_LEER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SNOWFLAKEFLUTTERTAIL,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUDSHOT, MOVE_BUBBLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_GATTLINGGROINK,
        .moves = {MOVE_BUBBLEBEAM, MOVE_SWIFT, MOVE_RECOVER, MOVE_RAPIDSPIN},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_RAGINGLONGLEGS,
        .moves = {MOVE_CONFUSION, MOVE_SCRATCH, MOVE_SCREECH, MOVE_DISABLE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerRolando[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_BREADBUG,
        .moves = {MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_SCARYFACE, MOVE_QUICKATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_BULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_SLEEPPOWDER, MOVE_SWEETSCENT, MOVE_SYNTHESIS},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_YELLOWWOLLYHOP,
        .moves = {MOVE_WATERGUN, MOVE_BITE, MOVE_RAPIDSPIN, MOVE_TAILWHIP},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_FIERYBLOWHOG,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLASH, MOVE_SMOKESCREEN, MOVE_SCARYFACE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_TITANBLOWHOG,
        .moves = {MOVE_FLAMETHROWER, MOVE_WINGATTACK, MOVE_SMOKESCREEN, MOVE_SCARYFACE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerGilbert[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DWARFFROSTYBULBORB,
        .moves = {MOVE_WINGATTACK, MOVE_FEATHERDANCE, MOVE_WHIRLWIND, MOVE_QUICKATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PILEATEDSNAGRET,
        .moves = {MOVE_DRILLPECK, MOVE_MIRRORMOVE, MOVE_PURSUIT, MOVE_LEER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_PAYDAY, MOVE_FEINTATTACK, MOVE_SCREECH, MOVE_BITE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MOCKIWI,
        .moves = {MOVE_SLAM, MOVE_DISABLE, MOVE_WRAP, MOVE_SUPERSONIC},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_TUSKEDBLOWHOG,
        .moves = {MOVE_HORNATTACK, MOVE_SCARYFACE, MOVE_SWAGGER, MOVE_TAILWHIP},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerOwen[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MAMASHEARGRUB,
        .moves = {MOVE_SCRATCH, MOVE_POISONSTING, MOVE_DOUBLEKICK, MOVE_BITE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PILEATEDSNAGRET,
        .moves = {MOVE_HORNATTACK, MOVE_POISONSTING, MOVE_DOUBLEKICK, MOVE_LEER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_BREADBUG,
        .moves = {MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_SCARYFACE, MOVE_QUICKATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_FURYSWIPES, MOVE_SWIFT, MOVE_SLASH, MOVE_POISONSTING},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_STOMP, MOVE_TAILWHIP},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerBerke[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_GREATERSPOTTEDJELLYFLOAT,
        .moves = {MOVE_TAKEDOWN, MOVE_AURORABEAM, MOVE_ICYWIND, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_ROCKBLAST, MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SNOWFLAKEFLUTTERTAIL,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUDSHOT, MOVE_BUBBLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_SLAM, MOVE_SANDSTORM, MOVE_DRAGONBREATH, MOVE_ROCKTHROW},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PEARLYCLAMCLAMP,
        .moves = {MOVE_SPIKECANNON, MOVE_AURORABEAM, MOVE_SUPERSONIC, MOVE_PROTECT},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerYuji[] = {
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_DOWNYSNAGRET,
        .moves = {MOVE_SLASH, MOVE_SWIFT, MOVE_SANDATTACK, MOVE_POISONSTING},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_ROCKBLAST, MOVE_MAGNITUDE, MOVE_MUDSPORT, MOVE_DEFENSECURL},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_DRAGONBREATH, MOVE_SANDSTORM, MOVE_ROCKTHROW, MOVE_BIND},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_ROCKBLAST, MOVE_MAGNITUDE, MOVE_ROLLOUT, MOVE_DEFENSECURL},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_BONEMERANG, MOVE_HEADBUTT, MOVE_LEER, MOVE_GROWL},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerWarren[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_BONEMERANG, MOVE_HEADBUTT, MOVE_LEER, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_BONEMERANG, MOVE_HEADBUTT, MOVE_LEER, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_ROCKBLAST, MOVE_FURYATTACK, MOVE_SCARYFACE},
    },
    {
        .iv = 100,
        .lvl = 39,
        .species = SPECIES_PILEATEDSNAGRET,
        .moves = {MOVE_FURYSWIPES, MOVE_BITE, MOVE_POISONSTING, MOVE_DOUBLEKICK},
    },
    {
        .iv = 100,
        .lvl = 39,
        .species = SPECIES_FEMALESHEARGRUB,
        .moves = {MOVE_BODYSLAM, MOVE_BITE, MOVE_POISONSTING, MOVE_DOUBLEKICK},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerMary[] = {
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_ARACHNODE,
        .moves = {MOVE_WRAP, MOVE_STUNSPORE, MOVE_POISONPOWDER, MOVE_GROWTH},
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_SKITTERLEAF,
        .moves = {MOVE_POISONPOWDER, MOVE_STUNSPORE, MOVE_ABSORB, MOVE_SWEETSCENT},
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_VINEWHIP, MOVE_STUNSPORE, MOVE_POISONPOWDER, MOVE_GROWTH},
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_ABSORB, MOVE_STUNSPORE, MOVE_POISONPOWDER, MOVE_SWEETSCENT},
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_BULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_SLEEPPOWDER, MOVE_VINEWHIP, MOVE_LEECHSEED},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerCaroline[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARACHNODE,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_STUNSPORE, MOVE_POISONPOWDER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SLEEPPOWDER, MOVE_POISONPOWDER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MOLDYSLOOCH,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_STUNSPORE, MOVE_SLEEPPOWDER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARMOREDCANNONBEETLE,
        .moves = {MOVE_GROWTH, MOVE_SLASH, MOVE_LEECHLIFE, MOVE_STUNSPORE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_HORNEDCANNONBEETLE,
        .moves = {MOVE_SPORE, MOVE_SLASH, MOVE_LEECHLIFE, MOVE_POISONPOWDER},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerAlexa[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SHEARWIG,
        .moves = {MOVE_LIGHTSCREEN, MOVE_COSMICPOWER, MOVE_DOUBLESLAP, MOVE_ENCORE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_GOOLIX,
        .moves = {MOVE_SING, MOVE_BODYSLAM, MOVE_ROLLOUT, MOVE_DISABLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_PAYDAY, MOVE_FEINTATTACK, MOVE_BITE, MOVE_SCREECH},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_TOADYBLOYSTER,
        .moves = {MOVE_SHEERCOLD, MOVE_TAKEDOWN, MOVE_REST, MOVE_AURORABEAM},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DANDELFLY,
        .moves = {MOVE_SING, MOVE_EGGBOMB, MOVE_SOFTBOILED, MOVE_MINIMIZE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerShannon[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DIRIGIBUG,
        .moves = {MOVE_PINMISSILE, MOVE_TWINEEDLE, MOVE_AGILITY, MOVE_PURSUIT},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_GLINTBEETLE,
        .moves = {MOVE_SAFEGUARD, MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_HORNEDCANNONBEETLE,
        .moves = {MOVE_SPORE, MOVE_LEECHLIFE, MOVE_SLASH, MOVE_GROWTH},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
        .moves = {MOVE_PSYBEAM, MOVE_STUNSPORE, MOVE_LEECHLIFE, MOVE_DISABLE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_STARTLESPORE,
        .moves = {MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC, MOVE_LEECHLIFE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerNaomi[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_FURYSWIPES, MOVE_SCREECH, MOVE_FEINTATTACK, MOVE_PAYDAY},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PRICKLEPUFF,
        .moves = {MOVE_AGILITY, MOVE_TAKEDOWN, MOVE_FIRESPIN, MOVE_STOMP},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_FURYATTACK, MOVE_FIRESPIN, MOVE_STOMP, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARISTOCRABOFFSPRING,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSERAY, MOVE_QUICKATTACK, MOVE_IMPRISON},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARISTOCRAB,
        .moves = {MOVE_SAFEGUARD, MOVE_WILLOWISP, MOVE_CONFUSERAY, MOVE_FIRESPIN},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerBrooke[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MUGGONFLY,
        .moves = {MOVE_SLAM, MOVE_BIND, MOVE_MEGADRAIN, MOVE_INGRAIN},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_ACID, MOVE_MOONLIGHT, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_MEGADRAIN, MOVE_ACID, MOVE_STUNSPORE, MOVE_AROMATHERAPY},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_BULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_SWEETSCENT, MOVE_GROWL, MOVE_LEECHSEED},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_JUMBOBULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_GROWTH, MOVE_SLEEPPOWDER, MOVE_POISONPOWDER},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerAustina[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_STOMP},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_PILEATEDSNAGRET,
        .moves = {MOVE_DOUBLEKICK, MOVE_FURYSWIPES, MOVE_BITE, MOVE_FLATTER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_FEMALESHEARGRUB,
        .moves = {MOVE_BODYSLAM, MOVE_DOUBLEKICK, MOVE_BITE, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MAMASHEARGRUB,
        .moves = {MOVE_HORNATTACK, MOVE_POISONSTING, MOVE_FOCUSENERGY, MOVE_LEER},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_MALESHEARGRUB,
        .moves = {MOVE_THRASH, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_PECK},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerJulie[] = {
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_FURYSWIPES, MOVE_BITE, MOVE_SCREECH, MOVE_FEINTATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_ARISTOCRAB,
        .moves = {MOVE_FLAMETHROWER, MOVE_WILLOWISP, MOVE_CONFUSERAY, MOVE_GRUDGE},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_FURYATTACK, MOVE_FIRESPIN, MOVE_TAKEDOWN, MOVE_AGILITY},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_SPOTTYBULBEAR,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDERWAVE, MOVE_DOUBLETEAM, MOVE_QUICKATTACK},
    },
    {
        .iv = 100,
        .lvl = 42,
        .species = SPECIES_HONEYWISP,
        .moves = {MOVE_THUNDER, MOVE_THUNDERWAVE, MOVE_SLAM, MOVE_DOUBLETEAM},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourLorelei[] = {
    {
        .iv = 250,
        .lvl = 52,
        .species = SPECIES_TOADYBLOYSTER,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_HAIL, MOVE_SAFEGUARD},
    },
    {
        .iv = 250,
        .lvl = 51,
        .species = SPECIES_PEARLYCLAMCLAMP,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIKES, MOVE_PROTECT, MOVE_HAIL, MOVE_DIVE},
    },
    {
        .iv = 250,
        .lvl = 52,
        .species = SPECIES_WADDLEPUS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_ARMOREDMAWDAD,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEPUNCH, MOVE_DOUBLESLAP, MOVE_LOVELYKISS, MOVE_ATTRACT},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_OATCHI,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_CONFUSERAY, MOVE_ICEBEAM, MOVE_SURF, MOVE_BODYSLAM},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourBruno[] = {
    {
        .iv = 250,
        .lvl = 51,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKTOMB, MOVE_IRONTAIL, MOVE_ROAR},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SKYUPPERCUT, MOVE_MACHPUNCH, MOVE_ROCKTOMB, MOVE_COUNTER},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAKICK, MOVE_FORESIGHT, MOVE_BRICKBREAK, MOVE_FACADE},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DOUBLEEDGE, MOVE_EARTHQUAKE, MOVE_IRONTAIL, MOVE_SANDTOMB},
    },
    {
        .iv = 250,
        .lvl = 56,
        .species = SPECIES_BEADYLONGLEGS,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_CROSSCHOP, MOVE_BULKUP, MOVE_SCARYFACE, MOVE_ROCKTOMB},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourAgatha[] = {
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_ICEBLOWNDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWPUNCH, MOVE_CONFUSERAY, MOVE_TOXIC, MOVE_DOUBLETEAM},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_ARCTICCANNONBEETLE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSERAY, MOVE_POISONFANG, MOVE_AIRCUTTER, MOVE_BITE},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_ICEBLOWNDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPNOSIS, MOVE_DREAMEATER, MOVE_CURSE, MOVE_MEANLOOK},
    },
    {
        .iv = 250,
        .lvl = 56,
        .species = SPECIES_DWARFBULBEAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SCREECH, MOVE_IRONTAIL, MOVE_BITE},
    },
    {
        .iv = 250,
        .lvl = 58,
        .species = SPECIES_ICEBLOWNDWEEVIL,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SHADOWBALL, MOVE_SLUDGEBOMB, MOVE_HYPNOSIS, MOVE_NIGHTMARE},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourLance[] = {
    {
        .iv = 250,
        .lvl = 56,
        .species = SPECIES_MASTERONION,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_DRAGONRAGE, MOVE_TWISTER, MOVE_BITE},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_GLOWSEED,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_SAFEGUARD, MOVE_DRAGONRAGE, MOVE_OUTRAGE},
    },
    {
        .iv = 250,
        .lvl = 54,
        .species = SPECIES_GLOWSEED,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_SAFEGUARD, MOVE_THUNDERWAVE, MOVE_OUTRAGE},
    },
    {
        .iv = 250,
        .lvl = 58,
        .species = SPECIES_ROCKPIKMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_ANCIENTPOWER, MOVE_WINGATTACK, MOVE_SCARYFACE},
    },
    {
        .iv = 250,
        .lvl = 60,
        .species = SPECIES_GLOWPIKMIN,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HYPERBEAM, MOVE_SAFEGUARD, MOVE_OUTRAGE, MOVE_WINGATTACK},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderBrock[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_TACKLE, MOVE_DEFENSECURL, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_TACKLE, MOVE_BIND, MOVE_ROCKTOMB, MOVE_NONE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderMisty[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SUNQUISH,
        .moves = {MOVE_TACKLE, MOVE_HARDEN, MOVE_RECOVER, MOVE_WATERPULSE},
    },
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_GATTLINGGROINK,
        .moves = {MOVE_SWIFT, MOVE_RECOVER, MOVE_RAPIDSPIN, MOVE_WATERPULSE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderLtSurge[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SONICBOOM, MOVE_TACKLE, MOVE_SCREECH, MOVE_SHOCKWAVE},
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SPOTTYBULBEAR,
        .moves = {MOVE_QUICKATTACK, MOVE_THUNDERWAVE, MOVE_DOUBLETEAM, MOVE_SHOCKWAVE},
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_HONEYWISP,
        .moves = {MOVE_QUICKATTACK, MOVE_THUNDERWAVE, MOVE_DOUBLETEAM, MOVE_SHOCKWAVE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderErika[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MOLDYSLOOCH,
        .moves = {MOVE_STUNSPORE, MOVE_ACID, MOVE_POISONPOWDER, MOVE_GIGADRAIN},
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_MUGGONFLY,
        .moves = {MOVE_POISONPOWDER, MOVE_CONSTRICT, MOVE_INGRAIN, MOVE_GIGADRAIN},
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_SLEEPPOWDER, MOVE_ACID, MOVE_STUNSPORE, MOVE_GIGADRAIN},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderKoga[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SELFDESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_TOXIC},
    },
    {
        .iv = 0,
        .lvl = 39,
        .species = SPECIES_SNOWYBLOWHOG,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_ACIDARMOR, MOVE_TOXIC},
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SELFDESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_TOXIC},
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_TOXIC},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderBlaine[] = {
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_BULBMIN,
        .moves = {MOVE_BITE, MOVE_ROAR, MOVE_TAKEDOWN, MOVE_FIREBLAST},
    },
    {
        .iv = 0,
        .lvl = 40,
        .species = SPECIES_PRICKLEPUFF,
        .moves = {MOVE_STOMP, MOVE_BOUNCE, MOVE_FIRESPIN, MOVE_FIREBLAST},
    },
    {
        .iv = 0,
        .lvl = 42,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_STOMP, MOVE_BOUNCE, MOVE_FIRESPIN, MOVE_FIREBLAST},
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_ADULTBULBMIN,
        .moves = {MOVE_BITE, MOVE_ROAR, MOVE_TAKEDOWN, MOVE_FIREBLAST},
    },
};

struct TrainerMonNoItemCustomMoves sParty_LeaderSabrina[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_LURINGSLURKER,
        .moves = {MOVE_PSYBEAM, MOVE_REFLECT, MOVE_FUTURESIGHT, MOVE_CALMMIND},
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_REDBUBBLIMP,
        .moves = {MOVE_BARRIER, MOVE_PSYBEAM, MOVE_BATONPASS, MOVE_CALMMIND},
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_STARTLESPORE,
        .moves = {MOVE_PSYBEAM, MOVE_GUST, MOVE_LEECHLIFE, MOVE_SUPERSONIC},
    },
    {
        .iv = 0,
        .lvl = 43,
        .species = SPECIES_VOLATILEDWEEVIL,
        .moves = {MOVE_PSYCHIC, MOVE_RECOVER, MOVE_FUTURESIGHT, MOVE_CALMMIND},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanThomas[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_BULBMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanArthur[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanTucker[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanNorton[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanWalter[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSsAnneWolpole[] = {
    {
        .iv = 50,
        .lvl = 19,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 50,
        .lvl = 18,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSsAnneBulborbLarva[] = {
    {
        .iv = 50,
        .lvl = 19,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 50,
        .lvl = 18,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_BULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSsAnneFieryBlowlet[] = {
    {
        .iv = 50,
        .lvl = 19,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 50,
        .lvl = 16,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 50,
        .lvl = 18,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalPokemonTowerWolpole[] = {
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 23,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_WOLLYHOP,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalPokemonTowerBulborbLarva[] = {
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 23,
        .species = SPECIES_MASTERONION,
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_BULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalPokemonTowerFieryBlowlet[] = {
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 23,
        .species = SPECIES_WOLLYHOP,
    },
    {
        .iv = 100,
        .lvl = 22,
        .species = SPECIES_MASTERONION,
    },
    {
        .iv = 100,
        .lvl = 20,
        .species = SPECIES_LURINGSLURKER,
    },
    {
        .iv = 100,
        .lvl = 25,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSilphWolpole[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_WOLLYHOP,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .iv = 150,
        .lvl = 40,
        .species = SPECIES_MASTERHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSilphBulborbLarva[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_MASTERONION,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .iv = 150,
        .lvl = 40,
        .species = SPECIES_JUMBOBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RivalSilphFieryBlowlet[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_WOLLYHOP,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_MASTERONION,
    },
    {
        .iv = 100,
        .lvl = 35,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .iv = 150,
        .lvl = 40,
        .species = SPECIES_TITANBLOWHOG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22LateWolpole[] = {
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_FROSTYBULBORB,
        .moves = {MOVE_FEATHERDANCE, MOVE_WINGATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_FURYATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_BULBMIN,
        .moves = {MOVE_FLAMEWHEEL, MOVE_TAKEDOWN, MOVE_LEER, MOVE_AGILITY},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_WOLLYHOP,
        .moves = {MOVE_SOLARBEAM, MOVE_SLEEPPOWDER, MOVE_POISONPOWDER, MOVE_STUNSPORE},
    },
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_VOLATILEDWEEVIL,
        .moves = {MOVE_PSYCHIC, MOVE_CALMMIND, MOVE_FUTURESIGHT, MOVE_DISABLE},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_MASTERHOP,
        .moves = {MOVE_WATERGUN, MOVE_RAINDANCE, MOVE_BITE, MOVE_RAPIDSPIN},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22LateBulborbLarva[] = {
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_FROSTYBULBORB,
        .moves = {MOVE_FEATHERDANCE, MOVE_WINGATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_FURYATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_MASTERONION,
        .moves = {MOVE_HYDROPUMP, MOVE_TWISTER, MOVE_LEER, MOVE_RAINDANCE},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_BULBMIN,
        .moves = {MOVE_FLAMEWHEEL, MOVE_TAKEDOWN, MOVE_LEER, MOVE_AGILITY},
    },
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_VOLATILEDWEEVIL,
        .moves = {MOVE_PSYCHIC, MOVE_CALMMIND, MOVE_FUTURESIGHT, MOVE_DISABLE},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_JUMBOBULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_SWEETSCENT, MOVE_GROWTH, MOVE_SYNTHESIS},
    },
};

struct TrainerMonNoItemCustomMoves sParty_RivalRoute22LateFieryBlowlet[] = {
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_FROSTYBULBORB,
        .moves = {MOVE_FEATHERDANCE, MOVE_WINGATTACK, MOVE_GUST, MOVE_QUICKATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_EMPERORBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_FURYATTACK},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_WOLLYHOP,
        .moves = {MOVE_SOLARBEAM, MOVE_SLEEPPOWDER, MOVE_POISONPOWDER, MOVE_STUNSPORE},
    },
    {
        .iv = 150,
        .lvl = 45,
        .species = SPECIES_MASTERONION,
        .moves = {MOVE_HYDROPUMP, MOVE_TWISTER, MOVE_LEER, MOVE_RAINDANCE},
    },
    {
        .iv = 150,
        .lvl = 47,
        .species = SPECIES_VOLATILEDWEEVIL,
        .moves = {MOVE_PSYCHIC, MOVE_CALMMIND, MOVE_FUTURESIGHT, MOVE_DISABLE},
    },
    {
        .iv = 250,
        .lvl = 53,
        .species = SPECIES_TITANBLOWHOG,
        .moves = {MOVE_FLAMETHROWER, MOVE_WINGATTACK, MOVE_SLASH, MOVE_SCARYFACE},
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionFirstWolpole[] = {
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_FROSTYBULBORB,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AERIALACE, MOVE_FEATHERDANCE, MOVE_SANDATTACK, MOVE_WHIRLWIND},
    },
    {
        .iv = 255,
        .lvl = 57,
        .species = SPECIES_VOLATILEDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_SOVREIGNBULBLAX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_EARTHQUAKE, MOVE_ROCKTOMB, MOVE_SCARYFACE},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_ADULTBULBMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE},
    },
    {
        .iv = 255,
        .lvl = 61,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_LIGHTSCREEN},
    },
    {
        .iv = 255,
        .lvl = 63,
        .species = SPECIES_MASTERHOP,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HYDROPUMP, MOVE_RAINDANCE, MOVE_SKULLBASH, MOVE_BITE},
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionFirstBulborbLarva[] = {
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_FROSTYBULBORB,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AERIALACE, MOVE_FEATHERDANCE, MOVE_SANDATTACK, MOVE_WHIRLWIND},
    },
    {
        .iv = 255,
        .lvl = 57,
        .species = SPECIES_VOLATILEDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_SOVREIGNBULBLAX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_EARTHQUAKE, MOVE_ROCKTOMB, MOVE_SCARYFACE},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_MASTERONION,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRAGONRAGE, MOVE_BITE, MOVE_THRASH},
    },
    {
        .iv = 255,
        .lvl = 61,
        .species = SPECIES_ADULTBULBMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE},
    },
    {
        .iv = 255,
        .lvl = 63,
        .species = SPECIES_JUMBOBULBORB,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SOLARBEAM, MOVE_SYNTHESIS, MOVE_SUNNYDAY, MOVE_GROWTH},
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionFirstFieryBlowlet[] = {
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_FROSTYBULBORB,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AERIALACE, MOVE_FEATHERDANCE, MOVE_SANDATTACK, MOVE_WHIRLWIND},
    },
    {
        .iv = 255,
        .lvl = 57,
        .species = SPECIES_VOLATILEDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_SOVREIGNBULBLAX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_EARTHQUAKE, MOVE_ROCKTOMB, MOVE_SCARYFACE},
    },
    {
        .iv = 255,
        .lvl = 59,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_LIGHTSCREEN},
    },
    {
        .iv = 255,
        .lvl = 61,
        .species = SPECIES_MASTERONION,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRAGONRAGE, MOVE_BITE, MOVE_THRASH},
    },
    {
        .iv = 255,
        .lvl = 63,
        .species = SPECIES_TITANBLOWHOG,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FIREBLAST, MOVE_AERIALACE, MOVE_SLASH, MOVE_FIRESPIN},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerPatricia[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerCarly[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerHope[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerPaula[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerLaurel[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerJody[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerTammy[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerRuth[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerKarina[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerJanae[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerAngelica[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerEmilia[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerJennifer[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler1[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler2[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler3[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler4[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler5[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler6[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler7[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Channeler8[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_WHISKERPILLAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerAmanda[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerStacy[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_ChannelerTasha[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_WHISKERPILLAR,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_ICEBLOWNDWEEVIL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerJeremy[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlma[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerSusie[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerValerie[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_SCORNET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerGwen[] = {
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 27,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerVirgil[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperFlint[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissy[] = {
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 31,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerIrene[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_GREATERSPOTTEDJELLYFLOAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerDana[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_SNOWBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAriana[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_ARACHNODE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerLeah[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperJustin[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MAMASHEARGRUB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerYazmin[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_MUGGONFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerKindra[] = {
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SKITTERLEAF,
    },
    {
        .iv = 0,
        .lvl = 28,
        .species = SPECIES_SKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerBecky[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerCelia[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanBrooks[] = {
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanLamar[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsEliAnne[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_GOOLIX,
    },
};

struct TrainerMonNoItemCustomMoves sParty_CoolCoupleRayTyra[] = {
    {
        .iv = 100,
        .lvl = 45,
        .species = SPECIES_FEMALESHEARGRUB,
        .moves = {MOVE_SUPERPOWER, MOVE_BODYSLAM, MOVE_DOUBLEKICK, MOVE_POISONSTING},
    },
    {
        .iv = 100,
        .lvl = 45,
        .species = SPECIES_MALESHEARGRUB,
        .moves = {MOVE_MEGAHORN, MOVE_THRASH, MOVE_DOUBLEKICK, MOVE_POISONSTING},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJes[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsKiriJan[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_FIERYBLOWLET,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinRonMya[] = {
    {
        .iv = 50,
        .lvl = 29,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 29,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleLeaJed[] = {
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_SCORCHCAKE,
    },
    {
        .iv = 0,
        .lvl = 29,
        .species = SPECIES_ARISTOCRAB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLiaLuc[] = {
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 30,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIan[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcher3[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BugCatcher4[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BugCatcher5[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BugCatcher6[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BugCatcher7[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_BugCatcher8[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterBen3[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterBen4[] = {
    {
        .iv = 120,
        .lvl = 48,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 120,
        .lvl = 48,
        .species = SPECIES_DWARFBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterChad2[] = {
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassReli2[] = {
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassReli3[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmy2[] = {
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmy3[] = {
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmy4[] = {
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterChad3[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassJanice2[] = {
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 20,
        .lvl = 20,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassJanice3[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterChad4[] = {
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_DWARFBULBEAR,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerFranklin2[] = {
    {
        .iv = 40,
        .lvl = 25,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 40,
        .lvl = 25,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnProfProfOak[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PlayerBrendan[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PlayerMay[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PlayerRed[] = {DUMMY_TRAINER_MON};
struct TrainerMonNoItemDefaultMoves sParty_PlayerLeaf[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt42[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_FIERYBULBLAX,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_FIERYBULBLAX,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicJaclyn[] = {
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
        .moves = {MOVE_NIGHTSHADE, MOVE_CONFUSERAY, MOVE_FUTURESIGHT, MOVE_WISH},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_WADDLEPUS,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .iv = 100,
        .lvl = 49,
        .species = SPECIES_LURINGSLURKER,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlSharon[] = {
    {
        .iv = 50,
        .lvl = 37,
        .species = SPECIES_BALDYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 37,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TuberAmira[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SCORNET,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SCORNET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAlize[] = {
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_STARNACLE,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerNicolas[] = {
    {
        .iv = 100,
        .lvl = 51,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SWEETSCENT, MOVE_WRAP},
    },
    {
        .iv = 100,
        .lvl = 51,
        .species = SPECIES_MOLDYSLOOCH,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerMadeline[] = {
    {
        .iv = 100,
        .lvl = 51,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_PETALDANCE, MOVE_ACID, MOVE_SWEETSCENT, MOVE_POISONPOWDER},
    },
    {
        .iv = 100,
        .lvl = 51,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUNSPORE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_AromaLadyNikki[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacStanly[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonItemDefaultMoves sParty_LadyJacki[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_GRABBIT,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_COPPELLER,
        .heldItem = ITEM_STARDUST,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PainterDaisy[] = {
    {
        .iv = 50,
        .lvl = 50,
        .species = SPECIES_DEMO77,
        .moves = {MOVE_DYNAMICPUNCH, MOVE_DIZZYPUNCH, MOVE_FOCUSPUNCH, MOVE_MEGAPUNCH},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerGoon[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_TACKLE},
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_ACIDARMOR, MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerGoon2[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_TACKLE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerGoon3[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_Biker2[] = {DUMMY_TRAINER_MON};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherAnthony[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_FLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherCharlie[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_DOODLEBUG,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_FLINTBEETLE,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_DOODLEBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsEliAnne2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_GOOLIX,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterJohnson[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_BikerRicardo[] = {
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS},
    },
    {
        .iv = 0,
        .lvl = 22,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE, MOVE_POISONGAS},
    },
    {
        .iv = 0,
        .lvl = 23,
        .species = SPECIES_MOLDYDWARFBULBORB,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE, MOVE_DISABLE, MOVE_POUND},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerJaren[] = {
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 24,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt43[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SOUL,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SCORCHCAKE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt44[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DANDELFLY,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt45[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_ARCTICCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt46[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ARCTICCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt47[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_MANATLEGS,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt48[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PROQUILLION,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PROQUILLION,
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketAdmin[] = {
    {
        .iv = 150,
        .lvl = 52,
        .species = SPECIES_SNOWYBLOWHOG,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SCREECH, MOVE_MINIMIZE, MOVE_ROCKTOMB},
    },
    {
        .iv = 150,
        .lvl = 53,
        .species = SPECIES_DWARFBULBEAR,
        .moves = {MOVE_SLUDGEBOMB, MOVE_BITE, MOVE_EARTHQUAKE, MOVE_IRONTAIL},
    },
    {
        .iv = 150,
        .lvl = 54,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_SLUDGEBOMB, MOVE_GIGADRAIN, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketAdmin2[] = {
    {
        .iv = 200,
        .lvl = 53,
        .species = SPECIES_ARCTICCANNONBEETLE,
        .moves = {MOVE_CONFUSERAY, MOVE_SLUDGEBOMB, MOVE_AIRCUTTER, MOVE_SHADOWBALL},
    },
    {
        .iv = 200,
        .lvl = 54,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_SLUDGEBOMB, MOVE_THUNDERBOLT, MOVE_EXPLOSION, MOVE_SHADOWBALL},
    },
    {
        .iv = 200,
        .lvl = 55,
        .species = SPECIES_REDPIKMIN,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_IRONTAIL, MOVE_SHADOWBALL},
    },
};

struct TrainerMonNoItemCustomMoves sParty_ScientistGideon[] = {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SWIFT, MOVE_SCREECH, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_PUFFYBLOWHOG,
        .moves = {MOVE_SCREECH, MOVE_SWIFT, MOVE_SPARK, MOVE_THUNDERWAVE},
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_ANODEBEETLE,
        .moves = {MOVE_TRIATTACK, MOVE_SPARK, MOVE_THUNDERWAVE, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_PIKUTABE,
        .moves = {MOVE_TRIATTACK, MOVE_CONVERSION, MOVE_RECOVER, MOVE_PSYBEAM},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAmara[] = {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_GREATERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_GREATERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_TOADYBLOYSTER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMaria[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAbigail[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BEADYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BEADYLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleFinn[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleGarrett[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BLIZZARDINGBLOWHOG,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_PEARLYCLAMCLAMP,
    },
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanTommy[] = {
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 33,
        .species = SPECIES_WOLPOLE,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlTanya[] = {
    {
        .iv = 50,
        .lvl = 38,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 38,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltShea[] = {
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltHugh[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_MANATLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperBryce[] = {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerClaire[] = {
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 35,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinMikKia[] = {
    {
        .iv = 50,
        .lvl = 39,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 39,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_AromaLadyViolet[] = {
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BULBORBLARVA,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BULBORB,
    },
    {
        .iv = 0,
        .lvl = 36,
        .species = SPECIES_BULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TuberAlexis[] = {
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_SUNQUISH,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
    {
        .iv = 0,
        .lvl = 34,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsJoyMeg[] = {
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 0,
        .lvl = 37,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleTisha[] = {
    {
        .iv = 0,
        .lvl = 38,
        .species = SPECIES_SNOWFLAKEFLUTTERTAIL,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PainterCelina[] = {
    {
        .iv = 50,
        .lvl = 50,
        .species = SPECIES_DEMO77,
        .moves = {MOVE_FLY, MOVE_DIG, MOVE_DIVE, MOVE_BOUNCE},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PainterRayna[] = {
    {
        .iv = 50,
        .lvl = 50,
        .species = SPECIES_DEMO77,
        .moves = {MOVE_CROSSCHOP, MOVE_MEGAHORN, MOVE_DOUBLEEDGE, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonItemDefaultMoves sParty_LadyGillian[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_ELECTRICCOTTONADE,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ELECTRICCOTTONADE,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
        .heldItem = ITEM_NUGGET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterDestin[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleToby[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_TOXSTOOL,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PHOSBAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt49[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt50[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PUFFMIN,
        .moves = {MOVE_MEMENTO, MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE},
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PUFFSTOOL,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt51[] = {
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_GATTLINGGROINK,
    },
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMilo[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_SNOWBULBORB,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChaz[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperHarold[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanTylor[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PRICKLEPUFF,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PRICKLEPUFF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMymo[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_SNOWFLAKEFLUTTERTAIL,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNicole[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_STARNACLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SisAndBroAvaGeb[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_AromaLadyRose[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_MASTERONION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSamir[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_MASTERONION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleDenise[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_HERMITCRAWMAD,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_BUGEYEDCRAWMAD,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsMiuMia[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerEarl[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacFoster[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLarry[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerDaryl[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SKITTERLEAF,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHector[] = {
    {
        .iv = 30,
        .lvl = 49,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 30,
        .lvl = 49,
        .species = SPECIES_ADULTBULBMIN,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicDario[] = {
    {
        .iv = 100,
        .lvl = 52,
        .species = SPECIES_BURROWNIT,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODORSLEUTH, MOVE_AGILITY},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicRodette[] = {
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
        .moves = {MOVE_NIGHTSHADE, MOVE_CONFUSERAY, MOVE_WISH, MOVE_FUTURESIGHT},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_SUNQUISH,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
    {
        .iv = 100,
        .lvl = 50,
        .species = SPECIES_PROQUILLION,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_AromaLadyMiah[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleEveJon[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonNoItemCustomMoves sParty_JugglerMason[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_SPECTRALID,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPIDSPIN, MOVE_TAKEDOWN},
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_BOGSWALLOW,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_SPECTRALID,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPIDSPIN, MOVE_EXPLOSION},
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlCyndy[] = {
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_BEEB,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 48,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlJocelyn[] = {
    {
        .iv = 50,
        .lvl = 38,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 50,
        .lvl = 38,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerEvan[] = {
    {
        .iv = 40,
        .lvl = 48,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 40,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 40,
        .lvl = 49,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMark2[] = {
    {
        .iv = 90,
        .lvl = 33,
        .species = SPECIES_EMPERORBULBLAX,
    },
    {
        .iv = 90,
        .lvl = 33,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerLogan[] = {
    {
        .iv = 100,
        .lvl = 37,
        .species = SPECIES_WOLLYHOP,
        .moves = {MOVE_SLEEPPOWDER, MOVE_POISONPOWDER, MOVE_STUNSPORE, MOVE_CONFUSION},
    },
    {
        .iv = 100,
        .lvl = 40,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_EGGBOMB, MOVE_STOMP, MOVE_CONFUSION, MOVE_HYPNOSIS},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerJackson[] = {
    {
        .iv = 100,
        .lvl = 49,
        .species = SPECIES_MUGGONFLY,
        .moves = {MOVE_SLAM, MOVE_MEGADRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .iv = 100,
        .lvl = 49,
        .species = SPECIES_WOLLYHOP,
        .moves = {MOVE_CONFUSION, MOVE_POISONPOWDER, MOVE_BARRAGE, MOVE_REFLECT},
    },
    {
        .iv = 100,
        .lvl = 49,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_STOMP},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnRangerBeth[] = {
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_ARACHNODE,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .iv = 100,
        .lvl = 38,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerKatelyn[] = {
    {
        .iv = 100,
        .lvl = 52,
        .species = SPECIES_DANDELFLY,
        .moves = {MOVE_EGGBOMB, MOVE_DEFENSECURL, MOVE_MINIMIZE, MOVE_SOFTBOILED},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerLeroy[] = {
    {
        .iv = 100,
        .lvl = 47,
        .species = SPECIES_SOVREIGNBULBLAX,
        .moves = {MOVE_TAKEDOWN, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_WADDLEPUS,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .iv = 100,
        .lvl = 47,
        .species = SPECIES_ADULTBULBMIN,
        .moves = {MOVE_DIZZYPUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_RAGINGLONGLEGS,
        .moves = {MOVE_CROSSCHOP, MOVE_VITALTHROW, MOVE_REVENGE, MOVE_SEISMICTOSS},
    },
    {
        .iv = 100,
        .lvl = 50,
        .species = SPECIES_SPOTTYBULBEAR,
        .moves = {MOVE_SLASH, MOVE_FEINTATTACK, MOVE_SNORE, MOVE_REST},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerMichelle[] = {
    {
        .iv = 100,
        .lvl = 47,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FEINTATTACK, MOVE_BITE},
    },
    {
        .iv = 100,
        .lvl = 47,
        .species = SPECIES_TOADYBLOYSTER,
        .moves = {MOVE_ICEBEAM, MOVE_TAKEDOWN, MOVE_ICYWIND, MOVE_GROWL},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_ARISTOCRAB,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSERAY, MOVE_WILLOWISP, MOVE_GRUDGE},
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRESPIN, MOVE_TAKEDOWN},
    },
    {
        .iv = 100,
        .lvl = 50,
        .species = SPECIES_BURROWNIT,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODORSLEUTH},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CoolCoupleLexNya[] = {
    {
        .iv = 100,
        .lvl = 52,
        .species = SPECIES_MAMASHEARGRUB,
        .moves = {MOVE_BODYSLAM, MOVE_MILKDRINK, MOVE_GROWL, MOVE_DEFENSECURL},
    },
    {
        .iv = 100,
        .lvl = 52,
        .species = SPECIES_TUSKEDBLOWHOG,
        .moves = {MOVE_THRASH, MOVE_HORNATTACK, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacBrandon[] = {
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemCustomMoves sParty_RuinManiacBenjamin[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_VEHEAMOTHPHOSBAT,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROLLOUT, MOVE_SELFDESTRUCT},
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROCKTHROW, MOVE_SELFDESTRUCT},
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PUCKERINGBLINNOW,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROCKTHROW, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PainterEdna[] = {
    {
        .iv = 50,
        .lvl = 50,
        .species = SPECIES_DEMO77,
        .moves = {MOVE_FAKEOUT, MOVE_EXTREMESPEED, MOVE_PROTECT, MOVE_QUICKATTACK},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GentlemanClifford[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_SCORCHCAKE,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonItemCustomMoves sParty_LadySelphy[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_DWARFORANGEBULBORB,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAYDAY, MOVE_BITE, MOVE_TAUNT, MOVE_TORMENT},
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_DWARFORANGEBULBORB,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAYDAY, MOVE_SCRATCH, MOVE_TORMENT, MOVE_TAUNT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLawson[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_SCORCHCAKE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PsychicLaura[] = {
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 100,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 100,
        .lvl = 49,
        .species = SPECIES_ELONGATEDCRUSHBLAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederBethany[] = {
    {
        .iv = 30,
        .lvl = 50,
        .species = SPECIES_DANDELFLY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAllison[] = {
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 30,
        .lvl = 48,
        .species = SPECIES_QUEENSHEARWIG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherGarret[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_SHEARFLEA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherJonah[] = {
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_CENTIPARE,
    },
    {
        .iv = 0,
        .lvl = 45,
        .species = SPECIES_DIRIGIBUG,
    },
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_CENTIPARE,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_DIRIGIBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVance[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_CREEPINGCHRYSANTHEMUM,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_STARTLESPORE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterNash[] = {
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_MOLDYDWARFBULBORB,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_MOLDYSLOOCH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterCordell[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassDalia[] = {
    {
        .iv = 0,
        .lvl = 46,
        .species = SPECIES_GRABBIT,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_GRABBIT,
    },
    {
        .iv = 0,
        .lvl = 47,
        .species = SPECIES_COPPELLER,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_COPPELLER,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassJoana[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperRiley[] = {
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_JOUSTMITE,
    },
    {
        .iv = 0,
        .lvl = 50,
        .species = SPECIES_SHEARFLEA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerMarcy[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ARMOREDCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ARMOREDCANNONBEETLE,
    },
    {
        .iv = 0,
        .lvl = 49,
        .species = SPECIES_HORNEDCANNONBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLayton[] = {
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 0,
        .lvl = 48,
        .species = SPECIES_DOWNYSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelsey2[] = {
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_BURROWINGSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelsey3[] = {
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelsey4[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperRicky2[] = {
    {
        .iv = 20,
        .lvl = 22,
        .species = SPECIES_WOLPOLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperRicky3[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperRicky4[] = {
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_YELLOWWOLLYHOP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperJeff2[] = {
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperJeff3[] = {
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperJeff4[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelle2[] = {
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 20,
        .lvl = 21,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 20,
        .lvl = 18,
        .species = SPECIES_SNOWBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelle3[] = {
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 26,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelle4[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 50,
        .species = SPECIES_FROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasu2[] = {
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_CRUMBUG,
    },
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasu3[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_BREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_EngineerBernie2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_ANODEBEETLE,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_ANODEBEETLE,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_ANODEBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerDarian2[] = {
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperChris2[] = {
    {
        .iv = 40,
        .lvl = 24,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 40,
        .lvl = 24,
        .species = SPECIES_FIERYBLOWLET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperChris3[] = {
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 60,
        .lvl = 29,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CamperChris4[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_ADULTBULBMIN,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_FIERYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlicia2[] = {
    {
        .iv = 40,
        .lvl = 25,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlicia3[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlicia4[] = {
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerJeremy2[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMark3[] = {
    {
        .iv = 150,
        .lvl = 54,
        .species = SPECIES_SOVREIGNBULBLAX,
    },
    {
        .iv = 150,
        .lvl = 54,
        .species = SPECIES_MOCKIWI,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHerman2[] = {
    {
        .iv = 90,
        .lvl = 29,
        .species = SPECIES_SCORCHCAKE,
    },
    {
        .iv = 90,
        .lvl = 29,
        .species = SPECIES_WADDLEPUS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHerman3[] = {
    {
        .iv = 150,
        .lvl = 54,
        .species = SPECIES_SCORCHCAKE,
    },
    {
        .iv = 150,
        .lvl = 54,
        .species = SPECIES_WADDLEPUS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerTrent2[] = {
    {
        .iv = 60,
        .lvl = 31,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 60,
        .lvl = 31,
        .species = SPECIES_PUCKERINGBLINNOW,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassMegan2[] = {
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 40,
        .lvl = 23,
        .species = SPECIES_SWARMINGSHEARGRUB,
    },
    {
        .iv = 40,
        .lvl = 21,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 40,
        .lvl = 22,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_LassMegan3[] = {
    {
        .iv = 80,
        .lvl = 46,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_MAMASHEARGRUB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SuperNerdGlenn2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_GamerRich2[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_BULBMIN,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_ARISTOCRABOFFSPRING,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerJaren2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanElliot2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PEARLYCLAMCLAMP,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RockerLuca2[] = {
    {
        .iv = 60,
        .lvl = 33,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 60,
        .lvl = 33,
        .species = SPECIES_PUFFMIN,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautySheila2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobert2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobert3[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerSusie2[] = {
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_DWARFBULBORB,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_DWARFBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerSusie3[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerSusie4[] = {
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_HONEYWISP,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_DWARFORANGEBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerLukas2[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_SNOWYBLOWHOG,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PUFFSTOOL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBenny2[] = {
    {
        .iv = 60,
        .lvl = 32,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 32,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBenny3[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlon2[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlon3[] = {
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BeautyGrace2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_FROSTYBULBORB,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_FOOLIX,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChester2[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_PYROCLASTICSLOOCH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChester3[] = {
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_LESSERSPOTTEDJELLYFLOAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerBecky2[] = {
    {
        .iv = 60,
        .lvl = 32,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 60,
        .lvl = 32,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerBecky3[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerBecky4[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_HONEYWISP,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_HONEYWISP,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinRonMya2[] = {
    {
        .iv = 110,
        .lvl = 33,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 110,
        .lvl = 33,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinRonMya3[] = {
    {
        .iv = 130,
        .lvl = 51,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 130,
        .lvl = 51,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinRonMya4[] = {
    {
        .iv = 170,
        .lvl = 56,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 56,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerRuben2[] = {
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_PUFFSTOOL,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_PUFFSTOOL,
    },
    {
        .iv = 80,
        .lvl = 48,
        .species = SPECIES_PUFFSTOOL,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallCamron2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SHAGGYLONGLEGS,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BikerJaxon2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_PUFFSTOOL,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallIsaiah2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallCorey2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SHAGGYLONGLEGS,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacob2[] = {
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_GIANTBREADBUG,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 28,
        .species = SPECIES_GIANTBREADBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacob3[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAlice2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDarrin2[] = {
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissy2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissy3[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_BEARDEDAMPRAT,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_FishermanWade2[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_PELLETPOSY,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJack2[] = {
    {
        .iv = 80,
        .lvl = 50,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIan2[] = {
    {
        .iv = 80,
        .lvl = 50,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 80,
        .lvl = 50,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIan3[] = {
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleFinn2[] = {
    {
        .iv = 80,
        .lvl = 50,
        .species = SPECIES_GATTLINGGROINK,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlSharon2[] = {
    {
        .iv = 130,
        .lvl = 50,
        .species = SPECIES_BALDYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 130,
        .lvl = 50,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlSharon3[] = {
    {
        .iv = 170,
        .lvl = 55,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 55,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlTanya2[] = {
    {
        .iv = 130,
        .lvl = 50,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 130,
        .lvl = 50,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlTanya3[] = {
    {
        .iv = 170,
        .lvl = 55,
        .species = SPECIES_WATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 55,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltShea2[] = {
    {
        .iv = 180,
        .lvl = 50,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 180,
        .lvl = 50,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltShea3[] = {
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_BEADYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltHugh2[] = {
    {
        .iv = 180,
        .lvl = 50,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 180,
        .lvl = 50,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_BlackBeltHugh3[] = {
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_BEADYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinMikKia2[] = {
    {
        .iv = 130,
        .lvl = 51,
        .species = SPECIES_RAGINGLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 130,
        .lvl = 51,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushKinMikKia3[] = {
    {
        .iv = 170,
        .lvl = 56,
        .species = SPECIES_BEADYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 56,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TuberAmira2[] = {
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 80,
        .lvl = 47,
        .species = SPECIES_WATERDUMPLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TwinsJoyMeg2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SHEARWIG,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PainterRayna2[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_DEMO77,
        .moves = {MOVE_CROSSCHOP, MOVE_MEGAHORN, MOVE_DOUBLEEDGE, MOVE_SELFDESTRUCT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungsterDestin2[] = {
    {
        .iv = 120,
        .lvl = 53,
        .species = SPECIES_BREADBUG,
    },
    {
        .iv = 120,
        .lvl = 53,
        .species = SPECIES_FROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAlize2[] = {
    {
        .iv = 150,
        .lvl = 53,
        .species = SPECIES_SPOTTYBULBEAR,
    },
    {
        .iv = 150,
        .lvl = 53,
        .species = SPECIES_SHEARWIG,
    },
    {
        .iv = 150,
        .lvl = 53,
        .species = SPECIES_STARNACLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJes2[] = {
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 60,
        .lvl = 30,
        .species = SPECIES_MAMASHEARGRUB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJes3[] = {
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_MALESHEARGRUB,
    },
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_FEMALESHEARGRUB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMilo2[] = {
    {
        .iv = 120,
        .lvl = 53,
        .species = SPECIES_DWARFFROSTYBULBORB,
    },
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_FROSTYBULBORB,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChaz2[] = {
    {
        .iv = 120,
        .lvl = 53,
        .species = SPECIES_PILEATEDSNAGRET,
    },
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_PILEATEDSNAGRET,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperHarold2[] = {
    {
        .iv = 120,
        .lvl = 53,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNicole2[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_STARNACLE,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicJaclyn2[] = {
    {
        .iv = 220,
        .lvl = 52,
        .species = SPECIES_MOCKIWI,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_FUTURESIGHT, MOVE_WISH},
    },
    {
        .iv = 220,
        .lvl = 52,
        .species = SPECIES_WADDLEPUS,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .iv = 220,
        .lvl = 54,
        .species = SPECIES_LURINGSLURKER,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSamir2[] = {
    {
        .iv = 120,
        .lvl = 55,
        .species = SPECIES_MASTERONION,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_HikerEarl2[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_ARMOREDCANNONLARVA,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLarry2[] = {
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_RAGINGLONGLEGS,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_RAGINGLONGLEGS,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHector2[] = {
    {
        .iv = 150,
        .lvl = 55,
        .species = SPECIES_SOVREIGNBULBLAX,
    },
    {
        .iv = 150,
        .lvl = 55,
        .species = SPECIES_ADULTBULBMIN,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicDario2[] = {
    {
        .iv = 220,
        .lvl = 56,
        .species = SPECIES_BURROWNIT,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODORSLEUTH, MOVE_AGILITY},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PsychicRodette2[] = {
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_MOCKIWI,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_WISH, MOVE_FUTURESIGHT},
    },
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_PROQUILLION,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_PROQUILLION,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_JugglerMason2[] = {
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPECTRALID,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_PUFFMIN,
    },
    {
        .iv = 120,
        .lvl = 52,
        .species = SPECIES_SPECTRALID,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerNicolas2[] = {
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_MOLDYSLOOCH,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_STUNSPORE, MOVE_WRAP},
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_MOLDYSLOOCH,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SLEEPPOWDER, MOVE_SLAM},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerMadeline2[] = {
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_SLEEPPOWDER},
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_ARMOREDCANNONLARVA,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUNSPORE},
    },
};

struct TrainerMonItemDefaultMoves sParty_CrushGirlCyndy2[] = {
    {
        .iv = 170,
        .lvl = 54,
        .species = SPECIES_SHAGGYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 54,
        .species = SPECIES_BEEB,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 170,
        .lvl = 54,
        .species = SPECIES_BEADYLONGLEGS,
        .heldItem = ITEM_BLACK_BELT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_TamerEvan2[] = {
    {
        .iv = 160,
        .lvl = 52,
        .species = SPECIES_DOWNYSNAGRET,
    },
    {
        .iv = 160,
        .lvl = 52,
        .species = SPECIES_MOCKIWI,
    },
    {
        .iv = 160,
        .lvl = 55,
        .species = SPECIES_SPOTTYBULBEAR,
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerJackson2[] = {
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_MUGGONFLY,
        .moves = {MOVE_SLAM, MOVE_MEGADRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .iv = 220,
        .lvl = 54,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_STUNSPORE, MOVE_REFLECT},
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_STOMP},
    },
};

struct TrainerMonNoItemCustomMoves sParty_PkmnRangerKatelyn2[] = {
    {
        .iv = 220,
        .lvl = 56,
        .species = SPECIES_DANDELFLY,
        .moves = {MOVE_EGGBOMB, MOVE_DEFENSECURL, MOVE_MINIMIZE, MOVE_SOFTBOILED},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerLeroy2[] = {
    {
        .iv = 220,
        .lvl = 52,
        .species = SPECIES_SOVREIGNBULBLAX,
        .moves = {MOVE_EARTHQUAKE, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE},
    },
    {
        .iv = 220,
        .lvl = 54,
        .species = SPECIES_WADDLEPUS,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .iv = 220,
        .lvl = 52,
        .species = SPECIES_ADULTBULBMIN,
        .moves = {MOVE_DIZZYPUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .iv = 220,
        .lvl = 52,
        .species = SPECIES_BEADYLONGLEGS,
        .moves = {MOVE_CROSSCHOP, MOVE_VITALTHROW, MOVE_REVENGE, MOVE_SEISMICTOSS},
    },
    {
        .iv = 220,
        .lvl = 55,
        .species = SPECIES_SPOTTYBULBEAR,
        .moves = {MOVE_SLASH, MOVE_FEINTATTACK, MOVE_SNORE, MOVE_REST},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CooltrainerMichelle2[] = {
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_DWARFORANGEBULBORB,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FEINTATTACK, MOVE_BITE},
    },
    {
        .iv = 220,
        .lvl = 53,
        .species = SPECIES_TOADYBLOYSTER,
        .moves = {MOVE_ICEBEAM, MOVE_TAKEDOWN, MOVE_ICYWIND, MOVE_SHEERCOLD},
    },
    {
        .iv = 220,
        .lvl = 54,
        .species = SPECIES_ARISTOCRAB,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSERAY, MOVE_WILLOWISP, MOVE_GRUDGE},
    },
    {
        .iv = 220,
        .lvl = 54,
        .species = SPECIES_SCORCHCAKE,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRESPIN, MOVE_TAKEDOWN},
    },
    {
        .iv = 220,
        .lvl = 56,
        .species = SPECIES_BURROWNIT,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODORSLEUTH},
    },
};

struct TrainerMonNoItemCustomMoves sParty_CoolCoupleLexNya2[] = {
    {
        .iv = 220,
        .lvl = 57,
        .species = SPECIES_MAMASHEARGRUB,
        .moves = {MOVE_BODYSLAM, MOVE_MILKDRINK, MOVE_GROWL, MOVE_DEFENSECURL},
    },
    {
        .iv = 220,
        .lvl = 57,
        .species = SPECIES_TUSKEDBLOWHOG,
        .moves = {MOVE_TAKEDOWN, MOVE_SCARYFACE, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColton2[] = {
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_DOODLEBUG,
    },
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_SWOOPINGSNITCHBUG,
    },
    {
        .iv = 20,
        .lvl = 19,
        .species = SPECIES_DOODLEBUG,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColton3[] = {
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_GLINTBEETLE,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_BUMBLINGSNITCHBUG,
    },
    {
        .iv = 60,
        .lvl = 27,
        .species = SPECIES_GLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColton4[] = {
    {
        .iv = 120,
        .lvl = 51,
        .species = SPECIES_GLINTBEETLE,
    },
    {
        .iv = 120,
        .lvl = 54,
        .species = SPECIES_DIRIGIBUG,
    },
    {
        .iv = 120,
        .lvl = 51,
        .species = SPECIES_GLINTBEETLE,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMatthew2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BURROWNIT,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleTony2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SPUTTLEFISH,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_SPUTTLEFISH,
    },
};

struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMelissa2[] = {
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .iv = 80,
        .lvl = 49,
        .species = SPECIES_BEARDEDAMPRAT,
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourLorelei2[] = {
    {
        .iv = 255,
        .lvl = 64,
        .species = SPECIES_TOADYBLOYSTER,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_SIGNALBEAM, MOVE_DOUBLETEAM},
    },
    {
        .iv = 255,
        .lvl = 63,
        .species = SPECIES_PEARLYCLAMCLAMP,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_SUPERSONIC, MOVE_RAINDANCE},
    },
    {
        .iv = 255,
        .lvl = 63,
        .species = SPECIES_TUSKEDBLOWHOG,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_DOUBLEEDGE, MOVE_ROCKSLIDE},
    },
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_ARMOREDMAWDAD,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_PSYCHIC, MOVE_LOVELYKISS, MOVE_ATTRACT},
    },
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_OATCHI,
        .heldItem = ITEM_CHERI_BERRY,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDER},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourBruno2[] = {
    {
        .lvl = 65,
        .species = SPECIES_MANATLEGS,
    },
    {
        .lvl = 65,
        .species = SPECIES_LONGWATERDUMPLE,
    },
    {
        .lvl = 65,
        .species = SPECIES_WATERDUMPLE,
    },
    {
        .lvl = 66,
        .species = SPECIES_MANATLEGS,
    },
    {
        .lvl = 68,
        .species = SPECIES_BEADYLONGLEGS,
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourAgatha2[] = {
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_ICEBLOWNDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_HYPNOSIS},
    },
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_FIREFLAPBULBORB,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_AIRCUTTER, MOVE_SHADOWBALL, MOVE_CONFUSERAY},
    },
    {
        .iv = 255,
        .lvl = 65,
        .species = SPECIES_COURAGEREACTOR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ATTRACT},
    },
    {
        .iv = 255,
        .lvl = 68,
        .species = SPECIES_DWARFBULBEAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_EARTHQUAKE, MOVE_GIGADRAIN, MOVE_DOUBLETEAM},
    },
    {
        .iv = 255,
        .lvl = 70,
        .species = SPECIES_ICEBLOWNDWEEVIL,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_SLUDGEBOMB},
    },
};

struct TrainerMonItemCustomMoves sParty_EliteFourLance2[] = {
    {
        .iv = 255,
        .lvl = 68,
        .species = SPECIES_MASTERONION,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_THUNDERWAVE},
    },
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_GLOWPIKMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_EARTHQUAKE, MOVE_DRAGONCLAW, MOVE_FLAMETHROWER},
    },
    {
        .iv = 255,
        .lvl = 66,
        .species = SPECIES_LONGWATERDUMPLE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_DRAGONDANCE, MOVE_SURF, MOVE_ICEBEAM},
    },
    {
        .iv = 255,
        .lvl = 70,
        .species = SPECIES_ROCKPIKMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_ANCIENTPOWER, MOVE_AERIALACE, MOVE_EARTHQUAKE},
    },
    {
        .iv = 255,
        .lvl = 72,
        .species = SPECIES_GLOWPIKMIN,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_HYPERBEAM, MOVE_OUTRAGE, MOVE_THUNDERBOLT, MOVE_ICEBEAM},
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionRematchWolpole[] = {
    {
        .lvl = 72,
        .species = SPECIES_SHEARFLEA,
    },
    {
        .lvl = 73,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .lvl = 72,
        .species = SPECIES_ICEPIKMIN,
    },
    {
        .lvl = 73,
        .species = SPECIES_ADULTBULBMIN,
    },
    {
        .lvl = 73,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
    },
    {
        .lvl = 75,
        .species = SPECIES_MASTERHOP,
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionRematchBulborbLarva[] = {
    {
        .lvl = 72,
        .species = SPECIES_SHEARFLEA,
    },
    {
        .lvl = 73,
        .species = SPECIES_VOLATILEDWEEVIL,
    },
    {
        .lvl = 72,
        .species = SPECIES_ICEPIKMIN,
    },
    {
        .lvl = 73,
        .species = SPECIES_MASTERONION,
    },
    {
        .lvl = 73,
        .species = SPECIES_ADULTBULBMIN,
    },
    {
        .lvl = 75,
        .species = SPECIES_JUMBOBULBORB,
    },
};

struct TrainerMonItemCustomMoves sParty_ChampionRematchFieryBlowlet[] = {
    {
        .iv = 255,
        .lvl = 72,
        .species = SPECIES_SHEARFLEA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCKTOMB},
    },
    {
        .iv = 255,
        .lvl = 73,
        .species = SPECIES_VOLATILEDWEEVIL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOWBALL, MOVE_CALMMIND, MOVE_REFLECT},
    },
    {
        .iv = 255,
        .lvl = 72,
        .species = SPECIES_ICEPIKMIN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIALACE},
    },
    {
        .iv = 255,
        .lvl = 73,
        .species = SPECIES_DESICCATEDSKITTERLEAF,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_PSYCHIC, MOVE_SLEEPPOWDER, MOVE_LIGHTSCREEN},
    },
    {
        .iv = 255,
        .lvl = 73,
        .species = SPECIES_MASTERONION,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_HYPERBEAM},
    },
    {
        .iv = 255,
        .lvl = 75,
        .species = SPECIES_TITANBLOWHOG,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FIREBLAST, MOVE_DRAGONCLAW, MOVE_AERIALACE, MOVE_EARTHQUAKE},
    },
};

struct TrainerMonNoItemDefaultMoves sParty_CueBallPaxton[] = {
    {
        .iv = 50,
        .lvl = 39,
        .species = SPECIES_PUFFSTOOL,
    },
    {
        .iv = 50,
        .lvl = 39,
        .species = SPECIES_SNOWYBLOWHOG,
    },
};
#endif

#ifdef STEVEBELS_TRAINER_TABLE

static const struct TrainerMonNoItemDefaultMoves sParty_RivalStarterLab1[] = {
    {
        .lvl = 5,
        .species = SPECIES_WOLPOLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RivalStarterLab2[] = {
    {
        .lvl = 5,
        .species = SPECIES_BULBORB,
    },
    {
        .lvl = 5,
        .species = SPECIES_JUMBOBULBORB,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_RivalStarterLab3[] = {
    {
        .lvl = 5,
        .species = SPECIES_FIERYBLOWLET,
    },
};
#endif