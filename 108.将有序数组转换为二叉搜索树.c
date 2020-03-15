/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (69.50%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 77.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
struct TreeNode *dfs(int *nums, int left, int right)
{
    int mid;
    struct TreeNode *node;

    if (left > right) {
        return NULL;
    }
    mid = (left + right) / 2;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = dfs(nums, left, mid - 1);
    node->right = dfs(nums, mid + 1, right);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return dfs(nums, 0, numsSize - 1);
}


// @lc code=end

