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
        printf("��ѡ��>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("������\n");
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    } while (input);

    return 0;
}