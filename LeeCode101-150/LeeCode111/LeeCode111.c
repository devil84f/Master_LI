/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-21 15:42:58
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-21 15:52:49
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode111\LeeCode111.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 递归计算二叉树的最小深度
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // 空树的深度为0
    }
    
    // 如果只有一个子树，则返回另一个子树的深度
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    
    // 计算左右子树的最小深度
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    // 返回最小的深度
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

// 辅助函数：创建树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 测试代码
int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int depth = minDepth(root);
    printf("The minimum depth of the binary tree is: %d\n", depth);

    return 0;
}
