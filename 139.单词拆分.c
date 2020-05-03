/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (43.68%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    41.1K
 * Total Submissions: 93.5K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
#include <stdbool.h>

int __strcmp(char *a, char *b)
{
    int i;
    int alen = strlen(a);
    int blen = strlen(b);

    if (alen < blen) {
        return 0;
    }
    for (i = 0; i < blen; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return blen;
}

#if 0
bool dfs(char * s, int start, char ** wordDict, int wordDictSize, int *flags){
    int i;
    int len;

    if (*(s + start) == '\0') {
        return true;
    }
    if (flags[start]) {
        return true;
    }
    for (i = 0; i < wordDictSize; i++) {
        len = __strcmp(s + start, wordDict[i]);
        if (len > 0) { 
            if(dfs(s, start + len, wordDict, wordDictSize, flags)) {
                flags[start] = true;
                return true;
            }
        }
    }
    flags[start] = false;
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int *flags;
    int slen = strlen(s);
    int i;

    flags = (int *)malloc(sizeof(int) * slen);
    for (i = 0; i < slen; i++) {
        flags[i] = 0;
    }
    return dfs(s, 0, wordDict, wordDictSize, flags);
}
#endif
struct queue {
    int *array;
    int capacity;
    int size;
    int front;
    int rear;
};

struct queue *create(int capacity)
{
    struct queue *q;

    q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (int *)malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = 0; 
    return q;
}

void enqueue(struct queue *q, int x)
{
    q->array[q->rear] = x;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(struct queue *q)
{
    int x;

    x = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

int size(struct queue *q)
{
    return q->size;
}

int empty(struct queue *q)
{
    return q->size == 0;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    struct queue *q;
    int i, j;
    int *visited;
    int slen;
    int len;

    slen = strlen(s);
    q = create(slen);
    enqueue(q, 0);
    visited = (int *)malloc(sizeof(int) * slen);
    for (i = 0; i < slen; i++) {
        visited[i] = 0;
    }
    while (!empty(q)) {
        i = dequeue(q);
        if (visited[i] == 0) {
            for (j = 0; j < wordDictSize; j++) {
                len = __strcmp(s + i, wordDict[j]);
                if (len > 0) {
                    //printf("%s %s\n", s + i, wordDict[j]);
                    if (*(s + i + len) == '\0') {
                        return true;
                    }
                    enqueue(q, i + len);
                }
            }
            visited[i] = 1;
        }
    }
    return false;
}

// @lc code=end

