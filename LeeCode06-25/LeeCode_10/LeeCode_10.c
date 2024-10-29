/***************************************************
 * Date:2024/10/15
 * 题目描述:
给定一个字符串 s 和一个字符模式 p，实现支持 . 和 * 的正则表达式匹配：
. 匹配任意单个字符。
* 匹配零个或多个前面的元素。

示例 1：
输入：s = "aa", p = "a*"
输出：true

示例 2：
输入：s = "ab", p = ".*"
输出：true

示例 3：
输入：s = "aab", p = "c*a*b"
输出：true

示例 4：
输入：s = "mississippi", p = "mis*is*p*."
输出：false
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];
    
    // 初始化 DP 数组
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;  // 空字符串和空模式是匹配的
    
    // 处理模式 p 中的 "*" 出现在开头的情况
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    // 填充 DP 表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    char s1[] = "aa";
    char p1[] = "a*";
    printf("Result: %d\n", isMatch(s1, p1));  // 输出 1 (true)
    
    char s2[] = "ab";
    char p2[] = ".*";
    printf("Result: %d\n", isMatch(s2, p2));  // 输出 1 (true)

    return 0;
}
