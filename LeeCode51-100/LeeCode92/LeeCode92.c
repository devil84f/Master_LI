/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-06 08:56:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-06 09:39:03
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode92\LeeCode92.c
 * @Description: 
    * ���㵥�����ͷָ�� head ���������� left �� right ������ left <= right ��
    * ���㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��
 */

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
struct ListNode {
    int val;
    struct ListNode *next;
};

// ��ת���� II ������
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    struct ListNode dummy; // �ڱ��ڵ�
    dummy.next = head;
    struct ListNode *prev = &dummy;

    // 1. �ҵ� left �ڵ��ǰ��
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // 2. ��ת����� [left, right] ����
    struct ListNode *curr = prev->next;
    struct ListNode *next = NULL;
    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    // 3. �����µ�����ͷ
    return dummy.next;
}

// ������������������
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
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createList(arr, 5);

    printf("ԭ����: ");
    printList(head);

    head = reverseBetween(head, 2, 4);

    printf("��ת������: ");
    printList(head);

    return 0;
}
