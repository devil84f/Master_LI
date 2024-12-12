/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-12 10:00:14
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-12 10:34:03
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode101\LeeCode101.c
 * @Description: 
 * 
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 定义二叉树节点结构体
struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数，检查两个节点是否对称
bool isSymmetric(struct TreeNode* left, struct TreeNode* right) {
    // 如果两个节点都为空，说明对称
    if (left == NULL && right == NULL) {
        return true;
    }
    // 如果一个为空，一个非空，或者值不相等，说明不对称
    if (left == NULL || right == NULL || left->val != right->val) {
        return false;
    }
    // 递归检查左子树和右子树
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

// 主函数，检查二叉树是否对称
bool Symmetric(struct TreeNode* root) {
    // 空树也是对称的
    if (root == NULL) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

// 测试代码
int main() {
    // 创建测试用的二叉树
    struct TreeNode root;
    root.val = 1;
    root.left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->val = 2;
    root.right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->val = 2;
    root.left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->left->val = 3;
    root.left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->right->val = 4;
    root.right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->left->val = 4;
    root.right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->right->val = 3;

    // 检查是否对称
    if (Symmetric(&root)) {
        printf("The tree is symmetric.\n");
    } else {
        printf("The tree is not symmetric.\n");
    }

    // 释放内存
    free(root.left->left);
    free(root.left->right);
    free(root.right->left);
    free(root.right->right);
    free(root.left);
    free(root.right);

    return 0;
}
