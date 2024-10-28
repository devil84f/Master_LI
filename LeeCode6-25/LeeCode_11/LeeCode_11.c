/***************************************************
 * Date:2024/10/16
 * ��Ŀ����:
��Ŀ������
����һ���������� height��ÿ��Ԫ�ش���ͼ�ж�Ӧλ�õĸ߶ȡ������Ŀ�����������߶ε�����������ģ�����ʢˮ�����������

ʾ����
ʾ�� 1��
���룺height = [1,8,6,2,5,4,8,3,7]
�����49
���ͣ��߶�Ϊ 8 �� 7 ���߶��γɵ������ܹ�ʢˮ���������Ϊ 49��

ʾ�� 2��
���룺height = [1,1]
�����1
/***************************************************/

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = current_height * width;
        max_area = max_area > current_area ? max_area : current_area;

        // �ƶ�ָ��϶��߶ε�ָ��
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    printf("Maximum area: %d\n", maxArea(height, size)); // �����49
    return 0;
}

