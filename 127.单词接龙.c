/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (40.76%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    30K
 * Total Submissions: 73.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
struct node {
    char *str;
    int index;
};

struct queue {
    struct node **array;
    int capacity;
    int size;
    int front;
    int rear;
};

struct queue *create(int capacity)
{
    int i;
    struct queue *q;

    q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (struct node **)malloc(sizeof(struct node*) * capacity);
    for (i = 0; i < capacity; i++) {
        q->array[i] = (struct node *)malloc(sizeof(struct node));
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(struct queue *q, char *s, int index)
{
    q->array[q->rear]->str = s;
    q->array[q->rear]->index = index;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

struct node *dequeue(struct queue *q)
{
    struct node *node;

    node = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

int size(struct queue *q)
{
    return q->size;
}

int empty(struct queue *q)
{
    return q->size == 0;
}

int canChange(char *a, char *b)
{
    int i;
    int len = strlen(a);
    int flag = 0;

    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            if (flag) {
                return 0;
            }
            else {
                flag = 1;
            }
        }
    }
    return flag;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    struct queue *q[2];
    int beginWordIndex = -1;
    int endWordIndex = -1;
    int i, j;
    int wordLen = strlen(beginWord);
    int *mark;
    int step = 1;

    for (i = 0; i < wordListSize; i++) {
        if (strcmp(beginWord, wordList[i]) == 0) {
            beginWordIndex = i;
        }
        if (strcmp(endWord, wordList[i]) == 0) {
            endWordIndex = i;
            break;
        }
    }
    if (endWordIndex < 0) {
        return 0;
    }
    q[0] = create(wordListSize * 2);
    q[1] = create(wordListSize * 2);
    enqueue(q[0], beginWord, beginWordIndex);
    enqueue(q[1], endWord, endWordIndex);
    mark = (int *)malloc(sizeof(int) * wordListSize * 2);
    for (i = 0; i < wordListSize * 2; i++) {
        mark[i] = 0;
    }
    if (beginWordIndex >= 0) {
        mark[beginWordIndex] = 1;
    }
    mark[endWordIndex] = 2;
    for (; !empty(q[0]) && !empty(q[1]); step++) {
        int searchSize;
        int searchIndex;
        int searchFlag;
        if (size(q[0]) <= size(q[1])) {
            searchSize = size(q[0]);
            searchIndex = 0;
        }
        else {
            searchSize = size(q[1]);
            searchIndex = 1;
        }
        searchFlag = 1 << searchIndex;
        for (i = 0; i < searchSize; i++) {
            struct node *node = dequeue(q[searchIndex]);
            //printf("- %s\n", node->str);
            if (node->index >= 0 && mark[node->index] == 3) {
                return step;
            }
            for (j = 0; j < wordListSize; j++) {
                if (mark[j] != searchFlag && canChange(node->str, wordList[j])) {
                    if (mark[j] | searchFlag == 3) {
                        return ++step;
                    }
                    //printf("+ %s\n", wordList[j]);
                    enqueue(q[searchIndex], wordList[j], j);
                    mark[j] |= searchFlag;
                }
            }
        }
    }
    return 0;
}


// @lc code=end

