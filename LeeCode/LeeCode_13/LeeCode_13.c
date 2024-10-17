/***************************************************
 * Date:2024/10/17
 * 题目描述:
将给定的罗马数字字符串转换为整数，规则基于罗马数字符号的组合与减法原则。

罗马数字规则：
罗马数字使用7个字母表示不同的数值：

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
在一些情况下，较小的数字位于较大的数字之前，表示减法。例如：

IV = 4 （5 - 1）
IX = 9 （10 - 1）
XL = 40 （50 - 10）
/***************************************************/

#include <stdio.h>

int romanToInt(char* s) {
    int result = 0;
    
    // 定义罗马数字符号与数值的对应关系
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
    printf("The integer value of %s is %d\n", roman, romanToInt(roman)); // 输出：1994
    return 0;
}

