/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-03 09:43:16
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-03 10:17:02
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode133\LeeCode133.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义图的节点结构体
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node** visited;

struct Node* dfs(struct Node* s) {
    if (s == NULL) {
        return NULL;
    }

    // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
    if (visited[s->val]) {
        return visited[s->val];
    }

    // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
    struct Node* cloneNode = (struct Node*)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;

    // 哈希表存储
    visited[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloneNode->numNeighbors);

    // 遍历该节点的邻居并更新克隆节点的邻居列表
    for (int i = 0; i < cloneNode->numNeighbors; i++) {
        cloneNode->neighbors[i] = dfs(s->neighbors[i]);
    }
    return cloneNode;
}

struct Node* cloneGraph(struct Node* s) {
    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    return dfs(s);
}

// 辅助函数：打印图
void printGraph(struct Node* node) {
    if (!node) return;

    printf("Node %d: ", node->val);
    for (int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");

    // 打印邻居节点的邻居
    for (int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i]);
    }
}

int main() {
    // 示例图的创建
    struct Node* node1 = malloc(sizeof(struct Node));
    node1->val = 1;
    node1->numNeighbors = 2;
    node1->neighbors = malloc(sizeof(struct Node*) * 2);

    struct Node* node2 = malloc(sizeof(struct Node));
    node2->val = 2;
    node2->numNeighbors = 2;
    node2->neighbors = malloc(sizeof(struct Node*) * 2);

    struct Node* node3 = malloc(sizeof(struct Node));
    node3->val = 3;
    node3->numNeighbors = 2;
    node3->neighbors = malloc(sizeof(struct Node*) * 2);

    struct Node* node4 = malloc(sizeof(struct Node));
    node4->val = 4;
    node4->numNeighbors = 1;
    node4->neighbors = malloc(sizeof(struct Node*) * 1);

    node1->neighbors[0] = node2;
    node1->neighbors[1] = node4;
    node2->neighbors[0] = node1;
    node2->neighbors[1] = node3;
    node3->neighbors[0] = node2;
    node3->neighbors[1] = node4;
    node4->neighbors[0] = node1;
    node4->neighbors[0] = node3;

    // 克隆图并打印
    struct Node* clonedGraph = cloneGraph(node1);
    printGraph(clonedGraph);

    return 0;
}
