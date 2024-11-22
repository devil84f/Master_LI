/***************************************************
 * Date:2024/11/22
 * 题目描述:
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

示例 1：
输入：n = 3, k = 3
输出："213"

示例 2：
输入：n = 4, k = 9
输出："2314"

示例 3：
输入：n = 3, k = 1
输出："123"
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 主函数：获取第 k 个排列
char* getPermutation(int n, int k) {
    // 计算阶乘数组
    int factorial[n];
    factorial[0] = 1;
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    // 可选数字列表
    int numbers[n];
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1; // 初始为 [1, 2, ..., n]
    }

    // 分配结果字符串
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0'; // 末尾加结束符

    // 调整为从 0 开始的索引
    k--;

    // 构造排列
    for (int i = 0; i < n; i++) {
        int index = k / factorial[n - 1 - i]; // 当前数字的索引
        result[i] = numbers[index] + '0';    // 转为字符
        // 删除已选数字
        for (int j = index; j < n - i - 1; j++) {
            numbers[j] = numbers[j + 1];
        }
        k %= factorial[n - 1 - i]; // 更新 k
    }

    return result;
}

// 测试代码
int main() {
    int n = 4, k = 9;
    char* result = getPermutation(n, k);
    printf("第 %d 个排列是: %s\n", k, result);
    free(result); // 释放内存
    return 0;
}
