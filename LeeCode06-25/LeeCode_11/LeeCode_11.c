/***************************************************
 * Date:2024/10/16
 * 题目描述:
题目描述：
给定一个整数数组 height，每个元素代表图中对应位置的高度。容器的宽度是由两个线段的索引差决定的，计算盛水的最大容量。

示例：
示例 1：
输入：height = [1,8,6,2,5,4,8,3,7]
输出：49
解释：高度为 8 和 7 的线段形成的容器能够盛水的最大容量为 49。

示例 2：
输入：height = [1,1]
输出：1
/***************************************************/

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = current_height * width;
        max_area = max_area > current_area ? max_area : current_area;

        // 移动指向较短线段的指针
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    printf("Maximum area: %d\n", maxArea(height, size)); // 输出：49
    return 0;
}

