/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-07 14:59:16
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-07 15:15:31
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode94\LeeCode94.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数：递归中序遍历 <左 根 右>
void inorderHelper(struct TreeNode *root, int *result, int *returnSize) {
    if (root == NULL) return;

    // 递归遍历左子树
    inorderHelper(root->left, result, returnSize);
    // 记录当前节点值
    result[(*returnSize)++] = root->val;
    // 递归遍历右子树
    inorderHelper(root->right, result, returnSize);
}

// 主函数：返回中序遍历结果
int* inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;

    // 为结果数组分配空间（假设最多有 100 个节点）
    int *result = (int *)malloc(100 * sizeof(int));
    if (result == NULL) return NULL;

    inorderHelper(root, result, returnSize);
    return result;
}

// 测试函数
int main() {
    // 构造二叉树 [1, null, 2, 3]
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node2 = {2, &node3, NULL};
    struct TreeNode root = {1, NULL, &node2};

    int returnSize;
    int *result = inorderTraversal(&root, &returnSize);

    printf("中序遍历结果: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // 释放内存
    return 0;
}
