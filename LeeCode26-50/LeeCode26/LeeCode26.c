/***************************************************
 * Date:2024/10/28
 * ��Ŀ����:
����һ�����������е��������� nums��Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ��������µĳ��ȡ�
Ԫ�ص����˳��Ӧ���ֲ��䡣��Ҫʹ�ö���Ŀռ䣬������ԭ���޸��������飬���� O(1) �Ķ���ռ�����ɡ�

ʾ����
���룺nums = [1, 1, 2]
�����2, nums = [1, 2]

���룺nums = [0,0,1,1,1,2,2,3,3,4]
�����5, nums = [0, 1, 2, 3, 4]
/***************************************************/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0; // ��ָ��
    for (int j = 1; j < numsSize; j++) { // ��ָ��
        if (nums[j] != nums[i]) { // ������Ԫ��
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // �����³���
}

// ���Ժ���
int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, size);
    printf("�µĳ���: %d\n", newLength);

    printf("�޸ĺ������: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
