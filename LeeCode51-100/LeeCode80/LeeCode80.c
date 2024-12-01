/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-01 21:29:36
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-01 21:31:02
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode80\LeeCode80.c
 * @Description: 
        * ����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ�ó��ִ����������ε�Ԫ��ֻ�������� ��
        * ����ɾ����������³��ȡ���Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

        ʾ�� 1��
        ���룺nums = [1,1,1,2,2,3]
        �����5, nums = [1,1,2,2,3]
        ���ͣ�����Ӧ�����³��� length = 5, 
        ����ԭ�����ǰ���Ԫ�ر��޸�Ϊ 1, 1, 2, 2, 3�� ����Ҫ���������г����³��Ⱥ����Ԫ�ء�
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize; // ����С�ڵ���2ʱ�����账��
    }

    int i = 2; // ָ�������������һ����д��λ��
    for (int j = 2; j < numsSize; j++) {
        // �����ǰԪ�����������鵹���ڶ���Ԫ�ز���ȣ���д��
        if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i; // ������ĳ���
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    printf("New length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
