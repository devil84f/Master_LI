/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-15 20:40:01
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-15 20:44:00
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode104\LeeCode104.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ��
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �ݹ�����������������
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0; // �սڵ㷵�����Ϊ 0

    // �ݹ��������������������������
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // ��������������ȵ����ֵ�� 1
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    // ���������� [3,9,20,null,null,15,7]
    struct TreeNode node7 = {7, NULL, NULL};
    struct TreeNode node15 = {15, NULL, NULL};
    struct TreeNode node20 = {20, &node15, &node7};
    struct TreeNode node9 = {9, NULL, NULL};
    struct TreeNode root = {3, &node9, &node20};

    // �ݹ鷨��������
    int depthRecursive = maxDepth(&root);
    printf("�ݹ鷨����������ȣ�%d\n", depthRecursive);

    return 0;
}
