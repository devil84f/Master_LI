/***************************************************
 * Date:2024/11/3
 * ��Ŀ����:
����һ�����������е��������� nums ��һ��Ŀ��ֵ target����� target �����������У�������������
���򣬷���������˳������λ�á�

ʾ�� 1��
����: nums = [1,3,5,6], target = 5
���: 2

ʾ�� 2��
����: nums = [1,3,5,6], target = 2
���: 1

ʾ�� 3��
����: nums = [1,3,5,6], target = 7
���: 4
/***************************************************/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;  // �ҵ�Ŀ��ֵ������������
        } else if (nums[mid] < target) {
            left = mid + 1;  // target���Ҳ࣬������߽�
        } else {
            right = mid - 1; // target����࣬�����ұ߽�
        }
    }
    return left;  // δ�ҵ�Ŀ��ֵ�����ز���λ��
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int result = searchInsert(nums, 4, target);
    printf("����λ��: %d\n", result);
    return 0;
}
