/***************************************************
 * Date:2024/11/21
1���������� С������
2������ת�� ��������
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