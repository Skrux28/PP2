//
// Created by 12254 on 2022/5/9.
//
typedef struct _Board{
    int row;
    int col;
    int size_l;
    char **boardArr;
}Board, *pBoard;

int loadFile(char* filename, Board * pb);

int runGame(Board * pb);

int history_save(char * filename, Board * pb);
