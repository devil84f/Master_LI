/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-26 15:26:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-26 16:15:27
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode117\LeeCode117.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 生成杨辉三角并返回二维数组
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // 创建二维数组存储杨辉三角
    int** result = (int**)malloc(numRows * sizeof(int*));

    // 为列数数组分配内存
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // 遍历每一行，计算并生成每行的元素
    for (int i = 0; i < numRows; i++) {
        // 当前行有 i+1 个元素
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;  // 每行的列数为 i+1
        
        // 每行的第一个和最后一个元素为 1
        result[i][0] = 1;
        result[i][i] = 1;

        // 填充当前行中间的元素
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    *returnSize = numRows;  // 返回行数
    return result;  // 返回生成的杨辉三角
}

// 打印杨辉三角
void printTriangle(int** triangle, int numRows, int* columnSizes) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;

    // 生成杨辉三角
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    // 打印杨辉三角
    printTriangle(triangle, numRows, returnColumnSizes);

    // 释放内存
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}
