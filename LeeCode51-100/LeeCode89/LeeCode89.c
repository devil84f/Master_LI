/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-04 23:33:58
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-04 23:34:34
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode89\LeeCode89.c
 * @Description:  89. 格雷编码
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;  // 返回的序列长度为 2^n
    int* result = (int*)malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = i ^ (i >> 1);  // 使用公式生成格雷编码
    }

    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int n = 3;
    int returnSize = 0;
    int* result = grayCode(n, &returnSize);
    printArray(result, returnSize);
    free(result);
    return 0;
}
