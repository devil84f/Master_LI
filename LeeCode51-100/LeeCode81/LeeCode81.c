/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-02 10:56:27
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-02 11:05:16
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode81\LeeCode81.c
 * @Description: 
 *      已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
        在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，
        使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
        例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
        给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。
        如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
        你必须尽可能减少整个操作步骤。

        示例 1：
        输入：nums = [2,5,6,0,0,1,2], target = 0
        输出：true

        示例 2：
        输入：nums = [2,5,6,0,0,1,2], target = 3
        输出：false
 */

#include <stdio.h>
#include <stdbool.h>

// 主函数实现搜索旋转排序数组
bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 如果找到目标值，直接返回 true
        if (nums[mid] == target) return true;

        // 如果无法判断哪一边有序
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // 如果左半部分是有序的
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // 在左半部分
            } else {
                left = mid + 1;  // 在右半部分
            }
        }
        // 如果右半部分是有序的
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  // 在右半部分
            } else {
                right = mid - 1; // 在左半部分
            }
        }
    }

    return false; // 未找到目标值
}

// 测试主函数
int main() {
    // 测试用例 1
    int nums1[] = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    printf("Test Case 1: %s\n", search(nums1, sizeof(nums1) / sizeof(nums1[0]), target1) ? "true" : "false");

    // 测试用例 2
    int nums2[] = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    printf("Test Case 2: %s\n", search(nums2, sizeof(nums2) / sizeof(nums2[0]), target2) ? "true" : "false");

    // 测试用例 3
    int nums3[] = {1, 0, 1, 1, 1};
    int target3 = 0;
    printf("Test Case 3: %s\n", search(nums3, sizeof(nums3) / sizeof(nums3[0]), target3) ? "true" : "false");

    // 测试用例 4
    int nums4[] = {1, 3};
    int target4 = 3;
    printf("Test Case 4: %s\n", search(nums4, sizeof(nums4) / sizeof(nums4[0]), target4) ? "true" : "false");

    return 0;
}

