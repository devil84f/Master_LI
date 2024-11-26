/***************************************************
 * Date:2024/11/26
 * ��Ŀ����:
���������������ַ��� a �� b ���Զ������ַ�������ʽ�������ǵĺ͡�

ʾ�� 1��
����:a = "11", b = "1"
�����"100"

ʾ�� 2��
���룺a = "1010", b = "1011"
�����"10101"
/***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a); // �ַ��� a �ĳ���
    int lenB = strlen(b); // �ַ��� b �ĳ���
    int maxLength = (lenA > lenB ? lenA : lenB) + 1; // ���ܵ���󳤶ȣ����ǽ�λ��
    
    char* result = (char*)malloc((maxLength + 1) * sizeof(char)); // �������ַ���
    result[maxLength] = '\0'; // �����ַ�����β��
    int carry = 0; // ��λ��־
    int index = maxLength - 1; // ����ַ�����ĩβ����

    // ��ĩβ��ǰ��λ���
    lenA--;
    lenB--;
    while (lenA >= 0 || lenB >= 0 || carry > 0) {
        int bitA = (lenA >= 0) ? a[lenA--] - '0' : 0; // �� a ȡ��ǰλ���� 0
        int bitB = (lenB >= 0) ? b[lenB--] - '0' : 0; // �� b ȡ��ǰλ���� 0
        int sum = bitA + bitB + carry; // ��ǰλ���
        result[index--] = (sum % 2) + '0'; // ��ǰλ���
        carry = sum / 2; // ���½�λ
    }

    // ����ж���� 0����ǰ���ƶ�����ַ���   ָ��   �ƶ������ַ�����Ԫ�ص�ַ
    return result + index + 1;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";

    char* result = addBinary(a, b);
    printf("���: %s\n", result);

    // ��Ϊ���������ƫ�ƣ���Ҫ��ԭʼ��ַ�ͷ�
    free(result - strlen(result));

    return 0;
}
