/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (49.22%)
 * Likes:    640
 * Dislikes: 0
 * Total Accepted:    102.7K
 * Total Submissions: 204K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
#include <stddef.h>
#include <stdbool.h>

bool isMirror(struct TreeNode *left, struct TreeNode *right)
{
    if (left && right) {
        if (left->val == right->val) {
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
        else {
            return false;
        }
    }
    else if (!left && !right) {
        return true;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root) {
        return isMirror(root->left, root->right);
    }
    return true;
}


// @lc code=end

