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
    end

LevelScript_IntroScene_Pikmin:
    compare StoryEventVar PikminHelped
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_Pikmin MSG_NORMAL

    setvar StoryEventVar PikminHelped
    setvar ShowImageVar 0x0
    callasm ShowImage
    end

LevelScript_IntroScene_PikminHelped:
    compare StoryEventVar WarpToRoom
    if equal _goto End

    textcolor TEXTCOLOR_BLUE
    msgbox gText_IntroScene_PikminHelped MSG_NORMAL

    setvar StoryEventVar WarpToRoom
    setvar ShowImageVar 0x0
    callasm ShowImage
    end

LevelScript_IntroScene_RoomWarp:
    compare StoryEventVar WarpedToRoom
    if equal _goto End

    setvar StoryEventVar WarpedToRoom
    warp 4 1 0xFF 6 6
    end

End:
    end
