//
// Created by 12254 on 2022/5/9.
//
#include <stdio.h>
#include "SDL/SDL2/SDL.h"
#include "SDL/SDL2/SDL_ttf.h"
#include "SDL/SDL2/SDL_image.h"

/**
 * structure to store the board and relative information
 */
typedef struct _Board{
    int row;
    int col;
    int size_l;
    int delay_t;
    int count_alive;
    char **boardArr;
}Board, *pBoard;

/**
 * writing the information of current game into the history.txt file
 * @param fp File pointer of the history.txt file
 * @param pb pointer of the Board structure
 * @return 0
 */
int history_save(FILE * fp, Board * pb);

/**
 * replace the '\n' with '\0'
 * @param str
 * @return str
 */
char* getLine(char* str);

/**
 * destroy the window, renderer and texture of SDL
 * @param window pointer of SDL_Window
 * @param render pointer of SDL_Renderer
 * @param texture pointer of SDL_texture
 * @return 0
 */
int Destroy(SDL_Window *window, SDL_Renderer *render, SDL_Texture *texture);
