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

// ����������ǲ����ض�ά����
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // ������ά����洢�������
    int** result = (int**)malloc(numRows * sizeof(int*));

    // Ϊ������������ڴ�
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // ����ÿһ�У����㲢����ÿ�е�Ԫ��
    for (int i = 0; i < numRows; i++) {
        // ��ǰ���� i+1 ��Ԫ��
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;  // ÿ�е�����Ϊ i+1
        
        // ÿ�еĵ�һ�������һ��Ԫ��Ϊ 1
        result[i][0] = 1;
        result[i][i] = 1;

        // ��䵱ǰ���м��Ԫ��
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    *returnSize = numRows;  // ��������
    return result;  // �������ɵ��������
}

// ��ӡ�������
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

    // �����������
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    // ��ӡ�������
    printTriangle(triangle, numRows, returnColumnSizes);

    // �ͷ��ڴ�
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}
