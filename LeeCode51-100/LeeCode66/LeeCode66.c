/***************************************************
 * Date:2024/11/26
 * 题目描述:
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [9]
输出：[1,0]
解释：输入数组表示数字 9。
加 1 得到了 9 + 1 = 10。
因此，结果应该是 [1,0]。
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 从末尾开始遍历，处理加法
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;  // 如果当前位小于 9，直接加一并返回
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;  // 如果当前位为 9，置为 0，并继续处理高位
    }

    // 如果循环结束仍有进位，说明需要扩展数组
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1; // 最高位为 1
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0; // 其他位为 0
    }
    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    int digits[] = {9, 9, 9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("结果: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    if (result != digits) {
        free(result); // 如果是动态分配的数组，记得释放内存
    }

    return 0;
}
