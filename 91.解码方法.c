/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.49%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 137.1K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

int numDecodings(char * s){
    int len;
    int pre = 1, nxt;
    int codeVal;

    if (s == NULL) {
        return 0;
    }
    len = strlen(s);

    if (len == 0) 
        return 0;
    else if (len == 1 && s[0] - '0' > 0) 
        return 1;
    else if (len == 1 && s[0] - '0' == 0) 
        return 0;

    codeVal = (s[0] - '0') * 10 + (s[1] - '0');
    if (codeVal == 0) 
        return 0;
    else if (0 < codeVal && codeVal < 10) 
        return 0;
    else if (codeVal == 10 || codeVal == 20) 
        nxt = 1;
    else if (10 < codeVal && codeVal <= 26) 
        nxt = 2;
    else if (codeVal > 26) {
        if(s[1] != '0') 
            nxt = 1;
        else 
            return 0;
    }
    for (int i = 2; i < len; ++i)
    {
        int codeVal = (s[i-1] - '0') * 10 + (s[i] - '0');
        if (codeVal == 0)
            return 0;
        else if (0 < codeVal && codeVal < 10) {   
            pre = nxt;
        }
        else if (codeVal == 10 || codeVal == 20) { 
            int tmpAmount = pre;
            pre = nxt;
            nxt = tmpAmount;
        }
        else if (10 < codeVal && codeVal <= 26) {
            int tmpAmount = pre + nxt;
            pre = nxt;
            nxt = tmpAmount;
        }
        else if (codeVal > 26){
            if (s[i] != '0') 
                pre = nxt; 
            else
                return 0;
        }
    }
    return nxt;
}


// @lc code=end

