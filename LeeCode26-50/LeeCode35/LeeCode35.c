/***************************************************
 * Date:2024/11/3
 * 题目描述:
给定一个按升序排列的整数数组 nums 和一个目标值 target，如果 target 存在于数组中，返回其索引。
否则，返回它将按顺序插入的位置。

示例 1：
输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2：
输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3：
输入: nums = [1,3,5,6], target = 7
输出: 4
/***************************************************/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;  // 找到目标值，返回其索引
        } else if (nums[mid] < target) {
            left = mid + 1;  // target在右侧，调整左边界
        } else {
            right = mid - 1; // target在左侧，调整右边界
        }
    }
    return left;  // 未找到目标值，返回插入位置
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int result = searchInsert(nums, 4, target);
    printf("插入位置: %d\n", result);
    return 0;
}
