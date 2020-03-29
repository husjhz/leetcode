/*
 * @lc app=leetcode.cn id=901 lang=c
 *
 * [901] 股票价格跨度
 *
 * https://leetcode-cn.com/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (41.27%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 7.4K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * 编写一个 StockSpanner 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。
 * 
 * 今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
 * 
 * 例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4,
 * 6]。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：["StockSpanner","next","next","next","next","next","next","next"],
 * [[],[100],[80],[60],[70],[60],[75],[85]]
 * 输出：[null,1,1,1,2,1,4,6]
 * 解释：
 * 首先，初始化 S = StockSpanner()，然后：
 * S.next(100) 被调用并返回 1，
 * S.next(80) 被调用并返回 1，
 * S.next(60) 被调用并返回 1，
 * S.next(70) 被调用并返回 2，
 * S.next(60) 被调用并返回 1，
 * S.next(75) 被调用并返回 4，
 * S.next(85) 被调用并返回 6。
 * 
 * 注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格
 * (包括今天的价格 75) 小于或等于今天的价格。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 调用 StockSpanner.next(int price) 时，将有 1 <= price <= 10^5。
 * 每个测试用例最多可以调用  10000 次 StockSpanner.next。
 * 在所有测试用例中，最多调用 150000 次 StockSpanner.next。
 * 此问题的总时间限制减少了 50%。
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

struct stack {
    int *array;
    int capacity;
    int size;
};

struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack *)malloc(sizeof(struct stack));
    s->array = (int *)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

int empty(struct stack *s)
{
    return s->size == 0;
}

void push(struct stack *s, int x)
{
    s->array[s->size++] = x;
}

int top(struct stack *s)
{
    return s->array[s->size - 1];
}

int pop(struct stack *s)
{
    return s->array[--s->size];
}

typedef struct {
    struct stack *s;
    struct stack *w;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj;

    obj = (StockSpanner *)malloc(sizeof(StockSpanner));
    obj->s = create(10000);
    obj->w = create(10000);
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int w = 1;

    while (!empty(obj->s) && top(obj->s) <= price) {
        pop(obj->s);
        w += pop(obj->w);
    }
    push(obj->s, price);
    push(obj->w, w);

    return w;
}

void stockSpannerFree(StockSpanner* obj) {
    
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
// @lc code=end

