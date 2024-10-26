/***************************************************
 * Date:2024/10/25
 * 题目描述:
给一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
 
提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 两两交换链表中的节点
struct ListNode* swapPairs(struct ListNode* head) {
    // 创建哑节点，指向头节点
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;

    // 当存在两个及以上节点时进行交换
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // 交换两个节点
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // 将 prev 移动到当前交换的后一个节点
        prev = first;
    }

    // 返回交换后的新头节点
    struct ListNode* newHead = dummy->next;
    free(dummy); // 释放哑节点
    return newHead;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 主函数测试
int main() {
    // 创建链表：1 -> 2 -> 3 -> 4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("原链表: ");
    printList(head);

    // 交换链表节点
    struct ListNode* newHead = swapPairs(head);

    printf("交换后的链表: ");
    printList(newHead);

    return 0;
}
