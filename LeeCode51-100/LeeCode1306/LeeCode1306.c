/***************************************************
 * Date:2024/11/17
 * ��Ŀ����:
������һ���Ǹ��������� arr�����ʼλ�ڸ��������ʼ�±� start ����
����λ���±� i ��ʱ����������� i + arr[i] ���� i - arr[i]��
�����ж��Լ��Ƿ��ܹ�������ӦԪ��ֵΪ 0 �� ��һ �±괦��
ע�⣬������ʲô����£��㶼�޷���������֮�⡣

ʾ�� 1��
���룺arr = [4,2,3,0,3,1,2], start = 5
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 5 -> �±� 4 -> �±� 1 -> �±� 3 
�±� 5 -> �±� 6 -> �±� 4 -> �±� 1 -> �±� 3 

ʾ�� 2��
���룺arr = [4,2,3,0,3,1,2], start = 0
�����true 
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 0 -> �±� 4 -> �±� 1 -> �±� 3

ʾ�� 3��
���룺arr = [3,0,2,1,2], start = 2
�����false
���ͣ��޷�����ֵΪ 0 ���±� 1 ���� 
/***************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ���нṹ������ʵ�� BFS
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

// ��ʼ������
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// ���
void enqueue(Queue* queue, int value) {
    queue->data[queue->rear++] = value;
}

// ����
int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// �ͷŶ���
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// ��Ծ��Ϸ III ��������
bool canReach(int* arr, int arrSize, int start) {
    if (arr[start] == 0) return true;

    bool* visited = (bool*)calloc(arrSize, sizeof(bool));  // ��Ƿ��ʹ��Ľڵ�
    Queue* queue = createQueue(arrSize);

    enqueue(queue, start);
    visited[start] = true;

    while (!isEmpty(queue)) {
        int curr = dequeue(queue);

        // ������Ծ������λ��
        int left = curr - arr[curr];
        int right = curr + arr[curr];

        // �������
        if (left >= 0 && !visited[left]) {
            if (arr[left] == 0) {
                free(visited);
                freeQueue(queue);
                return true;
            }
            enqueue(queue, left);
            visited[left] = true;
        }

        // �������
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
        printf("��������ֵΪ 0 ��λ�ã�\n");
    } else {
        printf("�޷�����ֵΪ 0 ��λ�ã�\n");
    }

    return 0;
}
