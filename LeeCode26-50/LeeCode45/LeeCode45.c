/***************************************************
 * Date:2024/11/8
 * ��Ŀ����:
����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��

ÿ��Ԫ�� nums[i] ��ʾ������ i ��ǰ��ת����󳤶ȡ����仰˵��
������� nums[i] �����������ת������ nums[i + j] ��:
0 <= j <= nums[i] 
i + j < n
���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]��

ʾ�� 1:
����: nums = [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
     ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�

ʾ�� 2:
����: nums = [2,3,0,1,4]
���: 2
/***************************************************/

#include <stdio.h>

// ��Ծ��Ϸ II ������
int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;  // �����鳤��Ϊ1ʱ������Ҫ��Ծ

    int jumps = 0;           // ��Ծ����
    int currentEnd = 0;      // ��ǰ��Ծ�ı߽�
    int farthest = 0;        // ��ǰ����������Զλ��

    for (int i = 0; i < numsSize - 1; i++) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;  // ������Զ����

        // ���ﵽ��ǰ�߽�ʱ�����������Ծ�����±߽�
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            // �����ǰ�߽��Ѿ��ܵ����յ㣬������ѭ��
            if (currentEnd >= numsSize - 1) {
                break;
            }
        }
    }
    return jumps;
}

// ���Դ���
int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = jump(nums, numsSize);
    printf("������Ծ����Ϊ: %d\n", result);
    
    return 0;
}
