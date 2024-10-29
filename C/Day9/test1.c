/***************************************************
 * Date:2024/10/29
 * 二维数组
 * 数组的越界
***************************************************/

#include <stdio.h>

// int main ()
// {
//     int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
//     int arr1[3][4] = {1,2,3,4,1,2,3,4,1,2,3,4}; // 先行后列依次填充，缺失补0
//     int arr2[3][4] = {{1,2},{3,4},{1,2}}; // 分组
//     int arr3[][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4}}; // n维数组，只有第一个维度可以省略
//     int arr4[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};

//     printf("%d\n", arr4[2][3]);
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 4; j++) {
//             printf("%d ", arr4[i][j]);
//         }
//         printf("\n");
//     }

//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 4; j++) {
//             printf("&arr4[%d][%d] = %p\n", i, j, arr4[i][j]);
//         }
//         printf("\n");
//     }

//     int sz = sizeof(arr) / sizeof(arr[0]);
//     printf("%d\n", arr[sz - 1]); // 越界  打印错误结果
//     return 0;
// }

// 数组传参，形参有两种写法
// 1 指针
// 2 数组

// 形参是数组的形式 : 大小可写可不写
#include <stdio.h>

// 数组
void bubble_sortd(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 指针
void bubble_sort1(int* arr,  int size) {
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 形参是指针的形式
int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int sz = sizeof(arr) / sizeof(arr[0]);
    // 冒泡排序
    bubble_sort1(arr, sz);

    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
