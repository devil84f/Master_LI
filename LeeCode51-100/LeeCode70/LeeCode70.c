/***************************************************
 * Date:2024/11/27
 * ��Ŀ����:

/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int dfs(int n, int* memo) {
    if (n == 0) {
        return 1; // ����¥��
    } else if (n < 0) {
        return 0; // ��Ч·��
    }
    if (memo[n] != -1) {
        return memo[n]; // �����Ѽ����ֵ
    }
    // �ݹ����
    memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
    return memo[n];
}

int climbStairs(int n) {
    // ��̬���� memo ���飬����ʼ��Ϊ -1
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    // ������
    int result = dfs(n, memo);

    // �ͷŶ�̬�ڴ�
    free(memo);

    return result;
}

int main() {
    int n;
    printf("������¥�ݵļ�����");
    scanf("%d", &n);

    int result = climbStairs(n);
    printf("���� %d �ֲ�ͬ�ķ������������� %d ��̨�ס�\n", result, n);

    return 0;
}
