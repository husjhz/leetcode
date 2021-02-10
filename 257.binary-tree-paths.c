/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.90%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 113.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
#define PATH_MAX_NUM    100000
void backtrace(struct TreeNode *root, int *nums, int n, char **returnArray, int *returnSize)
{
    if (root->left) {
        nums[n++] = root->val;
        backtrace(root->left, nums, n, returnArray, returnSize);
        n--;
    }
    if (root->right) {
        nums[n++] = root->val;
        backtrace(root->right, nums, n, returnArray, returnSize);
        n--;
    }
    if (!root->left && !root->right){
        int i;
        nums[n++] = root->val;
        returnArray[*returnSize] = malloc(sizeof(char) * n * 11);
        char *tmp = returnArray[*returnSize];
        for (i = 0; i < n - 1; i++) {
            tmp += sprintf(tmp, "%d->", nums[i]);
        }
        sprintf(tmp, "%d", nums[i]);
        (*returnSize)++;
    }
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **returnArray;
    int nums[1000];
    int n = 0;

    *returnSize = 0;
    if (root == NULL)
        return NULL;
    returnArray = (char **)malloc(sizeof(char *) * PATH_MAX_NUM);
    backtrace(root, nums, n, returnArray, returnSize);
    return returnArray;
}


// @lc code=end
