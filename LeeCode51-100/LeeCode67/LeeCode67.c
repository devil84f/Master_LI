/***************************************************
 * Date:2024/11/26
 * 题目描述:
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

示例 1：
输入:a = "11", b = "1"
输出："100"

示例 2：
输入：a = "1010", b = "1011"
输出："10101"
/***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a); // 字符串 a 的长度
    int lenB = strlen(b); // 字符串 b 的长度
    int maxLength = (lenA > lenB ? lenA : lenB) + 1; // 可能的最大长度（考虑进位）
    
    char* result = (char*)malloc((maxLength + 1) * sizeof(char)); // 分配结果字符串
    result[maxLength] = '\0'; // 设置字符串结尾符
    int carry = 0; // 进位标志
    int index = maxLength - 1; // 结果字符串的末尾索引

    // 从末尾向前逐位相加
    lenA--;
    lenB--;
    while (lenA >= 0 || lenB >= 0 || carry > 0) {
        int bitA = (lenA >= 0) ? a[lenA--] - '0' : 0; // 从 a 取当前位，或 0
        int bitB = (lenB >= 0) ? b[lenB--] - '0' : 0; // 从 b 取当前位，或 0
        int sum = bitA + bitB + carry; // 当前位求和
        result[index--] = (sum % 2) + '0'; // 当前位结果
        carry = sum / 2; // 更新进位
    }

    // 如果有多余的 0，在前面移动结果字符串   指针   移动的是字符串首元素地址
    return result + index + 1;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";

    char* result = addBinary(a, b);
    printf("结果: %s\n", result);

    // 因为结果可能有偏移，需要用原始地址释放
    free(result - strlen(result));

    return 0;
}
