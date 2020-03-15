/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (50.59%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 113.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
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
static inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

static inline int ABS(int a)
{
    return a < 0 ? -a : a;
}

static int height(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + MAX(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return ABS(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}


// @lc code=end

