#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "initial.h"

int main(int argc, char* args[])
{
    char gameFile[1024];
    char steps_c[1024];
    int steps = 0;
    int step_now = 0;
    char step_now_c[1024];
    char count_alive_c[1024];
    char row_c[1024];
    char col_c[1024];
    char models[1024];
    if(argc == 3){
        printf("Error\nExpected user: ./gameoflife game.txt(initial game file name) 100(steps of evolution)\n 1 or 2(model of initialization)");
        return  0;
    }
    else{
        strcpy(gameFile, args[0]);
        strcpy(steps_c, args[1]);
        steps = atoi(steps_c);
        strcpy(models, args[2]);
        printf("%s %s %s\n", args[0], args[1], args[2]);
    }

    pBoard pBoard1 = malloc(sizeof (Board));
    loadFile("game.txt", pBoard1);
//    loadFile(gameFile, pBoard1);
    int rect_r=0;
    int rect_c=0;
    int p_rect_r,p_rect_c;
    SDL_Window *window = NULL; // 窗口
    SDL_Renderer *render = NULL;// 渲染器
    SDL_Texture *texture = NULL; // 纹理
    SDL_Event event; // 监听事件
    int quit = 0; // 是否退出
    int stop = 0;
    int over = 0;
    int edit = 0;
    int win_w = pBoard1->row*pBoard1->size_l; // 窗口宽度
    int win_h = pBoard1->col*pBoard1->size_l +30 + 70; // 窗口高度
    int rect_w = pBoard1->size_l;
    int rect_h = pBoard1->size_l;
    int delay_time = 250;


    // 初始化
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);

    // 创建窗口，参数分别是窗口的标题，x,y,w,h，最后一个参数是一些flag(SDL_WINDOW_SHOWN表示将窗口显示出来)
    window = SDL_CreateWindow("The game of life",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,win_w,win_h,SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Create windows failed!\n");
        SDL_Quit();
    }

    // 窗口渲染
    // 创建渲染器
    render = SDL_CreateRenderer(window,-1,0);// 创建渲染器
    if (!render)
    {
        printf("Create render failed!\n");
        Destroy(window,render, texture);
    }

    // 创建纹理（第二个参数是指明像素格式，可以是YUV或RGB，第3个参数是指明纹理类型，可以是stream(流)或target(一般类型)）
    texture = SDL_CreateTexture(render,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,win_w,win_h);
    if (!texture)
    {
        printf("Create texture failed!\n");
        Destroy(window,render,texture);
    }

    TTF_Font * ttf_font = TTF_OpenFont("font/Roboto-Light.ttf", 15);
    if (! ttf_font){
        printf("Create ttf font failed!\n");
        TTF_CloseFont(ttf_font);
        TTF_Quit();
    }






    // SDL_Delay(10000);
    // 监听退出事件

    do {
        while (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:{
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:{
                            if(delay_time<=10){
                                delay_time = 10;
                            }
                            delay_time = delay_time-10;
                            break;
                        }
                        case SDLK_DOWN:{
                            delay_time = delay_time+10;
                            break;
                        }
                        case SDLK_SPACE:{
                            if(stop == 1){
                                stop = 0;
                            }
                            else{
                                stop = 1;
                            }
                            over = 0;
                            break;
                        }
                        case SDLK_1:{
                            Clean_board(pBoard1);
                            step_now = 0;
                            break;
                        }
                        case SDLK_2:{
                            Random_board(pBoard1);
                            break;
                        }
                        case SDLK_3:{
                            if (edit == 0){
                                edit = 1;
                            }
                            else{
                                edit = 0;
                            }
                            break;
                        }
                    }
                }
                case SDL_MOUSEBUTTONDOWN:{
                    int mouse_x = event.button.x/rect_w;
                    int mouse_y = (event.button.y-30)/rect_h;
                    if(event.button.button == SDL_BUTTON_LEFT && edit == 1){
                        pBoard1->boardArr[mouse_x][mouse_y] = '1';
                    }
                    if(event.button.button == SDL_BUTTON_RIGHT && edit == 1){
                        pBoard1->boardArr[mouse_x][mouse_y] = '0';
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2-25&&event.button.x<=win_w/2+25
                    &&event.button.y>=win_h-60&&event.button.y<=win_h - 15){
                        if(stop == 1){
                            stop = 0;
                        }
                        else{
                            stop = 1;
                        }
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2+25&&event.button.x<=win_w/2+65
                        &&event.button.y>=win_h-55&&event.button.y<=win_h-15){
                        if(delay_time<=10){
                            delay_time = 10;
                        }
                        delay_time = delay_time-10;
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2-25-40&&event.button.x<=win_w/2-25
                       &&event.button.y>=win_h-55&&event.button.y<=win_h-15){
                        delay_time = delay_time + 10;
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=5&&event.button.x<=35
                       &&event.button.y>=win_h-50&&event.button.y<=win_h-20){
                        Random_board(pBoard1);
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w-30-5&&event.button.x<=win_w-5
                       &&event.button.y>=win_h-50&&event.button.y<=win_h-20){
                        Clean_board(pBoard1);
                        step_now = 0;
                    }
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=60&&event.button.x<=90
                       &&event.button.y>=win_h-50&&event.button.y<=win_h-20){
                        if (edit == 0){
                            edit = 1;
                        }
                        else{
                            edit = 0;
                        }
                    }
                }
                case SDL_MOUSEMOTION:{
                    int mouse_x = event.button.x/rect_w;
                    int mouse_y = (event.button.y-30)/rect_h;
                    if(event.button.button == SDL_BUTTON_LEFT && edit == 1){
                        printf("oh yeah\n");
                        pBoard1 -> boardArr[mouse_x][mouse_y] = '1';
                    }
                    if(event.button.button == SDL_BUTTON_X1 && edit == 1){
                        printf("oh np\n");
                        pBoard1 -> boardArr[mouse_x][mouse_y] = '0';
                    }
                }
            }
        }


        SDL_SetRenderTarget(render,texture); // 改变渲染目标为纹理
        SDL_SetRenderDrawColor(render,255,255,255,255); // 设置纹理颜色(颜色为RGBA)
        SDL_RenderClear(render); //

        SDL_SetRenderDrawColor(render,43,43,43,255);
        SDL_Rect background;
        background.x = 0;
        background.y = 0;
        background.w = win_w;
        background.h = win_h;
        SDL_RenderFillRect(render, &background);

        sprintf(step_now_c,"%d",step_now);
        char *sum = (char*)malloc(strlen("Generation: ") + strlen(step_now_c));
        sprintf(sum,"%s%s","Generation: ",step_now_c);
        window_text(ttf_font, render, sum, 2, 6, 0);
        pBoard1->count_alive = 0;
        Count_alive(pBoard1);
        char *sum1 = (char*)malloc(strlen("Generation: ") + strlen(step_now_c));
        sprintf(count_alive_c, "%d",pBoard1->count_alive );
        sprintf(sum1,"%s%s","Alive: ",count_alive_c);
        window_text(ttf_font, render, sum1, 0, 6,win_w);
        char *sum2 = (char*)malloc(strlen("Generation: ") + strlen(step_now_c));
        sprintf(row_c, "%d",pBoard1->row);
        sprintf(col_c, "%d",pBoard1->col);
        sprintf(sum2,"%s%s%s%s","Size: ",row_c,"X", col_c);
        window_text(ttf_font, render, sum2, 1, 6,win_w);
        for(rect_r=0;rect_r<pBoard1->row;rect_r++){
            p_rect_r = rect_r*rect_w;
            for(rect_c=0;rect_c<pBoard1->col;rect_c++){
                p_rect_c = rect_c*rect_h;
                SDL_Rect rect; // 绘制的矩形
                rect.x = p_rect_r;
                rect.y = p_rect_c+30;
                rect.w = rect_w;
                rect.h = rect_h;
                if(pBoard1->boardArr[rect_r][rect_c] == '1'){
                    SDL_SetRenderDrawColor(render,43,43,43,255);
                }
                else{
                    SDL_SetRenderDrawColor(render,218,220,235,255);
                }
                SDL_RenderFillRect(render,&rect); // 填充

                SDL_SetRenderDrawColor(render,43,43,43,255);
                SDL_RenderDrawRect(render,&rect); // 绘制矩形
            }
        }
        if(stop == 0){
            char* button_img = {"img/begin.png"};
            Put_button(render, win_w, win_h, button_img, 0);
        } else{
            char* button_img = {"img/pause.png"};
            Put_button(render, win_w, win_h, button_img, 0);
        }
        char* button_img1 = {"img/speed_up.png"};
        Put_button(render, win_w, win_h, button_img1, 1);
        char* button_img2 = {"img/speed_down.png"};
        Put_button(render, win_w, win_h, button_img2, 2);
        char* button_img3 = {"img/random.png"};
        Put_button(render, win_w, win_h, button_img3, 3);
        char* button_img4 = {"img/clean.png"};
        Put_button(render, win_w, win_h, button_img4, 4);
        if(edit==0){
            char* button_img5 = {"img/edit.png"};
            Put_button(render, win_w, win_h, button_img5, 5);
        }
        else{
            char* button_img5 = {"img/edit_active.png"};
            Put_button(render, win_w, win_h, button_img5, 5);
        }

        // 恢复成默认渲染目标
        SDL_SetRenderTarget(render,NULL);
        // 将目标输出到显卡
        SDL_RenderCopy(render,texture,NULL,NULL);
        SDL_RenderPresent(render); // 显卡计算完后进行显示
        if(stop == 0){
            runGame(pBoard1);
            step_now++;
            SDL_Delay(delay_time);
        }
//        if (step_now == steps){
//            over = 1;
//        }
    } while (!quit);

    Destroy(window,render,texture);

    // 退出
    SDL_Quit();
    history_save("history.txt", pBoard1);
    return 0;
}

