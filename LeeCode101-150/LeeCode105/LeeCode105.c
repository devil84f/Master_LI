/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-16 09:12:42
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-16 09:13:10
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode105\LeeCode105.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 定义辅助栈节点
struct StackNode {
    struct TreeNode* node;
    int preorderStart, preorderEnd;
    int inorderStart, inorderEnd;
    struct StackNode* next;
};

// 入栈函数
void push(struct StackNode** stack, struct TreeNode* node, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->preorderStart = preorderStart;
    newNode->preorderEnd = preorderEnd;
    newNode->inorderStart = inorderStart;
    newNode->inorderEnd = inorderEnd;
    newNode->next = *stack;
    *stack = newNode;
}

// 出栈函数
struct StackNode* pop(struct StackNode** stack) {
    if (*stack == NULL) return NULL;
    struct StackNode* topNode = *stack;
    *stack = (*stack)->next;
    return topNode;
}

// 辅助函数：找到根节点在中序中的索引
int findIndex(int* inorder, int inorderStart, int inorderEnd, int value) {
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// 构造二叉树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) return NULL;

    // 初始化根节点
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    // 初始化辅助栈
    struct StackNode* stack = NULL;
    push(&stack, root, 0, preorderSize - 1, 0, inorderSize - 1);

    while (stack != NULL) {
        struct StackNode* current = pop(&stack);
        struct TreeNode* node = current->node;
        int preorderStart = current->preorderStart;
        int preorderEnd = current->preorderEnd;
        int inorderStart = current->inorderStart;
        int inorderEnd = current->inorderEnd;
        free(current);

        // 找到根节点在中序中的位置
        int rootIndex = findIndex(inorder, inorderStart, inorderEnd, node->val);

        // 构造右子树
        if (rootIndex + 1 <= inorderEnd) {
            struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            rightNode->val = preorder[preorderStart + (rootIndex - inorderStart) + 1];
            rightNode->left = NULL;
            rightNode->right = NULL;
            node->right = rightNode;
            push(&stack, rightNode, preorderStart + (rootIndex - inorderStart) + 1, preorderEnd, rootIndex + 1, inorderEnd);
        }

        // 构造左子树
        if (rootIndex - 1 >= inorderStart) {
            struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            leftNode->val = preorder[preorderStart + 1];
            leftNode->left = NULL;
            leftNode->right = NULL;
            node->left = leftNode;
            push(&stack, leftNode, preorderStart + 1, preorderStart + (rootIndex - inorderStart), inorderStart, rootIndex - 1);
        }
    }

    return root;
}

// 测试代码
void printInOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);

    printf("中序遍历结果：");
    printInOrder(root);
    printf("\n");

    return 0;
}
