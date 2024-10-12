/***************************************************
 * Date:2024/10/12
1）指针：仅指向地址
2）指针变量
3）指针变量的大小
***************************************************/

#include <stdio.h>

int main()
{
    int a = 10; // 向内存申请4个字节，存储10
    &a; // 取地址操作符
    printf("%d\n", a);
    printf("%p\n", &a);
    int* p = &a;
    // p就是指针变量

    char ch = 'w';
    char* pc = &ch;
    printf("%p\n", &ch);
    printf("%p\n", pc);

    *p = 20;
    printf("%d\n", a); // * ： 解引用，找到地址中的对象
    
    printf("%zu\n", sizeof(char*)); // 8
    printf("%zu\n", sizeof(int*)); // 8
    return 0;
}
