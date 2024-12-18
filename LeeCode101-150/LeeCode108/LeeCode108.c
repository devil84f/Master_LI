/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-18 09:56:18
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-18 11:50:18
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode108\LeeCode108.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 递归函数：根据数组区间生成平衡二叉搜索树
struct TreeNode* sortedArrayToBSTHelper(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    
    // 选择中间元素作为根节点
    int mid = left + (right - left) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);  // 递归构建左子树
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right); // 递归构建右子树
    
    return root;
}

// 主函数：将有序数组转换为平衡二叉搜索树
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}

// 辅助函数：打印树（中序遍历）
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

// 测试代码
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    struct TreeNode* root = sortedArrayToBST(nums, numsSize);
    
    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

