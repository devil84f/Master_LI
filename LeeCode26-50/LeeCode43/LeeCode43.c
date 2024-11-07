/***************************************************
 * Date:2024/11/7
 * 题目描述:
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
 
提示：
1 <= num1.length, num2.length <= 200
num1 和 num2 只能由数字组成。
num1 和 num2 都不包含任何前导零，除了数字0本身。
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 字符串相乘函数
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int totalLen = len1 + len2;
    
    // 创建数组来存储乘积的各个位的数值
    int* result = (int*)calloc(totalLen, sizeof(int));
    
    // 从个位开始逐位相乘
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            
            // 叠加到当前位置的值，并处理进位
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    
    // 跳过前导零
    int start = 0;
    while (start < totalLen && result[start] == 0) {
        start++;
    }
    
    // 若结果为零，则直接返回 "0"
    if (start == totalLen) {
        free(result);
        return strdup("0");
    }
    
    // 转换结果为字符串
    char* product = (char*)malloc((totalLen - start + 1) * sizeof(char));
    for (int i = start; i < totalLen; i++) {
        product[i - start] = result[i] + '0';
    }
    product[totalLen - start] = '\0';
    
    free(result);
    return product;
}

// 测试代码
int main() {
    char num1[] = "123";
    char num2[] = "456";
    
    char* result = multiply(num1, num2);
    printf("结果: %s\n", result);
    
    free(result);
    return 0;
}
