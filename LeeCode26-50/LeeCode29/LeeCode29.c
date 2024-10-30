/***************************************************
 * Date:2024/10/29
 * ��Ŀ����:
�������������������� dividend �ͳ��� divisor�������������Ҫ�� ��ʹ�� �˷���������ȡ�����㡣
��������Ӧ������ضϣ�Ҳ���ǽ�ȥ��truncate����С�����֡����磬8.345 �����ض�Ϊ 8 ��-2.7335 �����ض��� -2 ��
���ر����� dividend ���Գ��� divisor �õ��� �� ��

ʾ�� 1:
����: dividend = 10, divisor = 3
���: 3
����: 10/3 = 3.33333.. ������ضϺ�õ� 3 ��

ʾ�� 2:
����: dividend = 7, divisor = -3
���: -2
����: 7/-3 = -2.33333.. ������ضϺ�õ� -2 ��
/***************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// ��������
int divide(int dividend, int divisor) {
    // ��������������
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;


    // ȷ������ķ���
    int sign = ((dividend < 0) == (divisor < 0)) ? 1 : -1;

    // ʹ�� long long ת������ֹ���
    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);
    
    int result = 0;
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        result += multiple;
    }
    
    return sign == 1 ? result : -result;
}

// ����������
int main() {
    int dividend = 10;
    int divisor = 3;
    int result = divide(dividend, divisor);
    printf("��: %d\n", result);

    dividend = 7;
    divisor = -3;
    result = divide(dividend, divisor);
    printf("��: %d\n", result);

    dividend = -2147483648;
    divisor = 1;
    result = divide(dividend, divisor);
    printf("��: %d\n", result);

    return 0;
}
