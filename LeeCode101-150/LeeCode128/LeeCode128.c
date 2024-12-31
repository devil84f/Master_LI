/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-12-31 09:33:22
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-12-31 10:52:11
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode128\LeeCode128.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 哈希表节点结构
typedef struct HashNode {
    int key;
    struct HashNode* next;
} HashNode;

// 哈希表结构
typedef struct HashTable {
    HashNode** buckets;
    int size;
} HashTable;

// 创建哈希表
HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    table->size = size;
    return table;
}

// 哈希函数
int hash(int key, int size) {
    return (key < 0 ? -key : key) % size;
}

// 插入键到哈希表
void insertHashTable(HashTable* table, int key) {
    int index = hash(key, table->size);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->next = table->buckets[index];
    table->buckets[index] = node;
}

// 查找键是否存在
bool searchHashTable(HashTable* table, int key) {
    int index = hash(key, table->size);
    HashNode* node = table->buckets[index];
    while (node) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

// 释放哈希表
void freeHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        HashNode* node = table->buckets[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// 求最长连续序列长度
int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // 创建哈希表
    HashTable* table = createHashTable(numsSize);

    // 插入所有数字到哈希表
    for (int i = 0; i < numsSize; i++) {
        insertHashTable(table, nums[i]);
    }

    int maxLength = 0;

    // 遍历数组，检查最长连续序列
    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];
        if (!searchHashTable(table, currentNum - 1)) { // 判断是否是起点
            int length = 1;
            while (searchHashTable(table, currentNum + length)) {
                length++;
            }
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    // 释放哈希表
    freeHashTable(table);
    return maxLength;
}

int main() {
    // 示例1
    int nums1[] = {100, 4, 200, 1, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("最长连续序列的长度：%d\n", longestConsecutive(nums1, size1)); // 输出：4

    // 示例2
    int nums2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("最长连续序列的长度：%d\n", longestConsecutive(nums2, size2)); // 输出：9

    return 0;
}
