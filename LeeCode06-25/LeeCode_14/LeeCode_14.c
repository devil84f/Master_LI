/***************************************************
 * Date:2024/10/18
 * ��Ŀ����:
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1��
���룺strs = ["flower","flow","flight"]
�����"fl"

ʾ�� 2��
���룺strs = ["dog","racecar","car"]
�����""
���ͣ����벻���ڹ���ǰ׺��
/***************************************************/

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // ����һ���ַ�����Ϊ��ʼ����ǰ׺
    char* prefix = strs[0];
    
    for (int i = 1; i < strsSize; i++) {
        // �Ƚϵ�ǰ�ַ�����ǰ׺
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {
            // �����ƥ�䣬����ǰ׺
            prefix[strlen(prefix) - 1] = '\0'; // ʹ�� '\0' ��ֹ������ǰ׺
            
            // ���ǰ׺Ϊ�գ���ǰ�˳�
            if (strlen(prefix) == 0) return "";
        }
    }
    
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int size = sizeof(strs) / sizeof(strs[0]);
    printf("Longest common prefix: %s\n", longestCommonPrefix(strs, size)); // �����fl
    return 0;
}
