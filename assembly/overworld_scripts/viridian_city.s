.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_ViridianCity_YoungMan
.global EventScript_ViridianCity_Youngster
.global EventScript_ViridianCity_OldMan

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianCity_YoungMan:
    lock
    faceplayer

    setflag 0xA08
    trainerbattle0 0 330 0 gText_ViridianCity_BattleStart gText_ViridianCity_BattleEnd
    msgbox gText_ViridianCity_BattleOver MSG_NORMAL

    release
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianCity_Youngster:
    lock
    faceplayer
    additem ITEM_ICIUM_Z 1
    additem ITEM_MEGA_RING 1
@   additem ITEM_TM19 1

@   giveegg SPECIES_IVYSAUR

    @ Relatable Mons
    setvar 0x8000 MOVE_AURASPHERE
    setvar 0x8001 MOVE_DAZZLINGGLEAM
    setvar 0x8002 MOVE_THUNDERWAVE
    setvar 0x8003 MOVE_MOONLIGHT
    setvar 0x8004 NATURE_MODEST
    setvar 0x8005 NOT_SHINY
    setvar 0x8006 16
    setvar 0x8007 16
    setvar 0x8008 16
    setvar 0x8009 16
    setvar 0x800A 16
    setvar 0x800B 16
    givepokemon SPECIES_TOGETIC 26 ITEM_SHINY_STONE 0 1 10

    @ Set-Up Gyarados
    setvar 0x8000 MOVE_WATERFALL
    setvar 0x8001 MOVE_ICEFANG
    setvar 0x8002 MOVE_DRAGONDANCE
    setvar 0x8003 MOVE_EARTHQUAKE
    setvar 0x8004 NATURE_ADAMANT
    setvar 0x8005 IS_SHINY
    setvar 0x8006 16
    setvar 0x8007 16
    setvar 0x8008 16
    setvar 0x8009 16
    setvar 0x800A 16
    setvar 0x800B 16
    givepokemon SPECIES_GYARADOS 40 ITEM_WATERIUM_Z 0 1 5

    setflag 0x82F
    @ Mega Blaziken
    setvar 0x8000 MOVE_BLAZEKICK
    setvar 0x8001 MOVE_SKYUPPERCUT
    setvar 0x8002 MOVE_THUNDERPUNCH
    setvar 0x8003 MOVE_SWORDSDANCE
    setvar 0x8004 NATURE_ADAMANT
    setvar 0x8005 NOT_SHINY
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_BLAZIKEN 40 ITEM_BLAZIKENITE 0 9

    additem ITEM_MASTER_BALL 1
    msgbox gText_ViridianCity_BattleOver MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianCity_OldMan:
    lock
    faceplayer
    msgbox gText_ViridianCity_OldMan_IVChangeAsk MSG_YESNO
    compare LASTRESULT NO
    if TRUE _goto ViridianCity_OldMan_No

    msgbox gText_ViridianCity_OldMan_OpenMenu MSG_NORMAL
    special 0x9F  @ Opens Pokemon selection menu
    waitstate

    @ Uses var 0x8005 for party index
    copyvar 0x8005 0x8004

    compare 0x8005 0x7
    if TRUE _goto ViridianCity_OldMan_No
    goto ViridianCity_OldMan_SetIVs

ViridianCity_OldMan_No:
    msgbox gText_ViridianCity_OldMan_No MSG_NORMAL
    release
    end

ViridianCity_OldMan_SetIVs:
    resetvar 0x8006
    resetvar 0x8007
    resetvar 0x8008
    resetvar 0x8009
    setvar 0x800A 31 @ Special Attack
    resetvar 0x800B

    @ Calls the function to change IVs
    callasm SetCustomMonIVs

    msgbox gText_ViridianCity_OldMan_Done MSG_NORMAL
    release
    end
