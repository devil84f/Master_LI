/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-12-30 09:55:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-12-30 09:55:26
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode125\LeeCode125.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>>

bool isPalindrome(char * s) {
    int left = 0, right = strlen(s) - 1;

    while (left < right) {
        // ��������ĸ�����ֵ��ַ�
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // �Ƚ��ַ������Դ�Сд
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    // ʾ��1
    char s1[] = "A man, a plan, a canal: Panama";
    printf("�����%s\n", isPalindrome(s1) ? "true" : "false");  // �����true

    // ʾ��2
    char s2[] = "race a car";
    printf("�����%s\n", isPalindrome(s2) ? "true" : "false");  // �����false

    // ʾ��3
    char s3[] = " ";
    printf("�����%s\n", isPalindrome(s3) ? "true" : "false");  // �����true

    return 0;
}
