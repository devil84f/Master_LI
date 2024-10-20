/***************************************************
 * Date:2024/10/20
1）链式法则
2）函数的定义
3）函数的声明：放头文件
***************************************************/

#include <stdio.h>
#include "add.h" // 包含头文件 正常使用

// int Add(int x, int y); 函数定义到main()后要先声明 / main()前不用

int main()
{
    int a =0, b = 0;
    scanf("%d %d", &a, &b);
    int sum = Add(a, b);
    printf("%d\n", sum);
    printf("%d", printf("%d", printf("%d", 43))); // printf返回字符打印的字符数
    return 0;                                   
}

// int Add(int x, int y)
// {
//     return x + y;
// }