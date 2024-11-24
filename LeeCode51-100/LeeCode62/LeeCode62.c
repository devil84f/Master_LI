/***************************************************
 * Date:2024/11/24
 * ��Ŀ����:
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
���ܹ��ж�������ͬ��·����

ʾ�� 1��
���룺m = 3, n = 7
�����28

ʾ�� 2��
���룺m = 3, n = 2
�����3
���ͣ�
�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
1. ���� -> ���� -> ����
2. ���� -> ���� -> ����
3. ���� -> ���� -> ����
/***************************************************/

// #include <stdio.h>
// #include <stdlib.h>

// int uniquePaths(int m, int n) {
//     // ��̬�滮����
//     int dp[m][n];

//     // ��ʼ����һ�к͵�һ��
//     for (int i = 0; i < m; i++) {
//         dp[i][0] = 1;
//     }
//     for (int j = 0; j < n; j++) {
//         dp[0][j] = 1;
//     }

//     // ��䶯̬�滮��
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }

//     // �������½ǵ�·����
//     return dp[m - 1][n - 1];
// }

// int main() {
//     int m = 3, n = 7;
//     printf("��ͬ·��������: %d\n", uniquePaths(m, n));
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

// �ݹ鸨������
int dfs(int m, int n, int i, int j, int** memo) {
    // ��������߽磬���� 0
    if (i >= m || j >= n) {
        return 0;
    }
    // ��������յ㣬���� 1
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    // ����Ѿ��������ֱ�ӷ��ػ���Ľ��
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    // �ݹ����·�����������뻺��
    memo[i][j] = dfs(m, n, i + 1, j, memo) + dfs(m, n, i, j + 1, memo);
    return memo[i][j];
}

// ������
int uniquePaths(int m, int n) {
    // �����������鲢��ʼ��Ϊ -1
    int** memo = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        memo[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    // ���õݹ麯��
    int result = dfs(m, n, 0, 0, memo);

    // �ͷ��ڴ�
    for (int i = 0; i < m; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}

int main() {
    int m = 3, n = 7;
    printf("��ͬ·��������: %d\n", uniquePaths(m, n));
    return 0;
}
