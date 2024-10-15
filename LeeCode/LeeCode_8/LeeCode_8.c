/***************************************************
 * Date:2024/10/14
题目：字符串转换整数 (atoi)（LeetCode 第8题）

题目描述：
实现一个函数，将字符串转换为 32 位有符号整数 (类似于 C 语言中的 atoi 函数)。
函数 `myAtoi(string)` 的算法如下：
1. 读入字符串并丢弃无用的前导空格。
2. 检查下一个字符（如果存在），是正号还是负号，确定结果是正数还是负数。假设当前字符不是符号字符，则默认结果为正数。
3. 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。将这些数字转换为整数，并将其加到结果中。
4. 如果结果超出 32 位有符号整数范围 [-2^31, 2^31 - 1]，则返回 INT_MAX (2^31 - 1) 或 INT_MIN (-2^31)。
5. 如果输入中没有数字，返回 0。

注意：
- 函数忽略无效输入中的额外字符，只转换有效数字部分。
- 允许前导空格、正负号，但其他字符如字母或符号结束数字转换。

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42

示例 3:
输入: "4193 with words"
输出: 4193

示例 4:
输入: "words and 987"
输出: 0

示例 5:
输入: "-91283472332"
输出: -2147483648 （溢出）

提示：
- 输入字符串长度不超过 200 字符。
- 字符串可能为空，或者包含前导空格、非数字字符和符号字符。
- 字符串中的无效字符会导致转换停止。

解题思路：
1. 跳过字符串前面的空格。
2. 检查第一个非空字符是否为符号 `+` 或 `-`。
3. 逐个遍历字符串中的数字字符，计算结果。
4. 处理溢出情况，确保结果在 [-2^31, 2^31 - 1] 范围内。
****************************************************/
#include <stdio.h>
#include <limits.h>  // 包含 INT_MAX 和 INT_MIN 的定义

int myAtoi(char* str) {
    int i = 0, sign = 1;  // i 用于遍历字符串，sign 用于标记正负号
    long result = 0;      // 使用 long 以避免溢出

    // 跳过前导空格
    while (str[i] == ' ') {
        i++;
    }

    // 处理符号
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // 逐个字符处理数字
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');  // 更新结果
        // 检查溢出情况
        /* 
        应检查当前位result是否大于最大值上一位，如果相等，检查下一位str[i]是否要大于最后一位，防止当前数×10后溢出
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return negative ? INT_MIN : INT_MAX;
        } */
        if (result * sign > INT_MAX) {
            return INT_MAX;
        }
        if (result * sign < INT_MIN) {
            printf("%d\n", result * sign);
            return INT_MIN;
        }

        i++;
    }

    return (int)(result * sign);  // 返回最终的转换结果
}

int main() {
    char str1[] = "42";
    printf("Result: %d\n", myAtoi(str1));  // 输出：42

    char str2[] = "   -42";
    printf("Result: %d\n", myAtoi(str2));  // 输出：-42

    char str3[] = "4193 with words";
    printf("Result: %d\n", myAtoi(str3));  // 输出：4193

    char str4[] = "words and 987";
    printf("Result: %d\n", myAtoi(str4));  // 输出：0

    char str5[] = "-91283472332";
    printf("Result: %d\n", myAtoi(str5));  // 输出：-2147483648（溢出）

    return 0;
}
