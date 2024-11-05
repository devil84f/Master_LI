/***************************************************
 * Date:2024/11/4
 * ��Ŀ����:
����һ�� ���ظ�Ԫ�ص��������� candidates ��һ��Ŀ������ target ��
�ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���в�ͬ��� �������б���ʽ���ء�
����԰� ����˳�򷵻���Щ��ϡ�
candidates �е�ͬһ�����ֿ����������ظ���ѡȡ��
�������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ� 
���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����

ʾ�� 1��
���룺candidates = [2,3,6,7], target = 7
�����[[2,2,3],[7]]

ʾ�� 2��
����: candidates = [2,3,5], target = 8
���: [[2,2,2,2],[2,3,3],[3,5]]

ʾ�� 3��
����: candidates = [2], target = 1
���: []
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// ��̬�������ڴ洢���
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

// �������ӵ������
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

// ���ݺ���
void backtrack(int* candidates, int candidatesSize, int target, int* combination, int length, int start, ResultArray* result) {
    if (target == 0) {  // �ҵ�һ�����
        addResult(result, combination, length);
        return;
    }
    if (target < 0) return;  // ��Ч���

    for (int i = start; i < candidatesSize; i++) {
        combination[length] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], combination, length + 1, i, result);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    ResultArray* result = createResultArray();
    int* combination = (int*)malloc(target * sizeof(int));  // �洢�������

    // ���û��ݺ���
    backtrack(candidates, candidatesSize, target, combination, 0, 0, result);

    // ���ؽ��
    *returnSize = result->size;
    *returnColumnSizes = result->columnSizes;
    return result->data;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);

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
