/***************************************************
 * Date:2024/10/20
 * ��Ŀ����:�绰�������ĸ���
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
�绰�����ϵ���������ĸ�Ķ�Ӧ��ϵ���£�
2 -> "abc"
3 -> "def"
4 -> "ghi"
5 -> "jkl"
6 -> "mno"
7 -> "pqrs"
8 -> "tuv"
9 -> "wxyz"
����һ�������ַ��� digits���������ܱ�ʾ��������ĸ��ϡ�

ʾ�� 1��
���룺digits = "23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

ʾ�� 2��
���룺digits = ""
�����[]

ʾ�� 3��
���룺digits = "2"
�����["a", "b", "c"]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digitToChar(char digit) {
    switch (digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

void backtrack(char*** result, char* combination, const char* digits, int index, int* returnSize, int* capacity) {
    if (index == strlen(digits)) {
        if (*returnSize >= *capacity) {
            *capacity *= 2; // ��չ����
            *result = realloc(*result, sizeof(char*) * (*capacity)); // �޸Ĵ����ָ��
            if (*result == NULL) {
                exit(EXIT_FAILURE); // ���� realloc ʧ��
            }
        }
        (*result)[*returnSize] = strdup(combination); // ������ϵ������
        (*returnSize)++;
        return;
    }

    char* letters = digitToChar(digits[index]);
    for (int i = 0; letters[i] != '\0'; i++) {
        combination[index] = letters[i]; // ��ӵ�ǰ��ĸ
        backtrack(result, combination, digits, index + 1, returnSize, capacity); // �ݹ�
    }
    
    combination[index] = '\0'; // �ָ����״̬
}

char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100; // ��ʼ������
    char** result = malloc(sizeof(char*) * capacity);
    char* combination = malloc(sizeof(char) * (strlen(digits) + 1));
    combination[strlen(digits)] = '\0'; // ��ֹ��
    *returnSize = 0;

    backtrack(&result, combination, digits, 0, returnSize, &capacity);

    free(combination); // �ͷ�����ڴ�
    return result;
}

int main() {
    char digits[] = "5678";
    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);

    printf("Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // �ͷ��ڴ�
    }

    free(combinations);
    return 0;
}
