/***************************************************
 * Date:2024/10/12
1��ָ�룺��ָ���ַ
2��ָ�����
3��ָ������Ĵ�С
***************************************************/

#include <stdio.h>

int main()
{
    int a = 10; // ���ڴ�����4���ֽڣ��洢10
    &a; // ȡ��ַ������
    printf("%d\n", a);
    printf("%p\n", &a);
    int* p = &a;
    // p����ָ�����

    char ch = 'w';
    char* pc = &ch;
    printf("%p\n", &ch);
    printf("%p\n", pc);

    *p = 20;
    printf("%d\n", a); // * �� �����ã��ҵ���ַ�еĶ���
    
    printf("%zu\n", sizeof(char*)); // 8
    printf("%zu\n", sizeof(int*)); // 8
    return 0;
}
