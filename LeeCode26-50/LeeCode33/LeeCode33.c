/***************************************************
 * Date:2024/10/30  官方题解 
 * 题目描述:
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
使数组变为 [nums[k],nums[k+1], ..., nums[n-1],nums[0],nums[1],...,nums[k-1]]
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，
则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：
输入：nums = [1], target = 0
输出：-1
/***************************************************/

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // 找到目标值，直接返回索引
        }

        // 判断左半部分是否有序
        if (nums[left] <= nums[mid]) {
            // 如果目标值在左半部分，则继续搜索左半部分
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1; // 否则，搜索右半部分
            }
        } 
        // 否则右半部分一定是有序的
        else {
            // 如果目标值在右半部分，则继续搜索右半部分
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1; // 否则，搜索左半部分
            }
        }
    }

    return -1; // 未找到目标值
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int index = search(nums, 7, target);
    printf("Target %d found at index: %d\n", target, index);
    return 0;
}

