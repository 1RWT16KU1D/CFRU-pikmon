.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "story_scripts/TheImpactSite/Research_Lab/event_defines.s"

.global EventScript_TheImpactSite_ResearchLab_Olimar

EventScript_TheImpactSite_ResearchLab_Olimar:
    lockall
    faceplayer

    comparevartovalue StoryEventVar1 ResearchLabToChooseStarter
    if equal _goto EventScript_TheImpactSite_ResearchLab_Olimar_ChooseStarterText

    releaseall
    end

EventScript_TheImpactSite_ResearchLab_Olimar_ChooseStarterText:
    msgbox gText_TheImpactSite_ResearchLab_OlimarPleaseChooseStarter MSG_NORMAL
    releaseall
    end
