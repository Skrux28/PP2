#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
int main() {
    pBoard pBoard1 = malloc(sizeof (Board));
    loadFile("game.txt", pBoard1);
    printf("%d+%d\n", pBoard1->row, pBoard1->col);
    for(int i=0; i<pBoard1->row; i++){
        for(int j=0; j<pBoard1->col; j++){
            printf("%c", pBoard1->boardArr[i][j]);
        }
        printf("\n");
    }
    runGame(pBoard1);
}
