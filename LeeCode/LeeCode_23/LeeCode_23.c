/***************************************************
 * Date:2024/10/25
 * 题目描述:
给一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// 定义最小堆的结构体
struct MinHeap {
    struct ListNode **array;
    int size;
};

// 创建一个新的最小堆节点
struct MinHeap* createMinHeap(int k) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    heap->size = 0;
    return heap;
}

// 将堆元素进行上浮
void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx > 0 && heap->array[(idx - 1) / 2]->val > heap->array[idx]->val) {
        // 交换父节点和当前节点
        struct ListNode* temp = heap->array[idx];
        heap->array[idx] = heap->array[(idx - 1) / 2];
        heap->array[(idx - 1) / 2] = temp;
        idx = (idx - 1) / 2;
    }
}

// 将堆元素进行下沉
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

// 向堆中插入新元素
void insertMinHeap(struct MinHeap* heap, struct ListNode* node) {
    heap->array[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// 从堆中取出最小元素
struct ListNode* extractMin(struct MinHeap* heap) {
    struct ListNode* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// 合并K个升序链表
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    // 创建最小堆
    struct MinHeap* heap = createMinHeap(k);

    // 将每个链表的第一个节点插入堆中
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            insertMinHeap(heap, lists[i]);
        }
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // 依次取出堆中的最小元素，并插入结果链表中
    while (heap->size > 0) {
        struct ListNode* minNode = extractMin(heap);
        tail->next = minNode;
        tail = tail->next;

        // 如果取出的节点还有后续节点，将后续节点插入堆中
        if (minNode->next != NULL) {
            insertMinHeap(heap, minNode->next);
        }
    }

    return dummy.next;
}


// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// 释放链表
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// 主函数
int main() {
    // 创建测试用例：[[1,4,5],[1,3,4],[2,6]]
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);

    struct ListNode* lists[] = {list1, list2, list3};

    // 合并链表
    struct ListNode* result = mergeKLists(lists, 3);

    // 打印结果
    printf("合并后的链表: ");
    printList(result);

    // 释放内存
    freeList(result);

    return 0;
}