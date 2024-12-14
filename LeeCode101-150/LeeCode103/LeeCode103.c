/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-14 23:41:12
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-14 23:41:36
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode103\LeeCode103.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义树节点结构体
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 定义队列节点结构体
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

// 定义队列操作
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

struct TreeNode* dequeue(struct QueueNode **front, struct QueueNode **rear) {
    if (*front == NULL) return NULL;

    struct QueueNode *temp = *front;
    struct TreeNode *node = temp->node;

    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;

    free(temp);
    return node;
}

// 锯齿形层序遍历
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int **result = (int **)malloc(sizeof(int *) * 1000); // 预分配最大1000层
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);

    struct QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    bool leftToRight = true; // 控制遍历方向

    while (front != NULL) {
        int levelSize = 0;
        struct QueueNode *temp = front;

        // 统计当前层的节点数
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }

        result[*returnSize] = (int *)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;

        int *tempResult = (int *)malloc(sizeof(int) * levelSize);
        int index = 0;

        // 遍历当前层
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *current = dequeue(&front, &rear);
            tempResult[index++] = current->val;

            if (current->left != NULL) {
                enqueue(&front, &rear, current->left);
            }
            if (current->right != NULL) {
                enqueue(&front, &rear, current->right);
            }
        }

        // 根据方向保存到结果
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                result[*returnSize][i] = tempResult[i];
            }
        } else {
            for (int i = 0; i < levelSize; i++) {
                result[*returnSize][i] = tempResult[levelSize - i - 1];
            }
        }

        free(tempResult); // 释放临时结果
        leftToRight = !leftToRight; // 方向交替
        (*returnSize)++;
    }

    return result;
}

int main() {
    struct TreeNode node7 = {7, NULL, NULL};
    struct TreeNode node15 = {15, NULL, NULL};
    struct TreeNode node20 = {20, &node15, &node7};
    struct TreeNode node9 = {9, NULL, NULL};
    struct TreeNode root = {3, &node9, &node20};

    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **result = zigzagLevelOrder(&root, &returnSize, &returnColumnSizes);

    printf("锯齿形层序遍历结果:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]); // 释放每一层的内存
    }
    free(result); // 释放结果数组
    free(returnColumnSizes); // 释放列大小数组

    return 0;
}
