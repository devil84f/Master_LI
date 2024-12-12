/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-12 10:00:14
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-12 10:34:03
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode101\LeeCode101.c
 * @Description: 
 * 
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// ����������ڵ�ṹ��
struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};

// ������������������ڵ��Ƿ�Գ�
bool isSymmetric(struct TreeNode* left, struct TreeNode* right) {
    // ��������ڵ㶼Ϊ�գ�˵���Գ�
    if (left == NULL && right == NULL) {
        return true;
    }
    // ���һ��Ϊ�գ�һ���ǿգ�����ֵ����ȣ�˵�����Գ�
    if (left == NULL || right == NULL || left->val != right->val) {
        return false;
    }
    // �ݹ�����������������
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

// �����������������Ƿ�Գ�
bool Symmetric(struct TreeNode* root) {
    // ����Ҳ�ǶԳƵ�
    if (root == NULL) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

// ���Դ���
int main() {
    // ���������õĶ�����
    struct TreeNode root;
    root.val = 1;
    root.left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->val = 2;
    root.right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->val = 2;
    root.left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->left->val = 3;
    root.left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.left->right->val = 4;
    root.right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->left->val = 4;
    root.right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root.right->right->val = 3;

    // ����Ƿ�Գ�
    if (Symmetric(&root)) {
        printf("The tree is symmetric.\n");
    } else {
        printf("The tree is not symmetric.\n");
    }

    // �ͷ��ڴ�
    free(root.left->left);
    free(root.left->right);
    free(root.right->left);
    free(root.right->right);
    free(root.left);
    free(root.right);

    return 0;
}
