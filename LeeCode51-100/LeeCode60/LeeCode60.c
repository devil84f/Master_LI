/***************************************************
 * Date:2024/11/22
 * ��Ŀ����:
�������� [1,2,3,...,n]��������Ԫ�ع��� n! �����С�
����С˳���г����������������һһ��ǣ��� n = 3 ʱ, �����������£�
"123"
"132"
"213"
"231"
"312"
"321"
���� n �� k�����ص� k �����С�

ʾ�� 1��
���룺n = 3, k = 3
�����"213"

ʾ�� 2��
���룺n = 4, k = 9
�����"2314"

ʾ�� 3��
���룺n = 3, k = 1
�����"123"
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����������ȡ�� k ������
char* getPermutation(int n, int k) {
    // ����׳�����
    int factorial[n];
    factorial[0] = 1;
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    // ��ѡ�����б�
    int numbers[n];
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1; // ��ʼΪ [1, 2, ..., n]
    }

    // �������ַ���
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0'; // ĩβ�ӽ�����

    // ����Ϊ�� 0 ��ʼ������
    k--;

    // ��������
    for (int i = 0; i < n; i++) {
        int index = k / factorial[n - 1 - i]; // ��ǰ���ֵ�����
        result[i] = numbers[index] + '0';    // תΪ�ַ�
        // ɾ����ѡ����
        for (int j = index; j < n - i - 1; j++) {
            numbers[j] = numbers[j + 1];
        }
        k %= factorial[n - 1 - i]; // ���� k
    }

    return result;
}

// ���Դ���
int main() {
    int n = 4, k = 9;
    char* result = getPermutation(n, k);
    printf("�� %d ��������: %s\n", k, result);
    free(result); // �ͷ��ڴ�
    return 0;
}
