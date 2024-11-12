/***************************************************
 * Date:2024/11/11
 * ��Ŀ����:
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�

�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��

ʾ�� 1��
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[[7,4,1],[8,5,2],[9,6,3]]

ʾ�� 2��
���룺matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
�����[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
/***************************************************/

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // 1. ת�þ���
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // 2. ˮƽ��תÿһ��
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}

// ���Դ���
int main() {
    int n = 3;
    int* matrix[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}
    };

    rotate(matrix, n, NULL);

    printf("��ת��ľ���\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
