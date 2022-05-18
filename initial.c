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

