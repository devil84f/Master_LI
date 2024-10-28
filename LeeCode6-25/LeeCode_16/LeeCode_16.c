/***************************************************
 * Date:2024/10/19
 * 题目描述:
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
使它们的和与 target 最接近。返回这三个数的和。
假定每组输入只存在恰好一个解。

示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。

示例 2：
输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare); // 排序

    int closestSum = nums[0] + nums[1] + nums[2]; // 初始化最接近的和

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // 更新最接近的和
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum; // 如果恰好等于目标值
            }
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, sizeof(nums) / sizeof(nums[0]), target);
    printf("The closest sum to target %d is %d\n", target, result); // 输出：2
    return 0;
}
