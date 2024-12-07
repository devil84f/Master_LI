/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-07 14:20:16
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-07 14:20:42
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode93\LeeCode93.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 辅助函数：检查字符串是否为合法的 IP 段
int isValidSegment(const char *s, int start, int end) {
    if (start > end) return 0;

    // 如果有前导零且长度大于 1，则无效
    if (s[start] == '0' && start < end) return 0;

    // 计算数字值
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return 0; // 非数字
        num = num * 10 + (s[i] - '0');
        if (num > 255) return 0; // 超出范围
    }
    return 1;
}

// 回溯函数
void backtrack(char *s, int start, int segment, char *currentIP, int currentLen, char **result, int *returnSize) {
    int n = strlen(s);
    // 如果找到 4 段且刚好用完所有字符
    if (segment == 4 && start == n) {
        currentIP[currentLen - 1] = '\0'; // 去掉末尾的 '.'
        result[*returnSize] = strdup(currentIP); // 保存结果
        (*returnSize)++;
        return;
    }

    // 剩余字符不足或超出范围，剪枝
    if (segment == 4 || start == n) return;

    // 尝试分割 1 到 3 个字符作为当前段
    for (int len = 1; len <= 3; len++) {
        if (start + len - 1 >= n) break; // 超出字符串范围
        if (!isValidSegment(s, start, start + len - 1)) continue; // 非法段

        // 在 currentIP 中添加当前段
        strncpy(currentIP + currentLen, s + start, len);
        currentIP[currentLen + len] = '.'; // 添加 '.'

        // 递归处理下一段
        backtrack(s, start + len, segment + 1, currentIP, currentLen + len + 1, result, returnSize);
    }
}

// 主函数
char **restoreIpAddresses(char *s, int *returnSize) {
    *returnSize = 0;
    int n = strlen(s);

    // 最多 27 个有效 IP（假设最大输入为 "255255255255"）
    char **result = (char **)malloc(27 * sizeof(char *));
    char currentIP[20]; // 暂存当前 IP

    if (n < 4 || n > 12) return result; // 长度不合法，直接返回

    backtrack(s, 0, 0, currentIP, 0, result, returnSize);
    return result;
}

// 测试函数
int main() {
    char s[] = "25525511135";
    int returnSize;
    char **result = restoreIpAddresses(s, &returnSize);

    printf("有效的 IP 地址有：\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // 释放内存
    }
    free(result); // 释放内存

    return 0;
}
