/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-19 11:01:01
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-29 16:48:46
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode74\LeeCode74.c
 * @Description: 
 *      ����һ�����������������Ե� m x n ��������
        ÿ���е����������Ұ����ϸ����˳�����С�ÿ�еĵ�һ����������ǰһ�е����һ��������
        ����һ������ target ����� target �ھ����У����� true �����򣬷��� false ��

        ʾ�� 1��
        ���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        �����true
 */

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize; // ���������
    int n = *matrixColSize; // ���������
    
    int row = 0;
    int col = n - 1; // �����Ͻǿ�ʼ

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // �ҵ�Ŀ��ֵ
        } else if (matrix[row][col] < target) {
            row++; // Ŀ����ڵ�ǰֵ�������ƶ�
        } else {
            col--; // Ŀ��С�ڵ�ǰֵ�������ƶ�
        }
    }

    return false; // δ�ҵ�Ŀ��ֵ
}

int main() {
    // ʾ������
    int matrix[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int matrixSize = 4;
    int matrixColSize = 4;
    int target = 5;

    // ʹ�ö�̬���鴫�ݾ���
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
