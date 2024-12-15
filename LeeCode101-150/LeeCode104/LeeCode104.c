/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-15 20:40:01
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-15 20:44:00
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode104\LeeCode104.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 递归计算二叉树的最大深度
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0; // 空节点返回深度为 0

    // 递归计算左子树和右子树的最大深度
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // 返回左右子树深度的最大值加 1
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    // 构建二叉树 [3,9,20,null,null,15,7]
    struct TreeNode node7 = {7, NULL, NULL};
    struct TreeNode node15 = {15, NULL, NULL};
    struct TreeNode node20 = {20, &node15, &node7};
    struct TreeNode node9 = {9, NULL, NULL};
    struct TreeNode root = {3, &node9, &node20};

    // 递归法求最大深度
    int depthRecursive = maxDepth(&root);
    printf("递归法计算的最大深度：%d\n", depthRecursive);

    return 0;
}
