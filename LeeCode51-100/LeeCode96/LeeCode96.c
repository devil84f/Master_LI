/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-09 09:09:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-09 09:32:51
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode96\LeeCode96.c
 * @Description: 
 * 不同二叉搜索树数量
 */
#include <stdio.h>
#include <stdlib.h>

int numTrees(int n) {
    // 动态规划数组
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1; // 空树
    dp[1] = 1; // 只有一个节点

    // 填充 dp 数组
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    int result = dp[n];
    free(dp); // 释放内存
    return result;
}

int main() {
    int n = 5; // 测试输入
    printf("Number of unique BSTs for n = %d: %d\n", n, numTrees(n));
    return 0;
}

