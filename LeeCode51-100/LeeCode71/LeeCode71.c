/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-28 14:15:02
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-28 15:02:56
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode71\LeeCode71.c
 * @Description: 
 *              给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。
                在 Unix 风格的文件系统中规则如下：

                一个点 '.' 表示当前目录本身。
                此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
                任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
                任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
                返回的 简化路径 必须遵循下述格式：
                始终以斜杠 '/' 开头。
                两个目录名之间必须只有一个斜杠 '/' 。
                最后一个目录名（如果存在）不能 以 '/' 结尾。
                此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
                返回简化后得到的 规范路径 。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    // 创建一个栈
    char* stack[3000]; // 假设路径中最多有 3000 个目录
    int top = -1; // 栈顶指针
    
    char* token = strtok(path, "/"); // 按 "/" 分割路径

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // 如果是 ".."，弹出栈顶目录
            if (top >= 0) {
                top--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // 如果是有效目录名，压入栈
            stack[++top] = token;
        }
        token = strtok(NULL, "/"); // 继续分割下一个部分
    }
    
    // 拼接简化路径
    char* result = (char*)malloc(3000 * sizeof(char));
    result[0] = '\0';
    
    if (top == -1) {
        strcpy(result, "/");
    } else {
        for (int i = 0; i <= top; i++) {
            strcat(result, "/");
            strcat(result, stack[i]);
        }
    }
    
    return result;
}

int main() {
    char path[3000];
    printf("请输入路径：");
    scanf("%s", path);
    
    char* result = simplifyPath(path);
    printf("简化后的路径为：%s\n", result);
    
    free(result);
    return 0;
}
