//
// Created by 12254 on 2022/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
int chess[50][50];
int chess0[50][50];
int N=50;
void RunGame(int n)
{
    int i,j,s=0;
    int flag=0;
    while(n>=0)
    {
        system("cls");
        for(i=1;i<N+1;i++)
        {
            for(j=1;j<N+1;j++)
                if(chess[i][j]==1)
                    printf("█");//printf("■");
                else if(chess[i][j]==0)
                    printf("  ");
            printf("\n");
        }
        for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
            {
                s=Count(i,j);
                if(chess[i][j]==1)
                {
                    if(s<2)
                        chess0[i][j]=0;
                    else if(s>3)
                        chess0[i][j]=0;
                    else if(s==2||s==3)
                        chess0[i][j]=1;
                }
                else if(chess[i][j]==0)
                {
                    if(s==3)
                        chess0[i][j]=1;
                }
            }
        for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
                chess[i][j]=chess0[i][j];
        n--;
        if(flag==0)
        {
            getchar();
            flag=1;
        }
    }
}

int Count(int i,int j)
{
    int s=0,a,b;
    for(a=-1;a<=1;a++)
        for(b=-1;b<=1;b++)
            if(!(a==0&&b==0)&&chess[i+a][j+b]==1)
                s++;
    return s;
}

