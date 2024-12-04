#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For strcmp

// ���ݺ������������Ӽ�
void backtrack(int* nums, int numsSize, int start, int* current, int currentSize, int*** result, int* returnSize, int* returnCapacity) {
    // �����Ҫ����ռ䣬�����·���
    if (*returnSize >= *returnCapacity) {
        *returnCapacity *= 2;
        *result = realloc(*result, sizeof(int*) * (*returnCapacity));
        if (*result == NULL) {
            // ���realloc�Ƿ�ɹ�
            printf("Memory allocation failed!\n");
            exit(1);  // Exit if memory allocation fails
        }
    }
    
    // ���Ƶ�ǰ�Ӽ����洢
    int* subset = (int*)malloc(sizeof(int) * currentSize);
    if (subset == NULL) {
        // ���malloc�Ƿ�ɹ�
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    
    // ���Ƶ�ǰ�Ӽ����·�����ڴ�
    for (int i = 0; i < currentSize; i++) {
        subset[i] = current[i];
    }

    // ����ǰ�Ӽ���ӵ������
    (*result)[*returnSize] = subset;
    (*returnSize)++;

    // ���ݵݹ������Ӽ�
    for (int i = start; i < numsSize; i++) {
        // �����ظ���Ԫ��
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // ѡ��ǰԪ��
        current[currentSize] = nums[i];
        // �ݹ�������һ���Ӽ�
        backtrack(nums, numsSize, i + 1, current, currentSize + 1, result, returnSize, returnCapacity);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize) {
    // ����ȷ���ظ�Ԫ�ؿ��Ա�����
    qsort(nums, numsSize, sizeof(int), (int(*)(const void*, const void*))strcmp);

    // ��ʼ�����صĶ�ά����
    int **result = (int**)malloc(sizeof(int*) * 100); // ��ʼ�ռ��С
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }

    *returnSize = 0;
    int returnCapacity = 100;
    int* current = (int*)malloc(sizeof(int) * numsSize);
    if (current == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }

    // �������������Ӽ�
    backtrack(nums, numsSize, 0, current, 0, &result, returnSize, &returnCapacity);
    
    free(current);
    return result;
}

// ��ӡ��ά����
void printSubsets(int** result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        int j = 0;
        while (result[i][j] != '\0') {
            printf("%d", result[i][j]);
            if (result[i][j + 1] != '\0') {
                printf(", ");
            }
            j++;
        }
        printf("]\n");
    }
}

int main() {
    int nums[] = {1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    
    int** result = subsetsWithDup(nums, numsSize, &returnSize);
    
    printSubsets(result, returnSize);

    // �ͷ��ڴ�
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    
    return 0;
}
