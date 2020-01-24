/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

int lengthOfLongestSubstring(char * s){
    int maps[0x7f];
    int slen = strlen(s);
    int i;
    int max = -1;
    int count = 0;

    memset(maps, 0, sizeof(maps) / sizeof(maps[0]));
    for (i = 0; i < slen; i++) {
        if (maps[s[i]] == 0) {
            maps[s[i]] = 1;
            count++;
        }
        else {
            max = count > max ? count : max;
            count = 0;
            memset(maps, 0, sizeof(maps) / sizeof(maps[0]));
            maps[s[i]] = 1;
        }
    }
    return max;
}


// @lc code=end

