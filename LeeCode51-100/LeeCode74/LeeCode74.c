/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-19 11:01:01
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-29 16:48:46
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode74\LeeCode74.c
 * @Description: 
 *      给你一个满足下述两条属性的 m x n 整数矩阵：
        每行中的整数从左到右按非严格递增顺序排列。每行的第一个整数大于前一行的最后一个整数。
        给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

        示例 1：
        输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        输出：true
 */

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize; // 矩阵的行数
    int n = *matrixColSize; // 矩阵的列数
    
    int row = 0;
    int col = n - 1; // 从右上角开始

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // 找到目标值
        } else if (matrix[row][col] < target) {
            row++; // 目标大于当前值，向下移动
        } else {
            col--; // 目标小于当前值，向左移动
        }
    }

    return false; // 未找到目标值
}

int main() {
    // 示例矩阵
    int matrix[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int matrixSize = 4;
    int matrixColSize = 4;
    int target = 5;

    // 使用动态数组传递矩阵
    int* matrixPtr[4];
    for (int i = 0; i < matrixSize; i++) {
        matrixPtr[i] = matrix[i];
    }

    bool result = searchMatrix(matrixPtr, matrixSize, &matrixColSize, target);

    if (result) {
        printf("Found %d in the matrix.\n", target);
    } else {
        printf("%d not found in the matrix.\n", target);
    }

    return 0;
}
