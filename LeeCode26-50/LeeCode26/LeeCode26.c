/***************************************************
 * Date:2024/10/28
 * 题目描述:
给定一个按升序排列的整数数组 nums，要求原地删除重复出现的元素，使每个元素只出现一次，并返回新的长度。
元素的相对顺序应保持不变。不要使用额外的空间，必须在原地修改输入数组，并在 O(1) 的额外空间中完成。

示例：
输入：nums = [1, 1, 2]
输出：2, nums = [1, 2]

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0, 1, 2, 3, 4]
/***************************************************/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0; // 慢指针
    for (int j = 1; j < numsSize; j++) { // 快指针
        if (nums[j] != nums[i]) { // 遇到新元素
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // 返回新长度
}

// 测试函数
int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, size);
    printf("新的长度: %d\n", newLength);

    printf("修改后的数组: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
