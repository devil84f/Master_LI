#include <string.h>
#include "game.h"

void menu() {
    printf("********************************\n");
    printf("******  1. play  0. exit  ******\n");
    printf("********************************\n");
}

void game() {
    char ret = 0;
    char board[ROW][COL] = {0};
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    while (1) {
        PlayerMove(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
        ComputerMove(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
    }
    if (ret == '*') {
        printf("玩家赢\n");
    }
    else if (ret == '#') {
        printf("电脑赢\n");
    }
    else printf("平局\n");
    DisplayBoard(board, ROW, COL);
}

int main () {
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        menu();
        printf("请选择：>");
        scanf("%d", &input); 
        switch (input)
        {
        case 1:
            game();
            printf("三子棋\n");
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);

    return 0;
}
