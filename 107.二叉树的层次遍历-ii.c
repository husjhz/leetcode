/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.52%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 69.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
struct queue {
    struct TreeNode **array;
    int front;
    int rear;
    int capacity;
    int size;
};

struct queue *create(int capacity)
{
    struct queue *q;

    q = (struct queue*)malloc(sizeof(struct queue));
    q->array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * capacity);
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->size = 0;
    return q;
}

int queue_size(struct queue *q)
{
    return q->size;
}

void enqueue(struct queue *q, struct TreeNode *node)
{
    q->array[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

struct TreeNode *dequeue(struct queue *q)
{
    struct TreeNode *node;

    node = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

static int maxDepth(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **returnArray;
    struct queue *q;
    int i;
    int depth = maxDepth(root);
    struct TreeNode *node;

    *returnSize = depth;
    if (root == NULL) {
        return NULL;
    }
    returnArray = (int **)malloc(sizeof(int *) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    q = create(10000);

    enqueue(q, root);
    while (queue_size(q) > 0) {
        int count = 0;
        int size = queue_size(q);
        returnArray[depth - 1] = (int *)malloc(sizeof(int) * 10000);
        while (size-- > 0) {
            node = dequeue(q);
            returnArray[depth -1 ][count++] = node->val;
            if (node->left) {
                enqueue(q, node->left);
            }
            if (node->right) {
                enqueue(q, node->right);
            }
        }
        (*returnColumnSizes)[depth - 1] = count;
        depth--;
    }
    return returnArray;
}


// @lc code=end


