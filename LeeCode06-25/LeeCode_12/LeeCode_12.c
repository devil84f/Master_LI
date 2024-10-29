/***************************************************
 * Date:2024/10/17
 * ��Ŀ����:
������������ת��Ϊ�������֣�������ȡֵ��ΧΪ 1 �� 3999��

�������ֹ���
��������������7�����Ź��ɣ�I��1����V��5����X��10����L��50����C��100����D��500����M��1000����
�������ֵ������һЩ����������磺4 д�� IV��9 д�� IX��40 д�� XL��90 д�� XC��400 д�� CD��900 д�� CM��
/***************************************************/

#include <stdio.h>
#include <string.h>

char* intToRoman(int num) {
    // �����������ַ��ż����Ӧֵ
    char* roman_symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    // �������ڴ洢������ַ���
    static char result[20];
    int i = 0;
    result[0] = '\0'; // ��ʼ���ַ���Ϊ��
    
    // ����ƥ��ÿ���������ַ���
    while (num > 0) {
        while (num >= values[i]) {
            strcat(result, roman_symbols[i]);
            num -= values[i];
        }
        i++;
    }
    
    return result;
}

int main() {
    int num = 1994;
    printf("Roman numeral for %d is: %s\n", num, intToRoman(num));  // ���: MCMXCIV
    return 0;
}

