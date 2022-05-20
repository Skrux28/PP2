//
// Created by 12254 on 2022/5/9.
//
#include "SDL/SDL2/SDL.h"
#include "SDL/SDL2/SDL_ttf.h"
#include "SDL/SDL2/SDL_image.h"

typedef struct _Board{
    int row;
    int col;
    int size_l;
    int delay_t;
    int count_alive;
    char **boardArr;
}Board, *pBoard;

int loadFile(char* filename, Board * pb);

int history_save(char * filename, Board * pb);

char* getLine(char* str);

int Destroy(SDL_Window *window, SDL_Renderer *render, SDL_Texture *texture);
