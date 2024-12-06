/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-06 08:56:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-06 09:39:03
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode92\LeeCode92.c
 * @Description: 
    * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
    * 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 */

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 反转链表 II 主函数
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    struct ListNode dummy; // 哨兵节点
    dummy.next = head;
    struct ListNode *prev = &dummy;

    // 1. 找到 left 节点的前驱
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // 2. 反转链表的 [left, right] 部分
    struct ListNode *curr = prev->next;
    struct ListNode *next = NULL;
    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    // 3. 返回新的链表头
    return dummy.next;
}

// 辅助函数：创建链表
struct ListNode* createList(int* arr, int size) {
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 主函数测试
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createList(arr, 5);

    printf("原链表: ");
    printList(head);

    head = reverseBetween(head, 2, 4);

    printf("反转后链表: ");
    printList(head);

    return 0;
}
