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
        // 跳过非字母和数字的字符
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // 比较字符，忽略大小写
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    // 示例1
    char s1[] = "A man, a plan, a canal: Panama";
    printf("结果：%s\n", isPalindrome(s1) ? "true" : "false");  // 输出：true

    // 示例2
    char s2[] = "race a car";
    printf("结果：%s\n", isPalindrome(s2) ? "true" : "false");  // 输出：false

    // 示例3
    char s3[] = " ";
    printf("结果：%s\n", isPalindrome(s3) ? "true" : "false");  // 输出：true

    return 0;
}
