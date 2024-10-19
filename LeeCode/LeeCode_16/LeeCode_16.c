/***************************************************
 * Date:2024/10/19
 * ��Ŀ����:
����һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������
ʹ���ǵĺ��� target ��ӽ����������������ĺ͡�
�ٶ�ÿ������ֻ����ǡ��һ���⡣

ʾ�� 1��
���룺nums = [-1,2,1,-4], target = 1
�����2
���ͣ��� target ��ӽ��ĺ��� 2 (-1 + 2 + 1 = 2)��

ʾ�� 2��
���룺nums = [0,0,0], target = 1
�����0
���ͣ��� target ��ӽ��ĺ��� 0��0 + 0 + 0 = 0����
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare); // ����

    int closestSum = nums[0] + nums[1] + nums[2]; // ��ʼ����ӽ��ĺ�

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // ������ӽ��ĺ�
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum; // ���ǡ�õ���Ŀ��ֵ
            }
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, sizeof(nums) / sizeof(nums[0]), target);
    printf("The closest sum to target %d is %d\n", target, result); // �����2
    return 0;
}
