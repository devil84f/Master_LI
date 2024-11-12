/***************************************************
 * Date:2024/11/12
 * ��Ŀ����:
����һ���ַ������飬���㽫��ĸ��λ�������һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�

ʾ�� 1:
����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
���: [["bat"],["nat","tan"],["ate","eat","tea"]]

ʾ�� 2:
����: strs = [""]
���: [[""]]

ʾ�� 3:
����: strs = ["a"]
���: [["a"]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// �Ƚ������ַ�����������
int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

// �ַ���������
void sort_string(char *str) {
    qsort(str, strlen(str), sizeof(char), compare);
}

// ���ⷨ�����ؽ����Ϊ�����ķ���ֵ
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // ʹ�ù�ϣ��洢�������ַ����Ͷ�Ӧ����ĸ��λ��
    char* hash_map[10000]; // �������10000����ͬ����ĸ��λ��
    int hash_map_size = 0;
    
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);

    // ��ʱ�洢ÿ����ĸ��λ��
    char*** ans = (char***)malloc(sizeof(char**) * strsSize);
    
    for (int i = 0; i < strsSize; i++) {
        // ����ǰ�ַ���
        char *sorted_str = strdup(strs[i]); // ���Ƶ�ǰ�ַ���
        sort_string(sorted_str);

        // �����Ƿ��Ѵ��ڸ��������ַ���
        int found = -1;
        for (int j = 0; j < hash_map_size; j++) {
            if (strcmp(sorted_str, hash_map[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            // �µ���ĸ��λ����
            hash_map[hash_map_size] = sorted_str;
            ans[hash_map_size] = (char**)malloc(sizeof(char*) * strsSize);
            (*returnColumnSizes)[hash_map_size] = 0;
            found = hash_map_size;
            hash_map_size++;
        } else {
            free(sorted_str);  // �ͷŲ�����Ҫ���ڴ�
        }

        // ����ǰ�ַ��������Ӧ����ĸ��λ����
        ans[found][(*returnColumnSizes)[found]++] = strs[i];
    }

    *returnSize = hash_map_size;
    return ans;
}

int main() {
    // ����
    char *param_1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size_1 = 6;

    // ������
    int ret_size, *ret_colsize;
    
    // ���� groupAnagrams ��ֱ�ӽ��շ���ֵ
    char ***ret = groupAnagrams(param_1, size_1, &ret_size, &ret_colsize);
    
    // ��ӡ���
    printf("Total Groups: %d\n", ret_size);
    for (int i = 0; i < ret_size; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < ret_colsize[i]; j++) {
            printf("%s ", ret[i][j]);
        }
        printf("\n");
    }

    // �ͷ��ڴ�
    for (int i = 0; i < ret_size; i++) {
        free(ret[i]);
    }
    free(ret_colsize);
    free(ret);

    return 0;
}
