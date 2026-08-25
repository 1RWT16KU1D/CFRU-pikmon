.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"
.include "story_scripts/TheImpactSite/Research_Lab/event_defines.s"

.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Grass
.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Fire
.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Water

.global gMovement_TheImpactSite_ResearchLab_PlayerWalkUp

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Grass:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if greaterorequal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarFaceRight
    waitmovement WAIT_LATEST

    setvar VarTemp1 SPECIES_BULBORBLARVA
    setvar VarTemp2 LOCALID_BLOOMINGONION_FIRE
    setvar VarTemp3 SPECIES_FIERYBLOWLET
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Fire:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarFaceRight
    waitmovement WAIT_LATEST

    setvar VarTemp1 SPECIES_FIERYBLOWLET
    setvar VarTemp2 LOCALID_BLOOMINGONION_WATER
    setvar VarTemp3 SPECIES_WOLPOLE
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Water:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarFaceRight
    waitmovement WAIT_LATEST

    setvar VarTemp1 SPECIES_WOLPOLE
    setvar VarTemp2 LOCALID_BLOOMINGONION_GRASS
    setvar VarTemp3 SPECIES_BULBORBLARVA
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue:
    comparevartovalue VarTemp1 SPECIES_BULBORBLARVA
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithBulborbLarva
    comparevartovalue VarTemp1 SPECIES_FIERYBLOWLET
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithFieryBlowlet
    comparevartovalue VarTemp1 SPECIES_WOLPOLE
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithWolpole

EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithBulborbLarva:
    textcolor TEXTCOLOR_BLUE
    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_BloomingOnion_ChooseBulborbLarva MSG_YESNO
    compare LASTRESULT NO
    if TRUE _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_HidePokepicAndEnd
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_GivePikmonAndNickname

EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithFieryBlowlet:
    textcolor TEXTCOLOR_BLUE
    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_BloomingOnion_ChooseFieryBlowlet MSG_YESNO
    compare LASTRESULT NO
    if TRUE _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_HidePokepicAndEnd
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_GivePikmonAndNickname

EventScript_TheImpactSite_ResearchLab_BloomingOnion_ContinueWithWolpole:
    textcolor TEXTCOLOR_BLUE
    minimsgbox gText_Name_Olimar gText_TheImpactSite_ResearchLab_BloomingOnion_ChooseWolpole MSG_YESNO
    compare LASTRESULT NO
    if TRUE _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_HidePokepicAndEnd
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_GivePikmonAndNickname

EventScript_TheImpactSite_ResearchLab_BloomingOnion_GivePikmonAndNickname:
    hidepokepic
    hidesprite LASTTALKED

    textcolor TEXTCOLOR_BLACK
    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_PowerfulConnection MSG_KEEPOPEN
    setflag 0x828 @ Pikmon Option in Start Menu

    givepokemon VarTemp1 5 0 0 0 0
    bufferpokemon 0 VarTemp1
    preparemsg gText_TheImpactSite_ResearchLab_BloomingOnion_ReceivedPikmon
    waitmsg
    fanfare 0x13E
    waitfanfare

    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_NicknamePopup MSG_YESNO
    compare LASTRESULT YES
    if TRUE _call EventScript_TheImpactSite_ResearchLab_BloomingOnion_DoNickname

@ Intentional Fallthrough
EventScript_TheImpactSite_ResearchLab_BloomingOnion_OlimarChoosesPikmon:
    comparevartovalue VarTemp1 SPECIES_BULBORBLARVA
    if TRUE _call EventScript_TheImpactSite_ResearchLab_OlimarFieryBlowletMovement
    comparevartovalue VarTemp1 SPECIES_FIERYBLOWLET
    if TRUE _call EventScript_TheImpactSite_ResearchLab_OlimarWolpoleMovement
    comparevartovalue VarTemp1 SPECIES_WOLPOLE
    if TRUE _call EventScript_TheImpactSite_ResearchLab_OlimarBulborbLarvaMovement

    textcolor TEXTCOLOR_BLUE
    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_ExcellentChoice MSG_KEEPOPEN

    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarWalkUp
    waitmovement WAIT_LATEST
    hidesprite VarTemp2

    bufferpokemon 0 VarTemp3
    textcolor TEXTCOLOR_BLACK
    preparemsg gText_TheImpactSite_ResearchLab_BloomingOnion_OlimarReceivedPikmon
    waitmsg
    fanfare 0x13E @ Received Key Item Sound Effect
    waitfanfare

    setvar StoryEventVar1 ResearchLabChosenStarter
    release
    end

EventScript_TheImpactSite_ResearchLab_OlimarFieryBlowletMovement:
    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarChooseFieryBlowlet
    waitmovement WAIT_LATEST
    return

EventScript_TheImpactSite_ResearchLab_OlimarWolpoleMovement:
    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarChooseWolpole
    waitmovement WAIT_LATEST
    return

EventScript_TheImpactSite_ResearchLab_OlimarBulborbLarvaMovement:
    applymovement LOCALID_OLIMAR gMovement_TheImpactSite_ResearchLab_OlimarChooseBulborbLarva
    waitmovement WAIT_LATEST
    return

EventScript_TheImpactSite_ResearchLab_BloomingOnion_DoNickname:
    special 0x9E @ Nickname Screen
    waitstate
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_OlimarChoosesPikmon

EventScript_TheImpactSite_ResearchLab_BloomingOnion_HidePokepicAndEnd:
    hidepokepic
    release
    end

EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon:
    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 1
gMovement_TheImpactSite_ResearchLab_OlimarFaceRight:
    .byte look_right
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarChooseFieryBlowlet:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte look_up
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarChooseWolpole:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte look_up
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarChooseBulborbLarva:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte look_up
    .byte end_m

gMovement_TheImpactSite_ResearchLab_OlimarWalkUp:
gMovement_TheImpactSite_ResearchLab_PlayerWalkUp:
    .byte walk_up
    .byte end_m
