//
// Created by 12254 on 2022/5/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**
 * load the initial file information into the structure of the game board
 * @param fp pointer of the initial file
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int loadFile(FILE * fp, Board * pb){
    if (fp==NULL)
    {
        printf("Cannot find the file！\n");
        return -1;
    }
    if(pb==NULL){
        printf("Point to structure is NULL\n");
        return -1;
    }
    else{
        char Row[1024];
        fgets(Row,1024, fp);
        strcpy(Row, getLine(Row));
        pb->row = atoi(Row);
        char Col[1024];
        fgets(Col,1024, fp);
        strcpy(Col, getLine(Col));
        pb->col = atoi(Col);
        char Size[1024];
        fgets(Size,1024, fp);
        strcpy(Size, getLine(Size));
        pb->size_l = atoi(Size);
        char Delay_t[1024];
        fgets(Delay_t, 1024, fp);
        strcpy(Delay_t, getLine(Delay_t));
        pb->delay_t = atoi(Delay_t);
        pb->count_alive = 0;
        if(pb->col*pb->size_l>660||pb->col*pb->size_l<200){
            printf("[The height of the window is out of range!(100-600)]\n[Please set the size of the window again]\n");
            return -1;
        }
        if(pb->row*pb->size_l>1200||pb->row*pb->size_l<400){
            printf("[The width of the window is out of range!(400-1200)]\n[Please set the size of the window again]\n");
            return -1;
        }
        if(pb->row>100){
            printf("[The row of the game is too large!]\n[Please choose the row again]\n");
            return -1;
        }
        if(pb->row<3){
            printf("[The row of the game is too small!]\n[Please choose the row again]\n");
            return -1;
        }
        if(pb->col>100){
            printf("[The column of the game is too large!]\n[Please choose the column again]\n");
            return -1;
        }
        if(pb->col<3){
            printf("[The column of the game is too small!]\n[Please choose the column again]\n");
            return -1;
        }
        if(pb->size_l<8 || pb->size_l>30){
            printf("[The size of each rect is out of range!(8-30)]\n[Please choose the size of the rect again]\n");
        }
        pb->boardArr = (char **)malloc(sizeof(char *) * pb->row);
        for(int i=0; i<pb->row; i++){
            pb->boardArr[i] = (char *)malloc(sizeof(char) * pb->col);
        }
        int i;
        int j;
        char temp[1024];
        for(i=0; i<pb->row;i++){
            fgets(temp,1024,fp);
            for(j=0; j<pb->col;j++){
                pb->boardArr[i][j] = temp[j];
            }
        }
    }return 0;
}

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
int window_text(TTF_Font* ttf_font, SDL_Renderer *render, char *sum, int x, int y, int win_w){
    SDL_Color color = {218,220,235,255};
    if(!ttf_font){
        printf("ttf_font loading failed!\n");
        return -1;
    }
    if(!render){
        printf("render loading failed!\n");
        return -1;
    }
    if (win_w>1200||win_w<400){
        printf("width of window is out of range!\n");
        return -1;
    }
    if(strcmp(sum, NULL)){
        printf("there is no words to show!\n");
    }
    SDL_Surface *text1_surface=TTF_RenderUTF8_Blended(ttf_font, sum ,color);
    // create the texture
    SDL_Texture *texture2=SDL_CreateTextureFromSurface(render,text1_surface);
    // Copy surface to renderer
    SDL_Rect text_rect;
    if(x==0){
        x = win_w/2 - text1_surface->w/2;
    }
    if (x==1){
        x = win_w - text1_surface->w-4;
    }
    if(x<0||y<0){
        printf("x,y out of range!\n");
        return -1;
    }
    text_rect.x=x;
    text_rect.y=y;
    text_rect.w=text1_surface->w;
    text_rect.h=text1_surface->h;
    SDL_RenderCopy(render,texture2,NULL,&text_rect);
    SDL_FreeSurface(text1_surface);
    SDL_DestroyTexture(texture2);
    return 0;
}

/**
 * draw the function buttons on the window
 * @param render pointer of current renderer of the window
 * @param win_w size of the width of window
 * @param win_h size of the height of window
 * @param button_img the string to contain the path of img
 * @param index distinguish button function
 * @return 0
 */
int Put_button(SDL_Renderer *render, int win_w, int win_h, char *button_img, int index){
    if (!render){
        printf("render loading failed!");
        return -1;
    }
    if (win_w>1200||win_w<400){
        printf("width of window is out of range!");
        return -1;
    }
    if (win_h>660||win_h<200){
        printf("height of window is out of range!");
        return -1;
    }
    if(index<0||index>5){
        printf("index out of range!");
        return -1;
    };
    if(button_img == NULL){
        printf("button_img loading failed!");
        return -1;
    }
    SDL_Surface *Btn_surf = NULL;
    SDL_Texture *Btn_text = NULL;
    SDL_Rect ButtRect;
    if (index == 0){
        ButtRect.x = win_w / 2 - 25;
        ButtRect.y = win_h - 60;
        ButtRect.w = 50;
        ButtRect.h = 50;
    }
    if (index == 1){
        ButtRect.x = win_w / 2 + 25 ;
        ButtRect.y = win_h - 55;
        ButtRect.w = 40;
        ButtRect.h = 40;
    }
    if (index == 2){
        ButtRect.x = win_w / 2 - 25 - 40;
        ButtRect.y = win_h - 55;
        ButtRect.w = 40;
        ButtRect.h = 40;
    }
    if (index == 3){
        ButtRect.x = 5;
        ButtRect.y = win_h - 50;
        ButtRect.w = 30;
        ButtRect.h = 30;
    }
    if (index == 4){
        ButtRect.x = win_w - 30 -5;
        ButtRect.y = win_h - 50;
        ButtRect.w = 30;
        ButtRect.h = 30;
    }
    if (index == 5){
        ButtRect.x = 60;
        ButtRect.y = win_h - 50;
        ButtRect.w = 30;
        ButtRect.h = 30;
    }
    Btn_surf= IMG_Load(button_img);
    Btn_text = SDL_CreateTextureFromSurface(render, Btn_surf );
    SDL_RenderCopy(render, Btn_text, NULL, &ButtRect);
    return 0;
}


