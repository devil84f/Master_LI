/***************************************************
 * Date:2024/11/19
 * 题目描述:
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 
表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。
同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，
且区间之间不重叠（如果有必要的话，可以合并区间）。返回插入之后的 intervals。
注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

示例 1：
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

示例 2：
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// Helper function to get the minimum of two values
int min(int a, int b) {
    return a < b ? a : b;
}

// Helper function to get the maximum of two values
int max(int a, int b) {
    return a > b ? a : b;
}

// Main function to insert and merge intervals
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, 
             int* newInterval, int newIntervalSize, 
             int* returnSize, int** returnColumnSizes) {
    // Allocate space for the result
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int idx = 0; // Index to track result array

    int i = 0;

    // Step 1: Add all intervals that end before the new interval starts
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    // Step 2: Merge all overlapping intervals with the new interval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    // Add the merged interval
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = newInterval[0];
    result[idx][1] = newInterval[1];
    (*returnColumnSizes)[idx] = 2;
    idx++;

    // Step 3: Add all remaining intervals
    while (i < intervalsSize) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    // Update the return size
    *returnSize = idx;
    return result;
}

int main() {
    // Input intervals
    int intervalsSize = 2;
    int intervalsColSize[] = {2, 2};
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    intervals[0] = (int*)malloc(2 * sizeof(int));
    intervals[0][0] = 1; intervals[0][1] = 3;
    intervals[1] = (int*)malloc(2 * sizeof(int));
    intervals[1][0] = 6; intervals[1][1] = 9;

    // New interval
    int newInterval[] = {2, 5};
    int newIntervalSize = 2;

    // Output variables
    int returnSize;
    int* returnColumnSizes;

    // Call the insert function
    int** result = insert(intervals, intervalsSize, intervalsColSize, 
                          newInterval, newIntervalSize, 
                          &returnSize, &returnColumnSizes);

    // Print the result
    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
        free(result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);
    free(returnColumnSizes);
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);

    return 0;
}
