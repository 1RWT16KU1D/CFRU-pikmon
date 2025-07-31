#include "trainer_parties.h"
#include "trainer_defines.h"

#include "../../include/battle.h"
#include "../../include/global.h"

#include "../../include/constants/battle_ai.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/trainers.h"
#include "../../include/constants/trainer_classes.h"
#include "../../include/constants/opponents.h"

#include "new_text.h"

#ifdef STEVEBELS_TRAINER_TABLE

#define NO_NAME {_END, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE}
#define RIVAL_NAME {_G, _a, _r, _y, _END}


const struct Trainer gTrainers[] = {
    [TRAINER_NONE] = {
        .trainerName = NO_NAME,
    },
	[LASS_DIANA] = {
	    .partyFlags = 0,
	    .trainerClass = CLASS_BEAUTY,
	    .encounterMusic = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .trainerPic = TRAINER_PIC_AROMA_LADY_RS,
	    .trainerName = {_d, _i, _a, _n, _a, _END},
	    .items = {ITEM_ACRO_BIKE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	    .doubleBattle = FALSE,
	    .aiFlags = AI_SCRIPT_SEMI_SMART,  // Flags: 0x2
	    .partySize = NELEMS(sParty_LassDiana),
	    .party = {.NoItemDefaultMoves = sParty_LassDiana}
	},
};
#endif