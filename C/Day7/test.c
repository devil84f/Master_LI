/***************************************************
 * Date:2024/10/15
1）库函数
2）自定义函数
3）形式参数/实际参数
***************************************************/

#include <stdio.h>
#include <string.h>

void Swap(int *px, int *py)
{
    int z = *px;
    *px = *py;
    *py = z;
}

int main()
{
    int a = 10;
    int b = 20;
    char arr1[20] = { 0 };
    char arr2[] = "hello";
    strcpy(arr1, arr2); // 目标， 来源
    printf("%s\n", arr1);

    printf("交换前:a=%d b=%d\n", a, b);
    Swap(&a, &b); // 实参/形参的区别
    printf("交换后:a=%d b=%d\n", a, b);
    return 0;
}
