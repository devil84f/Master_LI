/***************************************************
 * Date:2024/10/27
 * ��Ŀ����:
����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������
���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����
���� nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
���� k��

ʾ�� 1��
���룺nums = [3,2,2,3], val = 3
�����2, nums = [2,2,_,_]
���ͣ���ĺ�������Ӧ�÷��� k = 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
���ڷ��ص� k ��Ԫ��֮��������ʲô������Ҫ��������ǲ����������⣩��

ʾ�� 2��
���룺nums = [0,1,2,2,3,0,4,2], val = 2
�����5, nums = [0,1,4,0,3,_,_,_]
���ͣ���ĺ���Ӧ�÷��� k = 5������ nums �е�ǰ���Ԫ��Ϊ 0,0,1,3,4��
ע�������Ԫ�ؿ�������˳�򷵻ء�
���ڷ��ص� k ��Ԫ��֮��������ʲô������Ҫ��������ǲ����������⣩��
/***************************************************/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;

    int i = 0; // ��ָ��
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            i++;
        }
        else {
            while (nums[j + 1] == val && j < numsSize) {
                j++;
            }
            nums[i] = nums[j + 1];
        }
    }
    return i; // �����³���
}

// ���Ժ���
int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int val = 2;
    int newLength = removeElement(nums, size, val);
    printf("�µĳ���: %d\n", newLength);

    printf("�޸ĺ������: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}