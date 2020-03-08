/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.27%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    104.4K
 * Total Submissions: 148.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode *root, int *returnArray, int *returnSize)
{
    if (root == NULL) {
        return;
    }
    dfs(root->left, returnArray, returnSize);
    returnArray[*returnSize] = root->val;
    (*returnSize)++;
    dfs(root->right, returnArray, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *returnArray;
    const int allocSize = 10000;

    returnArray = (int*)malloc(sizeof(int) * allocSize);
    *returnSize = 0;
    dfs(root, returnArray, returnSize);
    return returnArray;
}


// @lc code=end

