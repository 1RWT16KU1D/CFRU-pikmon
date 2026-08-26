.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "story_scripts/TheImpactSite/Research_Lab/event_defines.s"

.global TileScript_TheImpactSite_ResearchLab_StarterNotChosen

TileScript_TheImpactSite_ResearchLab_StarterNotChosen:
    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if lessthan _goto TileScript_TheImpactSite_ResearchLab_StarterNotChosen_StopPlayer

    release
    end

TileScript_TheImpactSite_ResearchLab_StarterNotChosen_StopPlayer:
    lock

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarLookDown
    waitmovement WAIT_LATEST

    textcolor TEXTCOLOR_BLUE
    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_OlimarStarterNotChosen MSG_KEEPOPEN
    closeonkeypress

    applymovement PLAYER gMovement_TheImpactSite_ResearchLab_PlayerWalkUp
    waitmovement WAIT_LATEST

    release
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 1
gMovement_TheImpactSite_ResearchLab_OlimarLookDown:
    .byte look_down
    .byte end_m
