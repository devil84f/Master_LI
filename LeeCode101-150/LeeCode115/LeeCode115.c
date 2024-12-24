/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-24 11:08:13
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-24 11:08:15
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode115\LeeCode115.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <string.h>

#define MOD 1000000007  // 定义常用的模数

// 动态规划实现：计算 t 在 s 中的不同子序列个数
long long numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    // dp[i][j] 表示 s[0..i-1] 中 t[0..j-1] 的不同子序列个数
    long long dp[m + 1][n + 1];

    // 初始化 dp 数组
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;  // 空字符串 t 总能在任何 s 中找到
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = 0;  // 非空字符串 t 不能在空字符串 s 中找到
    }

    // 填充 dp 数组
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                // 如果 s[i-1] == t[j-1]，我们可以选择包含 s[i-1] 或不包含
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            } else {
                // 如果 s[i-1] != t[j-1]，我们只能选择不包含 s[i-1]
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }

    // 返回 dp[m][n]，即 s[0..m-1] 中 t[0..n-1] 的不同子序列个数
    return dp[m][n];
}

// 测试代码
int main() {
    char s[] = "rabbbit";
    char t[] = "rabbit";

    long long result = numDistinct(s, t);
    printf("Number of distinct subsequences: %lld\n", result);

    return 0;
}
