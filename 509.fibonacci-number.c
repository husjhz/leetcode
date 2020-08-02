/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 *
 * https://leetcode-cn.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (66.52%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    68.5K
 * Total Submissions: 103K
 * Testcase Example:  '2'
 *
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * 
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 * 
 * 
 * 给定 N，计算 F(N)。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
 * 
 * 
 * 示例 2：
 * 
 * 输入：3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
 * 
 * 
 * 示例 3：
 * 
 * 输入：4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 ≤ N ≤ 30
 * 
 * 
 */

// @lc code=start


int fib(int N){
#if 0
    if (N < 2) {
        return N;
    }
    return fib(N - 1) + fib(N - 2);
#endif
    int i;
    int *tmp;

    if (N < 2) {
        return N;
    }
    tmp = (int *)malloc(sizeof(int) * N);
    tmp[0] = 0;
    tmp[1] = 1;
    for (i = 2; i < N; i++) {
        tmp[i] = tmp[i - 1] + tmp[i - 2];
    }
    return tmp[N - 1] + tmp[N - 2];
}


// @lc code=end
