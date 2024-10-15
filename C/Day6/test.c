/***************************************************
 * Date:2024/10/14
1）else匹配问题
2）switch语句
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
        printf("星期1\n");
        break;
    case 2:
        printf("星期2\n");
        break;
    case 3:
        printf("星期3\n");
        break;
    case 4:
        printf("星期4\n");
        break;
    case 5:
        printf("星期5\n");
        break;
    case 6:
        printf("星期6\n");
        break;
    case 7:
        printf("星期日\n");
        break;
    default:
        printf("错误\n");
        break;
    }
    return 0;
}
