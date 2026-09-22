<h1>Bemicro</h1>
A macropad designed for Hackclub's Stardance.<br>
This is a half macropad half beatmania controller inspired by the <a href="https://github.com/ianklug/bemini">Bemini</a>.<br>
This was started on the 12th, and is now concluding on the 21st. not too bad for a first hardware project, if i do say so myself.<br>
<img width="88" height="31" alt="image" src="https://github.com/user-attachments/assets/bc94f93b-829d-4696-a360-a68359bd6576" />
AI FREE!!
<br><br>
<h2>the board itself</h2>
This was probably the most fun part. <br>
The keys (including the encoder button) are wired in a matrix with diodes. Theres 4 Neopixel LEDs in a row, A rotary encoder, and a small OLED screen.
<br> Every pin of the Xiao RP2040 is used except for the 3.3v pin, which is unneeded here.<br>
<img width="935" height="810" alt="image" src="https://github.com/user-attachments/assets/233de5aa-caf7-4b86-be85-46242625183d" />
<br>
wiring it was also pretty fun, but not as much, it was a lot of doing and then redoing.<br>
i ended up with this masterfully (horribly) wired board<br>
<img width="858" height="585" alt="image" src="https://github.com/user-attachments/assets/8888ea27-230f-4021-acdd-8d5fad60362e" />
<br>
which looks like this in the 3d view<br>
<img width="992" height="690" alt="image" src="https://github.com/user-attachments/assets/12d83f01-1092-4167-bfd4-4b573068b7ef" />
<br><br>
<h2>The case!</h2>
its really bare bones. The Xiao, leds, keyswitches, and roatary encoder all need to be left (mostly) uncovered, so theres not much to really add a top over, so theres no top. for now.(if i feel its needed once its built, i will make one.)
<br><img width="699" height="431" alt="image" src="https://github.com/user-attachments/assets/6a5af3ac-eb84-4774-b105-8754b54bed96" /><br>
notably, the encoder knob (to mirror a beatmania controller) looks like a tunrtable... kinda. its that odd shape so that it can still be spin-able dj style, but also not cover the whole board.<br>
<img width="660" height="832" alt="image" src="https://github.com/user-attachments/assets/fdeff31d-d8e7-4466-8aaa-0a5e753a8012" /><br>
the board screws into the case (with the keyswitches facing "south" and the indent in the case facing "north"). the "turntable" friction fits over the D shaft of the rotary encoder.
<h2>qmk...</h2>
man qmk was a headache. it was quite the process to get rolling, mostly the guide was not at all for this usecase. but, with some perseverance and a bit of luck i figured it out.<br>
the default keybinds are as follows.<br>
  S,  D,  F,   ESC(on rotary encoder)<br>
Z,  X,  C,  V<br><br>
The rotary encoder itself types G on a counter clockwise turn and B on a clockwise turn <br>
holding the rotary encoder button also enables the led control layer, for as long as you hold it.<br>
the binds are <br>
       Hue up,    Sat up,    Val up,    ____(you should be holding this anyways)<br>
hue down,  sat down,   val down,    toggle underglow.<br>
there isnt yet a "macro"pad layer, but there will be in the future.<br><br>
<h1>bill of materials</h1>
1x Seeed Studio Xiao RP2040<br>
8x Through-hole 1N4148 diodes<br>
7x MX-style keyswitches<br>
1x EC11E rotary encoder (the kind with a switch)<br>
1x .91 inch OLED display<br>
7x MX keycaps (white in this case)<br>
2x M3x16mm screws<br>
2x M3x5x4mm heatset inserts.<br>
4x SK6812 MINI-E LEDs
