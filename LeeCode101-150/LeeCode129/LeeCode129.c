/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-01 23:18:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-01 23:18:33
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode129\LeeCode129.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �����ڵ㺯��
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �������������DFS���ݹ麯��
void dfs(struct TreeNode* root, int currentSum, int* totalSum) {
    if (root == NULL) {
        return;
    }

    // ���µ�ǰ·������
    currentSum = currentSum * 10 + root->val;

    // �����Ҷ�ӽڵ㣬�ۼӵ�ǰ·��������
    if (root->left == NULL && root->right == NULL) {
        *totalSum += currentSum;
    }

    // �ݹ���������������
    dfs(root->left, currentSum, totalSum);
    dfs(root->right, currentSum, totalSum);
}

// �������������Ҷ�ӽڵ�����֮��
int sumNumbers(struct TreeNode* root) {
    int totalSum = 0;
    dfs(root, 0, &totalSum);
    return totalSum;
}

int main() {
    // ʾ��1������������ [1,2,3]
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    
    printf("����Ҷ�ӽڵ�����֮�ͣ�%d\n", sumNumbers(root1)); // �����25

    // ʾ��2������������ [4,9,0,5,1]
    struct TreeNode* root2 = createNode(4);
    root2->left = createNode(9);
    root2->right = createNode(0);
    root2->left->left = createNode(5);
    root2->left->right = createNode(1);
    
    printf("����Ҷ�ӽڵ�����֮�ͣ�%d\n", sumNumbers(root2)); // �����1026

    // ʾ��3������������ [0]
    struct TreeNode* root3 = createNode(0);
    
    printf("����Ҷ�ӽڵ�����֮�ͣ�%d\n", sumNumbers(root3)); // �����0

    return 0;
}
