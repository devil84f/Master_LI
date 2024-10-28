/***************************************************
 * Date:2024/10/25
 * ��Ŀ����:
��һ���������飬ÿ�������Ѿ����������С�
���㽫��������ϲ���һ�����������У����غϲ��������

ʾ�� 1��
���룺lists = [[1,4,5],[1,3,4],[2,6]]
�����[1,1,2,3,4,4,5,6]
���ͣ������������£�
[
  1->4->5,
  1->3->4,
  2->6
]
�����Ǻϲ���һ�����������еõ���
1->1->2->3->4->4->5->6

ʾ�� 2��
���룺lists = []
�����[]

ʾ�� 3��
���룺lists = [[]]
�����[]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// ������С�ѵĽṹ��
struct MinHeap {
    struct ListNode **array;
    int size;
};

// ����һ���µ���С�ѽڵ�
struct MinHeap* createMinHeap(int k) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    heap->size = 0;
    return heap;
}

// ����Ԫ�ؽ����ϸ�
void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx > 0 && heap->array[(idx - 1) / 2]->val > heap->array[idx]->val) {
        // �������ڵ�͵�ǰ�ڵ�
        struct ListNode* temp = heap->array[idx];
        heap->array[idx] = heap->array[(idx - 1) / 2];
        heap->array[(idx - 1) / 2] = temp;
        idx = (idx - 1) / 2;
    }
}

// ����Ԫ�ؽ����³�
void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->val < heap->array[smallest]->val) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right]->val < heap->array[smallest]->val) {
        smallest = right;
    }

    if (smallest != idx) {
        struct ListNode* temp = heap->array[idx];
        heap->array[idx] = heap->array[smallest];
        heap->array[smallest] = temp;
        heapifyDown(heap, smallest);
    }
}

// ����в�����Ԫ��
void insertMinHeap(struct MinHeap* heap, struct ListNode* node) {
    heap->array[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// �Ӷ���ȡ����СԪ��
struct ListNode* extractMin(struct MinHeap* heap) {
    struct ListNode* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// �ϲ�K����������
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    // ������С��
    struct MinHeap* heap = createMinHeap(k);

    // ��ÿ������ĵ�һ���ڵ�������
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            insertMinHeap(heap, lists[i]);
        }
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // ����ȡ�����е���СԪ�أ���������������
    while (heap->size > 0) {
        struct ListNode* minNode = extractMin(heap);
        tail->next = minNode;
        tail = tail->next;

        // ���ȡ���Ľڵ㻹�к����ڵ㣬�������ڵ�������
        if (minNode->next != NULL) {
            insertMinHeap(heap, minNode->next);
        }
    }

    return dummy.next;
}


// �����½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// �ͷ�����
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// ������
int main() {
    // ��������������[[1,4,5],[1,3,4],[2,6]]
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);

    struct ListNode* lists[] = {list1, list2, list3};

    // �ϲ�����
    struct ListNode* result = mergeKLists(lists, 3);

    // ��ӡ���
    printf("�ϲ��������: ");
    printList(result);

    // �ͷ��ڴ�
    freeList(result);

    return 0;
}