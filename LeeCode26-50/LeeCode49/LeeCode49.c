/***************************************************
 * Date:2024/11/12
 * 题目描述:
给你一个字符串数组，请你将字母异位词组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// 比较两个字符串的排序结果
int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

// 字符串排序函数
void sort_string(char *str) {
    qsort(str, strlen(str), sizeof(char), compare);
}

// 主解法，返回结果作为函数的返回值
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // 使用哈希表存储排序后的字符串和对应的字母异位词
    char* hash_map[10000]; // 假设最多10000个不同的字母异位词
    int hash_map_size = 0;
    
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);

    // 临时存储每组字母异位词
    char*** ans = (char***)malloc(sizeof(char**) * strsSize);
    
    for (int i = 0; i < strsSize; i++) {
        // 排序当前字符串
        char *sorted_str = strdup(strs[i]); // 复制当前字符串
        sort_string(sorted_str);

        // 查找是否已存在该排序后的字符串
        int found = -1;
        for (int j = 0; j < hash_map_size; j++) {
            if (strcmp(sorted_str, hash_map[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            // 新的字母异位词组
            hash_map[hash_map_size] = sorted_str;
            ans[hash_map_size] = (char**)malloc(sizeof(char*) * strsSize);
            (*returnColumnSizes)[hash_map_size] = 0;
            found = hash_map_size;
            hash_map_size++;
        } else {
            free(sorted_str);  // 释放不再需要的内存
        }

        // 将当前字符串加入对应的字母异位词组
        ans[found][(*returnColumnSizes)[found]++] = strs[i];
    }

    *returnSize = hash_map_size;
    return ans;
}

int main() {
    // 输入
    char *param_1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size_1 = 6;

    // 输出结果
    int ret_size, *ret_colsize;
    
    // 调用 groupAnagrams 并直接接收返回值
    char ***ret = groupAnagrams(param_1, size_1, &ret_size, &ret_colsize);
    
    // 打印结果
    printf("Total Groups: %d\n", ret_size);
    for (int i = 0; i < ret_size; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < ret_colsize[i]; j++) {
            printf("%s ", ret[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < ret_size; i++) {
        free(ret[i]);
    }
    free(ret_colsize);
    free(ret);

    return 0;
}
