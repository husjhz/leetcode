/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层次遍历
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

#if 0
void dfs(struct TreeNode *root, int level, int **returnArray, int *returnSize, int **returnColumnSizes)
{
    const int ARRAY_SIZE = 10000;
    if (root == NULL) {
        return;
    }
    if (level == *returnSize) {
        returnArray[level] = malloc(sizeof(int) * ARRAY_SIZE);
        (*returnColumnSizes)[level] = 0;
        (*returnSize)++;
    }
    returnArray[level][(*returnColumnSizes)[level]++] = root->val;
    if (root->left) {
        dfs(root->left, level + 1, returnArray, returnSize, returnColumnSizes);
    }
    if (root->right) {
        dfs(root->right, level + 1, returnArray, returnSize, returnColumnSizes);
    }
}
#endif

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
    int i;

    q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * capacity);
    for (i = 0; i < capacity; i++) {
        q->array[i] = NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->size = 0;
    return q;
}

int quque_size(struct queue *q) {
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
    struct TreeNode *node = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
#if 0
    int **returnArray;
    const int RETURN_SIZE = 10000;
    int i;
    
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    returnArray = (int**)malloc(sizeof(int *) * RETURN_SIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * RETURN_SIZE);
    dfs(root, 0, returnArray, returnSize, returnColumnSizes);
    return returnArray;
#else
    int **returnArray;
    const int RETURN_SIZE = 10000;
    const int ARRAY_SIZE = 10000;
    const int QUEUE_SIZE = 10000;
    struct queue *q;
    struct TreeNode *node;
    int count;
    int size;

    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    returnArray = (int **)malloc(sizeof(int *) * RETURN_SIZE);
    *returnColumnSizes = (int *)malloc(sizeof(int) * RETURN_SIZE);
    q = create(QUEUE_SIZE);
    enqueue(q, root);
    while (quque_size(q) > 0) {
        returnArray[*returnSize] = (int *)malloc(sizeof(int) * ARRAY_SIZE);
        count = 0;
        size = quque_size(q);
        while (size > 0) {
            node = dequeue(q);
            returnArray[*returnSize][count++] = node->val;
            if (node->left) {
                enqueue(q, node->left);
            }
            if (node->right) {
                enqueue(q, node->right);
            }
            size--;
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }
    return returnArray;

#endif    
}


// @lc code=end

