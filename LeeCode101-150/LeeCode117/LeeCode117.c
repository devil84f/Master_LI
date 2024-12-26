/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-26 15:26:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-26 16:15:27
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode117\LeeCode117.c
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

// ��ʼ��Node����
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
struct Node* connect(struct Node* root) {
    if (!root) return NULL;
    
    struct Node* start = root;  // ��ǰ������Ľڵ�
    
    // ����ÿһ��
    while (start) {
        struct Node* current = start;
        struct Node* nextStart = NULL;  // ��һ�������ڵ�
        struct Node* prev = NULL;  // ��¼��һ��Ľڵ�
        
        // ������ǰ��Ľڵ�
        while (current) {
            if (current->left) {
                if (!nextStart) nextStart = current->left;  // ������һ�������ڵ�
                if (prev) prev->next = current->left;  // ������һ�ڵ���Ҳ�
                prev = current->left;  // ������һ�ڵ�Ϊ��ǰ���ӽڵ�
            }
            if (current->right) {
                if (!nextStart) nextStart = current->right;  // ������һ�������ڵ�
                if (prev) prev->next = current->right;  // ������һ�ڵ���Ҳ�
                prev = current->right;  // ������һ�ڵ�Ϊ��ǰ���ӽڵ�
            }
            current = current->next;  // �ƶ�����һ�ڵ�
        }
        
        // �ƶ�����һ��
        start = nextStart;
    }
    
    return root;
}

int main() {
    // ʾ��������һ���򵥵Ķ�����
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(7);
    
    // ��� next ָ��
    connect(root);
    
    // ������ڵ�� next ָ�루Ӧ���� NULL��
    printf("Root's next: %p\n", root->next);  // NULL
    
    return 0;
}
