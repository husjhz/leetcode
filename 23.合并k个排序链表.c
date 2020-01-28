/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.15%)
 * Likes:    461
 * Dislikes: 0
 * Total Accepted:    68.6K
 * Total Submissions: 141.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
struct minheap {
    struct ListNode **array;
    int capacity;
    int size;
};

static struct minheap *create(int capacity)
{
    struct minheap *p;

    p = (struct minheap*)malloc(sizeof(struct minheap));
    p->array = (struct ListNode**)malloc(sizeof(struct ListNode*) * (capacity + 1));
    p->capacity = capacity;
    p->size = 0;
    return p;
}

static void push(struct minheap *p, struct ListNode *node)
{
    int i;

    if (p->size > p->capacity + 1) {
        return;
    }
    i = ++p->size;
    while (i > 1 && node->val < p->array[i / 2]->val) {
        p->array[i] = p->array[i / 2];
        i = i / 2;
    }
    p->array[i] = node;
}

static int pop(struct minheap *p, struct ListNode **pnode)
{
    struct ListNode *node;
    int i, ci;

    if (p->size == 0) {
        return -1;
    }
    *pnode = p->array[1];
    node = p->array[p->size];
    i = 1;
    ci = 2;
    while (ci < p->size) {
        if (ci < p->size && p->array[ci + 1]->val < p->array[ci]->val) {
            ci++;
        }
        if (node->val > p->array[ci]->val) {
            p->array[i] = p->array[ci];
            i = ci;
            ci = 2 * i;
        }
        else {
            break;
        }
    }
    p->array[i] = node;
    p->size--;
    return 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct minheap *heap = create(10000);
    int i;
    struct ListNode *node;
    struct ListNode *p = NULL;
    struct ListNode *head = NULL;

    for (i = 0; i < listsSize; i++) {
        if (lists[i])
            push(heap, lists[i]);
    }
    while (pop(heap, &node) == 0) {
        if (p) {
            p->next = node;
            p = node;
            if (p->next) {
                push(heap, p->next);
            }
        }
        else {
            head = node;
            p = node;
            if(p->next) {
                push(heap, p->next);
            }    
        }
    }
    if (p) {
        p->next = NULL;
    }
    return head;
}

// @lc code=end

