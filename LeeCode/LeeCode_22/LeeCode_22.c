/***************************************************
 * Date:2024/10/24
 * ��Ŀ����:
���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�

ʾ�� 1��
���룺n = 3
�����["((()))","(()())","(())()","()(())","()()()"]

ʾ�� 2��
���룺n = 1
�����["()"]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ݹ�����������ϵĸ�������
void generateParenthesisHelper(char **result, int *returnSize, char *current, int left, int right, int n) {
    if (left == n && right == n) {
        // ���浱ǰ���ɵ����
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (left < n) {
        // ���������
        current[left + right] = '(';
        generateParenthesisHelper(result, returnSize, current, left + 1, right, n);
    }
    
    if (right < left) {
        // ���������
        current[left + right] = ')';
        generateParenthesisHelper(result, returnSize, current, left, right + 1, n);
    }
}

// ���㿨�����������ڹ������������
int catalanNumber(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = result * (2 * n - i) / (i + 1);
    }
    return result / (n + 1);
}

// ������������������Ч���������
char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;

    // ���������������������
    int maxSize = catalanNumber(n);
    
    char **result = (char **)malloc(maxSize * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';  // ����ַ�����'\0'��β
    
    // ���õݹ麯��
    generateParenthesisHelper(result, returnSize, current, 0, 0, n);
    
    free(current);
    return result;
}

// ���Գ���
int main() {
    int n = 4;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);
    
    // ����������ɵ��������
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);  // �ͷ�ÿ���ַ������ڴ�
    }
    free(result);  // �ͷŽ��������ڴ�
    
    return 0;
}
