/***************************************************
 * Date:2024/11/19
 * ��Ŀ����:
����һ�� ���ص��� ������������ʼ�˵�����������б� intervals������ intervals[i] = [starti, endi] 
��ʾ�� i ������Ŀ�ʼ�ͽ��������� intervals ���� starti �������С�
ͬ������һ������ newInterval = [start, end] ��ʾ��һ������Ŀ�ʼ�ͽ�����
�� intervals �в������� newInterval��ʹ�� intervals ��Ȼ���� starti �������У�
������֮�䲻�ص�������б�Ҫ�Ļ������Ժϲ����䣩�����ز���֮��� intervals��
ע�� �㲻��Ҫԭ���޸� intervals������Դ���һ��������Ȼ�󷵻�����

ʾ�� 1��
���룺intervals = [[1,3],[6,9]], newInterval = [2,5]
�����[[1,5],[6,9]]

ʾ�� 2��
���룺intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
�����[[1,2],[3,10],[12,16]]
���ͣ�������Ϊ�µ����� [4,8] �� [3,5],[6,7],[8,10] �ص���
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// Helper function to get the minimum of two values
int min(int a, int b) {
    return a < b ? a : b;
}

// Helper function to get the maximum of two values
int max(int a, int b) {
    return a > b ? a : b;
}

// Main function to insert and merge intervals
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, 
             int* newInterval, int newIntervalSize, 
             int* returnSize, int** returnColumnSizes) {
    // Allocate space for the result
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int idx = 0; // Index to track result array

    int i = 0;

    // Step 1: Add all intervals that end before the new interval starts
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    // Step 2: Merge all overlapping intervals with the new interval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    // Add the merged interval
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = newInterval[0];
    result[idx][1] = newInterval[1];
    (*returnColumnSizes)[idx] = 2;
    idx++;

    // Step 3: Add all remaining intervals
    while (i < intervalsSize) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    // Update the return size
    *returnSize = idx;
    return result;
}

int main() {
    // Input intervals
    int intervalsSize = 2;
    int intervalsColSize[] = {2, 2};
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    intervals[0] = (int*)malloc(2 * sizeof(int));
    intervals[0][0] = 1; intervals[0][1] = 3;
    intervals[1] = (int*)malloc(2 * sizeof(int));
    intervals[1][0] = 6; intervals[1][1] = 9;

    // New interval
    int newInterval[] = {2, 5};
    int newIntervalSize = 2;

    // Output variables
    int returnSize;
    int* returnColumnSizes;

    // Call the insert function
    int** result = insert(intervals, intervalsSize, intervalsColSize, 
                          newInterval, newIntervalSize, 
                          &returnSize, &returnColumnSizes);

    // Print the result
    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
        free(result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);
    free(returnColumnSizes);
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);

    return 0;
}
