/***************************************************
 * Date:2024/10/14
1��elseƥ������
2��switch���
***************************************************/

#include <stdio.h>

int main()
{
    int a = 0;
    int b = 2;
    if(a == 1)
        if(b == 2)
            printf("hh");
    else
        printf("haha");
    
    int day = 0;
    scanf("%d", &day);
    switch (day)
    {
    case 1:
        printf("����1\n");
        break;
    case 2:
        printf("����2\n");
        break;
    case 3:
        printf("����3\n");
        break;
    case 4:
        printf("����4\n");
        break;
    case 5:
        printf("����5\n");
        break;
    case 6:
        printf("����6\n");
        break;
    case 7:
        printf("������\n");
        break;
    default:
        printf("����\n");
        break;
    }
    return 0;
}
