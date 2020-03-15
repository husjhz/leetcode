/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode *root;
    int i;

    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = *preorder;
    for (i = 0; i < inorderSize; i++) {
        if (*preorder == inorder[i]) {
            break;
        }
    }
    root->left = buildTree(preorder + 1, i, inorder, i);
    root->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i  + 1, inorderSize - i  - 1);
    return root;
}


// @lc code=end

