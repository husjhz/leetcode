/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 *
 * algorithms
 * Easy (43.17%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    121.4K
 * Total Submissions: 281.1K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

// 1 2 3 4 3 2 1

bool isPalindrome(struct ListNode* head){
    struct ListNode *slow;
    struct ListNode *fast;
    struct ListNode *p, *pre = NULL;
    if (head == NULL || head->next == NULL)
        return true;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
        p->next = pre;
        pre = p;
    }
    if (fast)
        slow = slow->next;
    while (slow && p) {
        if (slow->val != p->val)
            return false;
        slow = slow->next;
        p = p->next;
    }
    return true;

}


// @lc code=end
