/***************************************************
 * Date:2024/10/17
 * ��Ŀ����:
�����������������ַ���ת��Ϊ��������������������ַ��ŵ���������ԭ��

�������ֹ���
��������ʹ��7����ĸ��ʾ��ͬ����ֵ��

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
��һЩ����£���С������λ�ڽϴ������֮ǰ����ʾ���������磺

IV = 4 ��5 - 1��
IX = 9 ��10 - 1��
XL = 40 ��50 - 10��
/***************************************************/

#include <stdio.h>

int romanToInt(char* s) {
    int result = 0;
    
    // �����������ַ�������ֵ�Ķ�Ӧ��ϵ
    while (*s) {
        if (*s == 'I') {
            if (*(s + 1) == 'V' || *(s + 1) == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (*s == 'V') {
            result += 5;
        } else if (*s == 'X') {
            if (*(s + 1) == 'L' || *(s + 1) == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (*s == 'L') {
            result += 50;
        } else if (*s == 'C') {
            if (*(s + 1) == 'D' || *(s + 1) == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (*s == 'D') {
            result += 500;
        } else if (*s == 'M') {
            result += 1000;
        }
        s++;
    }

    return result;
}

int main() {
    char roman[] = "MCMXCIV"; // 1994
    printf("The integer value of %s is %d\n", roman, romanToInt(roman)); // �����1994
    return 0;
}

