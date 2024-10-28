/***************************************************
 * Date:2024/10/18
 * ��Ŀ����:
����һ���������� nums������Ҫ�ҳ��������� nums[a] + nums[b] + nums[c] = 0 ����Ԫ�� (a, b, c)������ a��b �� c ������ͬ��

ʾ����
ʾ�� 1��

���룺nums = [-1, 0, 1, 2, -1, -4]
�����[[-1, -1, 2], [-1, 0, 1]]
ʾ�� 2��

���룺nums = []
�����[]
ʾ�� 3��

���룺nums = [0]
�����[]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 100; // ��ʼ������
    int** result = (int**)malloc(sizeof(int*) * capacity); // Ԥ���ռ�
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    qsort(nums, numsSize, sizeof(int), compare); // ����

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // ȥ��

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (*returnSize >= capacity) { // �������
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                }

                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // ȥ��
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, size, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]); // �ͷ��ڴ�
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}
