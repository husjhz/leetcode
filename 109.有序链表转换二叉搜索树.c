/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (70.69%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 29.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode *findMidListNode(struct ListNode *head, struct ListNode *end)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct TreeNode *dfs(struct ListNode *head, struct TreeNode *end)
{
    struct ListNode *mid;
    struct TreeNode *node;

    if (head == end) {
        return NULL;
    }
    mid = findMidListNode(head, end);
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = mid->val;
    node->left = dfs(head, mid);
    node->right = dfs(mid->next, end);
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    return dfs(head, NULL);
}


// @lc code=end

