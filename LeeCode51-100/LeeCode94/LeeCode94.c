/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-07 14:59:16
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-07 15:15:31
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode94\LeeCode94.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �����������ݹ�������� <�� �� ��>
void inorderHelper(struct TreeNode *root, int *result, int *returnSize) {
    if (root == NULL) return;

    // �ݹ����������
    inorderHelper(root->left, result, returnSize);
    // ��¼��ǰ�ڵ�ֵ
    result[(*returnSize)++] = root->val;
    // �ݹ����������
    inorderHelper(root->right, result, returnSize);
}

// ����������������������
int* inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;

    // Ϊ����������ռ䣨��������� 100 ���ڵ㣩
    int *result = (int *)malloc(100 * sizeof(int));
    if (result == NULL) return NULL;

    inorderHelper(root, result, returnSize);
    return result;
}

// ���Ժ���
int main() {
    // ��������� [1, null, 2, 3]
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node2 = {2, &node3, NULL};
    struct TreeNode root = {1, NULL, &node2};

    int returnSize;
    int *result = inorderTraversal(&root, &returnSize);

    printf("����������: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // �ͷ��ڴ�
    return 0;
}
