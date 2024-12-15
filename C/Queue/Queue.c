#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // �����������

typedef struct Queue {
    int data[MAX_SIZE]; // �洢���е�����
    int front;          // ����ͷ����
    int rear;           // ����β����
    int size;           // ��ǰ���д�С
} Queue;

// ��ʼ������
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue *q) {
    return q->size == 0;
}

// �ж϶����Ƿ�����
bool isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

// ��Ӳ���
bool enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("�����������޷����\n");
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // ѭ������ʵ��
    q->data[q->rear] = value;
    q->size++;
    return true;
}

// ���Ӳ���
bool dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("����Ϊ�գ��޷�����\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE; // ѭ������ʵ��
    q->size--;
    return true;
}

// ��ȡ��ͷԪ��
bool getFront(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("����Ϊ�գ��޷���ȡ��ͷԪ��\n");
        return false;
    }
    *value = q->data[q->front];
    return true;
}

// ��ӡ����
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("����Ϊ��\n");
        return;
    }
    printf("�������ݣ�");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

// ����������
int main() {
    Queue q;
    initQueue(&q);

    // ������Ӳ���
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    // ���Գ��Ӳ���
    int value;
    dequeue(&q, &value);
    printf("����Ԫ�أ�%d\n", value);
    printQueue(&q);

    // ��ȡ��ͷԪ��
    if (getFront(&q, &value)) {
        printf("��ͷԪ�أ�%d\n", value);
    }

    return 0;
}
