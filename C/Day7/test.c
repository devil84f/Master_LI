/***************************************************
 * Date:2024/10/15
1���⺯��
2���Զ��庯��
3����ʽ����/ʵ�ʲ���
***************************************************/

#include <stdio.h>
#include <string.h>

void Swap(int *px, int *py)
{
    int z = *px;
    *px = *py;
    *py = z;
}

int main()
{
    int a = 10;
    int b = 20;
    char arr1[20] = { 0 };
    char arr2[] = "hello";
    strcpy(arr1, arr2); // Ŀ�꣬ ��Դ
    printf("%s\n", arr1);

    printf("����ǰ:a=%d b=%d\n", a, b);
    Swap(&a, &b); // ʵ��/�βε�����
    printf("������:a=%d b=%d\n", a, b);
    return 0;
}
