/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-27 10:50:28
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-27 17:59:25
 * @FilePath: \Master_LI\C\Day14\day14.c
 * @Description: 1��ָ�����
 *               2��ָ�� +- ���� = ָ��
 *               3��ָ�� -  ָ�� = ָ���ָ���Ԫ�ظ���
 * 
 */

#include <stdio.h>
#include <string.h>
#define N_VALUES 5

int my_strlen (char* str) { // ���ǻ����汾  ���еݹ�汾
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

// ָ�� - ָ�� �汾
int my_strlen1 (char* str) {
    char* start = str;
    while (*str != '\0') {
        str++;
    }
    int count = str - start; 
    return count;
}

int main () {
    float values[N_VALUES];
    float *vp;
    for (vp = &values[0]; vp < &values[N_VALUES];) { // for ���һ��Ϊ��
        *vp++ = 0; // ���鸳ֵ 0
    }
    
    int arr[10] = {0};
    printf("%d\n", &arr[9] - &arr[0]); // |ָ�� - ָ��| �õ���ָ���ָ���Ԫ�ظ���������ֵ

    int arr1[10] = {0};
    printf("%d\n", &arr1[0] - &arr1[9]); // |ָ�� - ָ��| �õ���ָ���ָ���Ԫ�ظ���������ֵ

    int len = my_strlen1("abcdef");
    printf("%d\n", len);
    return 0;
}
 