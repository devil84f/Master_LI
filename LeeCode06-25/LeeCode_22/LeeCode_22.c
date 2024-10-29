/***************************************************
 * Date:2024/10/24
 * 题目描述:
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 递归生成括号组合的辅助函数
void generateParenthesisHelper(char **result, int *returnSize, char *current, int left, int right, int n) {
    if (left == n && right == n) {
        // 保存当前生成的组合
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (left < n) {
        // 添加左括号
        current[left + right] = '(';
        generateParenthesisHelper(result, returnSize, current, left + 1, right, n);
    }
    
    if (right < left) {
        // 添加右括号
        current[left + right] = ')';
        generateParenthesisHelper(result, returnSize, current, left, right + 1, n);
    }
}

// 计算卡塔兰数，用于估算括号组合数
int catalanNumber(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = result * (2 * n - i) / (i + 1);
    }
    return result / (n + 1);
}

// 主函数，生成所有有效的括号组合
char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;

    // 估计组合数（卡塔兰数）
    int maxSize = catalanNumber(n);
    
    char **result = (char **)malloc(maxSize * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';  // 结果字符串以'\0'结尾
    
    // 调用递归函数
    generateParenthesisHelper(result, returnSize, current, 0, 0, n);
    
    free(current);
    return result;
}

// 测试程序
int main() {
    int n = 4;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);
    
    // 输出所有生成的括号组合
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);  // 释放每个字符串的内存
    }
    free(result);  // 释放结果数组的内存
    
    return 0;
}
