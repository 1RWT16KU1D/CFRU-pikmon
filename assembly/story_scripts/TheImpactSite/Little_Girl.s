.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_TheImpactSite_LittleGirl

.equ FLAG_WILD_CUSTOM_MOVES, 0x90B
EventScript_TheImpactSite_LittleGirl:
    lock
    faceplayer

    setvar 0x8004 0xF
    special 0x62 @Erase Party

    addvar 0x402F 0x1
    givepokemon 0x402F 40 ITEM_NONE 0 1 0

    additem ITEM_BICYCLE 1
    additem ITEM_TM101 1
    additem ITEM_TM102 1
    additem ITEM_TM110 1

    bufferpokemon 0x0 0x402F
    msgbox gText_TheImpactSite_LittleGirl MSG_NORMAL
    release
    end
