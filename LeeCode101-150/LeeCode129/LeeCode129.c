/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-01 23:18:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-01 23:18:33
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode129\LeeCode129.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建节点函数
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 深度优先搜索（DFS）递归函数
void dfs(struct TreeNode* root, int currentSum, int* totalSum) {
    if (root == NULL) {
        return;
    }

    // 更新当前路径数字
    currentSum = currentSum * 10 + root->val;

    // 如果是叶子节点，累加当前路径的数字
    if (root->left == NULL && root->right == NULL) {
        *totalSum += currentSum;
    }

    // 递归左子树和右子树
    dfs(root->left, currentSum, totalSum);
    dfs(root->right, currentSum, totalSum);
}

// 主函数，求根到叶子节点数字之和
int sumNumbers(struct TreeNode* root) {
    int totalSum = 0;
    dfs(root, 0, &totalSum);
    return totalSum;
}

int main() {
    // 示例1：创建二叉树 [1,2,3]
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    
    printf("根到叶子节点数字之和：%d\n", sumNumbers(root1)); // 输出：25

    // 示例2：创建二叉树 [4,9,0,5,1]
    struct TreeNode* root2 = createNode(4);
    root2->left = createNode(9);
    root2->right = createNode(0);
    root2->left->left = createNode(5);
    root2->left->right = createNode(1);
    
    printf("根到叶子节点数字之和：%d\n", sumNumbers(root2)); // 输出：1026

    // 示例3：创建二叉树 [0]
    struct TreeNode* root3 = createNode(0);
    
    printf("根到叶子节点数字之和：%d\n", sumNumbers(root3)); // 输出：0

    return 0;
}
