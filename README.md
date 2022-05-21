# Game of Life 

## 1. URL of my Github:

[Skrux28/PP2 (github.com)](https://github.com/Skrux28/PP2)



## 2. Screenshot of my git commit history:





## 2. System overview

#### Project 2: the Game of Life has been chosen as the theme of this project. This  project will be implemented by the language of C and the following functions  are considered to be achieved in the final version of the project.



####  Instructions on how to run this program:

1. ##### Modify the initial file to custom window interface;

2. ##### Use command line arguments to choose different mode to initialize the game:

3. ```
   ./gameoflife game.txt(initial game file name) 1 or 2(model of initialization) 100(steps of evolution)
   Or ./gameoflife game.txt(initial game file name) 1 or 2(model of initialization)
   ```

   a. Mode 1(default): load the file to initialize the board of lives

   b. Mode 2: draw with the mouse by the users to initialize the board of lives

   c. Also, the users can choose the count of generation the game will stop at.

3. ##### During the evolution of lives, the program also provide with some visible buttons with functions:

   a. start-pause button(keyboard: space): users can choose to control the start and pause of the game;

   b. clean_board button(keyboard: '1'): users can clean the board and make the lives all dead;
   
   c. random_board button (keyboard: '2'): users can choose to let the board be a new random distribution;
   
   d. speed_up button (keyboard: 'up'): users can choose to boost the evolution of the game;
   
   e. speed_down button (keyboard: 'down'): users can choose to slow down  the evolution of the game;

5. ##### Finally, the users can choose to quit this game;