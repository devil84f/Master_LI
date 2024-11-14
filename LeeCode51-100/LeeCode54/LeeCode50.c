/***************************************************
 * Date:2024/11/13
 * 题目描述:
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

示例 1：
输入：x = 2.00000, n = 10
输出：1024.00000

示例 2：
输入：x = 2.10000, n = 3
输出：9.26100

示例 3：
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
/***************************************************/

#include <stdio.h>

// 递归实现快速幂算法
// double myPow(double x, int n) {
//     if (n == 0) return 1.0;  // 任何数的 0 次幂为 1
//     if (n < 0) {
//         // 处理负指数
//         if (n == -2147483648) {  // 避免 n != -n 这种情况
//             return 1.0 / (myPow(x, 2147483647) * x);
//         }
//         return 1.0 / myPow(x, -n);
//     }

//     // 快速幂递归
//     double half = myPow(x, n / 2);
//     if (n % 2 == 0) {
//         return half * half;
//     } else {
//         return half * half * x;
//     }
// }

double myPow(double x, int n) {
    long long N = n;  // 使用 long long 避免溢出
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;  // 如果 N 是奇数，额外乘一次 x
        }
        x *= x;           // 平方底数
        N /= 2;           // 将 N 减半
    }
    return result;
}

int main() {
    double x = 2.0;
    int n = 4;
    printf("%f\n", myPow(x, n));  // 输出 1024.000000

    x = 2.1;
    n = 3;
    printf("%f\n", myPow(x, n));  // 输出 9.261000

    x = 2.0;
    n = -2;
    printf("%f\n", myPow(x, n));  // 输出 0.250000

    return 0;
}
