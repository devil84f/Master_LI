/***************************************************
 * Date:2024/10/12
��Ŀ��Z ���α任��LeetCode ��6�⣩

��Ŀ������
��һ���ַ����� "Z" ���ν������У�������������ַ������������з�ʽ���£�
�����ַ��� "PAYPALISHIRING"��������Ҫ���䰴 Z ��������Ϊ 3 �У�
P   A   H   N
A P L S I I G
Y   I   R
֮�����ж�ȡ�ַ����õ� "PAHNAPLSIIGY"��

���룺
- s: ��ת�����ַ���
- numRows: ���� Z �������е�����
�����
�� Z �������в����ж�ȡ����ַ�����

�ⷨ˼·��
1. ����������� numRows Ϊ 1 ʱ��Z ���α任�����壬ֱ�ӷ����ַ�����
2. ��һ����ά���鱣��ÿһ�е��ַ���ģ�� Z ���ε����С�
3. ���������ַ��������������»����ϣ���������Ӧ���С�
4. ���ս������е��ַ�ƴ�����������ؽ����
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    // �����������
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    // ��̬����ÿһ�еĴ洢�ռ�
    char** rows = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        rows[i] = (char*)malloc(strlen(s) + 1);
        rows[i][0] = '\0';  // ��ʼ��Ϊ���ַ���
    }

    int current_row = 0;
    int going_down = 0;  // ���Ʒ���

    // �����ַ���
    for (int i = 0; s[i] != '\0'; ++i) {
        strncat(rows[current_row], &s[i], 1);  // ���ַ���ӵ���ǰ��
        // ��������һ�л����һ�У��л�����
        if (current_row == 0 || current_row == numRows - 1) {
            going_down = !going_down;
        }
        // ���ݷ����ƶ�
        current_row += going_down ? 1 : -1;
    }

    // ��������ƴ�ӽ���ĳ���
    char* result = (char*)malloc(strlen(s) + 1);
    result[0] = '\0';  // ��ʼ��Ϊ���ַ���

    // ƴ��������
    for (int i = 0; i < numRows; ++i) {
        strcat(result, rows[i]);
        free(rows[i]);  // �ͷ�ÿһ�е��ڴ�
    }

    free(rows);  // �ͷ���ָ��������ڴ�

    return result;  // �������ս��
}

// int main() {
//     char s[] = "PAYPALISHIRING";
//     int numRows = 3;
//     char* result = convert(s, numRows);
//     printf("%s\n", result);  // ���: "PAHNAPLSIIGY"
//     return 0;
// }

