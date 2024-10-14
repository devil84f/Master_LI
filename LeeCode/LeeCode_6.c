/***************************************************
 * Date:2024/10/12
题目：Z 字形变换（LeetCode 第6题）

题目描述：
将一个字符串以 "Z" 字形进行排列，并按行输出该字符串。具体排列方式如下：
给定字符串 "PAYPALISHIRING"，假设你要将其按 Z 字形排列为 3 行：
P   A   H   N
A P L S I I G
Y   I   R
之后，逐行读取字符，得到 "PAHNAPLSIIGY"。

输入：
- s: 待转换的字符串
- numRows: 代表 Z 字形排列的行数
输出：
按 Z 字形排列并逐行读取后的字符串。

解法思路：
1. 特殊情况：当 numRows 为 1 时，Z 字形变换无意义，直接返回字符串。
2. 用一个二维数组保存每一行的字符，模拟 Z 字形的排列。
3. 遍历输入字符串，按方向（向下或向上）依次填充对应的行。
4. 最终将所有行的字符拼接起来，返回结果。
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    // 特殊情况处理
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    // 动态分配每一行的存储空间
    char** rows = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        rows[i] = (char*)malloc(strlen(s) + 1);
        rows[i][0] = '\0';  // 初始化为空字符串
    }

    int current_row = 0;
    int going_down = 0;  // 控制方向

    // 遍历字符串
    for (int i = 0; s[i] != '\0'; ++i) {
        strncat(rows[current_row], &s[i], 1);  // 将字符添加到当前行
        // 如果到达第一行或最后一行，切换方向
        if (current_row == 0 || current_row == numRows - 1) {
            going_down = !going_down;
        }
        // 根据方向移动
        current_row += going_down ? 1 : -1;
    }

    // 计算最终拼接结果的长度
    char* result = (char*)malloc(strlen(s) + 1);
    result[0] = '\0';  // 初始化为空字符串

    // 拼接所有行
    for (int i = 0; i < numRows; ++i) {
        strcat(result, rows[i]);
        free(rows[i]);  // 释放每一行的内存
    }

    free(rows);  // 释放行指针数组的内存

    return result;  // 返回最终结果
}

// int main() {
//     char s[] = "PAYPALISHIRING";
//     int numRows = 3;
//     char* result = convert(s, numRows);
//     printf("%s\n", result);  // 输出: "PAHNAPLSIIGY"
//     return 0;
// }

