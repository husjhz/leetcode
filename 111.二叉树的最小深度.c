/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.68%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    57.7K
 * Total Submissions: 138.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int depth;
};

struct queue {
    struct key *array;
    int front;
    int rear;
    int capacity;
    int size;
};

struct queue *create(int capacity)
{
    struct queue *q;

    q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (struct key *)malloc(sizeof(struct key) * capacity);
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

void enqueue(struct queue *q, struct TreeNode *node, int depth)
{
    q->array[q->front].node = node;
    q->array[q->front].depth = depth;
    q->front = (q->front + 1) % q->capacity;
    q->size++;
}

struct key *dequeue(struct queue *q)
{
    struct key *key;

    key = &(q->array[q->rear]);
    q->rear = (q->rear + 1) % q->capacity;
    q->size--;
    return key;
}

int minDepth(struct TreeNode* root){
    struct queue *q;

    if (root == NULL) {
        return 0;
    }
    q = create(10000);
    enqueue(q, root, 1);
    while (queue_size(q) > 0) {
        struct key *key = dequeue(q);
        if (key->node->left == NULL && key->node->right == NULL) {
            return key->depth;
        }
        if (key->node->left) {
            enqueue(q, key->node->left, key->depth + 1);
        }
        if (key->node->right) {
            enqueue(q, key->node->right, key->depth + 1);
        }
    }
    return 0;
}


// @lc code=end

