/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *node = NULL;
    int carry = 0;
    struct ListNode *head = NULL;
    struct ListNode *last = NULL;

    while (l1 != NULL && l2 != NULL) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = (l1->val + l2->val + carry) % 10;
        node->next = NULL;
        carry = (l1->val + l2->val + carry) / 10;
        if (head == NULL) {
            head = node;
        }
        else {
            last->next = node;
        }
        last = node;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l2 != NULL) {
        l1 = l2;
    }
    while (l1 != NULL) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = (l1->val + carry) % 10;
        node->next = NULL;
        carry = (l1->val + carry) / 10;
        if (head == NULL) {
            head = node;
        }
        else {
            last->next = node;
        }
        last = node;
        l1 = l1->next;
    }
    if (carry) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        if (head == NULL) {
            head = node;
        }
        else {
            last->next = node;
        }
    }
    return head;
}


// @lc code=end

