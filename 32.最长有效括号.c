/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.86%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 121.9K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
struct brackets {
    int index;
    char ch;
};

struct stack {
    struct brackets *array;
    int capacity;
    int size;
};

static struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack*)malloc(sizeof(struct stack));
    s->array = (char*)malloc(sizeof(struct brackets) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

static int push(struct stack *s, int index, char ch)
{
    if (s->size == s->capacity) {
        return -1;
    }
    s->array[s->size].index = index;
    s->array[s->size].ch = ch;
    return ++s->size;
}

static int pop(struct stack *s, int *pindex, char *pch)
{
    if (s->size == 0) {
        return -1;
    }
    s->size--;
    *pindex = s->array[s->size].index;
    *pch = s->array[s->size].ch;
    return s->size;
}

static inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

int longestValidParentheses(char * s){
    int slen;
    struct stack *stack;
    int i;
    int index;
    char ch;
    
    if (s == NULL) {
        return 0;
    }
    slen = strlen(s);
    if (slen < 2) {
        return 0;
    }
    stack = create(slen);
    for (i = 0; i < slen; i++) {
        if (s[i] == '(') {
            push(stack, i, s[i]);
        }
        else if (stack->size == 0) {
            push(stack, i, s[i]);
        }
        else {
            pop(stack, &index, &ch);
            if (ch != '(') {
                push(stack, index, ch);
                push(stack, i, s[i]);
            }
        }
    }
    if (stack->size == 0) {
        free(stack);
        return slen;
    }
    else {
        int max = 0;
        int lastIndex = -1;
        for (i = 0; i < stack->size; i++) {
            max = MAX(max, stack->array[i].index - lastIndex - 1);
            lastIndex = stack->array[i].index;
        }
        max = MAX(max, slen - lastIndex - 1);
        free(stack);
        return max;
    }
}


// @lc code=end

