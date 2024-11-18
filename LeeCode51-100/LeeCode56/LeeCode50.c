/***************************************************
 * Date:2024/11/18
 * ��Ŀ����:
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi]��
����ϲ������ص������䣬������һ�����ص����������飬��������ǡ�ø��������е��������䡣

ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].

ʾ�� 2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣 
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// �ȽϺ��������ڰ������������
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];
    }
    return intervalA[1] - intervalB[1];
}

// �ϲ����亯��
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // �������������
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // ��̬����������
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    // ��ʼ����һ������
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;

    // ����������кϲ�
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[count][1]) {
            // �ϲ�����
            result[count][1] = (intervals[i][1] > result[count][1]) ? intervals[i][1] : result[count][1];
        } else {
            // ������
            count++;
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
        }
    }

    // ���·��صĽ����С
    *returnSize = count + 1;

    return result;
}

// ���Դ���
int main() {
    int intervalsArray[4][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int intervalsSize = 4;
    int* intervals[4];
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = intervalsArray[i];
    }
    int intervalsColSize[] = {2, 2, 2, 2};

    int returnSize;
    int* returnColumnSizes;

    int** result = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("�ϲ�������䣺\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}
