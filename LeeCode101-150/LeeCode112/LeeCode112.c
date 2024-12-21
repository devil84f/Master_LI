/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-21 15:52:26
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-21 15:53:35
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode112\LeeCode112.c
 * @Description: 
 * 
 */
/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-21 15:52:26
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-21 15:53:16
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode112\LeeCode112.c
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

// 递归判断是否存在路径和
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;  // 空树没有路径
    }
    
    // 如果当前节点是叶子节点
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;  // 判断当前路径和是否等于目标值
    }
    
    // 递归检查左右子树
    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
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
    struct TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);

    int targetSum = 22;
    if (hasPathSum(root, targetSum)) {
        printf("There is a path with sum %d.\n", targetSum);
    } else {
        printf("There is no path with sum %d.\n", targetSum);
    }

    return 0;
}
