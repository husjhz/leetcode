/*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (40.12%)
 * Total Accepted:    50.2K
 * Total Submissions: 125.2K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */


int trailingZeroes(int n) {
    int ans=0;
    long int i=0;
    for(i=5; n/i >=1 ;i*=5){
        ans+= n/i;
    }
    return ans;
}
