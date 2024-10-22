/***************************************************
 * Date:2024/10/21
 * ��Ŀ����:�绰�������ĸ���
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
/***************************************************/
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// ���������������½ڵ�
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// ɾ�������� N ���ڵ�
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *first = &dummy, *second = &dummy;

    // �ƶ� first ָ�� n + 1 ��
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // ͬʱ�ƶ� first �� second ָ��
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // ɾ�������� N ���ڵ�
    struct ListNode* toDelete = second->next;
    second->next = second->next->next;
    free(toDelete);

    return dummy.next;
}

// ������������ӡ����
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ������
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2; // ɾ��������2���ڵ�
    printf("ԭ����");
    printList(head);

    head = removeNthFromEnd(head, n);
    printf("ɾ��������%d���ڵ�������:", n);
    printList(head);

    // �ͷ������ڴ�
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
