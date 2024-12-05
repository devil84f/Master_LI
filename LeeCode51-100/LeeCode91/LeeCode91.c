/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-05 10:18:47
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-05 10:22:40
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode91\LeeCode91.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <string.h>

int numDecodings(char *s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int dp[n + 1]; 
    dp[0] = 1; // 空字符串的解码方法数
    dp[1] = 1; // 单个字符的解码方法数（非0）

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        // 单个字符解码
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        // 两个字符解码
        int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() {
    char s[] = "226";
    printf("解码方法总数: %d\n", numDecodings(s));
    return 0;
}
