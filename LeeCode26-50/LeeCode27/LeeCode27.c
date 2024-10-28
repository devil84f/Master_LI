/***************************************************
 * Date:2024/10/27
 * 题目描述:
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。

示例 1：
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2,_,_]
解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。

示例 2：
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3,_,_,_]
解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
/***************************************************/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;

    int i = 0; // 慢指针
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            i++;
        }
        else {
            while (nums[j + 1] == val && j < numsSize) {
                j++;
            }
            nums[i] = nums[j + 1];
        }
    }
    return i; // 返回新长度
}

// 测试函数
int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int val = 2;
    int newLength = removeElement(nums, size, val);
    printf("新的长度: %d\n", newLength);

    printf("修改后的数组: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}