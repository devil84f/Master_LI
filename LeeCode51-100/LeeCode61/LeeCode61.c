/***************************************************
 * Date:2024/11/23
 * ��Ŀ����:
����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�

ʾ�� 1��
���룺head = [1,2,3,4,5], k = 2
�����[4,5,1,2,3]

ʾ�� 2��
���룺head = [0,1,2], k = 4
�����[2,0,1]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// ��ת������
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head; // �������ֱ�ӷ���
    }

    // ����������
    int n = 1;
    struct ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // �Ż� k������ʵ����ת����
    k = k % n;
    if (k == 0) {
        return head; // ��� k Ϊ 0������Ҫ��ת
    }

    // ���������ɻ�
    tail->next = head;

    // �ҵ���ͷ�ڵ����β�ڵ�
    int stepsToNewHead = n - k;
    struct ListNode *newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    struct ListNode *newHead = newTail->next;

    // �Ͽ���
    newTail->next = NULL;

    return newHead;
}

// ���������������½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ������������ӡ����
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // �������� [1, 2, 3, 4, 5]
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭʼ����: ");
    printList(head);

    int k = 2;
    struct ListNode *rotated = rotateRight(head, k);

    printf("��ת�����: ");
    printList(rotated);

    return 0;
}
