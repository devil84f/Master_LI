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

#define MOD 1000000007  // ���峣�õ�ģ��

// ��̬�滮ʵ�֣����� t �� s �еĲ�ͬ�����и���
long long numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    // dp[i][j] ��ʾ s[0..i-1] �� t[0..j-1] �Ĳ�ͬ�����и���
    long long dp[m + 1][n + 1];

    // ��ʼ�� dp ����
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;  // ���ַ��� t �������κ� s ���ҵ�
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = 0;  // �ǿ��ַ��� t �����ڿ��ַ��� s ���ҵ�
    }

    // ��� dp ����
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                // ��� s[i-1] == t[j-1]�����ǿ���ѡ����� s[i-1] �򲻰���
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            } else {
                // ��� s[i-1] != t[j-1]������ֻ��ѡ�񲻰��� s[i-1]
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }

    // ���� dp[m][n]���� s[0..m-1] �� t[0..n-1] �Ĳ�ͬ�����и���
    return dp[m][n];
}

// ���Դ���
int main() {
    char s[] = "rabbbit";
    char t[] = "rabbit";

    long long result = numDistinct(s, t);
    printf("Number of distinct subsequences: %lld\n", result);

    return 0;
}
