.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_TheImpactSite_LittleGirl

.equ FLAG_WILD_CUSTOM_MOVES, 0x90B
EventScript_TheImpactSite_LittleGirl:
    faceplayer

    lock
    minimsgbox gText_Name_LittleGirl gText_ThisIsBeforeImage MSG_NORMAL
    setvar 0x8000 0
    callasm ShowImage
    waitstate
    msgbox gText_ThisIsAfterImage MSG_NORMAL
    setvar 0x8000 MOVE_POWERGEM
    setvar 0x8001 MOVE_TOXIC
    setvar 0x8002 MOVE_ICEBEAM
    setvar 0x8003 MOVE_ROCKSLIDE
    setvar 0x8004 5
    setvar 0x8005 1
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon 0x3 32 ITEM_HARD_STONE 0 1 0
    
    trainerbattle0 0 29 0 gText_ThisIsBeforeImage gText_ThisIsAfterImage
    msgbox gText_Name_LittleGirl MSG_NORMAL
    release
    end
