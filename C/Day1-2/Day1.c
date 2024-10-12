#include <stdio.h>

extern int Add(int x, int y); // 声明外部符号

int day_1()//主函数 
{
   // /* 第一次运行 C 程序 快捷运行：Ctrl+Alt+N */
   // printf("Hello, World! \n");//库函数：打印数据

   // /* 除号两端是整数结果是整数 有一个浮点数就为浮点 */
   // int a = 7 / 2; // 除
   // int b = 7 % 2; // 取模
   // float c = 7 / 2.0; // 除
   // printf("%d\n", a);
   // printf("%d\n", b);
   // printf("%.2f\n", c); // %.2f 保留小数点后两位

   // int arr[10] = {10}; // 给第一个元素复制10 其余为0
   // printf("%d\n", arr[1]);
   // printf("%d\n", sizeof(arr));

   /* 条件操作符 */
   int a = 10;
   int b = 20;
   int c = a > b ? a : b;
   int z = Add(a, b);
   printf("%d\n", c);
   printf("%d\n", z);
   return 0;   
}

