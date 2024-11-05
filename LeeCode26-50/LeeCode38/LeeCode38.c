/***************************************************
 * Date:2024/11/4
 * 题目描述:
报数序列是一个整数序列，按照如下规则生成：

countAndSay(1) 为字符串 "1"。
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个字符串。
具体描述方式如下：对上一个字符串，从左到右遍历其中连续的相同字符，
并将其数量和字符本身连接形成新的字符串。
例如：

1 读作 "一1" -> 11
11 读作 "二1" -> 21
21 读作 "一2一1" -> 1211
1211 读作 "一1一2二1" -> 111221
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    // 基本情况，返回第一个报数序列
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    // 从2到n，迭代生成每一个报数序列
    for (int i = 2; i <= n; i++) {
        int len = strlen(result);
        char* temp = (char*)malloc(2 * len + 1);  // 临时字符串
        int tempIndex = 0;

        for (int j = 0; j < len;) {
            int count = 1;
            while (j + count < len && result[j] == result[j + count]) {
                count++;  // 计算连续相同字符的数量
            }

            // 将数量和字符添加到临时字符串
            temp[tempIndex++] = '0' + count;
            temp[tempIndex++] = result[j];
            j += count;
        }
        temp[tempIndex] = '\0';

        // 用新的结果替换旧的结果
        free(result);
        result = temp;
    }

    return result;  // 返回最终的结果
}

int main() {
    int n = 8;
    char* result = countAndSay(n);
    printf("第 %d 个报数序列为: %s\n", n, result);
    free(result);  // 释放内存
    return 0;
}
