/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-06 23:31:36
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-06 23:46:50
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode136\LeeCode136.c
 * @Description: 
 * 
 */

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];  // ��ÿ�����ֽ���������
    }
    return result;  // ���շ���ֻ����һ�ε�����
}

int main() {
    int nums1[] = {2, 2, 1};
    int nums2[] = {4, 1, 2, 1, 2};
    int nums3[] = {1};
    
    printf("Result 1: %d\n", singleNumber(nums1, 3));  // ��� 1
    printf("Result 2: %d\n", singleNumber(nums2, 5));  // ��� 4
    printf("Result 3: %d\n", singleNumber(nums3, 1));  // ��� 1

    return 0;
}
