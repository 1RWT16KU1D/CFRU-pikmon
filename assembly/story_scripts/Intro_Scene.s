.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.global MapScript_IntroScene
.global End

MapScript_IntroScene:
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_IntroScene
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_IntroScene
    .byte MAP_SCRIPT_TERMIN

MapEntryScript_IntroScene:
    setvar StoryEventVar IntroSceneStart
    end

LevelScripts_IntroScene:
    levelscript StoryEventVar IntroSceneStart LevelScript_IntroScene_Greet
    levelscript StoryEventVar IntroScenePikmin LevelScript_IntroScene_Pikmin
    levelscript StoryEventVar PikminHelped LevelScript_IntroScene_PikminHelped
    levelscript StoryEventVar GotRescued LevelScript_IntroScene_GotRescued
    levelscript StoryEventVar PlaceIsSpecial LevelScript_IntroScene_PlaceIsSpecial
    levelscript StoryEventVar BloomingOnion LevelScript_IntroScene_BloomingOnion
    levelscript StoryEventVar ImpactSite LevelScript_IntroScene_ImpactSite
    levelscript StoryEventVar PikminBattles LevelScript_IntroScene_PikminBattles
    levelscript StoryEventVar WorldOfPikmin LevelScript_IntroScene_WorldOfPikmin
    levelscript StoryEventVar WarpToRoom LevelScript_IntroScene_RoomWarp
    .hword LEVEL_SCRIPT_TERMIN

LevelScript_IntroScene_Greet:
    lockall
    compare StoryEventVar WarpToRoom
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_Greet MSG_NORMAL
    
    setvar StoryEventVar IntroScenePikmin
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_Pikmin:
    compare StoryEventVar PikminHelped
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_Pikmin MSG_NORMAL

    setvar StoryEventVar PikminHelped
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PikminHelped:
    compare StoryEventVar GotRescued
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_PikminHelped MSG_NORMAL

    setvar StoryEventVar GotRescued
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_GotRescued:
    compare StoryEventVar PlaceIsSpecial
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_GotRescued MSG_NORMAL

    setvar StoryEventVar PlaceIsSpecial
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PlaceIsSpecial:
    compare StoryEventVar BloomingOnion
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_PlaceIsSpecial MSG_NORMAL

    setvar StoryEventVar BloomingOnion
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_BloomingOnion:
    compare StoryEventVar ImpactSite
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_BloomingOnion MSG_NORMAL

    setvar StoryEventVar ImpactSite
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_ImpactSite:
    compare StoryEventVar PikminBattles
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_ImpactSite MSG_NORMAL

    setvar StoryEventVar PikminBattles
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_PikminBattles:
    compare StoryEventVar WorldOfPikmin
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_PikminBattles MSG_NORMAL

    setvar StoryEventVar WorldOfPikmin
    setvar ShowImageVar 0x0
    callasm ShowImage
    waitstate
    end

LevelScript_IntroScene_WorldOfPikmin:
    compare StoryEventVar WarpToRoom
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_WorldOfPikmin MSG_NORMAL

    setvar StoryEventVar WarpToRoom
    end

LevelScript_IntroScene_RoomWarp:
    compare StoryEventVar WarpedToRoom
    if equal _goto End

    setvar StoryEventVar WarpedToRoom
    warp 4 1 0xFF 6 6
    end

End:
    end
