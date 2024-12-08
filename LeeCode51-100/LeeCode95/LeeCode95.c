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

// �������Ľṹ
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ����һ���½ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���ɴ� start �� end ������ BST
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
        // ������
        int leftSize = 0;
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, &leftSize);

        // ������
        int rightSize = 0;
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, &rightSize);

        // ������������͵�ǰ���ڵ�
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

// �����������ɴ� 1 �� n ������ BST
struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, n, returnSize);
}

// ����������ӡ�������������
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
