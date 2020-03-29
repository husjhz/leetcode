/*
 * @lc app=leetcode.cn id=135 lang=c
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (42.08%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 40K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */


// @lc code=start
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

int top(struct stack *s)
{
    return s->array[s->size - 1];
}

int pop(struct stack *s)
{
    return s->array[--s->size];
}

void push(struct stack *s, int x)
{
    s->array[s->size++] = x;
}

int empty(struct stack *s)
{
    return s->size == 0;
}

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int candy(int* ratings, int ratingsSize){
    int *nums;
    int i;
    struct stack *s;
    int total = 0;

    nums = (int *)malloc(sizeof(int) * ratingsSize);
    for (i = 0; i < ratingsSize; i++) {
        nums[i] = 1;
    }
    s = create(ratingsSize);
    for (i = 0; i < ratingsSize + 1; i++) {
        while (!empty(s)) {
            if (i == ratingsSize || ratings[i] > ratings[top(s)]) {
                int x = pop(s);
                if (x < ratingsSize - 1 && ratings[x] > ratings[x + 1]) {
                    nums[x] = MAX(nums[x], nums[x + 1] + 1);
                }
                if (x > 0 && ratings[x] > ratings[x - 1]) {
                    nums[x] = MAX(nums[x], nums[x - 1] + 1);
                }
                total += nums[x];
            }
            else {
                break;
            }
        }  
        if (i < ratingsSize)
            push(s, i); 
    }
    return total;
}


// @lc code=end

