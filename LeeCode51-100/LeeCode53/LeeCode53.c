/***************************************************
 * Date:2024/11/15
 * ��Ŀ����:
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ���
���������͡��������������е�һ���������֡�

ʾ�� 1��
���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
�����6
���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��

ʾ�� 2��
���룺nums = [1]
�����1

ʾ�� 3��
���룺nums = [5,4,-1,7,8]
�����23
/***************************************************/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxSum = nums[0];  // ��������
    int currentSum = nums[0];  // ���浱ǰ���������

    for (int i = 1; i < numsSize; i++) {
        currentSum = currentSum > 0 ? currentSum + nums[i] : nums[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubArray(nums, numsSize);
    printf("����������Ϊ: %d\n", result);  // ��� 6

    return 0;
}
