/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-23 10:36:15
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-23 11:01:51
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode114\LeeCode114.c
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

// �ݹ�ʵ�֣���������չ��Ϊ����
void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    // �����ǰ�ڵ���������������������
    if (root->left != NULL) {
        // �ȱ���������
        struct TreeNode* rightSubtree = root->right;
        
        // ����������Ϊ������
        root->right = root->left;
        root->left = NULL;
        
        // �ҵ�ԭ�������������ҽڵ�
        struct TreeNode* temp = root->right;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        
        // ����������������ӵ����ҽڵ�
        temp->right = rightSubtree;
    }
    
    // �ݹ鴦��������
    flatten(root->right);
}

// �����������������ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ��ӡ�������������ӵ���ʽ��
void printFlattenedTree(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

// ���Դ���
int main() {
    // �������Զ�����
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    // ���� flatten ������������չ��Ϊ����
    flatten(root);

    // ��ӡչ���������
    printFlattenedTree(root);

    return 0;
}
