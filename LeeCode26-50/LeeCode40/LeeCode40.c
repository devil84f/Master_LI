/***************************************************
 * Date:2024/11/6
 * ��Ŀ����:
����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ��
�ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��
ע�⣺�⼯���ܰ����ظ�����ϡ� 

ʾ�� 1:
����: candidates = [10,1,2,7,6,1,5], target = 8,
���:
[[1,1,6],
[1,2,5],
[1,7],
[2,6]]

ʾ�� 2:
����: candidates = [2,5,2,1,2], target = 5,
���:
[[1,2,2],
[5]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** data;
    int* columnSizes;
    int size;
    int capacity;
} ResultArray;

// ��ʼ���������
ResultArray* createResultArray() {
    ResultArray* result = (ResultArray*)malloc(sizeof(ResultArray));
    result->data = (int**)malloc(100 * sizeof(int*));
    result->columnSizes = (int*)malloc(100 * sizeof(int));
    result->size = 0;
    result->capacity = 100;
    return result;
}

// �����ϵ��������
void addResult(ResultArray* result, int* combination, int length) {
    if (result->size >= result->capacity) {
        result->capacity *= 2;
        result->data = (int**)realloc(result->data, result->capacity * sizeof(int*));
        result->columnSizes = (int*)realloc(result->columnSizes, result->capacity * sizeof(int));
    }
    result->data[result->size] = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        result->data[result->size][i] = combination[i];
    }
    result->columnSizes[result->size] = length;
    result->size++;
}

// �ȽϺ�������������
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// ���ݺ���
void backtrack(int* candidates, int candidatesSize, int target, int* combination, int length, int start, ResultArray* result) {
    if (target == 0) {  // �ҵ�һ�����
        addResult(result, combination, length);
        return;
    }
    if (target < 0) return;  // ��ǰ�����Ч

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;  // �����ظ�Ԫ��
        combination[length] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], combination, length + 1, i + 1, result);
    }
}

// ������
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);  // ���򣬷���ȥ��
    ResultArray* result = createResultArray();
    int* combination = (int*)malloc(target * sizeof(int));  // ���ڴ洢��ǰ���

    backtrack(candidates, candidatesSize, target, combination, 0, 0, result);

    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    return result->data;
}

// ���Դ���
int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum2(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);

    printf("����ܺ͵Ľ��Ϊ��\n");
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
