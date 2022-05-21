//
// Created by 12254 on 2022/5/9.
//
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**
 * replace the '\n' with '\0'
 * @param str
 * @return str
 */
char* getLine(char* str) {
    int size = strlen(str);
    if((size != 0) && (str[size-1] == '\n')) {
        str[size-1] ='\0';
    }
    return str;
}

/**
 * writing the information of current game into the history.txt file
 * @param fp File pointer of the history.txt file
 * @param pb pointer of the Board structure
 * @return 0
 */
int history_save(FILE * fp, Board * pb){
    if (fp==NULL)
    {
        printf("Cannot find the file！\n");
        return -1;
    }
    else {
        fprintf(fp, "%d\n%d\n%d\n%d\n", pb->row, pb->col, pb->size_l, pb->delay_t);
        for(int i=0;i<pb->row; i++){
            for(int j=0;j<pb->col;j++){
                fprintf(fp,"%c", pb->boardArr[i][j]);
                if(j==pb->col-1){
                    fprintf(fp,"%c\n", pb->boardArr[i][j]);
                }
            }
        }
    }
    return 0;
}

/**
 * destroy the window, renderer and texture of SDL
 * @param window pointer of SDL_Window
 * @param render pointer of SDL_Renderer
 * @param texture pointer of SDL_texture
 * @return 0
 */
int Destroy(SDL_Window *window, SDL_Renderer *render, SDL_Texture *texture){
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    if (render)
    {
        SDL_DestroyRenderer(render);
    }
    if (texture)
    {
        SDL_DestroyTexture(texture);
    }
    return 0;
}

