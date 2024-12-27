/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-26 15:26:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-27 09:21:02
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode119\LeeCode119.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = calloc(*returnSize, sizeof(int)); 
    row[0] = 1;

    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            row[j] += row[j - 1];
        }
    }

    return row;
}


int main() {
    int returnSize;
    int rowIndex = 3;
    int* row = getRow(rowIndex, &returnSize);

    // Print the row
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", row[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(row);
    return 0;
}
