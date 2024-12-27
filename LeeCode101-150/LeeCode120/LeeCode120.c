/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-27 10:02:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-27 10:12:02
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode120\LeeCode120.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int numRows) {
    // �ӵ����ڶ��п�ʼ����
    for (int i = numRows - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // ���µ�ǰԪ�ص�ֵΪ������������С·����
            triangle[i][j] += (triangle[i+1][j] < triangle[i+1][j+1]) ? triangle[i+1][j] : triangle[i+1][j+1];
        }
    }

    // ���ض���Ԫ�ص���С·����
    return triangle[0][0];
}

int main() {
    int numRows = 4;
    
    // ��������������
    int* triangle[] = {
        (int[]){2},
        (int[]){3, 4},
        (int[]){6, 5, 7},
        (int[]){4, 1, 8, 3}
    };

    // �����С·����
    int result = minimumTotal(triangle, numRows);

    // ������
    printf("��С·�����ǣ�%d\n", result);

    return 0;
}
