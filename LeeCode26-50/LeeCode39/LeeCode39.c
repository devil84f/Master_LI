/***************************************************
 * Date:2024/11/4
 * 题目描述:
给你一个 无重复元素的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有不同组合 ，并以列表形式返回。
你可以按 任意顺序返回这些组合。
candidates 中的同一个数字可以无限制重复被选取。
如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]

示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
输入: candidates = [2], target = 1
输出: []
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// 动态数组用于存储结果
typedef struct {
    int** data;
    int* columnSizes;
    int size;
    int capacity;
} ResultArray;

// 初始化结果数组
ResultArray* createResultArray() {
    ResultArray* result = (ResultArray*)malloc(sizeof(ResultArray));
    result->data = (int**)malloc(100 * sizeof(int*));
    result->columnSizes = (int*)malloc(100 * sizeof(int));
    result->size = 0;
    result->capacity = 100;
    return result;
}

// 将组合添加到结果中
void addResult(ResultArray* result, int* combination, int length) {
    if (result->size >= result->capacity) {
        result->capacity *= 2;
        result->data = (int**)realloc(result->data, result->capacity * sizeof(int*));
        result->columnSizes = (int*)realloc(result->columnSizes, result->capacity * sizeof(int));
    }
    result->data[result->size] = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        result->data[result->size][i] = combination[i];
    }
    result->columnSizes[result->size] = length;
    result->size++;
}

// 回溯函数
void backtrack(int* candidates, int candidatesSize, int target, int* combination, int length, int start, ResultArray* result) {
    if (target == 0) {  // 找到一个组合
        addResult(result, combination, length);
        return;
    }
    if (target < 0) return;  // 无效组合

    for (int i = start; i < candidatesSize; i++) {
        combination[length] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], combination, length + 1, i, result);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    ResultArray* result = createResultArray();
    int* combination = (int*)malloc(target * sizeof(int));  // 存储单个组合

    // 调用回溯函数
    backtrack(candidates, candidatesSize, target, combination, 0, 0, result);

    // 返回结果
    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    return result->data;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);

    printf("组合总和的结果为：\n");
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
