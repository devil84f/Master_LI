/***************************************************
 * Date:2024/11/9
 * 题目描述:
给定一个不含重复数字的数组 nums ，返回其所有可能的全排列。你可以按任意顺序返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int** data;       // 存储所有排列结果
    int* columnSizes; // 每个排列的长度
    int size;         // 当前排列的数量
    int capacity;     // 容量
} ResultArray;

// 初始化结果数组
ResultArray* createResultArray(int capacity) {
    ResultArray* result = (ResultArray*)malloc(sizeof(ResultArray));
    result->data = (int**)malloc(capacity * sizeof(int*));
    result->columnSizes = (int*)malloc(capacity * sizeof(int));
    result->size = 0;
    result->capacity = capacity;
    return result;
}

// 添加排列到结果数组
void addResult(ResultArray* result, int* permutation, int length) {
    if (result->size >= result->capacity) {
        result->capacity *= 2;
        result->data = (int**)realloc(result->data, result->capacity * sizeof(int*));
        result->columnSizes = (int*)realloc(result->columnSizes, result->capacity * sizeof(int));
    }
    result->data[result->size] = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        result->data[result->size][i] = permutation[i];
    }
    result->columnSizes[result->size] = length;
    result->size++;
}

// 递归函数生成排列
void backtrack(int* nums, int numsSize, int* permutation, int level, bool* used, ResultArray* result) {
    if (level == numsSize) {  // 生成完整排列
        addResult(result, permutation, numsSize);
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {  // 选择一个未使用的数字
            used[i] = true;
            permutation[level] = nums[i];
            backtrack(nums, numsSize, permutation, level + 1, used, result);  // 递归
            used[i] = false;  // 回溯
        }
    }
}

// 主函数
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    ResultArray* result = createResultArray(100); // 初始化结果数组
    int* permutation = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    
    backtrack(nums, numsSize, permutation, 0, used, result);
    
    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    free(permutation);
    free(used);
    return result->data;
}

// 测试代码
int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    
    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    
    printf("所有排列结果:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]);
    }
    
    free(result);
    free(returnColumnSizes);
    return 0;
}
