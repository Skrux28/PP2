//
// Created by 12254 on 2022/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

int runGame(Board * pb){
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
    return 1;
}

int Random_board(pBoard pb){
    int count, liv ;
    for(int i=0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            liv = rand()%2;
//            printf(" %d ", liv);
            if( liv == 1 ){
                pb->boardArr[i][j] = '1';
                count++;
            }
            else{
                pb->boardArr[i][j] = '0';
            }
        }
    }
}

int Clean_board(pBoard pb){
    for(int i = 0; i<pb->row; i++){
        for(int j=0; j<pb->col; j++){
            pb->boardArr[i][j] = '0';
        }
    }
    return 1;
}