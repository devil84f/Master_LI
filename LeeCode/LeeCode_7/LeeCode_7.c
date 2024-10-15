/***************************************************
 * Date:2024/10/14
题目：整数反转（LeetCode 第7题）

题目描述：
给你一个 32 位的有符号整数 x，返回 x 中数字反转后的结果。如果反转后的整数超过了 32 位有符号整数的范围 [-2^31, 2^31 - 1]，则返回 0。

示例 1:
输入: x = 123
输出: 321

示例 2:
输入: x = -123
输出: -321

示例 3:
输入: x = 120
输出: 21

提示：
-2^31 <= x <= 2^31 - 1

解题思路：
1. 处理正负号：记录输入整数的符号，反转后的结果应保持相同符号。
2. 逐位反转：使用取模操作提取数字的最后一位，并逐步构建反转后的数字。
3. 溢出处理：在构建反转数字之前检查是否会超过 32 位整数的范围。
   32 位有符号整数的范围为 [-2147483648, 2147483647]。
****************************************************/
#include <stdio.h>
#include <limits.h>  // 包含 INT_MAX 和 INT_MIN 的定义

int reverse(int x) {
    int reversed = 0;  // 存储反转后的整数

    while (x != 0) {
        int pop = x % 10;  // 提取最后一位数字
        x /= 10;           // 移除最后一位数字

        // 检查是否会发生溢出
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) {
            return 0;  // 溢出，返回 0
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) {
            return 0;  // 溢出，返回 0
        }

        // 更新反转后的数字
        reversed = reversed * 10 + pop;
    }

    return reversed;
}

int main() {
    int x = 123;
    printf("Reversed: %d\n", reverse(x));  // 输出：321

    x = -123;
    printf("Reversed: %d\n", reverse(x));  // 输出：-321

    x = 1534236469;
    printf("Reversed: %d\n", reverse(x));  // 输出：0（溢出）

    return 0;
}
