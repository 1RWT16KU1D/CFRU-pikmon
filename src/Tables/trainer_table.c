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

const struct Trainer gTrainersStevebel[];

bool8 IsTrainerBlank(u16 trainerId)
{
    if (trainerId >= TRAINERS_COUNT)
        return TRUE; // Fora do limite? Considera inválido.

    const struct Trainer *trainer = &gTrainersStevebel[trainerId];
    return trainer->partyFlags == 0 && trainer->party.NoItemDefaultMoves == 0;
}

struct Trainer GetTrainer(u16 trainerId)
{
    if (trainerId >= TRAINERS_COUNT)
        return gOriginalTrainers[0]; // Retorna algum valor "seguro"

    if (IsTrainerBlank(trainerId))
        return gOriginalTrainers[trainerId];
    else
        return gTrainersStevebel[trainerId];
}

const struct Trainer *GetTrainerPtr(u16 trainerId)
{
    if (trainerId >= TRAINERS_COUNT)
        return &gOriginalTrainers[0];

    if (IsTrainerBlank(trainerId))
        return &gOriginalTrainers[trainerId];
    else
        return &gTrainersStevebel[trainerId];
}

#define NO_NAME {_END, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE, _SPACE}
#define RIVAL_NAME {_G, _a, _r, _y, _END}


const struct Trainer gTrainersStevebel[] = {
    [TRAINER_NONE] = {
        .trainerName = NO_NAME,
    },
    [TRAINER_RIVAL_STARTER_LAB_1] = {
	    .partyFlags = 0,
	    .trainerClass = CLASS_RIVAL,
	    .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
	    .trainerPic = TRAINER_PIC_BLUE,
	    .trainerName = { _T, _e, _r, _r, _y, _END },
	    .items = {},
	    .doubleBattle = FALSE,
	    .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,  // Flags: 0x3
	    .partySize = NELEMS(sParty_RivalStarterLab1),
	    .party = {.NoItemDefaultMoves = sParty_RivalStarterLab1}
	},
    [TRAINER_RIVAL_STARTER_LAB_2] = {
	    .partyFlags = 0,
	    .trainerClass = CLASS_RIVAL,
	    .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
	    .trainerPic = TRAINER_PIC_BLUE,
	    .trainerName = { _T, _e, _r, _r, _y, _END },
	    .items = {},
	    .doubleBattle = TRUE,
	    .aiFlags = AI_SCRIPT_CHECK_GOOD_MOVE,  // Flags: 0x3
	    .partySize = NELEMS(sParty_RivalStarterLab2),
	    .party = {.NoItemDefaultMoves = sParty_RivalStarterLab2}
	},
    [TRAINER_RIVAL_STARTER_LAB_3] = {
	    .partyFlags = 0,
	    .trainerClass = CLASS_RIVAL,
	    .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
	    .trainerPic = TRAINER_PIC_BLUE,
	    .trainerName = { _T, _e, _r, _r, _y, _END },
	    .items = {},
	    .doubleBattle = FALSE,
	    .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_SEMI_SMART,  // Flags: 0x3
	    .partySize = NELEMS(sParty_RivalStarterLab3),
	    .party = {.NoItemDefaultMoves = sParty_RivalStarterLab3}
	},
};
#endif