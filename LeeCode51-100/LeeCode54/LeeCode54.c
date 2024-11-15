/***************************************************
 * Date:2024/11/13
 * ��Ŀ����:
����һ�� m �� n �еľ��� matrix ���밴��˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�

ʾ�� 1��
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,3,6,9,8,7,4,5]

ʾ�� 2��
���룺matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
�����[1,2,3,4,8,12,11,10,9,5,6,7]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    int total = matrixSize * matrixColSize[0];
    
    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    while (top <= bottom && left <= right) {
        // �����ұ�������
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;  // ������������

        // ���ϵ��±���������
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;  // ������������

        // ���ҵ���������У�ȷ����δ��������
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;  // ������������
        }

        // ���µ��ϱ��������У�ȷ����δ��������
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;  // ������������
        }
    }

    return result;
}

int main() {
    int rows = 3, cols = 3;
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* matrix[3];
    for (int i = 0; i < rows; i++) {
        matrix[i] = data[i];
    }
    int matrixColSize[] = {3, 3, 3};
    int returnSize;

    int* result = spiralOrder(matrix, rows, matrixColSize, &returnSize);

    printf("����˳��������: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
