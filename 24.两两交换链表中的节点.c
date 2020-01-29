/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.33%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 102.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode *newHead;
    struct ListNode *p;
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    newHead = head->next;
    p = head;
    while (head && head->next) {
        p1 = head;
        p2 = head->next;
        head = head->next->next;
        p->next = p2;
        p2->next = p1;
        p = p1;
    }
    p->next = head ? head : NULL;
    return newHead;
}


// @lc code=end

