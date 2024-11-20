/***************************************************
 * Date:2024/11/1
 * ��Ŀ����:
����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ��������һ�����ʵĳ��ȡ�
������ָ������ĸ��ɡ��������κοո��ַ���������ַ�����

ʾ�� 1��
���룺s = "Hello World"
�����5
���ͣ����һ�������ǡ�World��������Ϊ 5��

ʾ�� 2��
���룺s = "   fly me   to   the moon  "
�����4
���ͣ����һ�������ǡ�moon��������Ϊ 4��
/***************************************************/

#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Step 1: Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Step 2: Count the length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char s[] = "Hello World   ";
    int result = lengthOfLastWord(s);
    printf("The length of the last word is: %d\n", result);
    return 0;
}
