OUTSIDE TILE

section0: # 72DF40
  lockall
  if.flag.set.call 0x00C7 <section6>
  setvar temp1 1
  goto <section1>
  end

section1: # 72DF55
  pause 30
  showsprite 3
  if.compare.call temp1 == 0 <section2>
  if.compare.call temp1 == 1 <section3>
  pause 30
  msgbox.default <17D74A>
{
Ship: Welcome to PNF-404, 
traveller number 10,262,001!

May I please see your ID?
}
  closeonkeypress
  pause 10
  move.npc 3 <auto>
{
emote_exclamation_mark
}
  pause 10
  msgbox.default <auto>
{
Ship: Oh! Its you [player]! 
Olimar told me about you! 
...Infact follow me.
}
  closeonkeypress
  pause 30
  if.compare.call temp1 == 0 <section4>
  if.compare.call temp1 == 1 <section5>
  setdooropened 16 13
  doorchange
  applymovement 3 <auto>
{
walk_up
set_invisible
}
  move.player <auto>
{
walk_up
set_invisible
}
  setdoorclosed 16 13
  doorchange
  setflag 0x00C7
  setvar 0x4055 1
  clearflag 0x002B
  setvar 0x4050 1
  setflag 0x002C
  setflag 0x4001
  warp.xy 4 3 6 12
  waitstate
  releaseall
  end

section2: # 72DFED
  move.npc 3 <auto>
{
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
}
  return

section3: # 72DFF8
  move.npc 3 <auto>
{
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
}
  return

section4: # 72E003
  applymovement 3 <auto>
{
walk_down
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_in_place_fastest_up
}
  move.player <auto>
{
walk_down
walk_down
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
}
  return

section5: # 72E015
  applymovement 3 <auto>
{
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_up
walk_up
walk_in_place_fastest_up
}
  move.player <auto>
{
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_up
}
  return

section6: # 72E027
  releaseall
  end

IN LAB

section0: # 7B0AC0
  lockall
  textcolor 0
  move.npc 4 <7B07B2>
{
walk_up
walk_up
walk_up
walk_up
walk_up
walk_left
}
  hidesprite 4
  movesprite2 4 5 6
  spritebehave 4 FaceUp
  spritebehave 8 FaceUp
  clearflag 0x002B
  move.npc 8 <1A75E9>
{
walk_in_place_up
}
  move.player <7B07B9>
{
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
}
  clearflag 0x4001
  savesong mus_dummy
  fadedefault
  msgbox.default <7B0840>
{
Ship: Olimar! [player] is finally 
here. Can I do something else now?
}
  closeonkeypress
  pause 60
  move.npc 8 <7B098D>
{
walk_in_place_down
}
  msgbox.default <18DFBC>
{
Olimar: Oh [player]! Im so glad you
 accepted my invitation! Come come,
 I need to show you something.
}
  closeonkeypress
  pause 30
  msgbox.default <18DCB9>
{
Ship: Ahem, may I go now...?
}
  move.npc 8 <7B098F>
{
walk_in_place_right
}
  msgbox.default <7B0A00>
{
Olimar: This is the invention I 
mentioned in my message, my proudest 
accomplishment, the blooming onion!
}
  pause 60
  move.npc 4 <7B0991>
{
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
set_invisible
}
  move.npc 8 <auto>
{
walk_in_place_down
}
  msgbox.default <auto>
{
Olimar: I'm sure you know what these
contain right?
}
  pause 60
  msgbox.default <auto>
{
Olimar: I'll take your silence as a
yes! Now go ahead and pick one! I'd
like to formally introduce these
'Pikmon' to you.
}
  setvar 0x4055 2
  releaseall
  end
