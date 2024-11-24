/***************************************************
 * Date:2024/11/24
 * 题目描述:
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
/***************************************************/

// #include <stdio.h>
// #include <stdlib.h>

// int uniquePaths(int m, int n) {
//     // 动态规划数组
//     int dp[m][n];

//     // 初始化第一行和第一列
//     for (int i = 0; i < m; i++) {
//         dp[i][0] = 1;
//     }
//     for (int j = 0; j < n; j++) {
//         dp[0][j] = 1;
//     }

//     // 填充动态规划表
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }

//     // 返回右下角的路径数
//     return dp[m - 1][n - 1];
// }

// int main() {
//     int m = 3, n = 7;
//     printf("不同路径的数量: %d\n", uniquePaths(m, n));
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

// 递归辅助函数
int dfs(int m, int n, int i, int j, int** memo) {
    // 如果超出边界，返回 0
    if (i >= m || j >= n) {
        return 0;
    }
    // 如果到达终点，返回 1
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    // 如果已经计算过，直接返回缓存的结果
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    // 递归计算路径数，并存入缓存
    memo[i][j] = dfs(m, n, i + 1, j, memo) + dfs(m, n, i, j + 1, memo);
    return memo[i][j];
}

// 主函数
int uniquePaths(int m, int n) {
    // 创建缓存数组并初始化为 -1
    int** memo = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        memo[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    // 调用递归函数
    int result = dfs(m, n, 0, 0, memo);

    // 释放内存
    for (int i = 0; i < m; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}

int main() {
    int m = 3, n = 7;
    printf("不同路径的数量: %d\n", uniquePaths(m, n));
    return 0;
}
