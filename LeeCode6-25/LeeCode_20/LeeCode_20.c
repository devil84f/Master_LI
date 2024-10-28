/***************************************************
 * Date:2024/10/23
 * ��Ŀ����:��֤�����������ַ����Ƿ���Ч����Ч��������Ҫ��������������

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
���ܵ��������Ͱ�����()��[]��{}��
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// �ж������Ƿ���Ч�ĺ���
bool isValid(char * s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len);  // ��̬����ջ�ڴ�
    int top = -1;  // ջ��ָ���ʼ��Ϊ-1

    // �����ַ���
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        // ����������ţ���ջ
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            // ����������ţ����ջ���Ƿ���ƥ���������
            if (top == -1) {  // ջΪ�գ���������ƥ��
                free(stack);
                return false;
            }
            char topChar = stack[top--];  // ����ջ��Ԫ��
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) {
                free(stack);
                return false;
            }
        }
    }

    // �ж�ջ�Ƿ�Ϊ��
    bool isValid = (top == -1);
    free(stack);  // �ͷ�ջ�ڴ�
    return isValid;
}

// ������
int main() {
    // ��������
    char s1[] = "()[]{}";
    char s2[] = "([)]";
    char s3[] = "{[]}";
    
    // ����isValid��������ӡ���
    printf("Test 1: %s -> %s\n", s1, isValid(s1) ? "Valid" : "Invalid");
    printf("Test 2: %s -> %s\n", s2, isValid(s2) ? "Valid" : "Invalid");
    printf("Test 3: %s -> %s\n", s3, isValid(s3) ? "Valid" : "Invalid");

    return 0;
}
