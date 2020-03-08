/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (54.34%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 46K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 *
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 * 示例:
 *
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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


struct ListNode* partition(struct ListNode* head, int x){
    int len;
    struct ListNode *tail = head;
    struct ListNode newhead;

    if (head == NULL) {
        return head;
    }
    len = 1;
    while (tail->next != NULL) {
        len++;
        tail = tail->next;
    }
    if (len == 1) {
        return head;
    }
    newhead.next = head;
    head = &newhead;
    while(len--) {
        if (head->next->val >= x) {
            tail->next = head->next;
            tail = tail->next;
            head->next = head->next->next;
        }
        else {
            head = head->next;
        }   
    }
    tail->next = NULL;
    return newhead.next;
}


// @lc code=end

