/***************************************************
 * Date:2024/10/30  �ٷ���� 
 * ��Ŀ����:
���������һ�� ����  ���ǽ������г�Ա�����л�����˳�����С�

���磬arr = [1,2,3] ��������Щ���������� arr �����У�[1,2,3]��[1,3,2]��[3,1,2]��[2,3,1] ��
��������� ��һ������ ��ָ����������һ���ֵ����������С�����ʽ�أ����������������и������ֵ�˳���С����������һ�������У�
��ô����� ��һ������ �������������������������������Ǹ����С������������һ����������У���ô��������������Ϊ�ֵ�����С�����У�������Ԫ�ذ��������У���
���磬arr = [1,2,3] ����һ�������� [1,3,2] ��
���Ƶأ�arr = [2,3,1] ����һ�������� [3,1,2] ��
�� arr = [3,2,1] ����һ�������� [1,2,3] ����Ϊ [3,2,1] ������һ���ֵ����������С�
����һ���������� nums ���ҳ� nums ����һ�����С�
���� ԭ�� �޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

ʾ�� 1��
���룺nums = [1,2,3]
�����[1,3,2]

ʾ�� 2��
���룺nums = [3,2,1]
�����[1,2,3]

ʾ�� 3��
���룺nums = [1,1,5]
�����[1,5,1]
/***************************************************/

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    
    // Step 1: ���ҵ����ҵ���һ���½���λ��
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    if (i >= 0) {
        // Step 2: ���ҵ����ҵ���һ������ nums[i] ��Ԫ��
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Step 3: ���� nums[i] �� nums[j]
        swap(&nums[i], &nums[j]);
    }
    
    // Step 4: ��ת i+1 ��ĩβ��Ԫ��
    reverse(nums, i + 1, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, numsSize);

    printf("Next permutation: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
