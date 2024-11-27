/***************************************************
 * Date:2024/11/27
 * 题目描述:
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
输入：x = 4
输出：2

示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
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
            return mid; // 找到精确平方根
        } else if ((long long)mid * mid < x) {
            ans = mid; // mid 是当前的最大可能解
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

    double guess = x; // 初始猜测
    while (1) {
        double nextGuess = (guess + x / guess) / 2;
        if ((int)guess == (int)nextGuess) { // 当整数部分不再变化时，退出
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
