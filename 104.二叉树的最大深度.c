/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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

#if 0
int dfs(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return MAX(dfs(root->left), dfs(root->right)) + 1;
}
#else
struct KeyNode {
    struct TreeNode *node;
    int depth;
};
#endif

int maxDepth(struct TreeNode* root){
#if 0    
    if (root == NULL) {
        return 0;
    }
    return dfs(root);
#else
    struct KeyNode *stack;
    int stackSize;
    struct TreeNode *node;
    int currDepth;
    int maxDepth = 0;

    if (root == NULL) {
        return 0;
    }
    stack = (struct KeyNode *)malloc(sizeof(struct KeyNode) * 10000);
    stackSize = 0;

    stack[stackSize].node = root;
    stack[stackSize].depth = 1;
    stackSize++;
    while (stackSize > 0) {
        node = stack[stackSize - 1].node;
        currDepth = stack[stackSize - 1].depth;
        stackSize--;
        if (node) {
            maxDepth = MAX(currDepth, maxDepth);
            stack[stackSize].node = node->left;
            stack[stackSize].depth = currDepth + 1;
            stackSize++;
            stack[stackSize].node = node->right;
            stack[stackSize].depth = currDepth + 1;
            stackSize++;
        }
    }
    return maxDepth;
#endif    
}


// @lc code=end

