/***************************************************
 * Date:2024/10/30  �ٷ���� 
 * ��Ŀ����:
�������� nums ���������У������е�ֵ ������ͬ ��
�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ�������ת��
ʹ�����Ϊ [nums[k],nums[k+1], ..., nums[n-1],nums[0],nums[1],...,nums[k-1]]
���磬 [0,1,2,4,5,6,7] ���±� 3 ������ת����ܱ�Ϊ [4,5,6,7,0,1,2] ��
���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ��
�򷵻������±꣬���򷵻� -1 ��
��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

ʾ�� 1��
���룺nums = [4,5,6,7,0,1,2], target = 0
�����4

ʾ�� 2��
���룺nums = [4,5,6,7,0,1,2], target = 3
�����-1

ʾ�� 3��
���룺nums = [1], target = 0
�����-1
/***************************************************/

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // �ҵ�Ŀ��ֵ��ֱ�ӷ�������
        }

        // �ж���벿���Ƿ�����
        if (nums[left] <= nums[mid]) {
            // ���Ŀ��ֵ����벿�֣������������벿��
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1; // ���������Ұ벿��
            }
        } 
        // �����Ұ벿��һ���������
        else {
            // ���Ŀ��ֵ���Ұ벿�֣�����������Ұ벿��
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1; // ����������벿��
            }
        }
    }

    return -1; // δ�ҵ�Ŀ��ֵ
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int index = search(nums, 7, target);
    printf("Target %d found at index: %d\n", target, index);
    return 0;
}

