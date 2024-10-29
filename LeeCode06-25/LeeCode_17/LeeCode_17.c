/***************************************************
 * Date:2024/10/20
 * 题目描述:电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
电话键盘上的数字与字母的对应关系如下：
2 -> "abc"
3 -> "def"
4 -> "ghi"
5 -> "jkl"
6 -> "mno"
7 -> "pqrs"
8 -> "tuv"
9 -> "wxyz"
给定一个数字字符串 digits，返回它能表示的所有字母组合。

示例 1：
输入：digits = "23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a", "b", "c"]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digitToChar(char digit) {
    switch (digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

void backtrack(char*** result, char* combination, const char* digits, int index, int* returnSize, int* capacity) {
    if (index == strlen(digits)) {
        if (*returnSize >= *capacity) {
            *capacity *= 2; // 扩展容量
            *result = realloc(*result, sizeof(char*) * (*capacity)); // 修改传入的指针
            if (*result == NULL) {
                exit(EXIT_FAILURE); // 处理 realloc 失败
            }
        }
        (*result)[*returnSize] = strdup(combination); // 复制组合到结果中
        (*returnSize)++;
        return;
    }

    char* letters = digitToChar(digits[index]);
    for (int i = 0; letters[i] != '\0'; i++) {
        combination[index] = letters[i]; // 添加当前字母
        backtrack(result, combination, digits, index + 1, returnSize, capacity); // 递归
    }
    
    combination[index] = '\0'; // 恢复组合状态
}

char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100; // 初始化容量
    char** result = malloc(sizeof(char*) * capacity);
    char* combination = malloc(sizeof(char) * (strlen(digits) + 1));
    combination[strlen(digits)] = '\0'; // 终止符
    *returnSize = 0;

    backtrack(&result, combination, digits, 0, returnSize, &capacity);

    free(combination); // 释放组合内存
    return result;
}

int main() {
    char digits[] = "5678";
    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);

    printf("Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // 释放内存
    }

    free(combinations);
    return 0;
}
