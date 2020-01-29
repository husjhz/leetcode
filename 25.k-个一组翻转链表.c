/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (55.20%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 61.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
struct stack {
    struct ListNode **array;
    int capacity;
    int size;
};

static struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack*)malloc(sizeof(struct stack));
    s->array = (struct ListNode**)malloc(sizeof(struct ListNode*) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

static int push(struct stack *s, struct ListNode *node)
{
    if (s->size == s->capacity) {
        return -1;
    }
    s->array[s->size++] = node;
    return s->size;
}

static int pop(struct stack *s, struct ListNode **pnode)
{
    if (s->size == 0) {
        return -1;
    }
    *pnode = s->array[--s->size];
    return s->size;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *newHead = head;
    struct ListNode *node;
    struct ListNode *p = NULL;
    struct ListNode *tmp = head;
    struct stack *stack;
    int retval;
    
    if (head == NULL || k < 2) {
        return head;
    }
    stack = create(k);
    while (tmp) {
        retval = push(stack, tmp);
        tmp = tmp->next;
        if (retval == k) {
            while (pop(stack, &node) >= 0) {
                if (p) {
                    p->next = node;
                    p = node;
                }
                else {
                    p = node;
                    newHead = p;
                }
            }   
        }
    }
    if (p) {
        if (stack->size > 0) {
            p->next = stack->array[0];
        }
        else {
            p->next = NULL;
        }
    }
    return newHead;
}

// @lc code=end

