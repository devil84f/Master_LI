/***************************************************
 * Date:2024/11/13
 * ��Ŀ����:
ʵ�� pow(x, n) �������� x ������ n ���ݺ���������xn ����

ʾ�� 1��
���룺x = 2.00000, n = 10
�����1024.00000

ʾ�� 2��
���룺x = 2.10000, n = 3
�����9.26100

ʾ�� 3��
���룺x = 2.00000, n = -2
�����0.25000
���ͣ�2-2 = 1/22 = 1/4 = 0.25
/***************************************************/

#include <stdio.h>

// �ݹ�ʵ�ֿ������㷨
// double myPow(double x, int n) {
//     if (n == 0) return 1.0;  // �κ����� 0 ����Ϊ 1
//     if (n < 0) {
//         // ����ָ��
//         if (n == -2147483648) {  // ���� n != -n �������
//             return 1.0 / (myPow(x, 2147483647) * x);
//         }
//         return 1.0 / myPow(x, -n);
//     }

//     // �����ݵݹ�
//     double half = myPow(x, n / 2);
//     if (n % 2 == 0) {
//         return half * half;
//     } else {
//         return half * half * x;
//     }
// }

double myPow(double x, int n) {
    long long N = n;  // ʹ�� long long �������
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;  // ��� N �������������һ�� x
        }
        x *= x;           // ƽ������
        N /= 2;           // �� N ����
    }
    return result;
}

int main() {
    double x = 2.0;
    int n = 4;
    printf("%f\n", myPow(x, n));  // ��� 1024.000000

    x = 2.1;
    n = 3;
    printf("%f\n", myPow(x, n));  // ��� 9.261000

    x = 2.0;
    n = -2;
    printf("%f\n", myPow(x, n));  // ��� 0.250000

    return 0;
}
