/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-29 15:50:39
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-29 15:51:05
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode73\LeeCode73.c
 * @Description: 
 * ����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ��ԭ���㷨��

ʾ�� 1��
���룺matrix = [[1,1,1],[1,0,1],[1,1,1]]
�����[[1,0,1],[0,0,0],[1,0,1]]
 */

#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize; // ���������
    int n = *matrixColSize; // ���������

    int firstRowZero = 0, firstColZero = 0;

    // ����һ���Ƿ���Ҫ����
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // ����һ���Ƿ���Ҫ����
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // ʹ�õ�һ�к͵�һ�б������������Ҫ����
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // ��Ǹ���
                matrix[0][j] = 0; // ��Ǹ���
            }
        }
    }

    // ���ݱ�ǵ���������
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // �����һ��
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // �����һ��
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    int m = 3, n = 4;
    
    // ��̬�����ڴ�
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // ��ʼ������
    int matrixData[3][4] = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    // �����ݸ��Ƶ���̬����ľ�����
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrixData[i][j];
        }
    }

    setZeroes(matrix, m, &n);

    // ��ӡ���
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // �ͷ��ڴ�
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

