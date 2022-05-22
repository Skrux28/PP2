#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "initial.h"

// run the whole process of the game
// show the window with SDL2
int main(int argc, char* args[])
{
    // Initialize the variables
    char gameFile[1024];
    char steps_c[1024];
    int steps = 0;
    int step_now = 0;
    char step_now_c[1024];
    char count_alive_c[1024];
    char row_c[1024];
    char col_c[1024];
    char models[1024];
    char *sum = (char*)malloc(1024);
    char *sum1 = (char*)malloc(1024);
    char *sum2 = (char*)malloc(1024);
    int rect_r=0;
    int rect_c=0;
    int p_rect_r,p_rect_c;
    // pointer to the window
    SDL_Window *window = NULL;
    // pointer to the renderer
    SDL_Renderer *render = NULL;
    // pointer to the texture
    SDL_Texture *texture = NULL;
    // Listen for an event
    SDL_Event event;
    // Recording pause state
    int quit = 0;
    int stop = 0;
    int edit = 0;
    // create the pointer of the board structure
    pBoard pBoard1 = malloc(sizeof (Board));
    // check the command line parameter
    if(argc != 4 && argc!=3){
        printf("Error\nExpected user: ./gameoflife game.txt(initial game file name) 1 or 2(model of initialization) 100(steps of evolution)\n"
               "Or ./gameoflife game.txt(initial game file name) 1 or 2(model of initialization)\n"
               );
        return  -1;
    }
    else{
        // Assigns command line arguments to variables
        if(argc == 4){
            strcpy(gameFile, args[1]);
            strcpy(steps_c, args[3]);
            steps = atoi(steps_c);
            strcpy(models, args[2]);
            printf("%s %s %s\n", args[1], args[2], args[3]);
            FILE * game_fp;
            game_fp = fopen(gameFile,"r");
            // check whether the loading of the initial file is successful
            // if not return -1
            if (loadFile(game_fp, pBoard1) != 0){
                printf("Load the initial file failed!\n");
                return -1;
            }
            if(strcmp(models, "1")==0){
                printf("Reading the board from the file...");
            }
            if(strcmp(models, "2")==0){
                printf("Initialize the boarding...");
                Clean_board(pBoard1);
                stop = 1;
                edit = 1;
            }
            else{
                printf("The model you choose is wrong\n using initial file to begin");
            }
        }
        if (argc == 3){
            strcpy(gameFile, args[1]);
            steps = 0;
            strcpy(models, args[2]);
            printf("%s %s\n", args[1], args[2]);
            FILE * game_fp;
            game_fp = fopen(gameFile,"r");
            // check whether the loading of the initial file is successful
            // if not return -1
            if (loadFile(game_fp, pBoard1) != 0){
                printf("Load the initial file failed!\n");
                return -1;
            }
            if(strcmp(models, "1")==0){
                printf("Reading the board from the file...");
            }
            if(strcmp(models, "2")==0){
                printf("Initialize the boarding...");
                Clean_board(pBoard1);
                stop = 1;
                edit = 1;
            }
            else{
                printf("The model you choose is wrong\n using initial file to begin");
            }
        }
    }

    // initialize the size of the window
    int win_w = pBoard1->row*pBoard1->size_l;
    int win_h = pBoard1->col*pBoard1->size_l +30 + 70;
    int rect_w = pBoard1->size_l;
    int rect_h = pBoard1->size_l;
    int delay_time = 250;


    // initialize the SDL
    SDL_Init(SDL_INIT_VIDEO);
    // initialize the SDL_ttf
    TTF_Init();
    // initialize the SDL_Img
    IMG_Init(IMG_INIT_PNG);

    // create the window
    window = SDL_CreateWindow("The game of life",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,win_w,win_h,SDL_WINDOW_SHOWN);
    // check whether the window created successfully
    // if not quit the game
    if (!window)
    {
        printf("Create windows failed!\n");
        SDL_Quit();
    }

    // build the renderer
    render = SDL_CreateRenderer(window,-1,0);
    // check whether the renderer created successfully
    // if not quit the game
    if (!render)
    {
        printf("Create render failed!\n");
        Destroy(window,render, texture);
    }

    // create the texture
    texture = SDL_CreateTexture(render,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,win_w,win_h);
    // check whether the renderer created successfully
    // if not quit the game
    if (!texture)
    {
        printf("Create texture failed!\n");
        Destroy(window,render,texture);
    }
    // build the ttf_font pointer and load the .ttf file
    TTF_Font * ttf_font = TTF_OpenFont("font/Roboto-Light.ttf", 15);
    // check whether the ttf_font created successfully
    // if not quit the TTF
    if (! ttf_font){
        printf("Create ttf font failed!\n");
        TTF_CloseFont(ttf_font);
        TTF_Quit();
    }
    // the whole process of the game
    do {
        // Mapping user Operations
        while (SDL_PollEvent(&event)){
            // switch the event
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                // keyboard operations
                case SDL_KEYDOWN:{
                    switch(event.key.keysym.sym)
                    {
                        // speed up when up is pressed
                        case SDLK_UP:{
                            if(delay_time<=10){
                                delay_time = 10;
                            }
                            delay_time = delay_time-10;
                            break;
                        }
                        // speed down when down is pressed
                        case SDLK_DOWN:{
                            delay_time = delay_time+10;
                            break;
                        }
                        // pause the game when space is pressed
                        case SDLK_SPACE:{
                            if(stop == 1){
                                stop = 0;
                            }
                            else{
                                stop = 1;
                            }
                            break;
                        }
                        // clean the game board when '1' is pressed
                        case SDLK_1:{
                            Clean_board(pBoard1);
                            step_now = 0;
                            break;
                        }
                        // display a random board when '2' is pressed
                        case SDLK_2:{
                            Random_board(pBoard1);
                            step_now = 0;
                            break;
                        }
                        // let the users edit the board with mouse
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
                // mouse operations
                case SDL_MOUSEBUTTONDOWN:{
                    // get which rect to change the states
                    int mouse_x = event.button.x/rect_w;
                    int mouse_y = (event.button.y-30)/rect_h;
                    if(event.button.button == SDL_BUTTON_LEFT && edit == 1){
                        pBoard1->boardArr[mouse_x][mouse_y] = '1';
                    }
                    if(event.button.button == SDL_BUTTON_RIGHT && edit == 1){
                        pBoard1->boardArr[mouse_x][mouse_y] = '0';
                    }
                    // check whether the pause button is pressed
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2-25&&event.button.x<=win_w/2+25
                    &&event.button.y>=win_h-60&&event.button.y<=win_h - 15){
                        if(stop == 1){
                            stop = 0;
                        }
                        else{
                            stop = 1;
                        }
                    }
                    // check whether the speeding up button is pressed
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2+25&&event.button.x<=win_w/2+65
                        &&event.button.y>=win_h-55&&event.button.y<=win_h-15){
                        if(delay_time<=10){
                            delay_time = 10;
                        }
                        delay_time = delay_time-10;
                    }
                    // check whether the speeding down button is pressed
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w/2-25-40&&event.button.x<=win_w/2-25
                       &&event.button.y>=win_h-55&&event.button.y<=win_h-15){
                        delay_time = delay_time + 10;
                    }
                    // check whether the random button is pressed
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=5&&event.button.x<=35
                       &&event.button.y>=win_h-50&&event.button.y<=win_h-20){
                        Random_board(pBoard1);
                    }
                    // check whether the cleaning button is pressed
                    if(event.button.button==SDL_BUTTON_LEFT&&event.button.x>=win_w-30-5&&event.button.x<=win_w-5
                       &&event.button.y>=win_h-50&&event.button.y<=win_h-20){
                        Clean_board(pBoard1);
                        step_now = 0;
                    }
                    // check whether the editing button is pressed
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
                // Listen for mouse position to edit the board
                case SDL_MOUSEMOTION:{
                    int mouse_x = event.button.x/rect_w;
                    int mouse_y = (event.button.y-30)/rect_h;
                    if(event.button.button == SDL_BUTTON_LEFT && edit == 1){
                        pBoard1 -> boardArr[mouse_x][mouse_y] = '1';
                    }
                    if(event.button.button == SDL_BUTTON_X1 && edit == 1){
                        pBoard1 -> boardArr[mouse_x][mouse_y] = '0';
                    }
                }
            }
        }

        // change the render target to texture
        SDL_SetRenderTarget(render,texture);
        // Set texture color (RGBA color)
        SDL_SetRenderDrawColor(render,255,255,255,255);
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render,43,43,43,255);
        // setting the rect to show the background
        SDL_Rect background;
        background.x = 0;
        background.y = 0;
        background.w = win_w;
        background.h = win_h;
        SDL_RenderFillRect(render, &background);

        // show the ttf_font to record the generation of current board
        sprintf(step_now_c,"%d",step_now);
        sprintf(sum,"%s%s","Generation: ",step_now_c);
        window_text(ttf_font, render, sum, 2, 6, 0);
        // show the ttf_font to record the count of the alive
        pBoard1->count_alive = 0;
        Count_alive(pBoard1);
        sprintf(count_alive_c, "%d",pBoard1->count_alive );
        sprintf(sum1,"%s%s","Alive: ",count_alive_c);
        window_text(ttf_font, render, sum1, 0, 6,win_w);
        // show the ttf_font to record the size of current game board
        sprintf(row_c, "%d",pBoard1->row);
        sprintf(col_c, "%d",pBoard1->col);
        sprintf(sum2,"%s%s%s%s","Size: ",row_c,"X", col_c);
        window_text(ttf_font, render, sum2, 1, 6,win_w);
        // using SDL to draw the game board
        for(rect_r=0;rect_r<pBoard1->row;rect_r++){
            p_rect_r = rect_r*rect_w;
            for(rect_c=0;rect_c<pBoard1->col;rect_c++){
                p_rect_c = rect_c*rect_h;
                SDL_Rect rect;
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
                SDL_RenderFillRect(render,&rect);
                SDL_SetRenderDrawColor(render,43,43,43,255);
                SDL_RenderDrawRect(render,&rect);
            }
        }
        // using the SDL_img to show the buttons
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

        // Restore to default render target
        SDL_SetRenderTarget(render,NULL);
        // Outputs the target to the graphics card
        SDL_RenderCopy(render,texture,NULL,NULL);
        // Display the graphics card after calculation
        SDL_RenderPresent(render);
        // check whether the board need to evolute
        if(stop == 0 ){
            runGame(pBoard1);
            step_now++;
            SDL_Delay(delay_time);
        }
        if(step_now==steps){
            stop = 1;
        }
    } while (!quit);

    // destroy the window, renderer and texture when quiting the window
    Destroy(window,render,texture);

    // quit the SDL
    SDL_Quit();
    // write the information of current game board into the history.txt file
    FILE *history_file;
    history_file = fopen("history.txt","w");
    if(history_save(history_file, pBoard1) != 0){
        printf("saving the history failed!\n");
    };
    for (int i = 0; i < pBoard1->row;i++) {
        free(pBoard1->boardArr[i]);
    }
    free(pBoard1->boardArr);
    return 0;
}