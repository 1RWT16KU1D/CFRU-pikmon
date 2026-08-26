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

    setvar 0x8000 MOVE_CRUSHINGBLOW
    setvar 0x8001 MOVE_DEFOG
    setvar 0x8002 MOVE_TELEPORT
    setvar 0x8003 MOVE_SWEETSCENT
    setvar 0x8004 5
    setvar 0x8005 1
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_MASTERHOP 40 ITEM_NONE 0 1 0

    additem ITEM_BICYCLE 1
    additem ITEM_TM101 1
    additem ITEM_TM102 1
    additem ITEM_TM110 1

    msgbox gText_TheImpactSite_LittleGirl MSG_NORMAL
    release
    end
