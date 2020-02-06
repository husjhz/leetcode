/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.42%)
 * Likes:    811
 * Dislikes: 0
 * Total Accepted:    126.7K
 * Total Submissions: 265.8K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
int dfs(int i, int n, int *dp)
{
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (dp[i] > 0) {
        return dp[i];
    }
    dp[i] = dfs(i + 1, n, dp) + dfs(i + 2, n, dp);
    return dp[i];
}

int climbStairs(int n){
    int *dp;
    int i;

    dp = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        dp[i] = 0;
    }
    return dfs(0, n, dp);
}


// @lc code=end

