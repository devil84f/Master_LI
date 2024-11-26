/***************************************************
 * Date:2024/11/26
 * 题目描述:
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
/***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    int dp[m][n];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
            // if (dp[i-1][j] < dp[i][j-1]) {
            //     dp[i][j] = grid[i][j] + dp[i-1][j];
            // }
            // else {
            //     dp[i][j] = grid[i][j] + dp[i][j-1];
            // }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int row1[] = {1, 3, 1};
    int row2[] = {1, 5, 1};
    int row3[] = {4, 2, 1};
    int* grid[] = {row1, row2, row3};
    int colSize = 3;

    printf("最小路径和: %d\n", minPathSum(grid, 3, &colSize));
    return 0;
}
