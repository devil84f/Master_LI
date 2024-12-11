/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-11 09:35:00
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-11 11:29:12
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode100\LeeCode100.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义树节点结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // 两个节点都为空
    if (p == NULL && q == NULL) return true;
    
    // 其中一个节点为空，或者值不同
    if (p == NULL || q == NULL || p->val != q->val) return false;

    // 递归检查左子树和右子树
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 主函数
int main() {
    // 创建两棵相同的树
    struct TreeNode* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    struct TreeNode* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    // 检查是否相同
    if (isSameTree(p, q)) {
        printf("两棵树相同\n");
    } else {
        printf("两棵树不同\n");
    }

    return 0;
}
