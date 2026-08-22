.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_TheImpactSite_ResearchLab_FemaleAide

EventScript_TheImpactSite_ResearchLab_FemaleAide:
    lock
    faceplayer

    msgbox gText_TheImpactSite_ResearchLab_FemaleAide MSG_KEEPOPEN
    closeonkeypress

    release
    end
