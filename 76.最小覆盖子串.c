/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (34.76%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 61.1K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
int isContain(int *smaps, int *tmaps)
{
    int i;

    for (i = 0; i < 128; i++) {
        if (smaps[i] < tmaps[i]) {
            return 0;
        }
    }
    return 1;
}

char * minWindow(char * s, char * t){
    int left = 0;
    int right = 0;
    int slen = strlen(s);
    int tlen = strlen(t);
    int minLen = slen + 1;
    int minLeft;
    int minRight;
    char *returnStr = NULL;
    int smaps[128];
    int tmaps[128];
    int i;

    if (slen < tlen) {
        return "";
    }
    memset(smaps, 0, sizeof(smaps));
    memset(tmaps, 0, sizeof(tmaps));
    for (i = 0; i < tlen; i++) {
        tmaps[t[i]]++;
    }
    smaps[s[0]]++;
    while (left <= right && right < slen) {
        if (right - left + 1 >= tlen) {
            if (!isContain(smaps, tmaps)) {
                right++;
                smaps[s[right]]++;
            }
            else {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                    minRight = right;
                }
                smaps[s[left]]--;
                left++;
            }
        }
        else {
            right++;
            smaps[s[right]]++;
        }
    }
    if (minLen != slen + 1) {
        returnStr = malloc(sizeof(char) * (minLen + 1));
        memcpy(returnStr, s + minLeft, minLen);
        returnStr[minLen] = '\0';
    }
    else {
        return "";
    }
    return returnStr;
}

// @lc code=end

