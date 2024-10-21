/***************************************************
 * Date:2024/10/21
 * ��Ŀ����:�绰�������ĸ���
����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target ��
�����ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] 
����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����

0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰� ����˳�� ���ش� ��

ʾ�� 1��
���룺nums = [1,0,-1,0,-2,2], target = 0
�����[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

ʾ�� 2��
���룺nums = [2,2,2,2,2], target = 8
�����[[2,2,2,2]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int capacity = 10000; // ������෵��10000����
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = numsSize - 1;

            while (k < l) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if (sum == target) {
                    result[*returnSize] = malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];
                    result[*returnSize][3] = nums[l];
                    (*returnColumnSizes)[*returnSize] = 4; // ÿ�����Ĵ�СΪ4
                    (*returnSize)++;

                    while (k < l && nums[k] == nums[k + 1]) k++;
                    while (k < l && nums[l] == nums[l - 1]) l--;
                    k++;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {1000000000,1000000000,1000000000,1000000000};
    int target = 0;
    int returnSize;
    int* returnColumnSizes;
    
    int** result = fourSum(nums, 6, target, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d, %d]\n", result[i][0], result[i][1], result[i][2], result[i][3]);
        free(result[i]); // �ͷ��ڴ�
    }
    free(result); // �ͷ��ڴ�
    free(returnColumnSizes); // �ͷŷ����д�С����

    return 0;
}


