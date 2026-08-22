.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Grass
.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Fire
.global EventScript_TheImpactSite_ResearchLab_BloomingOnion_Water

@ Defines for this file
.equ BLOOMINGONION_GRASS, 5
.equ BLOOMINGONION_FIRE, 6
.equ BLOOMINGONION_WATER, 7
.equ OLIMAR, 8

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Grass:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if greaterorequal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    spriteface OLIMAR look_down
    setvar VarTemp1 SPECIES_BULBORBLARVA
    setvar VarTemp2 BLOOMINGONION_FIRE
    setvar VarTemp3 SPECIES_FIERYBLOWLET
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Fire:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    spriteface OLIMAR look_down
    setvar VarTemp1 SPECIES_FIERYBLOWLET
    setvar VarTemp2 BLOOMINGONION_WATER
    setvar VarTemp3 SPECIES_WOLPOLE
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_Water:
    lock

    comparevartovalue StoryEventVar1 ResearchLabChosenStarter
    if equal _goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon

    spriteface OLIMAR look_down
    setvar VarTemp1 SPECIES_WOLPOLE
    setvar VarTemp2 BLOOMINGONION_GRASS
    setvar VarTemp3 SPECIES_BULBORB
    showpokepic VarTemp1 10 3
    
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue

EventScript_TheImpactSite_ResearchLab_BloomingOnion_ShowStarterAndContinue:
    comparevartovalue VarTemp1 SPECIES_BULBORB
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
    goto EventScript_TheImpactSite_ResearchLab_BloomingOnion_OlimarChoosesPikmon

EventScript_TheImpactSite_ResearchLab_BloomingOnion_OlimarChoosesPikmon:
    textcolor TEXTCOLOR_BLUE
    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_ExcellentChoice MSG_KEEPOPEN
    hidesprite VarTemp2

    bufferpokemon 0 VarTemp3
    textcolor TEXTCOLOR_BLACK
    preparemsg gText_TheImpactSite_ResearchLab_BloomingOnion_OlimarReceivedPikmon
    waitmsg
    fanfare 0x13E
    waitfanfare

    setvar StoryEventVar1 ResearchLabChosenStarter
    release
    end

EventScript_TheImpactSite_ResearchLab_BloomingOnion_DoNickname:
    special 0x9E
    waitstate
    return

EventScript_TheImpactSite_ResearchLab_BloomingOnion_HidePokepicAndEnd:
    hidepokepic
    release
    end

EventScript_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon:
    msgbox gText_TheImpactSite_ResearchLab_BloomingOnion_LastPikmon MSG_KEEPOPEN
    release
    end
