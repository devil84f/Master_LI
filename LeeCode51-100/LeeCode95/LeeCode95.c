/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-08 18:11:16
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-08 18:15:45
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode95\LeeCode95.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义树的结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建一个新节点
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 生成从 start 到 end 的所有 BST
struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 1;
        struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        result[0] = NULL;
        return result;
    }

    int totalSize = 0;
    struct TreeNode** result = NULL;

    for (int i = start; i <= end; i++) {
        // 左子树
        int leftSize = 0;
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, &leftSize);

        // 右子树
        int rightSize = 0;
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, &rightSize);

        // 组合左右子树和当前根节点
        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = createNode(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];

                result = (struct TreeNode**)realloc(result, sizeof(struct TreeNode*) * (totalSize + 1));
                result[totalSize++] = root;
            }
        }

        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = totalSize;
    return result;
}

// 主函数：生成从 1 到 n 的所有 BST
struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, n, returnSize);
}

// 测试用例打印树（先序遍历）
void printTree(struct TreeNode* root) {
    if (!root) {
        printf("null ");
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int returnSize;
    struct TreeNode** trees = generateTrees(3, &returnSize);

    printf("Generated %d unique BSTs:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printTree(trees[i]);
        printf("\n");
    }

    return 0;
}
