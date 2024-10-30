/***************************************************
 * Date:2024/10/29
 * ��Ŀ����:
���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
��� needle ���� haystack ��һ���֣��򷵻�  -1 ��

ʾ�� 1��
���룺haystack = "sadbutsad", needle = "sad"
�����0
���ͣ�"sad" ���±� 0 �� 6 ��ƥ�䡣
��һ��ƥ������±��� 0 �����Է��� 0 ��

ʾ�� 2��
���룺haystack = "leetcode", needle = "leeto"
�����-1
���ͣ�"leeto" û���� "leetcode" �г��֣����Է��� -1 ��
/***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��������ƥ���LPS���飩
void computeLPSArray(char *needle, int needleLen, int *lps) {
    int len = 0; // ��ǰ�ǰ��׺����
    lps[0] = 0;  // ��һ���ַ��� lps Ϊ 0
    int i = 1;

    while (i < needleLen) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // ���˵���һ�����ܵ�ǰ׺����
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP �㷨ʵ��
int strStr(char *haystack, char *needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if (needleLen == 0) return 0; // ���ַ������

    // ���� LPS ����
    int *lps = (int *)malloc(sizeof(int) * needleLen);
    computeLPSArray(needle, needleLen, lps);

    int i = 0; // ���ַ�����ָ��
    int j = 0; // ģʽ����ָ��

    while (i < haystackLen) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }
        if (j == needleLen) {
            free(lps); // ƥ��ɹ����ͷ��ڴ�
            return i - j;
        } else if (i < haystackLen && haystack[i] != needle[j]) {
            if (j != 0) {
                j = lps[j - 1]; // ���� LPS �������
            } else {
                i++;
            }
        }
    }

    free(lps); // ƥ��ʧ�ܣ��ͷ��ڴ�
    return -1;
}

// ���Ժ���
int main() {
    char haystack[] = "bacbababaabcbab";
    char needle[] = "abababca";

    int index = strStr(haystack, needle);
    printf("���ַ�����ʼ����: %d\n", index);

    return 0;
}
