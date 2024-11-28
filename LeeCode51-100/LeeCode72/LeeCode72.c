/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-28 15:12:39
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-28 15:21:51
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode72\LeeCode72.c
 * @Description: 
 * 
 */
/***************************************************
 * Date:2024/11/1
 * ��Ŀ����:

/***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    int minVal = a < b ? a : b;
    return minVal < c ? minVal : c;
}

int minDistance(char *word1, char *word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    // ���� DP ����
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // ��ʼ���߽�
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;  // ɾ��
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;  // ����
    }

    // ��� DP ��
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    // ���ս��
    int result = dp[m][n];

    // �ͷ��ڴ�
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char word1[100], word2[100];
    printf("�������һ�����ʣ�");
    scanf("%s", word1);
    printf("������ڶ������ʣ�");
    scanf("%s", word2);

    int result = minDistance(word1, word2);
    printf("��С�༭����Ϊ��%d\n", result);

    return 0;
}
