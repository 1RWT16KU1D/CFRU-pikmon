.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.global MapScript_IntroScene
.global End

@@ Defines for this file
.equ OLIMAR, 1

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MapScript_IntroScene:
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_IntroScene
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_IntroScene
    .byte MAP_SCRIPT_TERMIN

MapEntryScript_IntroScene:
    setvar StoryEventVar1 IntroSceneStart
    end

LevelScripts_IntroScene:
    levelscript StoryEventVar1 IntroSceneStart LevelScript_IntroScene_Greet
    levelscript StoryEventVar1 IntroScenePikmin LevelScript_IntroScene_Pikmin
    levelscript StoryEventVar1 IntroScenePikminHelped LevelScript_IntroScene_PikminHelped
    levelscript StoryEventVar1 IntroSceneGotRescued LevelScript_IntroScene_GotRescued
    levelscript StoryEventVar1 IntroScenePlaceIsSpecial LevelScript_IntroScene_PlaceIsSpecial
    levelscript StoryEventVar1 IntroSceneBloomingOnion LevelScript_IntroScene_BloomingOnion
    levelscript StoryEventVar1 IntroSceneImpactSite LevelScript_IntroScene_ImpactSite
    levelscript StoryEventVar1 IntroScenePikminBattles LevelScript_IntroScene_PikminBattles
    levelscript StoryEventVar1 IntroSceneWorldOfPikmin LevelScript_IntroScene_WorldOfPikmin
    levelscript StoryEventVar1 IntroSceneWarpToRoom LevelScript_IntroScene_RoomWarp
    .hword LEVEL_SCRIPT_TERMIN

LevelScript_IntroScene_Greet:
    lockall
    movecamera gMovement_IntroScene_OlimarMoveCamera
    msgboxtransparent gText_IntroScene_3Dots MSG_NORMAL
    pause 10
    applymovement OLIMAR gMovement_IntroScene_OlimarMoveLeft10StepsLookDown
    waitmovement OLIMAR
    pause 10
    compare StoryEventVar1 IntroSceneWarpToRoom
    if equal _goto End

    msgboxtransparent gText_IntroScene_Greet MSG_NORMAL
    
    setvar StoryEventVar1 IntroScenePikmin
    setvar ShowImageVar VAR_IMAGE_1
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_Pikmin:
    compare StoryEventVar1 IntroScenePikminHelped
    if equal _goto End

    applymovement OLIMAR gMovement_IntroScene_OlimarMoveLeft
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_Pikmin MSG_NORMAL

    applymovement OLIMAR gMovement_IntroScene_OlimarLookDown
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_Pikmin2 MSG_NORMAL

    setvar StoryEventVar1 IntroScenePikminHelped
    setvar ShowImageVar VAR_IMAGE_2
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PikminHelped:
    compare StoryEventVar1 IntroSceneGotRescued
    if equal _goto End

    applymovement OLIMAR gMovement_IntroScene_OlimarMoveRight3StepsLookDown
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_PikminHelped MSG_NORMAL

    setvar StoryEventVar1 IntroSceneGotRescued
    setvar ShowImageVar VAR_IMAGE_3
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_GotRescued:
    compare StoryEventVar1 IntroScenePlaceIsSpecial
    if equal _goto End

    msgboxtransparent gText_IntroScene_GotRescued MSG_NORMAL

    setvar StoryEventVar1 IntroScenePlaceIsSpecial
    setvar ShowImageVar VAR_IMAGE_4
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PlaceIsSpecial:
    compare StoryEventVar1 IntroSceneBloomingOnion
    if equal _goto End

    applymovement OLIMAR gMovement_IntroScene_OlimarMoveLeft
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_PlaceIsSpecial MSG_NORMAL

    applymovement OLIMAR gMovement_IntroScene_OlimarMoveLeftLookDown
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_PlaceIsSpecial2 MSG_NORMAL

    setvar StoryEventVar1 IntroSceneBloomingOnion
    setvar ShowImageVar VAR_IMAGE_5
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_BloomingOnion:
    compare StoryEventVar1 IntroSceneImpactSite
    if equal _goto End

    msgboxtransparent gText_IntroScene_BloomingOnion MSG_NORMAL

    setvar StoryEventVar1 IntroSceneImpactSite
    setvar ShowImageVar VAR_IMAGE_6
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_ImpactSite:
    compare StoryEventVar1 IntroScenePikminBattles
    if equal _goto End

    msgboxtransparent gText_IntroScene_ImpactSite MSG_NORMAL

    setvar StoryEventVar1 IntroScenePikminBattles
    setvar ShowImageVar VAR_IMAGE_7
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PikminBattles:
    compare StoryEventVar1 IntroSceneWorldOfPikmin
    if equal _goto End

    applymovement OLIMAR gMovement_IntroScene_OlimarWalkDown
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_PikminBattles MSG_NORMAL

    setvar StoryEventVar1 IntroSceneWorldOfPikmin
    setvar ShowImageVar VAR_IMAGE_8
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_WorldOfPikmin:
    compare StoryEventVar1 IntroSceneWarpToRoom
    if equal _goto End

    applymovement OLIMAR gMovement_IntroScene_OlimarWalkUp
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_WorldOfPikmin MSG_NORMAL

    applymovement OLIMAR gMovement_IntroScene_OlimarLookDown
    waitmovement OLIMAR
    msgboxtransparent gText_IntroScene_WorldOfPikmin2 MSG_NORMAL

    setvar StoryEventVar1 IntroSceneWarpToRoom
    end

LevelScript_IntroScene_RoomWarp:
    compare StoryEventVar1 IntroSceneWarpedToRoom
    if equal _goto End

    playbgm 278 @Titlescreen
    setvar ShowImageVar VAR_IMAGE_9
    callasm ShowImage
    hidesprite OLIMAR
    waitstate

    callasm DoNamePlayer
    waitstate

    setvar StoryEventVar1 IntroSceneWarpedToRoom
    warp 4 1 0xFF 6 6 @ Player's Room
    end

End:
    end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 1

gMovement_IntroScene_OlimarMoveCamera:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

gMovement_IntroScene_OlimarMoveLeft10StepsLookDown:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte look_down
    .byte end_m

gMovement_IntroScene_OlimarMoveLeft:
    .byte walk_left
    .byte end_m

gMovement_IntroScene_OlimarLookDown:
    .byte look_down
    .byte end_m

gMovement_IntroScene_OlimarMoveRight3StepsLookDown:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte look_down
    .byte end_m

gMovement_IntroScene_OlimarMoveLeftLookDown:
    .byte walk_left
    .byte look_down
    .byte end_m

gMovement_IntroScene_OlimarWalkDown:
    .byte walk_down
    .byte end_m

gMovement_IntroScene_OlimarWalkUp:
    .byte walk_up
    .byte end_m
