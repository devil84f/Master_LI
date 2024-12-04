#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For strcmp

// 回溯函数生成所有子集
void backtrack(int* nums, int numsSize, int start, int* current, int currentSize, int*** result, int* returnSize, int* returnCapacity) {
    // 如果需要更多空间，则重新分配
    if (*returnSize >= *returnCapacity) {
        *returnCapacity *= 2;
        *result = realloc(*result, sizeof(int*) * (*returnCapacity));
        if (*result == NULL) {
            // 检查realloc是否成功
            printf("Memory allocation failed!\n");
            exit(1);  // Exit if memory allocation fails
        }
    }
    
    // 复制当前子集并存储
    int* subset = (int*)malloc(sizeof(int) * currentSize);
    if (subset == NULL) {
        // 检查malloc是否成功
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    
    // 复制当前子集到新分配的内存
    for (int i = 0; i < currentSize; i++) {
        subset[i] = current[i];
    }

    // 将当前子集添加到结果中
    (*result)[*returnSize] = subset;
    (*returnSize)++;

    // 回溯递归生成子集
    for (int i = start; i < numsSize; i++) {
        // 跳过重复的元素
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // 选择当前元素
        current[currentSize] = nums[i];
        // 递归生成下一个子集
        backtrack(nums, numsSize, i + 1, current, currentSize + 1, result, returnSize, returnCapacity);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize) {
    // 排序，确保重复元素可以被跳过
    qsort(nums, numsSize, sizeof(int), (int(*)(const void*, const void*))strcmp);

    // 初始化返回的二维数组
    int **result = (int**)malloc(sizeof(int*) * 100); // 初始空间大小
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }

    *returnSize = 0;
    int returnCapacity = 100;
    int* current = (int*)malloc(sizeof(int) * numsSize);
    if (current == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }

    // 回溯生成所有子集
    backtrack(nums, numsSize, 0, current, 0, &result, returnSize, &returnCapacity);
    
    free(current);
    return result;
}

// 打印二维数组
void printSubsets(int** result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        int j = 0;
        while (result[i][j] != '\0') {
            printf("%d", result[i][j]);
            if (result[i][j + 1] != '\0') {
                printf(", ");
            }
            j++;
        }
        printf("]\n");
    }
}

int main() {
    int nums[] = {1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    
    int** result = subsetsWithDup(nums, numsSize, &returnSize);
    
    printSubsets(result, returnSize);

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    
    return 0;
}
