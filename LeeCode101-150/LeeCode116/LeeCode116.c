/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-26 15:26:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-26 15:40:01
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode116\LeeCode116.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

// ��α����Ľ������
struct Node* connect(struct Node* root) {
    if (!root) return NULL;
    
    struct Node* start = root;  // ��ǰ������Ľڵ�

    // ����ÿһ��
    while (start) {
        struct Node* current = start;
        
        // ������ǰ��
        while (current) {
            if (current->left) current->left->next = current->right;  // ����������������
            if (current->right && current->next) current->right->next = current->next->left; // ������������һ�ڵ��������
            current = current->next; // �ƶ�����һ�ڵ�
        }
        
        // �ƶ�����һ��
        start = start->left;
    }
    
    return root;
}

// �����������������ڵ�
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // ʾ��������һ���򵥵�����������
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // ��� next ָ��
    connect(root);
    
    // ������ڵ�� next ָ�루Ӧ���� NULL��
    printf("Root's next: %p\n", root->next);  // NULL
    
    return 0;
}
