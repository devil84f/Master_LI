#include <stdio.h>
#include <string.h>

void menu() {
    printf("********************************\n");
    printf("******  1. play  0. exit  ******\n");
    printf("********************************\n");
}

int main () {
    int input = 0;
    do {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
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