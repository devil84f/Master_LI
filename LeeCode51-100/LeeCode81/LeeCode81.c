/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-02 10:56:27
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-02 11:05:16
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode81\LeeCode81.c
 * @Description: 
 *      ��֪����һ�����ǽ������е��������� nums �������е�ֵ���ػ�����ͬ��
        �ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת ��
        ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ ��������
        ���磬 [0,1,2,4,4,4,5,6,6,7] ���±� 5 ������ת����ܱ�Ϊ [4,5,6,6,7,0,1,2,4,4] ��
        ���� ��ת�� ������ nums ��һ������ target �������дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С�
        ��� nums �д������Ŀ��ֵ target ���򷵻� true �����򷵻� false ��
        ����뾡���ܼ��������������衣

        ʾ�� 1��
        ���룺nums = [2,5,6,0,0,1,2], target = 0
        �����true

        ʾ�� 2��
        ���룺nums = [2,5,6,0,0,1,2], target = 3
        �����false
 */

#include <stdio.h>
#include <stdbool.h>

// ������ʵ��������ת��������
bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // ����ҵ�Ŀ��ֵ��ֱ�ӷ��� true
        if (nums[mid] == target) return true;

        // ����޷��ж���һ������
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // �����벿���������
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // ����벿��
            } else {
                left = mid + 1;  // ���Ұ벿��
            }
        }
        // ����Ұ벿���������
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  // ���Ұ벿��
            } else {
                right = mid - 1; // ����벿��
            }
        }
    }

    return false; // δ�ҵ�Ŀ��ֵ
}

// ����������
int main() {
    // �������� 1
    int nums1[] = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    printf("Test Case 1: %s\n", search(nums1, sizeof(nums1) / sizeof(nums1[0]), target1) ? "true" : "false");

    // �������� 2
    int nums2[] = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    printf("Test Case 2: %s\n", search(nums2, sizeof(nums2) / sizeof(nums2[0]), target2) ? "true" : "false");

    // �������� 3
    int nums3[] = {1, 0, 1, 1, 1};
    int target3 = 0;
    printf("Test Case 3: %s\n", search(nums3, sizeof(nums3) / sizeof(nums3[0]), target3) ? "true" : "false");

    // �������� 4
    int nums4[] = {1, 3};
    int target4 = 3;
    printf("Test Case 4: %s\n", search(nums4, sizeof(nums4) / sizeof(nums4[0]), target4) ? "true" : "false");

    return 0;
}

