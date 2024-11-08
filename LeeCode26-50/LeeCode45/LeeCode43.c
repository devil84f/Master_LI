/***************************************************
 * Date:2024/11/8
 * 题目描述:
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，
如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
/***************************************************/

#include <stdio.h>

// 跳跃游戏 II 主函数
int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;  // 当数组长度为1时，不需要跳跃

    int jumps = 0;           // 跳跃次数
    int currentEnd = 0;      // 当前跳跃的边界
    int farthest = 0;        // 当前能跳到的最远位置

    for (int i = 0; i < numsSize - 1; i++) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;  // 更新最远距离

        // 当达到当前边界时，必须进行跳跃，更新边界
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            // 如果当前边界已经能到达终点，则跳出循环
            if (currentEnd >= numsSize - 1) {
                break;
            }
        }
    }
    return jumps;
}

// 测试代码
int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = jump(nums, numsSize);
    printf("最少跳跃次数为: %d\n", result);
    
    return 0;
}
