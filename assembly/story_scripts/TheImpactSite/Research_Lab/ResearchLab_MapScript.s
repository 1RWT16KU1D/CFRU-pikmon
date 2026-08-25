.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"
.include "story_scripts/TheImpactSite/Research_Lab/event_defines.s"

.global MapScript_ResearchLab

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MapScript_ResearchLab:
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_ResearchLab_OnTransition
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_ResearchLab
    .byte MAP_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MapEntryScript_ResearchLab_OnTransition:
    comparevartovalue StoryEventVar1 ResearchLabEnteredFirstTime
    if lessthan _call MapEntryScript_ResearchLab_ReadyToChooseStarter

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if greaterorequal _call MapEntryScript_ResearchLab_HideShip
    end

MapEntryScript_ResearchLab_ReadyToChooseStarter:
    setvar StoryEventVar1 ResearchLabEnteredFirstTime
    setobjectxyperm LOCALID_SHIP 6 11
    spritebehave LOCALID_SHIP look_up
    savebgm 302 @ MUS_OAK
    return

MapEntryScript_ResearchLab_HideShip:
    setflag 0x2B @ FLAG_HIDE_SHIP
    return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
LevelScripts_ResearchLab:
    levelscript StoryEventVar1 ResearchLabEnteredFirstTime LevelScript_ResearchLab_ChooseStarterScene
    .hword LEVEL_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
LevelScript_ResearchLab_ChooseStarterScene:
    lockall
    textcolor TEXTCOLOR_BLUE

    compare StoryEventVar1 ResearchLabToChooseStarter
    if greaterorequal _goto End

    applymovement LOCALID_SHIP gMovement_TheImpactSite_ResearchLab_ShipWalkUp5StepsLookLeft
    waitmovement WAIT_LATEST

    hidesprite LOCALID_SHIP
    setobjectxyperm LOCALID_SHIP 5 6

    spritebehave LOCALID_SHIP 0x7
    spritebehave LOCALID_OLIMAR 0x7
    clearflag 0x2B @ FLAG_HIDE_SHIP_IN_LAB

    applymovement PLAYER gMovement_TheImpactSite_ResearchLab_PlayerWalkUp6Steps
    waitmovement WAIT_LATEST

    clearflag 0x4001 @ FLAG_DONT_TRANSITION_MUSIC
    playsong2 0x12E
    fadedefault

    applymovement LOCALID_SHIP gMovement_TheImpactSite_ResearchLab_OlimarWalkUpOnSpotFast
    waitmovement WAIT_LATEST
    minimsgbox gText_Name_Ship gText_TheImpactSite_ResearchLab_ShipDeliveredPlayerToOlimar MSG_KEEPOPEN
    closeonkeypress

    pause 60
    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_ShipWalkDownOnSpotFast
    waitmovement WAIT_LATEST

    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_OlimarWantsToShowPlayerSomething MSG_KEEPOPEN
    closeonkeypress
    pause 30

    minimsgbox gText_Name_Ship gText_TheImpactSite_ResearchLab_ShipWantsToLeave MSG_KEEPOPEN
    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarWalkRightOnSpotFast
    waitmovement WAIT_LATEST

    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_OlimarBloomingOnionInvention MSG_KEEPOPEN
    pause 60

    applymovement LOCALID_SHIP gMovement_TheImpactSite_ResearchLab_ShipWalkDown8StepsAndHide
    waitmovement WAIT_LATEST

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarWalkDownOnSpotFast
    waitmovement WAIT_LATEST

    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_OlimarAsksPlayerAboutBloomingOnionInside MSG_KEEPOPEN
    pause 60

    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_OlimarTakeSilenceAsYesGoAndPickStarter MSG_KEEPOPEN
    closeonkeypress

    setvar StoryEventVar1 ResearchLabToChooseStarter
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 1

gMovement_TheImpactSite_ResearchLab_ShipWalkUp5StepsLookLeft:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarWalkUpOnSpotFast:
    .byte walk_up_onspot_fast
    .byte end_m

gMovement_TheImpactSite_ResearchLab_PlayerWalkUp6Steps:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

gMovement_TheImpactSite_ResearchLab_ShipWalkDownOnSpotFast:
gMovement_TheImpactSite_ResearchLab_OlimarWalkDownOnSpotFast:
    .byte walk_down_onspot_fast
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarWalkRightOnSpotFast:
    .byte walk_right
    .byte walk_right_onspot_fast
    .byte end_m

gMovement_TheImpactSite_ResearchLab_ShipWalkDown8StepsAndHide:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte set_invisible
    .byte end_m
