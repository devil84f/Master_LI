/*************************
 * Date:2024/10/11
1）寄存器变量
2）define定义常量/宏
**************************/

#include <stdio.h>
#define NUM 100 // 表示符常量
#define ADD(x, y) ((x) + (y))

int main()
{
    register int num = 3; // “建议” 3存储在寄存器中，到底放哪还是编译器说的算

    printf("%d\n", NUM);
    int n = NUM;
    printf("%d\n", n);
    int arr[NUM] = { 0 };

    int a = 10;
    int b = 20;
    int c = ADD(a, b);
    printf("%d\n", c);

    printf("hello");
    return 0;
}
