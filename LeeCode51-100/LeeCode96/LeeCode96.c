/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-09 09:09:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-09 09:32:51
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode96\LeeCode96.c
 * @Description: 
 * ��ͬ��������������
 */
#include <stdio.h>
#include <stdlib.h>

int numTrees(int n) {
    // ��̬�滮����
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1; // ����
    dp[1] = 1; // ֻ��һ���ڵ�

    // ��� dp ����
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    int result = dp[n];
    free(dp); // �ͷ��ڴ�
    return result;
}

int main() {
    int n = 5; // ��������
    printf("Number of unique BSTs for n = %d: %d\n", n, numTrees(n));
    return 0;
}

