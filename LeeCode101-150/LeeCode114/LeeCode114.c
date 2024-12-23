/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-23 10:36:15
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-23 11:01:51
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode114\LeeCode114.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 递归实现：将二叉树展开为链表
void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    // 如果当前节点有左子树，处理左子树
    if (root->left != NULL) {
        // 先保存右子树
        struct TreeNode* rightSubtree = root->right;
        
        // 将左子树变为右子树
        root->right = root->left;
        root->left = NULL;
        
        // 找到原来左子树的最右节点
        struct TreeNode* temp = root->right;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        
        // 将保存的右子树连接到最右节点
        temp->right = rightSubtree;
    }
    
    // 递归处理右子树
    flatten(root->right);
}

// 辅助函数：创建树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 打印链表（右子树连接的形式）
void printFlattenedTree(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

// 测试代码
int main() {
    // 构建测试二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    // 调用 flatten 函数将二叉树展开为链表
    flatten(root);

    // 打印展开后的链表
    printFlattenedTree(root);

    return 0;
}
