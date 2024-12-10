/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-10 10:13:28
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-10 10:16:08
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode97\LeeCode97.c
 * @Description: 
 * 
 */

 #include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    // 长度不符，直接返回 false
    if (len1 + len2 != len3) {
        return false;
    }

    // 动态规划数组
    bool dp[len1 + 1][len2 + 1];

    // 初始化 dp 数组
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
            } else {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[] = "aab";
    char s2[] = "axy";
    char s3[] = "aaxaby";

    if (isInterleave(s1, s2, s3)) {
        printf("Yes, %s can be formed by interleaving %s and %s.\n", s3, s1, s2);
    } else {
        printf("No, %s cannot be formed by interleaving %s and %s.\n", s3, s1, s2);
    }

    return 0;
}
