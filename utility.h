//
// Created by 12254 on 2022/5/9.
//
typedef struct _Board{
    int row;
    int col;
    char **boardArr;
}Board, *pBoard;

int loadFile(char* filename, Board * pb);

int runGame(Board * pb);
