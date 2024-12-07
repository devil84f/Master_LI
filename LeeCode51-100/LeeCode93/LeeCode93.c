/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-07 14:20:16
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-07 14:20:42
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode93\LeeCode93.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������������ַ����Ƿ�Ϊ�Ϸ��� IP ��
int isValidSegment(const char *s, int start, int end) {
    if (start > end) return 0;

    // �����ǰ�����ҳ��ȴ��� 1������Ч
    if (s[start] == '0' && start < end) return 0;

    // ��������ֵ
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return 0; // ������
        num = num * 10 + (s[i] - '0');
        if (num > 255) return 0; // ������Χ
    }
    return 1;
}

// ���ݺ���
void backtrack(char *s, int start, int segment, char *currentIP, int currentLen, char **result, int *returnSize) {
    int n = strlen(s);
    // ����ҵ� 4 ���Ҹպ����������ַ�
    if (segment == 4 && start == n) {
        currentIP[currentLen - 1] = '\0'; // ȥ��ĩβ�� '.'
        result[*returnSize] = strdup(currentIP); // ������
        (*returnSize)++;
        return;
    }

    // ʣ���ַ�����򳬳���Χ����֦
    if (segment == 4 || start == n) return;

    // ���Էָ� 1 �� 3 ���ַ���Ϊ��ǰ��
    for (int len = 1; len <= 3; len++) {
        if (start + len - 1 >= n) break; // �����ַ�����Χ
        if (!isValidSegment(s, start, start + len - 1)) continue; // �Ƿ���

        // �� currentIP ����ӵ�ǰ��
        strncpy(currentIP + currentLen, s + start, len);
        currentIP[currentLen + len] = '.'; // ��� '.'

        // �ݹ鴦����һ��
        backtrack(s, start + len, segment + 1, currentIP, currentLen + len + 1, result, returnSize);
    }
}

// ������
char **restoreIpAddresses(char *s, int *returnSize) {
    *returnSize = 0;
    int n = strlen(s);

    // ��� 27 ����Ч IP�������������Ϊ "255255255255"��
    char **result = (char **)malloc(27 * sizeof(char *));
    char currentIP[20]; // �ݴ浱ǰ IP

    if (n < 4 || n > 12) return result; // ���Ȳ��Ϸ���ֱ�ӷ���

    backtrack(s, 0, 0, currentIP, 0, result, returnSize);
    return result;
}

// ���Ժ���
int main() {
    char s[] = "25525511135";
    int returnSize;
    char **result = restoreIpAddresses(s, &returnSize);

    printf("��Ч�� IP ��ַ�У�\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // �ͷ��ڴ�
    }
    free(result); // �ͷ��ڴ�

    return 0;
}
