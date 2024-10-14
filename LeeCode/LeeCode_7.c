/***************************************************
 * Date:2024/10/14
��Ŀ��������ת��LeetCode ��7�⣩

��Ŀ������
����һ�� 32 λ���з������� x������ x �����ַ�ת��Ľ���������ת������������� 32 λ�з��������ķ�Χ [-2^31, 2^31 - 1]���򷵻� 0��

ʾ�� 1:
����: x = 123
���: 321

ʾ�� 2:
����: x = -123
���: -321

ʾ�� 3:
����: x = 120
���: 21

��ʾ��
-2^31 <= x <= 2^31 - 1

����˼·��
1. ���������ţ���¼���������ķ��ţ���ת��Ľ��Ӧ������ͬ���š�
2. ��λ��ת��ʹ��ȡģ������ȡ���ֵ����һλ�����𲽹�����ת������֡�
3. ����������ڹ�����ת����֮ǰ����Ƿ�ᳬ�� 32 λ�����ķ�Χ��
   32 λ�з��������ķ�ΧΪ [-2147483648, 2147483647]��
****************************************************/
#include <stdio.h>
#include <limits.h>  // ���� INT_MAX �� INT_MIN �Ķ���

int reverse(int x) {
    int reversed = 0;  // �洢��ת�������

    while (x != 0) {
        int pop = x % 10;  // ��ȡ���һλ����
        x /= 10;           // �Ƴ����һλ����

        // ����Ƿ�ᷢ�����
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) {
            return 0;  // ��������� 0
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) {
            return 0;  // ��������� 0
        }

        // ���·�ת�������
        reversed = reversed * 10 + pop;
    }

    return reversed;
}

// int main() {
//     int x = 123;
//     printf("Reversed: %d\n", reverse(x));  // �����321

//     x = -123;
//     printf("Reversed: %d\n", reverse(x));  // �����-321

//     x = 1534236469;
//     printf("Reversed: %d\n", reverse(x));  // �����0�������

//     return 0;
// }