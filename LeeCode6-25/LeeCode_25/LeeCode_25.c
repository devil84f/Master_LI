/***************************************************
 * Date:2024/10/27
 * ��Ŀ����:
��һ�������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������
k ��һ��������������ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
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

// ��ת����
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

// K ��һ�鷴ת����
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1 || head == NULL) return head;

    // �����ƽڵ�
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* end = head;

    while (end != NULL) {
        // �� end ָ���ƶ����� k ���ڵ�
        for (int i = 1; i < k && end != NULL; i++) {
            end = end->next;
        }
        
        if (end == NULL) break;  // �ڵ㲻�� k ��������ѭ��

        struct ListNode* nextGroup = end->next;
        struct ListNode* start = prev->next;

        // �Ͽ�������ת��ǰ��
        end->next = NULL;
        prev->next = reverse(start, end->next);

        // ����ת��������������ӵ���һ��
        start->next = nextGroup;

        // �ƶ� prev �� end ����һ�����
        prev = start;
        end = prev->next;
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
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
    // ��������1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭ����: ");
    printList(head);

    // K ��һ�鷴ת
    int k = 4;
    struct ListNode* newHead = reverseKGroup(head, k);

    printf("K = %d ʱ�ķ�ת����: ", k);
    printList(newHead);

    return 0;
}
