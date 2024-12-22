/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-22 20:47:19
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-22 20:53:15
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode113\LeeCode113.c
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

// 路径数组结构体
int** ret;
int retSize;
int* retColSize;

int* path;
int pathSize;

void dfs(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return;
    }
    path[pathSize++] = root->val;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL && targetSum == 0) {
        int* tmp = malloc(sizeof(int) * pathSize);
        memcpy(tmp, path, sizeof(int) * pathSize);
        ret[retSize] = tmp;
        retColSize[retSize++] = pathSize;
    }
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    pathSize--;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    ret = malloc(sizeof(int*) * 2001);
    retColSize = malloc(sizeof(int) * 2001);
    path = malloc(sizeof(int) * 2001);
    retSize = pathSize = 0;
    dfs(root, targetSum);
    *returnColumnSizes = retColSize;
    *returnSize = retSize;
    return ret;
}


// 辅助函数：创建树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 打印路径
void printResult(int** result, int* returnColumnSizes, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
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
    int returnSize = 0;
    int* returnColumnSizes = (int*)malloc(100 * sizeof(int));  // 存储每条路径的列大小
    int** result = pathSum(root, targetSum, &returnSize, &returnColumnSizes);
    
    printf("Paths with sum %d:\n", targetSum);
    printResult(result, returnColumnSizes, returnSize);

    return 0;
}
