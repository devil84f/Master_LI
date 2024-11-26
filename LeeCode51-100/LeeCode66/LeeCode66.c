/***************************************************
 * Date:2024/11/26
 * ��Ŀ����:
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��

ʾ�� 1��
���룺digits = [1,2,3]
�����[1,2,4]
���ͣ����������ʾ���� 123��

ʾ�� 2��
���룺digits = [4,3,2,1]
�����[4,3,2,2]
���ͣ����������ʾ���� 4321��

ʾ�� 3��
���룺digits = [9]
�����[1,0]
���ͣ����������ʾ���� 9��
�� 1 �õ��� 9 + 1 = 10��
��ˣ����Ӧ���� [1,0]��
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // ��ĩβ��ʼ����������ӷ�
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;  // �����ǰλС�� 9��ֱ�Ӽ�һ������
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;  // �����ǰλΪ 9����Ϊ 0�������������λ
    }

    // ���ѭ���������н�λ��˵����Ҫ��չ����
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1; // ���λΪ 1
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0; // ����λΪ 0
    }
    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    int digits[] = {9, 9, 9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("���: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    if (result != digits) {
        free(result); // ����Ƕ�̬��������飬�ǵ��ͷ��ڴ�
    }

    return 0;
}
