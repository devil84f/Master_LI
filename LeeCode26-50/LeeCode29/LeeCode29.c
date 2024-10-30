/***************************************************
 * Date:2024/10/29
 * 题目描述:
给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。
整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。
返回被除数 dividend 除以除数 divisor 得到的 商 。

示例 1:
输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = 3.33333.. ，向零截断后得到 3 。

示例 2:
输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = -2.33333.. ，向零截断后得到 -2 。
/***************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// 除法函数
int divide(int dividend, int divisor) {
    // 处理特殊溢出情况
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;


    // 确定结果的符号
    int sign = ((dividend < 0) == (divisor < 0)) ? 1 : -1;

    // 使用 long long 转换来防止溢出
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

// 测试主函数
int main() {
    int dividend = 10;
    int divisor = 3;
    int result = divide(dividend, divisor);
    printf("商: %d\n", result);

    dividend = 7;
    divisor = -3;
    result = divide(dividend, divisor);
    printf("商: %d\n", result);

    dividend = -2147483648;
    divisor = 1;
    result = divide(dividend, divisor);
    printf("商: %d\n", result);

    return 0;
}
