.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_TheImpactSite_ResearchLab_MaleAide_2

EventScript_TheImpactSite_ResearchLab_MaleAide_2:
    lock
    faceplayer

    msgbox gText_TheImpactSite_ResearchLab_MaleAide_2 MSG_KEEPOPEN
    closeonkeypress

    release
    end
