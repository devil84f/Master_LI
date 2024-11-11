/***************************************************
 * Date:2024/11/9
 * ��Ŀ����:
����һ�������ظ����ֵ����� nums �����������п��ܵ�ȫ���С�����԰�����˳�򷵻ش𰸡�

ʾ�� 1��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

ʾ�� 2��
���룺nums = [0,1]
�����[[0,1],[1,0]]

ʾ�� 3��
���룺nums = [1]
�����[[1]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int** data;       // �洢�������н��
    int* columnSizes; // ÿ�����еĳ���
    int size;         // ��ǰ���е�����
    int capacity;     // ����
} ResultArray;

// ��ʼ���������
ResultArray* createResultArray(int capacity) {
    ResultArray* result = (ResultArray*)malloc(sizeof(ResultArray));
    result->data = (int**)malloc(capacity * sizeof(int*));
    result->columnSizes = (int*)malloc(capacity * sizeof(int));
    result->size = 0;
    result->capacity = capacity;
    return result;
}

// ������е��������
void addResult(ResultArray* result, int* permutation, int length) {
    if (result->size >= result->capacity) {
        result->capacity *= 2;
        result->data = (int**)realloc(result->data, result->capacity * sizeof(int*));
        result->columnSizes = (int*)realloc(result->columnSizes, result->capacity * sizeof(int));
    }
    result->data[result->size] = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        result->data[result->size][i] = permutation[i];
    }
    result->columnSizes[result->size] = length;
    result->size++;
}

// �ݹ麯����������
void backtrack(int* nums, int numsSize, int* permutation, int level, bool* used, ResultArray* result) {
    if (level == numsSize) {  // ������������
        addResult(result, permutation, numsSize);
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {  // ѡ��һ��δʹ�õ�����
            used[i] = true;
            permutation[level] = nums[i];
            backtrack(nums, numsSize, permutation, level + 1, used, result);  // �ݹ�
            used[i] = false;  // ����
        }
    }
}

// ������
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    ResultArray* result = createResultArray(100); // ��ʼ���������
    int* permutation = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    
    backtrack(nums, numsSize, permutation, 0, used, result);
    
    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    free(permutation);
    free(used);
    return result->data;
}

// ���Դ���
int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    
    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    
    printf("�������н��:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]);
    }
    
    free(result);
    free(returnColumnSizes);
    return 0;
}
