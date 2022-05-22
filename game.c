//
// Created by 12254 on 2022/5/6.
//
#include <stdlib.h>
#include "game.h"

/**
 * the function to run the whole precess of the game
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int runGame(Board * pb){
    if (!pb){
        printf("Cannot get the board!\n");
        return -1;
    }
    int scale[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
    int i,j;
    int x=0;
    int y=0;
    for(i=0; i<pb->row; i++){
        for(j=0; j<pb->col; j++){
            int count=0;
            for(int m=0; m < 8; m++){
                x=i+scale[m][0];
                y=j+scale[m][1];
                if(x>=0&&x<pb->row&&y>=0&&y<pb->col){
                    if(pb->boardArr[x][y]>=49){
                        count+=1;
                    }
                }
            }
            if(pb->boardArr[i][j] == '1' && (count<2||count>3)){
                pb->boardArr[i][j] = '2';
            }
            else if(pb->boardArr[i][j] == '0' && count==3 ){
                pb->boardArr[i][j] = 47;
            }
        }
    }
    for(i=0; i<pb->row; i++){
        for(j=0; j<pb->col; j++) {
            if(pb->boardArr[i][j] == '2'){
                pb->boardArr[i][j] = '0';
            }
            if( pb->boardArr[i][j] == 47){
                pb->boardArr[i][j] = '1';
            }
        }
    }
    return 0;
}

/**
 * make a new random distribution to display the board
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Random_board(pBoard pb){
    if (!pb){
        printf("Cannot get the board!\n");
        return -1;
    }
    int count, liv ;
    for(int i=0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            liv = rand()%2;
            if( liv == 1 ){
                pb->boardArr[i][j] = '1';
                count++;
            }
            else{
                pb->boardArr[i][j] = '0';
            }
        }
    }
    return 0;
}

/**
 * clean the board to let every cells die
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Clean_board(pBoard pb){
    if (!pb){
        printf("Cannot get the board!\n");
        return -1;
    }
    for(int i = 0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            pb->boardArr[i][j] = '0';
        }
    }
    return 0;
}

/**
 * count the current count of alive cells of the board
 * @param pb pointer of the structure Board which store the information of current game board
 * @return 0
 */
int Count_alive(pBoard pb){
    if (!pb){
        printf("Cannot get the board!\n");
        return -1;
    }
    for(int i = 0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            if (pb->boardArr[i][j] == '1'){
                pb->count_alive ++;
            }
        }
    }
    return 0;
}