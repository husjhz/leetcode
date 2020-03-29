/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.71%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    86.7K
 * Total Submissions: 202.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
bool isNumOrAlpha(char c)
{
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isEqual(char a, char b)
{
    if (a >= 'A' && a <= 'Z') {
        a = a - 'A' + 'a';
    }
    if (b >= 'A' && b <= 'Z') {
        b = b - 'A' + 'a';
    }
    return a == b;
}

bool isPalindrome(char * s){
    int len;
    int i, j;

    if (s == NULL) {
        return false;
    }
    if (*s == '\0') {
        return true;
    }
    len = strlen(s);
    i = 0;
    j = len - 1;
    while (i < j) {
        while (i < j && !isNumOrAlpha(s[i])) {
            i++;
        }
        while (i < j && !isNumOrAlpha(s[j])) {
            j--;
        }
        if (!isEqual(s[i], s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


// @lc code=end

