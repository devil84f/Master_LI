/***************************************************
 * Date:2024/11/18
 * 题目描述:
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于按起点排序区间
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];
    }
    return intervalA[1] - intervalB[1];
}

// 合并区间函数
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 按起点排序区间
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // 动态分配结果数组
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    // 初始化第一个区间
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;

    // 遍历区间进行合并
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[count][1]) {
            // 合并区间
            result[count][1] = (intervals[i][1] > result[count][1]) ? intervals[i][1] : result[count][1];
        } else {
            // 新区间
            count++;
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
        }
    }

    // 更新返回的结果大小
    *returnSize = count + 1;

    return result;
}

// 测试代码
int main() {
    int intervalsArray[4][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int intervalsSize = 4;
    int* intervals[4];
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = intervalsArray[i];
    }
    int intervalsColSize[] = {2, 2, 2, 2};

    int returnSize;
    int* returnColumnSizes;

    int** result = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("合并后的区间：\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}
