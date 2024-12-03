/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-03 10:24:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-03 10:26:15
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode86\LeeCode86.c
 * @Description: 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct ListNode {
    int val;
    struct ListNode* next;
};

// �ָ�����
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* smallHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* small = smallHead; // С�� x ������ͷ�ڵ�
    struct ListNode* large = largeHead; // ���ڵ��� x ������ͷ�ڵ�

    // ��������
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }

    // �� large ����ƴ�ӵ� small ���ֺ���
    large->next = NULL;  // ��ֹ����ѭ��
    small->next = largeHead->next;

    // �ͷ�����ͷ�ڵ��ڴ�
    free(largeHead);
    struct ListNode* result = smallHead->next;
    free(smallHead);
    return result;
}

// ������������ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf("->");
        head = head->next;
    }
    printf("\n");
}

// ������������������
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        temp->next = node;
        temp = node;
    }
    return head;
}

// ���Դ���
int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    struct ListNode* head = createList(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Original list: ");
    printList(head);

    int x = 3;
    struct ListNode* modifiedList = partition(head, x);
    printf("Modified list: ");
    printList(modifiedList);

    return 0;
}
