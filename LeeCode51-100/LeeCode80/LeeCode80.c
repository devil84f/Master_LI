/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-01 21:29:36
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-01 21:31:02
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode80\LeeCode80.c
 * @Description: 
        * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，
        * 返回删除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

        示例 1：
        输入：nums = [1,1,1,2,2,3]
        输出：5, nums = [1,1,2,2,3]
        解释：函数应返回新长度 length = 5, 
        并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize; // 长度小于等于2时，无需处理
    }

    int i = 2; // 指向最终数组的下一个待写入位置
    for (int j = 2; j < numsSize; j++) {
        // 如果当前元素与最终数组倒数第二个元素不相等，则写入
        if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i; // 新数组的长度
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    printf("New length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
