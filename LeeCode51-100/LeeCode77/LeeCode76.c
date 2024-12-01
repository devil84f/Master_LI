/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-30 22:06:04
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-30 22:08:39
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode76\LeeCode76.c
 * @Description: 
 *      给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
        你可以按 任何顺序 返回答案。

        示例 1：
        输入：n = 4, k = 2
        输出：
        [
        [2,4],
        [3,4],
        [2,3],
        [1,2],
        [1,3],
        [1,4],
        ]
 */

#include <stdio.h>
#include <stdlib.h>

// 动态数组结构
typedef struct {
    int** data;
    int size;
    int capacity;
} Array;

void initArray(Array* arr, int capacity) {
    arr->data = (int**)malloc(sizeof(int*) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
}

void addToArray(Array* arr, int* combination, int k) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int**)realloc(arr->data, sizeof(int*) * arr->capacity);
    }
    arr->data[arr->size] = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        arr->data[arr->size][i] = combination[i];
    }
    arr->size++;
}

void backtrack(int n, int k, int start, int* combination, int combSize, Array* result) {
    if (combSize == k) {
        addToArray(result, combination, k);
        return;
    }
    for (int i = start; i <= n; i++) {
        combination[combSize] = i;
        backtrack(n, k, i + 1, combination, combSize + 1, result);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    Array result;
    initArray(&result, 16);
    int* combination = (int*)malloc(sizeof(int) * k);
    backtrack(n, k, 1, combination, 0, &result);

    *returnSize = result.size;
    *returnColumnSizes = (int*)malloc(sizeof(int) * result.size);
    for (int i = 0; i < result.size; i++) {
        (*returnColumnSizes)[i] = k;
    }

    free(combination);
    return result.data;
}

int main() {
    int n = 4, k = 2;
    int returnSize;
    int* returnColumnSizes;

    int** combinations = combine(n, k, &returnSize, &returnColumnSizes);

    printf("Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", combinations[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(combinations[i]); // 释放每个组合的内存
    }

    free(combinations); // 释放结果数组的内存
    free(returnColumnSizes); // 释放列大小数组的内存

    return 0;
}


