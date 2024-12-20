/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-20 09:46:46
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-20 10:30:40
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode110\LeeCode110.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 计算树的高度，如果树不平衡，返回 -1
int checkHeight(struct TreeNode* root) {
    // 空树的高度为 0
    if (root == NULL) {
        return 0;
    }

    // 递归计算左子树高度
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1; // 如果左子树不平衡，直接返回 -1
    }

    // 递归计算右子树高度
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) {
        return -1; // 如果右子树不平衡，直接返回 -1
    }

    // 判断当前节点的左右子树高度差
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // 如果高度差大于 1，返回 -1，表示不平衡
    }

    // 返回当前节点的高度
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// 判断树是否为平衡二叉树
bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
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
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(3);
    root->left->left->left = createNode(4);
    root->left->left->right = createNode(4);

    if (isBalanced(root)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    return 0;
}
