/***************************************************
 * Date:2024/11/13
 * 题目描述:
给你一个 m 行 n 列的矩阵 matrix ，请按照顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
        // 从左到右遍历顶行
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;  // 顶行向下收缩

        // 从上到下遍历最右列
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;  // 右列向左收缩

        // 从右到左遍历底行（确保尚未遍历过）
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;  // 底行向上收缩
        }

        // 从下到上遍历最左列（确保尚未遍历过）
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;  // 左列向右收缩
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

    printf("螺旋顺序遍历结果: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
