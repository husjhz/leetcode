/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (67.81%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 45.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
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
struct TreeNode *findPos(struct TreeNode *root)
{
    if (root->right == NULL) {
        return root;
    }
    return findPos(root->right);
}

void flatten(struct TreeNode* root){
    struct TreeNode *right;
    struct TreeNode *tmp;

    if (root == NULL) {
        return;
    }
    right = root->right;
    if (root->left) {
        tmp = findPos(root->left);
        tmp->right = right;
        root->right = root->left;
        root->left = NULL;
    }
    flatten(root->right);
}


// @lc code=end

