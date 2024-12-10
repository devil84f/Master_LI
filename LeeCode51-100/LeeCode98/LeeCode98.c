/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-10 10:48:03
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-10 10:52:46
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode98\LeeCode98.c
 * @Description: 
 * 
 */

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>

// ����������ڵ�
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ��������
bool inorder(struct TreeNode* root, long* prev) {
    if (root == NULL) {
        return true;
    }

    // ���������
    if (!inorder(root->left, prev)) {
        return false;
    }

    // ��鵱ǰ�ڵ�
    if (root->val <= *prev) {
        return false;
    }
    *prev = root->val;

    // ���������
    return inorder(root->right, prev);
}

bool isValidBST(struct TreeNode* root) {
    long prev = LONG_MIN; // ��ʼ��Ϊ��Сֵ
    return inorder(root, &prev);
}
