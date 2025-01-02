/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-02 09:50:41
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-02 10:21:18
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode131\LeeCode131.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ж��Ƿ��ǻ��Ĵ�
int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// ���ݺ���
void dfs(char* s, int n, int i, int** f, char*** ret, int* retSize, int* retColSize, char** ans, int* ansSize) {
    if (i == n) {
        char** tmp = malloc(sizeof(char*) * (*ansSize));
        for (int j = 0; j < (*ansSize); j++) {
            int ansColSize = strlen(ans[j]);
            tmp[j] = malloc(sizeof(char) * (ansColSize + 1));
            strcpy(tmp[j], ans[j]);
        }
        ret[*retSize] = tmp;
        retColSize[(*retSize)++] = *ansSize;
        return;
    }
    for (int j = i; j < n; ++j) {
        if (f[i][j]) {
            char* sub = malloc(sizeof(char) * (j - i + 2));
            for (int k = i; k <= j; k++) {
                sub[k - i] = s[k];
            }
            sub[j - i + 1] = '\0';
            ans[(*ansSize)++] = sub;
            dfs(s, n, j + 1, f, ret, retSize, retColSize, ans, ansSize);
            --(*ansSize);
        }
    }
}

// ������
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int maxRetLen = 1000; // Ԥ����󷵻ط�����
    char*** ret = malloc(sizeof(char**) * maxRetLen);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * maxRetLen);
    
    // ��̬�滮���ʼ��
    int** f = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            f[i][j] = 0;
        }
        f[i][i] = 1; // �����ַ��ǻ���
    }

    // ��䶯̬�滮��
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len == 2 || f[i + 1][j - 1])) {
                f[i][j] = 1;
            }
        }
    }

    char* ans[n];
    int ansSize = 0;
    dfs(s, n, 0, f, ret, returnSize, *returnColumnSizes, ans, &ansSize);
    return ret;
}

int main() {
    char s[] = "aab";
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    char*** result = partition(s, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\" ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
