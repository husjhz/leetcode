/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (60.57%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    95.1K
 * Total Submissions: 157K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到
 * 1。如果 可以变为  1，那么这个数就是快乐数。
 * 
 * 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct list_head {
    struct list_head *prev, *next;
};

#define INIT_LIST_HEAD(head) do { \
    (head)->prev = head; \
    (head)->next = head; \
} while (0)

void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    prev->next = new;
    new->prev = prev;
    new->next = next;
    next->prev = new;
}

void list_add(struct list_head *head, struct list_head *new)
{
    __list_add(new, head, head->next);
}

void __list_del(struct list_head *prev, struct list_head *next)
{
    prev->next = next;
    next->prev = prev;
}

void list_del(struct list_head *node)
{
    __list_del(node->prev, node->next);
}

int list_empty(struct list_head *head)
{
    return head->next == head;
}

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(pos, type, member) \
    (type *)((char *)pos - (int)(&((type *)0)->member))

struct entry {
    struct list_head list;
    int data;
};

struct hash_node {
    struct list_head list;
};

#define BUCKETS_SIZE    10000
struct hash_node buckets[BUCKETS_SIZE];

void hash_init(void)
{
    int i;
    for (i = 0; i < BUCKETS_SIZE; i++) {
        INIT_LIST_HEAD(&(buckets[i].list));
    }
}

struct entry *hash_find(int n)
{
    struct hash_node *hash = &buckets[n % BUCKETS_SIZE];
    struct list_head *pos;
    struct entry *e;

    if (list_empty(&hash->list))
        return NULL;
    list_for_each(pos, &hash->list) {
        e = list_entry(pos, struct entry, list);
        if (e->data == n) {
            return e;
        }
    }
    return NULL;
}

void hash_add(int n)
{
    struct hash_node *hash = &buckets[n % BUCKETS_SIZE];
    struct entry *e;

    e = (struct entry *)malloc(sizeof(struct entry));
    e->data = n;
    list_add(&hash->list, &e->list);
}

void hash_del(int n)
{
    struct hash_node *hash = &buckets[n % BUCKETS_SIZE];
    struct entry *e;

    e = hash_find(n);
    if (e) {
        list_del(&e->list);
        free(e);
    }
}

static int helper(int n)
{
    int sum = 0;
    int a;

    while (n > 0) {
        a = n % 10;
        n = n / 10;
        sum += a * a;
    }
    return sum;
}

bool isHappy(int n){
    hash_init();
    while (n != 1) {
        if (hash_find(n))
            return false;
        hash_add(n);
        n = helper(n);
    }
    return true;
}

// @lc code=end
