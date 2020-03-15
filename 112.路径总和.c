/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (49.21%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    58.7K
 * Total Submissions: 119.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
struct key {
    struct TreeNode *node;
    int sum;
};

struct stack {
    struct key *array;
    int capacity;
    int size;
};

struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack *)malloc(sizeof(struct stack));
    s->array = (struct key *)malloc(sizeof(struct key) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

int stack_size(struct stack *s)
{
    return s->size;
}

void push(struct stack *s, struct TreeNode *node, int sum)
{
    s->array[s->size].node = node;
    s->array[s->size].sum = sum;
    s->size++;
}

void pop(struct stack *s, struct TreeNode **pNode, int *pSum)
{
    struct key *key;

    key = &(s->array[--s->size]);
    *pNode = key->node;
    *pSum = key->sum;
}

bool hasPathSum(struct TreeNode* root, int sum){
    struct stack *s;
    struct TreeNode *node;
    int curSum;

    if (root == NULL) {
        return false;
    }
    s = create(10000);
    push(s, root, sum - root->val);
    while (stack_size(s) > 0) {
        pop(s, &node, &curSum);
        if (node->left == NULL && node->right == NULL && curSum == 0) {
            return true;
        }
        if (node->right) {
            push(s, node->right, curSum - node->right->val);
        }
        if (node->left) {
            push(s, node->left, curSum - node->left->val);
        }
    }
    return false;
}


// @lc code=end

