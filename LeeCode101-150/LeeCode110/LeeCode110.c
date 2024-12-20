/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-20 09:46:46
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-20 10:30:40
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode110\LeeCode110.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �������ڵ�ṹ��
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �������ĸ߶ȣ��������ƽ�⣬���� -1
int checkHeight(struct TreeNode* root) {
    // �����ĸ߶�Ϊ 0
    if (root == NULL) {
        return 0;
    }

    // �ݹ�����������߶�
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1; // �����������ƽ�⣬ֱ�ӷ��� -1
    }

    // �ݹ�����������߶�
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) {
        return -1; // �����������ƽ�⣬ֱ�ӷ��� -1
    }

    // �жϵ�ǰ�ڵ�����������߶Ȳ�
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // ����߶Ȳ���� 1������ -1����ʾ��ƽ��
    }

    // ���ص�ǰ�ڵ�ĸ߶�
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// �ж����Ƿ�Ϊƽ�������
bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}

// �����������������ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ���Դ���
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(3);
    root->left->left->left = createNode(4);
    root->left->left->right = createNode(4);

    if (isBalanced(root)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    return 0;
}
