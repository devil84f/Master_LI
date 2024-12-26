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

// 初始化Node函数
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

// 填充每个节点的下一个右侧节点指针
struct Node* connect(struct Node* root) {
    if (!root) return NULL;
    
    struct Node* start = root;  // 当前层最左的节点
    
    // 遍历每一层
    while (start) {
        struct Node* current = start;
        struct Node* nextStart = NULL;  // 下一层的最左节点
        struct Node* prev = NULL;  // 记录上一层的节点
        
        // 遍历当前层的节点
        while (current) {
            if (current->left) {
                if (!nextStart) nextStart = current->left;  // 设置下一层的最左节点
                if (prev) prev->next = current->left;  // 连接上一节点的右侧
                prev = current->left;  // 更新上一节点为当前左子节点
            }
            if (current->right) {
                if (!nextStart) nextStart = current->right;  // 设置下一层的最左节点
                if (prev) prev->next = current->right;  // 连接上一节点的右侧
                prev = current->right;  // 更新上一节点为当前右子节点
            }
            current = current->next;  // 移动到下一节点
        }
        
        // 移动到下一层
        start = nextStart;
    }
    
    return root;
}

int main() {
    // 示例：创建一个简单的二叉树
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(7);
    
    // 填充 next 指针
    connect(root);
    
    // 输出根节点的 next 指针（应该是 NULL）
    printf("Root's next: %p\n", root->next);  // NULL
    
    return 0;
}
