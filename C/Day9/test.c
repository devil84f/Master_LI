/***************************************************
 * Date:2024/10/29

1）求第n个斐波那契数列
1 1 2 3 5 8 13 21
        1                   n<=2
Fib(n)
        Fib(n-1)+Fib(n-2)   n>2 

2）数组学习
***************************************************/

#include <stdio.h>

int Fib (int n) { // 递归 慢 （可能溢出）
    if (n <= 2)
        return 1;
    else
        return Fib(n-1) + Fib(n-2);
}

int Fib1 (int n) { // 迭代 快速 （可能溢出）
    int a = 1;
    int b = 1;
    int c = 0;
    if (n <= 2)
        return 1;
    else
        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;

        }
        return c;
}

// int main ()
// {
//     int i = 40;
//     int num = Fib1(i);
//     printf("斐波那契数列第 %d 位: %d\n", i, num);

//     // 支持C99编译器  数组大小可变  int arr[n]
//     int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
//     char ch1[10] = {'a', 1, 'c'}; // a b c 0 0 0 0 0 0 0
//     char ch2[10] = "abc";           // a b c \0 0 0 0 0 0 0

//     // 连续地址
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < sz; i++)
//         printf("&arr[%d] = %p\n", i, &arr[i]);
    
//     return 0;
// }
