/***************************************************
 * Date:2024/10/20
1����ʽ����
2�������Ķ���
3����������������ͷ�ļ�
***************************************************/

#include <stdio.h>
#include "add.h" // ����ͷ�ļ� ����ʹ��

// int Add(int x, int y); �������嵽main()��Ҫ������ / main()ǰ����

int main()
{
    int a =0, b = 0;
    scanf("%d %d", &a, &b);
    int sum = Add(a, b);
    printf("%d\n", sum);
    printf("%d", printf("%d", printf("%d", 43))); // printf�����ַ���ӡ���ַ���
    return 0;                                   
}

// int Add(int x, int y)
// {
//     return x + y;
// }