/***************************************************
 * Date:2024/10/17
 * 题目描述:
将给定的整数转换为罗马数字，整数的取值范围为 1 到 3999。

罗马数字规则：
罗马数字由以下7个符号构成：I（1），V（5），X（10），L（50），C（100），D（500），M（1000）。
罗马数字的组合有一些特殊规则，例如：4 写作 IV，9 写作 IX，40 写作 XL，90 写作 XC，400 写作 CD，900 写作 CM。
/***************************************************/

#include <stdio.h>
#include <string.h>

char* intToRoman(int num) {
    // 定义罗马数字符号及其对应值
    char* roman_symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    // 定义用于存储结果的字符串
    static char result[20];
    int i = 0;
    result[0] = '\0'; // 初始化字符串为空
    
    // 依次匹配每个罗马数字符号
    while (num > 0) {
        while (num >= values[i]) {
            strcat(result, roman_symbols[i]);
            num -= values[i];
        }
        i++;
    }
    
    return result;
}

int main() {
    int num = 1994;
    printf("Roman numeral for %d is: %s\n", num, intToRoman(num));  // 输出: MCMXCIV
    return 0;
}

