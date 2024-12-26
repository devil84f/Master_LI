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

// 层次遍历的解决方案
struct Node* connect(struct Node* root) {
    if (!root) return NULL;
    
    struct Node* start = root;  // 当前层最左的节点

    // 遍历每一层
    while (start) {
        struct Node* current = start;
        
        // 遍历当前层
        while (current) {
            if (current->left) current->left->next = current->right;  // 左子树连接右子树
            if (current->right && current->next) current->right->next = current->next->left; // 右子树连接下一节点的左子树
            current = current->next; // 移动到下一节点
        }
        
        // 移动到下一层
        start = start->left;
    }
    
    return root;
}

// 辅助函数：创建树节点
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // 示例：创建一个简单的完美二叉树
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // 填充 next 指针
    connect(root);
    
    // 输出根节点的 next 指针（应该是 NULL）
    printf("Root's next: %p\n", root->next);  // NULL
    
    return 0;
}
