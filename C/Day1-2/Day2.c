/*
�ؼ���
*/

#include <stdio.h>
extern int day_1();
// typedef unsigned int uint;

// typedef struct Node
// {
//     int data;
//     struct Node* next;
// }Node;

// int mian()
// {
//     unsigned int num = 0;
//     uint num2 = 1;
//     struct Node n;
//     Node n2;
//     return 0;
// }


void test()
{
    // int a = 1;
    static int a = 1;
    a++; // ǰ��û�����ʱ ++a��a++��ͬ
    printf("%d ", a); // output 2
}
extern int g_val; // �����ⲿ����
int main()
{
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }
    
    printf("\n%d\n", g_val);
    day_1();
    return 0; 
}