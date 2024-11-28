/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-11-28 14:15:02
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-11-28 15:02:56
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode71\LeeCode71.c
 * @Description: 
 *              ����һ���ַ��� path ����ʾָ��ĳһ�ļ���Ŀ¼�� Unix ��� ����·�� ���� '/' ��ͷ�������㽫��ת��Ϊ ���Ӽ��Ĺ淶·����
                �� Unix �����ļ�ϵͳ�й������£�

                һ���� '.' ��ʾ��ǰĿ¼����
                ���⣬������ '..' ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼����
                ������������б�ܣ�����'//' �� '///'��������Ϊ����б�� '/'��
                �κ�������ʽ�ĵ㣨���磬'...' �� '....'��������Ϊ��Ч���ļ�/Ŀ¼���ơ�
                ���ص� ��·�� ������ѭ������ʽ��
                ʼ����б�� '/' ��ͷ��
                ����Ŀ¼��֮�����ֻ��һ��б�� '/' ��
                ���һ��Ŀ¼����������ڣ����� �� '/' ��β��
                ���⣬·���������Ӹ�Ŀ¼��Ŀ���ļ���Ŀ¼��·���ϵ�Ŀ¼���������� '.' �� '..'����
                ���ؼ򻯺�õ��� �淶·�� ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    // ����һ��ջ
    char* stack[3000]; // ����·��������� 3000 ��Ŀ¼
    int top = -1; // ջ��ָ��
    
    char* token = strtok(path, "/"); // �� "/" �ָ�·��

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // ����� ".."������ջ��Ŀ¼
            if (top >= 0) {
                top--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // �������ЧĿ¼����ѹ��ջ
            stack[++top] = token;
        }
        token = strtok(NULL, "/"); // �����ָ���һ������
    }
    
    // ƴ�Ӽ�·��
    char* result = (char*)malloc(3000 * sizeof(char));
    result[0] = '\0';
    
    if (top == -1) {
        strcpy(result, "/");
    } else {
        for (int i = 0; i <= top; i++) {
            strcat(result, "/");
            strcat(result, stack[i]);
        }
    }
    
    return result;
}

int main() {
    char path[3000];
    printf("������·����");
    scanf("%s", path);
    
    char* result = simplifyPath(path);
    printf("�򻯺��·��Ϊ��%s\n", result);
    
    free(result);
    return 0;
}
