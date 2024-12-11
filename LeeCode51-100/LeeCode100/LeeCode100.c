/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-11 09:35:00
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-11 11:29:12
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode100\LeeCode100.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �������ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // �����ڵ㶼Ϊ��
    if (p == NULL && q == NULL) return true;
    
    // ����һ���ڵ�Ϊ�գ�����ֵ��ͬ
    if (p == NULL || q == NULL || p->val != q->val) return false;

    // �ݹ�����������������
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// ������
int main() {
    // ����������ͬ����
    struct TreeNode* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    struct TreeNode* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    // ����Ƿ���ͬ
    if (isSameTree(p, q)) {
        printf("��������ͬ\n");
    } else {
        printf("��������ͬ\n");
    }

    return 0;
}
