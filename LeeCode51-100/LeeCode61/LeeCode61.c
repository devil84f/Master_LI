/***************************************************
 * Date:2024/11/23
 * 题目描述:
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 旋转链表函数
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head; // 特殊情况直接返回
    }

    // 计算链表长度
    int n = 1;
    struct ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // 优化 k，计算实际旋转步数
    k = k % n;
    if (k == 0) {
        return head; // 如果 k 为 0，不需要旋转
    }

    // 将链表连成环
    tail->next = head;

    // 找到新头节点和新尾节点
    int stepsToNewHead = n - k;
    struct ListNode *newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    struct ListNode *newHead = newTail->next;

    // 断开环
    newTail->next = NULL;

    return newHead;
}

// 辅助函数：创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
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
    // 创建链表 [1, 2, 3, 4, 5]
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原始链表: ");
    printList(head);

    int k = 2;
    struct ListNode *rotated = rotateRight(head, k);

    printf("旋转链表后: ");
    printList(rotated);

    return 0;
}
