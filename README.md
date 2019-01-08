# musicVisualizer
A music visualiser using openFrameworks which generates visuals for the song "White Winter Hymnal" by Fleet Foxes.

To run the project, the files in their current folders must be placed inside an OpenFrameworks project folder, as created through the project generator in OF. However, the source code in the src folder is written in C++ and is accessible to anyone who is interested in looking through the  visual simulations.

The visuals of the project have two main scenes: a snowy scene with custom snowflake particle movement for when the song is quieter, and a vibrant summer scene with strawberry plants growing when the song is building up to its climax. The sun changes size with the first tone
of the song, and then continues to change as the song plays but not as consistently as in the first section of the song. The strawberries 
appear on the beat of the drum. I built my own particle system to mimic snowflakes, which is shown when the song is quiet and when it is paused.

The playback of the song can be toggled on and off by pressing the spacebar, and the debug controls can be turned on and off with the D key. 
Lastly, the velocity of the snowflakes shifts with the volume of the vocals at the end of the song.

In total, I track:
-drums
-chorus vocals at the beginning
-solo vocals at the end
-volume for triggering snow
-play/pause
