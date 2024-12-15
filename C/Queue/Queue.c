#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // 队列最大容量

typedef struct Queue {
    int data[MAX_SIZE]; // 存储队列的数组
    int front;          // 队列头索引
    int rear;           // 队列尾索引
    int size;           // 当前队列大小
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// 判断队列是否为空
bool isEmpty(Queue *q) {
    return q->size == 0;
}

// 判断队列是否已满
bool isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

// 入队操作
bool enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("队列已满，无法入队\n");
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // 循环队列实现
    q->data[q->rear] = value;
    q->size++;
    return true;
}

// 出队操作
bool dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("队列为空，无法出队\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE; // 循环队列实现
    q->size--;
    return true;
}

// 获取队头元素
bool getFront(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("队列为空，无法获取队头元素\n");
        return false;
    }
    *value = q->data[q->front];
    return true;
}

// 打印队列
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("队列为空\n");
        return;
    }
    printf("队列内容：");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

// 主函数测试
int main() {
    Queue q;
    initQueue(&q);

    // 测试入队操作
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    // 测试出队操作
    int value;
    dequeue(&q, &value);
    printf("出队元素：%d\n", value);
    printQueue(&q);

    // 获取队头元素
    if (getFront(&q, &value)) {
        printf("队头元素：%d\n", value);
    }

    return 0;
}
