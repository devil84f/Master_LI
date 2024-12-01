/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-01 20:44:28
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-01 20:47:16
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode78\LeeCode78.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int** result, int* returnColumnSizes, int* subset, int subsetSize, int start, int* returnSize) {
    // 创建一个当前子集的副本
    result[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++) {
        result[*returnSize][i] = subset[i];
    }
    returnColumnSizes[*returnSize] = subsetSize;
    (*returnSize)++;

    // 继续生成子集
    for (int i = start; i < numsSize; i++) {
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, result, returnColumnSizes, subset, subsetSize + 1, i + 1, returnSize);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize; // 子集总数是 2^n
    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
    *returnSize = 0;

    int* subset = (int*)malloc(numsSize * sizeof(int)); // 临时存储一个子集
    backtrack(nums, numsSize, result, *returnColumnSizes, subset, 0, 0, returnSize);

    free(subset);
    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    // 打印结果
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]");
        if (i < returnSize - 1) printf(",");
        printf("\n");
    }
    printf("]\n");

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
