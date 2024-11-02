/***************************************************
 * Date:2024/11/2 
 * ��Ŀ����:
����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target��
�����ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
��������в�����Ŀ��ֵ target������ [-1, -1]��
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

ʾ�� 1��
���룺nums = [5,7,7,8,8,10], target = 8
�����[3,4]

ʾ�� 2��
���룺nums = [5,7,7,8,8,10], target = 6
�����[-1,-1]

ʾ�� 3��
���룺nums = [], target = 0
�����[-1,-1]
/***************************************************/

#include <stdio.h>

int findFirst(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first = mid;
            right = mid - 1; // ����������ҵ���һ��λ��
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

int findLast(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last = mid;
            left = mid + 1; // ���Ҳ������ҵ����һ��λ��
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    *returnSize = 2;
    return result;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    int* result = searchRange(nums, 6, target, &returnSize);
    printf("[%d, %d]\n", result[0], result[1]);
    free(result);
    return 0;
}
