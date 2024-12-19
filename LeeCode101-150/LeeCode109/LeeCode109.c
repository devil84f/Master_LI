/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-19 09:30:58
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-19 09:31:00
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode109\LeeCode109.c
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

// ����������ڵ�
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ����ָ���ҵ������м�ڵ�
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// �ݹ鹹������������
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    // �ҵ��м�ڵ�
    struct ListNode* mid = findMiddle(head);

    // �������ڵ�
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = root->right = NULL;

    // ���������ֻ��һ��Ԫ�أ�����Ҫ�ݹ�
    if (head == mid) {
        return root;
    }

    // �ݹ鹹��������
    struct ListNode* leftList = head;
    struct ListNode* rightList = mid->next;
    struct ListNode* temp = leftList;
    while (temp->next != mid) {
        temp = temp->next;
    }
    temp->next = NULL;

    root->left = sortedListToBST(leftList);
    root->right = sortedListToBST(rightList);

    return root;
}

// ������������ӡ�����������������
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

// ���Դ���
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = -10;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = -3;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 0;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 5;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 9;
    head->next->next->next->next->next = NULL;

    struct TreeNode* root = sortedListToBST(head);
    inorderTraversal(root);  // �������������
    printf("\n");

    return 0;
}
