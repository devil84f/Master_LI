/***************************************************
 * Date:2024/11/25
 * 题目描述:
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。
机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
返回机器人能够到达右下角的不同路径数量。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;       // 行数
    int n = *obstacleGridColSize;   // 列数

    // 如果起点有障碍物，直接返回 0
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // 动态规划数组
    int dp[m][n];

    // 初始化
    dp[0][0] = 1; // 起点路径数为 1
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i-1][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j-1];
    }

    // 动态规划计算
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // 有障碍物，路径数为 0
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    // 返回右下角的路径数
    return dp[m-1][n-1];
}

int main() {
    int grid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int* gridPointer[3] = {grid[0], grid[1], grid[2]};
    int cols = 3;
    printf("不同路径的数量: %d\n", uniquePathsWithObstacles(gridPointer, 3, &cols));
    return 0;
}
