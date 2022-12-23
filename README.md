# RoboBand
 Arduino code for the Pequeña Banda Robótica.

 The repository includes several Arduino Projects:

 ## libraries:
 These files should be placed inside your *Arduino/libraries* folder, as they contain the base classes.

### RoboSong
Base template class for storing the songs. The template takes the following parameters:
* NB_LIMBS: number of lims of the corresponding robot.
* BITS_FOR_POS: number of bits dedicated in each byte to store the position.

### MusicianRobot
Base template class for managing the different robots. The template takes two parameters, defining the geometry of the robot:
* NB_HIT_JOINTS
* NB_POS_JOINTS

### RoboController
Manages the logic and the relationship between the song and the robot.

## Drums:
### DrumSong
Class for storing the scores for the drum. Includes a method for the creation of the following predefined patterns:
* SIMPLEST_RYTHM
* BASIC_RYTHM 1
* BASIC_RYTHM_WO_ACC 2
* CRESCENDO 3

### DrumRobot
Class for managing the behaviour of the drum robot.

## Glockenspiel:
### GlockSong
Class for storing the scores for the drum. Includes a method for the creation of some predefined patterns.

### GlockRobot
Class for managing the behaviour of the drum robot.

## Singers:
### SingSong
Class for storing the scores for the singers. Includes a method for the creation of some predefined patterns.

### SingRobot
Class for managing the behaviour of the singer robot.
