/***************************************************
 * Date:2024/11/17
 * 题目描述:
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。
当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。
请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。
注意，不管是什么情况下，你都无法跳到数组之外。

示例 1：
输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -> 下标 4 -> 下标 1 -> 下标 3 
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3 

示例 2：
输入：arr = [4,2,3,0,3,1,2], start = 0
输出：true 
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 0 -> 下标 4 -> 下标 1 -> 下标 3

示例 3：
输入：arr = [3,0,2,1,2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。 
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 队列结构，用于实现 BFS
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

// 初始化队列
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// 入队
void enqueue(Queue* queue, int value) {
    queue->data[queue->rear++] = value;
}

// 出队
int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

// 判断队列是否为空
bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// 释放队列
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// 跳跃游戏 III 的主函数
bool canReach(int* arr, int arrSize, int start) {
    if (arr[start] == 0) return true;

    bool* visited = (bool*)calloc(arrSize, sizeof(bool));  // 标记访问过的节点
    Queue* queue = createQueue(arrSize);

    enqueue(queue, start);
    visited[start] = true;

    while (!isEmpty(queue)) {
        int curr = dequeue(queue);

        // 尝试跳跃到左右位置
        int left = curr - arr[curr];
        int right = curr + arr[curr];

        // 检查左跳
        if (left >= 0 && !visited[left]) {
            if (arr[left] == 0) {
                free(visited);
                freeQueue(queue);
                return true;
            }
            enqueue(queue, left);
            visited[left] = true;
        }

        // 检查右跳
        if (right < arrSize && !visited[right]) {
            if (arr[right] == 0) {
                free(visited);
                freeQueue(queue);
                return true;
            }
            enqueue(queue, right);
            visited[right] = true;
        }
    }

    free(visited);
    freeQueue(queue);
    return false;
}

int main() {
    int arr[] = {4, 2, 3, 0, 3, 1, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int start = 5;

    if (canReach(arr, arrSize, start)) {
        printf("可以跳到值为 0 的位置！\n");
    } else {
        printf("无法跳到值为 0 的位置！\n");
    }

    return 0;
}
