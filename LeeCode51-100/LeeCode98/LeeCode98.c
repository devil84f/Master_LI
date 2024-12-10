/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-10 10:48:03
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-10 10:52:46
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode98\LeeCode98.c
 * @Description: 
 * 
 */

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>

// 定义二叉树节点
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数
bool inorder(struct TreeNode* root, long* prev) {
    if (root == NULL) {
        return true;
    }

    // 检查左子树
    if (!inorder(root->left, prev)) {
        return false;
    }

    // 检查当前节点
    if (root->val <= *prev) {
        return false;
    }
    *prev = root->val;

    // 检查右子树
    return inorder(root->right, prev);
}

bool isValidBST(struct TreeNode* root) {
    long prev = LONG_MIN; // 初始化为最小值
    return inorder(root, &prev);
}
