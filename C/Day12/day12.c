/***************************************************
 * Date:2024/11/21
1）整型提升 小于整形
2）算术转换 大于整形
***************************************************/
#include <stdio.h>

int main () {
    char a = 5;
    char b = 126;
    char c = a + b;
    printf("%d\n", c);

    char d = 1;
    printf("%u\n", sizeof(d));
    printf("%u\n", sizeof(+d));
    printf("%u\n", sizeof(-d));

    return 0;
}