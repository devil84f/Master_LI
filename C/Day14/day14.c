/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-27 10:50:28
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-27 17:59:25
 * @FilePath: \Master_LI\C\Day14\day14.c
 * @Description: 1）指针进阶
 *               2）指针 +- 整数 = 指针
 *               3）指针 -  指针 = 指针和指针间元素个数
 * 
 */

#include <stdio.h>
#include <string.h>
#define N_VALUES 5

int my_strlen (char* str) { // 这是基础版本  还有递归版本
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

// 指针 - 指针 版本
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
    for (vp = &values[0]; vp < &values[N_VALUES];) { // for 最后一个为空
        *vp++ = 0; // 数组赋值 0
    }
    
    int arr[10] = {0};
    printf("%d\n", &arr[9] - &arr[0]); // |指针 - 指针| 得到是指针和指针间元素个数：绝对值

    int arr1[10] = {0};
    printf("%d\n", &arr1[0] - &arr1[9]); // |指针 - 指针| 得到是指针和指针间元素个数：绝对值

    int len = my_strlen1("abcdef");
    printf("%d\n", len);
    return 0;
}
 