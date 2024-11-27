/***************************************************
 * Date:2024/11/27
 * ��Ŀ����:
����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��
ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��

ʾ�� 1��
���룺x = 4
�����2

ʾ�� 2��
���룺x = 8
�����2
���ͣ�8 ������ƽ������ 2.82842..., ���ڷ���������������С�����ֽ�����ȥ��
/***************************************************/

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 0, right = x, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((long long)mid * mid == x) {
            return mid; // �ҵ���ȷƽ����
        } else if ((long long)mid * mid < x) {
            ans = mid; // mid �ǵ�ǰ�������ܽ�
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int mySqrt1(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    double guess = x; // ��ʼ�²�
    while (1) {
        double nextGuess = (guess + x / guess) / 2;
        if ((int)guess == (int)nextGuess) { // ���������ֲ��ٱ仯ʱ���˳�
            break;
        }
        guess = nextGuess;
    }

    return (int)guess;
}

int main() {
    int x = 8;
    printf("sqrt(%d) = %d\n", x, mySqrt(x));
    printf("sqrt(%d) = %d\n", x, mySqrt1(x));
    
    return 0;
}
