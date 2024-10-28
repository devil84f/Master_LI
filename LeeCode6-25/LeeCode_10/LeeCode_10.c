/***************************************************
 * Date:2024/10/15
 * ��Ŀ����:
����һ���ַ��� s ��һ���ַ�ģʽ p��ʵ��֧�� . �� * ��������ʽƥ�䣺
. ƥ�����ⵥ���ַ���
* ƥ���������ǰ���Ԫ�ء�

ʾ�� 1��
���룺s = "aa", p = "a*"
�����true

ʾ�� 2��
���룺s = "ab", p = ".*"
�����true

ʾ�� 3��
���룺s = "aab", p = "c*a*b"
�����true

ʾ�� 4��
���룺s = "mississippi", p = "mis*is*p*."
�����false
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];
    
    // ��ʼ�� DP ����
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;  // ���ַ����Ϳ�ģʽ��ƥ���
    
    // ����ģʽ p �е� "*" �����ڿ�ͷ�����
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    // ��� DP ��
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
    printf("Result: %d\n", isMatch(s1, p1));  // ��� 1 (true)
    
    char s2[] = "ab";
    char p2[] = ".*";
    printf("Result: %d\n", isMatch(s2, p2));  // ��� 1 (true)

    return 0;
}
