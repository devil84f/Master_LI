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

// 定义区间结构体
typedef struct {
    int start;
    int end;
} Interval;

// 函数声明
Interval* insert(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize);

// 主函数
int main() {
    Interval intervals[] = {{1, 3}, {6, 9}};
    Interval newInterval = {2, 5};
    int returnSize;

    Interval* result = insert(intervals, 2, newInterval, &returnSize);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");

    free(result);
    return 0;
}

// 插入区间函数
Interval* insert(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize) {
    // 动态分配足够大的结果数组
    Interval* result = (Interval*)malloc((intervalsSize + 1) * sizeof(Interval));
    int idx = 0;

    // 遍历区间
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i].end < newInterval.start) {
            // 当前区间在新区间左侧
            result[idx++] = intervals[i];
        } else if (intervals[i].start > newInterval.end) {
            // 当前区间在新区间右侧
            result[idx++] = newInterval;
            newInterval = intervals[i]; // 替换新区间为当前区间
        } else {
            // 当前区间与新区间重叠，合并区间
            newInterval.start = (newInterval.start < intervals[i].start) ? newInterval.start : intervals[i].start;
            newInterval.end = (newInterval.end > intervals[i].end) ? newInterval.end : intervals[i].end;
        }
    }

    // 将最后的区间加入结果
    result[idx++] = newInterval;

    // 返回结果大小
    *returnSize = idx;
    return result;
}
