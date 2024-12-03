/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-03 09:33:02
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-03 09:34:01
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode83\LeeCode83.c
 * @Description: 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct ListNode {
    int val;
    struct ListNode *next;
};

// ɾ�����������е��ظ�Ԫ��
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head; // ��ʼ��ָ��

    // ��������
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // �����ǰ�ڵ����һ���ڵ��ֵ��ͬ��������һ���ڵ�
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // �ͷű�ɾ���Ľڵ�
        } else {
            // ���ֵ��ͬ���ƶ�����һ���ڵ�
            current = current->next;
        }
    }

    return head;
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
    int arr1[] = {1, 1, 2};
    struct ListNode* head1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("Original list: ");
    printList(head1);

    head1 = deleteDuplicates(head1);
    printf("Modified list: ");
    printList(head1);

    int arr2[] = {1, 1, 2, 3, 3};
    struct ListNode* head2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("Original list: ");
    printList(head2);

    head2 = deleteDuplicates(head2);
    printf("Modified list: ");
    printList(head2);

    return 0;
}
