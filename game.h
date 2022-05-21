//
// Created by 12254 on 2022/5/6.
//
#include "utility.h"
#ifndef PP2_GAME_H
#define PP2_GAME_H

/**
 * the function to run the whole precess of the game
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int runGame(Board * pb);

/**
 * clean the board to let every cells die
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Clean_board(pBoard pb);

/**
 * make a new random distribution to display the board
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Random_board(pBoard pb);

/**
 * count the current count of alive cells of the board
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Count_alive(pBoard pb);
#endif //PP2_GAME_H
