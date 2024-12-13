/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-13 09:19:43
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-13 09:47:23
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode102\LeeCode102.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建二叉树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Returns an array of arrays of integers. 
 * The sizes of the arrays are returned as *returnColumnSizes array. 
 * The size of the outer array is returned as *returnSize.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 // 队列节点
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

 // 队列操作
void enqueue(struct QueueNode **front, struct QueueNode **rear, struct TreeNode *node) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

struct TreeNode *dequeue(struct QueueNode **front, struct QueueNode **rear) {
    if (*front == NULL) return NULL;
    struct QueueNode *temp = *front;
    struct TreeNode *node = temp->node;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return node;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 初始化队列
    struct QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    // 动态分配初始空间
    int capacity = 10; // 初始容量
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    while (front != NULL) {
        int level_size = 0;
        struct QueueNode *temp = front;

        // 统计当前层节点数量
        while (temp != NULL) {
            level_size++;
            temp = temp->next;
        }

        // 如果超过当前容量，扩展空间
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int**)realloc(result, capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
            if (result == NULL || *returnColumnSizes == NULL) {
                fprintf(stderr, "内存分配失败\n");
                exit(EXIT_FAILURE);
            }
        }

        // 存储当前层的节点值
        result[*returnSize] = (int*)malloc(level_size * sizeof(int));
        if (result[*returnSize] == NULL) {
            fprintf(stderr, "内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        (*returnColumnSizes)[*returnSize] = level_size;

        for (int i = 0; i < level_size; i++) {
            struct TreeNode *node = dequeue(&front, &rear);
            result[*returnSize][i] = node->val;
            if (node->left != NULL) enqueue(&front, &rear, node->left);
            if (node->right != NULL) enqueue(&front, &rear, node->right);
        }

        (*returnSize)++;
    }

    return result;
}


// 打印二维数组
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]");
        if (i < returnSize - 1) printf(",");
        printf("\n");
    }
    printf("]\n");
}

// 主函数
int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int returnSize;
    int* returnColumnSizes;
    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printf("层序遍历结果：\n");
    printResult(result, returnSize, returnColumnSizes);

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}