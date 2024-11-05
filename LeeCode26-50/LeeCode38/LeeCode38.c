/***************************************************
 * Date:2024/11/4
 * ��Ŀ����:
����������һ���������У��������¹������ɣ�

countAndSay(1) Ϊ�ַ��� "1"��
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ���ַ�����
����������ʽ���£�����һ���ַ����������ұ���������������ͬ�ַ���
�������������ַ����������γ��µ��ַ�����
���磺

1 ���� "һ1" -> 11
11 ���� "��1" -> 21
21 ���� "һ2һ1" -> 1211
1211 ���� "һ1һ2��1" -> 111221
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    // ������������ص�һ����������
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    // ��2��n����������ÿһ����������
    for (int i = 2; i <= n; i++) {
        int len = strlen(result);
        char* temp = (char*)malloc(2 * len + 1);  // ��ʱ�ַ���
        int tempIndex = 0;

        for (int j = 0; j < len;) {
            int count = 1;
            while (j + count < len && result[j] == result[j + count]) {
                count++;  // ����������ͬ�ַ�������
            }

            // ���������ַ���ӵ���ʱ�ַ���
            temp[tempIndex++] = '0' + count;
            temp[tempIndex++] = result[j];
            j += count;
        }
        temp[tempIndex] = '\0';

        // ���µĽ���滻�ɵĽ��
        free(result);
        result = temp;
    }

    return result;  // �������յĽ��
}

int main() {
    int n = 8;
    char* result = countAndSay(n);
    printf("�� %d ����������Ϊ: %s\n", n, result);
    free(result);  // �ͷ��ڴ�
    return 0;
}
