/***************************************************
 * Date:2024/11/25
 * ��Ŀ����:
����һ�� m x n ���������� grid��һ�������˳�ʼλ�� ���Ͻǣ��� grid[0][0]����
�����˳����ƶ��� ���½ǣ��� grid[m - 1][n - 1]����������ÿ��ֻ�����»��������ƶ�һ����
�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ�������˵��ƶ�·���в��ܰ��� �κ� ���ϰ���ķ���
���ػ������ܹ��������½ǵĲ�ͬ·��������

ʾ�� 1��
���룺obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
�����2
���ͣ�3x3 ��������м���һ���ϰ��
�����Ͻǵ����½�һ���� 2 ����ͬ��·����
1. ���� -> ���� -> ���� -> ����
2. ���� -> ���� -> ���� -> ����

ʾ�� 2��
���룺obstacleGrid = [[0,1],[0,0]]
�����1
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;       // ����
    int n = *obstacleGridColSize;   // ����

    // ���������ϰ��ֱ�ӷ��� 0
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // ��̬�滮����
    int dp[m][n];

    // ��ʼ��
    dp[0][0] = 1; // ���·����Ϊ 1
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i-1][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j-1];
    }

    // ��̬�滮����
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // ���ϰ��·����Ϊ 0
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    // �������½ǵ�·����
    return dp[m-1][n-1];
}

int main() {
    int grid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int* gridPointer[3] = {grid[0], grid[1], grid[2]};
    int cols = 3;
    printf("��ͬ·��������: %d\n", uniquePathsWithObstacles(gridPointer, 3, &cols));
    return 0;
}
