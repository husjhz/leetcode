/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.74%)
 * Likes:    821
 * Dislikes: 0
 * Total Accepted:    169.8K
 * Total Submissions: 286.7K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p;
    struct ListNode *ret;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    if (p1->val <= p2->val) {
        p = p1;
        p1 = p1->next;
    }
    else {
        p = p2;
        p2 = p2->next;
    }
    ret = p;
    while (p1 && p2) {
        if (p1->val <= p2->val) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        else {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
    }
    p->next = p1 ? p1 : p2;
    return ret;
}


// @lc code=end

