/***************************************************
 * Date:2024/11/26
1��ָ�����
***************************************************/
#include <stdio.h>
#include <string.h>

int main () {
    int a = 10; // a�����α�����ռ��4���ֽڵ��ڴ�ռ�
    int* p = &a; // p��һ��ָ�������������ŵ�ַ ������һ������

    int* pi = NULL;
    char* pc = NULL;
    printf("%zu\n", sizeof(pi));
    printf("%zu\n", sizeof(pc));

    int b = 0x11223344;
            //0001 0001 0010 0010 0011 0011 0100 0100
    char* pb = (char*)&b;
    * pb = 0;
    printf("%X\n", b);

    int d = 0x11223344;
    int* pd = &d;
    char* pcd = (char*)&d;
    printf("pd = %p\n", pd);
    printf("pd+1 = %p\n", pd+1);
    printf("pcd = %p\n", pcd);
    printf("pcd+1 = %p\n", pcd+1);

    int* arry[3] = {0};
    int size = sizeof(arry) / sizeof(arry[0]); // ���������С
    for (int i = 0; i < size; i++) {
        printf("%d ", arry[i]);
    }
    printf("\n"); // ��ӡ���з�

    int x = 1;
    int y = 2;
    int i = (x > y ? x : y);
    printf("%d\n", i);

    char* ar = "abc";
    printf("%d\n", strlen(ar));
    return 0;
}
 