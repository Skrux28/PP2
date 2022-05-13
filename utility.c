//
// Created by 12254 on 2022/5/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

char* getLine(char* str) {
    int size = strlen(str);
    if((size != 0) && (str[size-1] == '\n')) {
        str[size-1] ='\0';
    }
    return str;
}

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
//    for(i=0; i<pb->row; i++){
//        for(j=0; j<pb->col; j++) {
//            printf("%c", pb->boardArr[i][j]);
//        }
//        printf("\n");
//    }
    return 1;
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

