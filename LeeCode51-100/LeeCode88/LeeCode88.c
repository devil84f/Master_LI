/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-04 18:14:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-04 18:19:14
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode88\LeeCode88.c
 * @Description: 
 * 
 */

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = nums1Size - 1; // 从 nums1 的尾部开始填充
    while (m > 0 || n > 0) {
        if (n > 0 && (m == 0 || nums1[m - 1] < nums2[n - 1])) {
            nums1[i--] = nums2[--n];
        } else {
            nums1[i--] = nums1[--m];
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;

    printf("Before merge:\n");
    printf("nums1: ");
    printArray(nums1, m + n);
    printf("nums2: ");
    printArray(nums2, n);

    merge(nums1, m+n, m, nums2, n, n);

    printf("After merge:\n");
    printArray(nums1, m + n);

    return 0;
}