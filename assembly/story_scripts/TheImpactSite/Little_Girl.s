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
    additem 0x323 1 @ITEM_GLOOMY_ROCK
    msgbox gText_ThisIsAfterImage MSG_NORMAL
    
    setvar 0x8004 0xF
    special 0x62 @Erase Party

    setvar 0x8000 MOVE_ACIDREFLEX
    setvar 0x8001 MOVE_STONEPUNCH
    setvar 0x8002 MOVE_DIRECLAW
    setvar 0x8003 MOVE_TELEKINESIS
    setvar 0x8004 5
    setvar 0x8005 1
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon 0x3 32 ITEM_HARD_STONE 0 1 0
    setwildbattle 0x3 10 ITEM_NONE
    dowildbattle
    msgboxtransparent gText_GreatBattle MSG_NORMAL
    release
    end
