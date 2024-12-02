/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-02 11:21:53
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-02 11:30:03
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode82\LeeCode82.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 删除排序链表中的重复元素 II
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // 创建一个虚拟头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy; // prev 是指向当前不重复元素的前一个节点

    while (head != NULL) {
        // 如果当前节点的值与下一个节点的值相同
        if (head->next != NULL && head->val == head->next->val) {
            // 跳过所有重复节点
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            // 删除重复元素
            prev->next = head->next;
        } else {
            // 当前节点不是重复节点，继续遍历
            prev = prev->next;
        }
        head = head->next;
    }
    struct ListNode* result = dummy->next;
    free(dummy); // 释放虚拟头节点
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

int main() {
    int arr1[] = {1, 2, 3, 3, 4, 4, 5};
    struct ListNode* head1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("Original list: ");
    printList(head1);

    head1 = deleteDuplicates(head1);
    printf("Modified list: ");
    printList(head1);

    int arr2[] = {1, 1, 1, 2, 3};
    struct ListNode* head2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("Original list: ");
    printList(head2);

    head2 = deleteDuplicates(head2);
    printf("Modified list: ");
    printList(head2);

    return 0;
}
