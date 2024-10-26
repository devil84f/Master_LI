/***************************************************
 * Date:2024/10/25
 * ��Ŀ����:
��һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
�����ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

ʾ�� 1��
���룺head = [1,2,3,4]
�����[2,1,4,3]

ʾ�� 2��
���룺head = []
�����[]

ʾ�� 3��
���룺head = [1]
�����[1]
 
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 100] ��
0 <= Node.val <= 100
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct ListNode {
    int val;
    struct ListNode *next;
};

// �����½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// �������������еĽڵ�
struct ListNode* swapPairs(struct ListNode* head) {
    // �����ƽڵ㣬ָ��ͷ�ڵ�
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;

    // ���������������Ͻڵ�ʱ���н���
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // ���������ڵ�
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // �� prev �ƶ�����ǰ�����ĺ�һ���ڵ�
        prev = first;
    }

    // ���ؽ��������ͷ�ڵ�
    struct ListNode* newHead = dummy->next;
    free(dummy); // �ͷ��ƽڵ�
    return newHead;
}

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ����������
int main() {
    // ��������1 -> 2 -> 3 -> 4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("ԭ����: ");
    printList(head);

    // ��������ڵ�
    struct ListNode* newHead = swapPairs(head);

    printf("�����������: ");
    printList(newHead);

    return 0;
}
