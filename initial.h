//
// Created by 12254 on 2022/5/14.
//

#ifndef PP2_INITIAL_H
#define PP2_INITIAL_H

/**
 * load the initial file information into the structure of the game board
 * @param fp pointer of the initial file
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int loadFile(FILE * fp, Board * pb);

/**
 * show the ttf_font to show the generation, count of alive cells and size of the board
 * @param ttf_font pointer to current ttf_font
 * @param render pointer of current renderer of the window
 * @param sum the string contains the text
 * @param x original position of x
 * @param y original position of y
 * @param win_w size of the width of window
 * @return 0
 */
int window_text(TTF_Font* ttf_font, SDL_Renderer *render, char *sum, int x, int y, int win_w);

/**
 * draw the function buttons on the window
 * @param render pointer of current renderer of the window
 * @param win_w size of the width of window
 * @param win_h size of the height of window
 * @param button_img the string to contain the path of img
 * @param index distinguish button function
 * @return 0
 */
int Put_button(SDL_Renderer *render, int win_w, int win_h, char *button_img, int index);
#endif //PP2_INITIAL_H
