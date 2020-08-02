/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (51.02%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    124.9K
 * Total Submissions: 244.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *node;

    for (node = head; node != NULL; ) {
        if (node->next != NULL && node->val == node->next->val) {
            node->next = node->next->next;
        } 
        else {
            node = node->next;
        }
    }
    return head;
}


// @lc code=end
