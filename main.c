#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "SDL/SDL2/SDL.h"
//int main() {
//    pBoard pBoard1 = malloc(sizeof (Board));
//    loadFile("game.txt", pBoard1);
//    printf("%d+%d\n", pBoard1->row, pBoard1->col);
//    for(int i=0; i<pBoard1->row; i++){
//        for(int j=0; j<pBoard1->col; j++){
//            printf("%c", pBoard1->boardArr[i][j]);
//        }
//        printf("\n");
//    }
//    runGame(pBoard1);
//}

int Destroy(SDL_Window *window, SDL_Renderer *render, SDL_Texture *texture){
    if (window) // 销毁window
    {
        SDL_DestroyWindow(window);
    }
    if (render) // 销毁渲染器
    {
        SDL_DestroyRenderer(render);
    }
    if (texture) // 销毁纹理
    {
        SDL_DestroyTexture(texture);
    }
}

pBoard Clean_board(pBoard pb){
    for(int i = 0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            pb->boardArr[i][j] = '0';
        }
    }
    return pb;
}

pBoard Random_board(pBoard pb){
    int count ;
    do{
        count = rand()%(pb->row*pb->col);
    }while(count>0);

    do{
        for(int i=0; i<pb->row; i++){
            for(int j=0; j<pb->col; j++){
                if( rand()%2 == 0){
                    pb->boardArr[i][j] = '1';
                    count--;
                }
                else{
                    pb->boardArr[i][j] = '0';
                }
            }
        }
    } while (count!=0);
}

int main(int argc, char* args[])
{
    pBoard pBoard1 = malloc(sizeof (Board));
    loadFile("game.txt", pBoard1);
    int sum=pBoard1->row*pBoard1->col;
    int rect_r=0;
    int rect_c=0;
    int p_rect_r,p_rect_c;
    SDL_Window *window = NULL; // 窗口
    SDL_Renderer *render = NULL;// 渲染器
    SDL_Texture *texture = NULL; // 纹理
    SDL_Event event; // 监听事件
    int quit = 0; // 是否退出
    int stop = 0;
    int win_w = pBoard1->row*pBoard1->size_l; // 窗口宽度
    int win_h = pBoard1->col*pBoard1->size_l; // 窗口高度
    int rect_w = pBoard1->size_l;
    int rect_h = pBoard1->size_l;
    int delay_time = 250;


    // 初始化
    SDL_Init(SDL_INIT_VIDEO);

    // 创建窗口，参数分别是窗口的标题，x,y,w,h，最后一个参数是一些flag(SDL_WINDOW_SHOWN表示将窗口显示出来)
    window = SDL_CreateWindow("The game of life",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,win_w,win_h,SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("创建窗口失败\n");
//        goto __EXIT;
        SDL_Quit();
    }

    // 窗口渲染
    // 创建渲染器
    render = SDL_CreateRenderer(window,-1,0);// 创建渲染器
    if (!render)
    {
        printf("创渲染器口失败\n");
//        goto __DESTROY;
        Destroy(window,render, texture);
    }
    // SDL_SetRenderDrawColor(render,255,0,0,255); // 设置窗口颜色，后面几个参数分别是RGBA
    // SDL_RenderClear(render); // 清空窗口
    // SDL_RenderPresent(render); // 将窗口展示出来

    // 创建纹理（第二个参数是指明像素格式，可以是YUV或RGB，第3个参数是指明纹理类型，可以是stream(流)或target(一般类型)）
    texture = SDL_CreateTexture(render,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,win_w,win_h);
    if (!texture)
    {
        printf("纹理创建失败!\n");
//        goto __DESTROY;
        Destroy(window,render,texture);
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
//                            printf("speed up");
                            break;
                        }
                        case SDLK_DOWN:{
//                            printf("speed down");
                            break;
                        }
                        case SDLK_SPACE:{
                            if(stop == 1){
                                stop = 0;
                            }
                            else{
                                stop = 1;
                            }
                            break;
                        }
                        case SDLK_c:{
                            pBoard1 = Clean_board(pBoard1);
                            break;
                        }
                    }
                    case SDL_KEYUP:{
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_UP:{
//                                printf("speed up");
                                if(delay_time<=10){
                                    delay_time = 10;
                                }
                                delay_time = delay_time-10;
                                break;
                            }
                            case SDLK_DOWN:{
//                                printf("speed down");
                                delay_time = delay_time+10;
                                break;
                            }
                            case SDLK_SPACE:{
                                break;
                            }
                            case SDLK_c:{
                                printf("cao!");
                                break;
                            }
                        }
                    }
                }
            }
        }


        SDL_SetRenderTarget(render,texture); // 改变渲染目标为纹理
        SDL_SetRenderDrawColor(render,255,255,255,255); // 设置纹理颜色(颜色为RGBA)
        SDL_RenderClear(render); // 清空渲染器

        for(rect_r=0;rect_r<pBoard1->row;rect_r++){
            p_rect_r = rect_r*rect_w;
            for(rect_c=0;rect_c<pBoard1->col;rect_c++){
                p_rect_c = rect_c*rect_h;
                SDL_Rect rect; // 绘制的矩形
                rect.x = p_rect_r;
                rect.y = p_rect_c;
                rect.w = rect_w;
                rect.h = rect_h;
//                SDL_SetRenderDrawColor(render,43,43,43,255);
//                SDL_RenderDrawRect(render,&rect); // 绘制矩形
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
        //                 恢复成默认渲染目标
        SDL_SetRenderTarget(render,NULL);
        // 将目标输出到显卡
        SDL_RenderCopy(render,texture,NULL,NULL);
        SDL_RenderPresent(render); // 显卡计算完后进行显示
        if(stop == 0){
            runGame(pBoard1);
        }
        SDL_Delay(delay_time);
    } while (!quit);

    Destroy(window,render,texture);

//    __DESTROY:
//    if (window) // 销毁window
//    {
//        SDL_DestroyWindow(window);
//    }
//    if (render) // 销毁渲染器
//    {
//        SDL_DestroyRenderer(render);
//    }
//    if (texture) // 销毁纹理
//    {
//        SDL_DestroyTexture(texture);
//    }


    __EXIT:
    // 退出
    SDL_Quit();
    history_save("history.txt", pBoard1);
    return 0;
}

