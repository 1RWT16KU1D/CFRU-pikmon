.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScriptP_ViridianCity_YoungMan

EventScriptP_ViridianCity_YoungMan:

@   givepokemon SPECIES_GYARADOS 25 0x220 0 0 0
@   additem ITEM_MEGA_RING 1 @ Gyaradosite

@   trainerbattle0 0 329 0 gText_ViridianCity_YoungManIntro gText_ViridianCity_YoungManLoss
@   msgbox gText_ViridianCity_YoungManAfter MSG_FACE
    
    setflag 0x918
    setflag 0x91E
    setflag 0xA00

    givepokemon 0x154 100 0 0 0 0
    givepokemon 0x190 100 0 0 0 0
    givepokemon 0xFA 100 0 0 0 0
    givepokemon 0x458 100 0 0 0 0
    givepokemon 0x13A 100 0 0 0 0
    givepokemon 0x58B 100 0 0 0 0

    setflag 0x820
    setflag 0x821
    setflag 0x822
    setflag 0x823
    setflag 0x824
    setflag 0x825
    setflag 0x826
    setflag 0x827
    setflag 0x828
    setflag 0x829
    setflag 0x82F
    
    special 0x16F
    setflag 0x906
    giveegg 0x19
    giveitem 0x1A 100 0
    removeitem 0x1A 0x31

    special 0
    trainerbattle0 0 0x19D 0x0 gText_Initial gText_Lose
    msgbox gText_Later MSG_NORMAL
    special 0
    fadescreen 1

    warp 3 0 0xFF 5 8
    waitstate
    release
    end
