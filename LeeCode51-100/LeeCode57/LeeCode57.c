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

// ��������ṹ��
typedef struct {
    int start;
    int end;
} Interval;

// ��������
Interval* insert(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize);

// ������
int main() {
    Interval intervals[] = {{1, 3}, {6, 9}};
    Interval newInterval = {2, 5};
    int returnSize;

    Interval* result = insert(intervals, 2, newInterval, &returnSize);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");

    free(result);
    return 0;
}

// �������亯��
Interval* insert(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize) {
    // ��̬�����㹻��Ľ������
    Interval* result = (Interval*)malloc((intervalsSize + 1) * sizeof(Interval));
    int idx = 0;

    // ��������
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i].end < newInterval.start) {
            // ��ǰ���������������
            result[idx++] = intervals[i];
        } else if (intervals[i].start > newInterval.end) {
            // ��ǰ�������������Ҳ�
            result[idx++] = newInterval;
            newInterval = intervals[i]; // �滻������Ϊ��ǰ����
        } else {
            // ��ǰ�������������ص����ϲ�����
            newInterval.start = (newInterval.start < intervals[i].start) ? newInterval.start : intervals[i].start;
            newInterval.end = (newInterval.end > intervals[i].end) ? newInterval.end : intervals[i].end;
        }
    }

    // ���������������
    result[idx++] = newInterval;

    // ���ؽ����С
    *returnSize = idx;
    return result;
}
