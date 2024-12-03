/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-03 10:24:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-03 10:26:15
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode86\LeeCode86.c
 * @Description: 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct ListNode {
    int val;
    struct ListNode* next;
};

// 分隔链表
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* smallHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* small = smallHead; // 小于 x 的虚拟头节点
    struct ListNode* large = largeHead; // 大于等于 x 的虚拟头节点

    // 遍历链表
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }

    // 将 large 部分拼接到 small 部分后面
    large->next = NULL;  // 防止链表循环
    small->next = largeHead->next;

    // 释放虚拟头节点内存
    free(largeHead);
    struct ListNode* result = smallHead->next;
    free(smallHead);
    return result;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf("->");
        head = head->next;
    }
    printf("\n");
}

// 辅助函数：创建链表
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        temp->next = node;
        temp = node;
    }
    return head;
}

// 测试代码
int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    struct ListNode* head = createList(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Original list: ");
    printList(head);

    int x = 3;
    struct ListNode* modifiedList = partition(head, x);
    printf("Modified list: ");
    printList(modifiedList);

    return 0;
}
