/***************************************************
 * Date:2024/11/7
 * ��Ŀ����:
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������

ʾ�� 1:
����: num1 = "2", num2 = "3"
���: "6"

ʾ�� 2:
����: num1 = "123", num2 = "456"
���: "56088"
 
��ʾ��
1 <= num1.length, num2.length <= 200
num1 �� num2 ֻ����������ɡ�
num1 �� num2 ���������κ�ǰ���㣬��������0����
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ַ�����˺���
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int totalLen = len1 + len2;
    
    // �����������洢�˻��ĸ���λ����ֵ
    int* result = (int*)calloc(totalLen, sizeof(int));
    
    // �Ӹ�λ��ʼ��λ���
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            
            // ���ӵ���ǰλ�õ�ֵ���������λ
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    
    // ����ǰ����
    int start = 0;
    while (start < totalLen && result[start] == 0) {
        start++;
    }
    
    // �����Ϊ�㣬��ֱ�ӷ��� "0"
    if (start == totalLen) {
        free(result);
        return strdup("0");
    }
    
    // ת�����Ϊ�ַ���
    char* product = (char*)malloc((totalLen - start + 1) * sizeof(char));
    for (int i = start; i < totalLen; i++) {
        product[i - start] = result[i] + '0';
    }
    product[totalLen - start] = '\0';
    
    free(result);
    return product;
}

// ���Դ���
int main() {
    char num1[] = "123";
    char num2[] = "456";
    
    char* result = multiply(num1, num2);
    printf("���: %s\n", result);
    
    free(result);
    return 0;
}
