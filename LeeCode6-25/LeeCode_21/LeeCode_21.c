/***************************************************
 * Date:2024/10/23
 * ��Ŀ����:
Ҫ��������������ϲ�Ϊһ���µ��������������غϲ��������
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
struct ListNode {
    int val;
    struct ListNode *next;
};

// �ϲ�������������ĺ���
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // ��������ͷ�ڵ�
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    // �Ƚ���������Ľڵ㣬��˳��ϲ�
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

    // ����ʣ�������ڵ�
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    // ���غϲ��������
    return dummy.next;
}

// ��������ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ������
int main() {
    // ������һ���������� 1 -> 2 -> 4
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    // �����ڶ����������� 1 -> 3 -> 4
    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    // �ϲ���������
    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    // ��ӡ�ϲ��������
    printList(mergedList);

    return 0;
}
