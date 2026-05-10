.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

@@ Defines for this script
.equ SHIP, 3

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_TheImpactSite_OlimarTilescript
EventScript_TheImpactSite_OlimarTilescript:
    lockall
    checkflag 0x00C7
    if SET _goto EventScript_TheImpactSite_OlimarTilescript_6

    setvar VarTemp1 1
    goto EventScript_TheImpactSite_OlimarTilescript_1
    end

EventScript_TheImpactSite_OlimarTilescript_1:
    pause 30
    showsprite SHIP
    comparevartovalue VarTemp1 0x0
    if equal _call EventScript_TheImpactSite_OlimarTilescript_2
    comparevartovalue VarTemp1 0x1
    if equal _call EventScript_TheImpactSite_OlimarTilescript_3
    pause 30
    textcolor TEXTCOLOR_BLUE
    minimsgbox gText_Name_Ship gText_TheImpactSite_OlimarTilescript_1 MSG_KEEPOPEN
    closeonkeypress
    pause 10
    
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_1
    waitmovement SHIP
    pause 10

    minimsgbox gText_Name_Ship gText_TheImpactSite_OlimarTilescript_2 MSG_KEEPOPEN
    closeonkeypress
    pause 30

    comparevartovalue VarTemp1 0x0
    if equal _call EventScript_TheImpactSite_OlimarTilescript_4
    comparevartovalue VarTemp1 0x1
    if equal _call EventScript_TheImpactSite_OlimarTilescript_5

    setdooropen 16 13
    waitdooranim
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_2
    waitmovement SHIP
    applymovement PLAYER gMovement_TheImpactSite_OlimarTilescript_2
    waitmovement PLAYER
    setdoorclosed 16 13
    waitdooranim

    setflag 0x00C7
    setvar 0x4055 1
    clearflag 0x002B
    setvar 0x4050 1
    setflag 0x002C
    setflag 0x4001
    warp 4 3 0xFF 6 12 @Research Lab Door
    waitstate
    releaseall
    end

EventScript_TheImpactSite_OlimarTilescript_2:
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_3
    waitmovement SHIP
    return

EventScript_TheImpactSite_OlimarTilescript_3:
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_3
    waitmovement SHIP
    return

EventScript_TheImpactSite_OlimarTilescript_4:
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_4
    waitmovement SHIP
    applymovement PLAYER gMovement_TheImpactSite_OlimarTilescript_5
    waitmovement PLAYER
    return

EventScript_TheImpactSite_OlimarTilescript_5:
    applymovement SHIP gMovement_TheImpactSite_OlimarTilescript_6
    applymovement PLAYER gMovement_TheImpactSite_OlimarTilescript_7
    waitmovement PLAYER
    return

EventScript_TheImpactSite_OlimarTilescript_6:
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 1
gMovement_TheImpactSite_OlimarTilescript_1:
    .byte exclaim
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_2:
    .byte walk_up
    .byte set_invisible
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_3:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_4:
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_5:
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_6:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_up_onspot_fastest
    .byte end_m

gMovement_TheImpactSite_OlimarTilescript_7:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m
