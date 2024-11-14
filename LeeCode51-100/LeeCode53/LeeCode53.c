/***************************************************
 * Date:2024/11/15
 * 题目描述:
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
返回其最大和。子数组是数组中的一个连续部分。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
/***************************************************/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxSum = nums[0];  // 保存最大和
    int currentSum = nums[0];  // 保存当前的子数组和

    for (int i = 1; i < numsSize; i++) {
        currentSum = currentSum > 0 ? currentSum + nums[i] : nums[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubArray(nums, numsSize);
    printf("最大子数组和为: %d\n", result);  // 输出 6

    return 0;
}
