/***************************************************
 * Date:2024/10/23
 * 题目描述:验证给定的括号字符串是否有效。有效的括号需要满足以下条件：

左括号必须由相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
可能的括号类型包括：()、[]、{}。
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 判断括号是否有效的函数
bool isValid(char * s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len);  // 动态分配栈内存
    int top = -1;  // 栈顶指针初始化为-1

    // 遍历字符串
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        // 如果是左括号，入栈
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            // 如果是右括号，检查栈顶是否有匹配的左括号
            if (top == -1) {  // 栈为空，右括号无匹配
                free(stack);
                return false;
            }
            char topChar = stack[top--];  // 弹出栈顶元素
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) {
                free(stack);
                return false;
            }
        }
    }

    // 判断栈是否为空
    bool isValid = (top == -1);
    free(stack);  // 释放栈内存
    return isValid;
}

// 主函数
int main() {
    // 测试样例
    char s1[] = "()[]{}";
    char s2[] = "([)]";
    char s3[] = "{[]}";
    
    // 调用isValid函数并打印结果
    printf("Test 1: %s -> %s\n", s1, isValid(s1) ? "Valid" : "Invalid");
    printf("Test 2: %s -> %s\n", s2, isValid(s2) ? "Valid" : "Invalid");
    printf("Test 3: %s -> %s\n", s3, isValid(s3) ? "Valid" : "Invalid");

    return 0;
}
