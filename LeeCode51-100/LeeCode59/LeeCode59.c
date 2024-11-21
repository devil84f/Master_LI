/***************************************************
 * Date:2024/11/21
 * ��Ŀ����:
����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ�
��Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��

ʾ�� 1��
���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]

ʾ�� 2��
���룺n = 1
�����[[1]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // Initialize boundaries
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1; // Start filling from 1

    while (num <= n * n) {
        // Fill top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Fill bottom row
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // Fill left column
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    *returnSize = n;
    return matrix;
}

int main() {
    int n = 3;
    int returnSize;
    int* returnColumnSizes;

    // Generate the spiral matrix
    int** result = generateMatrix(n, &returnSize, &returnColumnSizes);

    // Print the result
    printf("Spiral Matrix:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]); // Free each row
    }

    // Free allocated memory
    free(result);
    free(returnColumnSizes);

    return 0;
}
