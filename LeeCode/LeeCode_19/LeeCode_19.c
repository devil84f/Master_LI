/***************************************************
 * Date:2024/10/21
 * 题目描述:电话号码的字母组合
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
/***************************************************/
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 辅助函数：创建新节点
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 删除倒数第 N 个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *first = &dummy, *second = &dummy;

    // 移动 first 指针 n + 1 步
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // 同时移动 first 和 second 指针
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // 删除倒数第 N 个节点
    struct ListNode* toDelete = second->next;
    second->next = second->next->next;
    free(toDelete);

    return dummy.next;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 主函数
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2; // 删除倒数第2个节点
    printf("原链表：");
    printList(head);

    head = removeNthFromEnd(head, n);
    printf("删除倒数第%d个节点后的链表:", n);
    printList(head);

    // 释放链表内存
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
