/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-30 21:49:03
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-30 21:51:06
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode75\LeeCode75.c
 * @Description: 
*       给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
        使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
        我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
        必须在不使用库内置的 sort 函数的情况下解决这个问题。

        示例 1：
        输入：nums = [2,0,2,1,1,0]
        输出：[0,0,1,1,2,2]

        示例 2：
        输入：nums = [2,0,1]
        输出：[0,1,2]
 */

#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int p0 = 0, curr = 0, p2 = numsSize - 1;

    while (curr <= p2) {
        if (nums[curr] == 0) {
            // 交换 nums[curr] 和 nums[p0]
            int temp = nums[curr];
            nums[curr] = nums[p0];
            nums[p0] = temp;
            p0++;
            curr++;
        } else if (nums[curr] == 2) {
            // 交换 nums[curr] 和 nums[p2]
            int temp = nums[curr];
            nums[curr] = nums[p2];
            nums[p2] = temp;
            p2--;
        } else {
            curr++;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    sortColors(nums, numsSize);

    // 输出排序后的数组
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
