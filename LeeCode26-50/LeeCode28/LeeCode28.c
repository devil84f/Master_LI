/***************************************************
 * Date:2024/10/29
 * 题目描述:
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。

示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
/***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 构建部分匹配表（LPS数组）
void computeLPSArray(char *needle, int needleLen, int *lps) {
    int len = 0; // 当前最长前后缀长度
    lps[0] = 0;  // 第一个字符的 lps 为 0
    int i = 1;

    while (i < needleLen) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // 回退到上一个可能的前缀长度
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP 算法实现
int strStr(char *haystack, char *needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if (needleLen == 0) return 0; // 空字符串情况

    // 构建 LPS 数组
    int *lps = (int *)malloc(sizeof(int) * needleLen);
    computeLPSArray(needle, needleLen, lps);

    int i = 0; // 主字符串的指针
    int j = 0; // 模式串的指针

    while (i < haystackLen) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }
        if (j == needleLen) {
            free(lps); // 匹配成功，释放内存
            return i - j;
        } else if (i < haystackLen && haystack[i] != needle[j]) {
            if (j != 0) {
                j = lps[j - 1]; // 利用 LPS 数组回退
            } else {
                i++;
            }
        }
    }

    free(lps); // 匹配失败，释放内存
    return -1;
}

// 测试函数
int main() {
    char haystack[] = "bacbababaabcbab";
    char needle[] = "abababca";

    int index = strStr(haystack, needle);
    printf("子字符串起始索引: %d\n", index);

    return 0;
}
