/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-17 09:53:56
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-17 09:56:31
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode107\LeeCode107.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 定义队列节点结构体
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

// 队列操作：入队
void enqueue(struct QueueNode **front, struct QueueNode **rear, struct TreeNode *node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// 队列操作：出队
struct TreeNode* dequeue(struct QueueNode **front) {
    if (*front == NULL) return NULL;
    struct QueueNode* temp = *front;
    *front = (*front)->next;
    struct TreeNode* node = temp->node;
    free(temp);  // 释放出队的节点
    return node;
}

// 判断队列是否为空
int isEmpty(struct QueueNode* front) {
    return front == NULL;
}

// 主算法：层次遍历并反转
void levelOrderBottomHelper(struct TreeNode* root, int* returnSize, int*** result) {
    if (root == NULL) return;

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;
    enqueue(&front, &rear, root);

    while (!isEmpty(front)) {
        int levelSize = 0;
        struct QueueNode* temp = front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }

        int* level = (int*)malloc(sizeof(int) * levelSize);
        *result = realloc(*result, sizeof(int*) * (*returnSize + 1));  // 修正这一行

        int i = 0;
        for (i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(&front);
            level[i] = node->val;
            if (node->left != NULL) enqueue(&front, &rear, node->left);
            if (node->right != NULL) enqueue(&front, &rear, node->right);
        }
        
        (*result)[*returnSize] = level;
        (*returnSize)++;
    }
}

// 主函数
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** result = NULL;
    levelOrderBottomHelper(root, returnSize, &result);

    // 返回列数
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = sizeof(result[i]) / sizeof(result[i][0]);
    }

    // 反转二维数组
    for (int i = 0; i < *returnSize / 2; i++) {
        int* temp = result[i];
        result[i] = result[*returnSize - i - 1];
        result[*returnSize - i - 1] = temp;
    }

    return result;
}

int main() {
    // 示例输入
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = levelOrderBottom(root, &returnSize, &returnColumnSizes);

    // 输出结果
    printf("Level order bottom:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }

    // 释放内存
    free(result);
    free(returnColumnSizes);
    free(root);

    return 0;
}
