//
// Created by 12254 on 2022/5/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "SDL/SDL2/SDL.h"

char* getLine(char* str) {
    int size = strlen(str);
    if((size != 0) && (str[size-1] == '\n')) {
        str[size-1] ='\0';
    }
    return str;
}

int history_save(char * filename, Board * pb){
    FILE *fp;
    if ((fp = fopen(filename,"w"))==NULL)
    {
        printf("Cannot find the file！\n");
        exit(-1);
    }
    else {
        fprintf(fp, "%d\n%d\n", pb->row, pb->col);
        for(int i=0;i<pb->row; i++){
            for(int j=0;j<pb->col;j++){
                fprintf(fp,"%c", pb->boardArr[i][j]);
                if(j==pb->col-1){
                    fprintf(fp,"%c\n", pb->boardArr[i][j]);
                }
            }
        }
    }
    return 1;
}

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
}

