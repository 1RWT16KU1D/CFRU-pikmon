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
};
#endif