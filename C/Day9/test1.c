/***************************************************
 * Date:2024/10/29
 * ��ά����
 * �����Խ��
***************************************************/

#include <stdio.h>

// int main ()
// {
//     int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
//     int arr1[3][4] = {1,2,3,4,1,2,3,4,1,2,3,4}; // ���к���������䣬ȱʧ��0
//     int arr2[3][4] = {{1,2},{3,4},{1,2}}; // ����
//     int arr3[][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4}}; // nά���飬ֻ�е�һ��ά�ȿ���ʡ��
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
//     printf("%d\n", arr[sz - 1]); // Խ��  ��ӡ������
//     return 0;
// }

// ���鴫�Σ��β�������д��
// 1 ָ��
// 2 ����

// �β����������ʽ : ��С��д�ɲ�д
#include <stdio.h>

// ����
void bubble_sortd(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ָ��
void bubble_sort1(int* arr,  int size) {
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// �β���ָ�����ʽ
int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int sz = sizeof(arr) / sizeof(arr[0]);
    // ð������
    bubble_sort1(arr, sz);

    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
