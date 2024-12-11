/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-11 09:35:00
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-11 09:39:02
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode99\LeeCode99.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 中序遍历存储节点
void inorder(struct TreeNode* root, struct TreeNode** nodes, int* index) {
    if (root == NULL) return;

    inorder(root->left, nodes, index);
    nodes[(*index)++] = root;
    inorder(root->right, nodes, index);
}

// 恢复二叉搜索树
void recoverTree(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* nodes[1000];
    int index = 0;

    // 中序遍历存储所有节点
    inorder(root, nodes, &index);

    // 找到两个被交换的节点
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    for (int i = 0; i < index - 1; i++) {
        if (nodes[i]->val > nodes[i + 1]->val) {
            if (first == NULL) first = nodes[i];
            second = nodes[i + 1];
        }
    }

    // 恢复树
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

// 创建新节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 打印二叉树的中序遍历
void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// 主函数
int main() {
    // 创建测试用例
    // 构建以下树：
    //     1
    //    / \
    //   3   4
    //    \
    //     2
    struct TreeNode* root = createNode(1);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->right = createNode(2);

    printf("原始中序遍历: ");
    printInorder(root);
    printf("\n");

    // 恢复二叉搜索树
    recoverTree(root);

    printf("恢复后中序遍历: ");
    printInorder(root);
    printf("\n");

    return 0;
}
