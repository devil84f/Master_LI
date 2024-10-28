/***************************************************
 * Date:2024/10/18
 * 题目描述:
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
/***************************************************/

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // 将第一个字符串作为初始公共前缀
    char* prefix = strs[0];
    
    for (int i = 1; i < strsSize; i++) {
        // 比较当前字符串与前缀
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {
            // 如果不匹配，缩短前缀
            prefix[strlen(prefix) - 1] = '\0'; // 使用 '\0' 终止符缩短前缀
            
            // 如果前缀为空，提前退出
            if (strlen(prefix) == 0) return "";
        }
    }
    
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int size = sizeof(strs) / sizeof(strs[0]);
    printf("Longest common prefix: %s\n", longestCommonPrefix(strs, size)); // 输出：fl
    return 0;
}
