#include <stdio.h>

extern int Add(int x, int y); // �����ⲿ����

int day_1()//������ 
{
   // /* ��һ������ C ���� ������У�Ctrl+Alt+N */
   // printf("Hello, World! \n");//�⺯������ӡ����

   // /* ����������������������� ��һ����������Ϊ���� */
   // int a = 7 / 2; // ��
   // int b = 7 % 2; // ȡģ
   // float c = 7 / 2.0; // ��
   // printf("%d\n", a);
   // printf("%d\n", b);
   // printf("%.2f\n", c); // %.2f ����С�������λ

   // int arr[10] = {10}; // ����һ��Ԫ�ظ���10 ����Ϊ0
   // printf("%d\n", arr[1]);
   // printf("%d\n", sizeof(arr));

   /* ���������� */
   int a = 10;
   int b = 20;
   int c = a > b ? a : b;
   int z = Add(a, b);
   printf("%d\n", c);
   printf("%d\n", z);
   return 0;   
}

