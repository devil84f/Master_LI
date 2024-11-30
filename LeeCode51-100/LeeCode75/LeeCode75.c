/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-30 21:49:03
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-30 21:51:06
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode75\LeeCode75.c
 * @Description: 
*       ����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��ԭ�ض����ǽ�������
        ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
        ����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
        �����ڲ�ʹ�ÿ����õ� sort ����������½��������⡣

        ʾ�� 1��
        ���룺nums = [2,0,2,1,1,0]
        �����[0,0,1,1,2,2]

        ʾ�� 2��
        ���룺nums = [2,0,1]
        �����[0,1,2]
 */

#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int p0 = 0, curr = 0, p2 = numsSize - 1;

    while (curr <= p2) {
        if (nums[curr] == 0) {
            // ���� nums[curr] �� nums[p0]
            int temp = nums[curr];
            nums[curr] = nums[p0];
            nums[p0] = temp;
            p0++;
            curr++;
        } else if (nums[curr] == 2) {
            // ���� nums[curr] �� nums[p2]
            int temp = nums[curr];
            nums[curr] = nums[p2];
            nums[p2] = temp;
            p2--;
        } else {
            curr++;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    sortColors(nums, numsSize);

    // �������������
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
