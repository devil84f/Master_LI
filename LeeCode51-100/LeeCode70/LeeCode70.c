/***************************************************
 * Date:2024/11/27
 * 题目描述:

/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int dfs(int n, int* memo) {
    if (n == 0) {
        return 1; // 到达楼顶
    } else if (n < 0) {
        return 0; // 无效路径
    }
    if (memo[n] != -1) {
        return memo[n]; // 返回已计算的值
    }
    // 递归计算
    memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
    return memo[n];
}

int climbStairs(int n) {
    // 动态分配 memo 数组，并初始化为 -1
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    // 计算结果
    int result = dfs(n, memo);

    // 释放动态内存
    free(memo);

    return result;
}

int main() {
    int n;
    printf("请输入楼梯的级数：");
    scanf("%d", &n);

    int result = climbStairs(n);
    printf("共有 %d 种不同的方法可以爬到第 %d 级台阶。\n", result, n);

    return 0;
}
