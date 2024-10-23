/***************************************************
 * Date:2024/10/23
 * 题目描述:
要求将两个升序链表合并为一个新的升序链表，并返回合并后的链表
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 合并两个有序链表的函数
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 创建虚拟头节点
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    // 比较两个链表的节点，按顺序合并
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 处理剩余的链表节点
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    // 返回合并后的链表
    return dummy.next;
}

// 创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 主函数
int main() {
    // 创建第一个有序链表 1 -> 2 -> 4
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    // 创建第二个有序链表 1 -> 3 -> 4
    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    // 合并两个链表
    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    // 打印合并后的链表
    printList(mergedList);

    return 0;
}
