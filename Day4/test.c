/*************************
 * Date:2024/10/11
1���Ĵ�������
2��define���峣��/��
**************************/

#include <stdio.h>
#define NUM 100 // ��ʾ������
#define ADD(x, y) ((x) + (y))

int main()
{
    register int num = 3; // �����顱 3�洢�ڼĴ����У����׷��Ļ��Ǳ�����˵����

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
