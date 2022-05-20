//
// Created by 12254 on 2022/5/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int loadFile(char* filename, Board * pb){
    FILE *fp;
    if ((fp = fopen(filename,"r"))==NULL)
    {
        printf("Cannot find the file！\n");
        exit(-1);
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
        return 1;
    }
}

int window_text(TTF_Font* ttf_font, SDL_Renderer *render, char *sum, int x, int y, int win_w){
    SDL_Color color = {218,220,235,255};
    SDL_Surface *text1_surface=TTF_RenderUTF8_Blended(ttf_font,"hello,world!",color);
    /*创建纹理*/
    SDL_Texture * texture2=SDL_CreateTextureFromSurface(render,text1_surface);
    TTF_SetFontStyle(ttf_font,TTF_STYLE_BOLD);
    /*创建字体显示表面*/
    text1_surface=TTF_RenderUTF8_Blended(ttf_font, sum ,color);
    /*创建纹理*/
    texture2=SDL_CreateTextureFromSurface(render,text1_surface);
    /*将surface拷贝到渲染器*/
    SDL_Rect dstrect;
    if(x==0){
        x = win_w/2 - text1_surface->w/2;
    }
    if (x==1){
        x = win_w - text1_surface->w-4;
    }
    dstrect.x=x;/*显示的起始位置*/
    dstrect.y=y;/*显示的起始位置*/
    dstrect.w=text1_surface->w;/*显示的宽度*/
    dstrect.h=text1_surface->h;/*显示的高度*/
    SDL_RenderCopy(render,texture2,NULL,&dstrect);
    SDL_FreeSurface(text1_surface);/*释放surface*/
    SDL_DestroyTexture(texture2);/*释放纹理*/
    return 0;
}

int Put_button(SDL_Renderer *render, int win_w, int win_h, char *button_img, int index){
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
}


