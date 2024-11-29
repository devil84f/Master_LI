/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-29 15:50:39
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-29 15:51:05
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode73\LeeCode73.c
 * @Description: 
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用原地算法。

示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
 */

#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize; // 矩阵的行数
    int n = *matrixColSize; // 矩阵的列数

    int firstRowZero = 0, firstColZero = 0;

    // 检查第一行是否需要置零
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // 检查第一列是否需要置零
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // 使用第一行和第一列标记其他行列需要置零
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // 标记该行
                matrix[0][j] = 0; // 标记该列
            }
        }
    }

    // 根据标记的行列置零
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // 处理第一行
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // 处理第一列
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    int m = 3, n = 4;
    
    // 动态分配内存
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // 初始化矩阵
    int matrixData[3][4] = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    // 将数据复制到动态分配的矩阵中
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrixData[i][j];
        }
    }

    setZeroes(matrix, m, &n);

    // 打印结果
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

