/***************************************************
 * Date:2024/11/6
 * 题目描述:
给定一个候选人编号的集合 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[[1,1,6],
[1,2,5],
[1,7],
[2,6]]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[[1,2,2],
[5]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

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

// 添加组合到结果数组
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

// 比较函数，用于排序
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// 回溯函数
void backtrack(int* candidates, int candidatesSize, int target, int* combination, int length, int start, ResultArray* result) {
    if (target == 0) {  // 找到一个组合
        addResult(result, combination, length);
        return;
    }
    if (target < 0) return;  // 当前组合无效

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;  // 跳过重复元素
        combination[length] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], combination, length + 1, i + 1, result);
    }
}

// 主函数
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);  // 排序，方便去重
    ResultArray* result = createResultArray();
    int* combination = (int*)malloc(target * sizeof(int));  // 用于存储当前组合

    backtrack(candidates, candidatesSize, target, combination, 0, 0, result);

    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    return result->data;
}

// 测试代码
int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum2(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);

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
