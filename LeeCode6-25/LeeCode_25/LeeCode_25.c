/***************************************************
 * Date:2024/10/27
 * 题目描述:
给一个链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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

// 反转链表
struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != tail) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// K 个一组反转链表
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1 || head == NULL) return head;

    // 创建哑节点
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* end = head;

    while (end != NULL) {
        // 将 end 指针移动到第 k 个节点
        for (int i = 1; i < k && end != NULL; i++) {
            end = end->next;
        }
        
        if (end == NULL) break;  // 节点不足 k 个，跳出循环

        struct ListNode* nextGroup = end->next;
        struct ListNode* start = prev->next;

        // 断开链表，反转当前组
        end->next = NULL;
        prev->next = reverse(start, end->next);

        // 将反转后的链表重新连接到下一组
        start->next = nextGroup;

        // 移动 prev 和 end 到下一组起点
        prev = start;
        end = prev->next;
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
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
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原链表: ");
    printList(head);

    // K 个一组反转
    int k = 4;
    struct ListNode* newHead = reverseKGroup(head, k);

    printf("K = %d 时的反转链表: ", k);
    printList(newHead);

    return 0;
}
