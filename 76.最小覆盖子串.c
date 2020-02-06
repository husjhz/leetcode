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
static inline int MIN(int a, int b)
{
    return a < b ? a : b;
}

#if 0
int isContains(char *s, int left, int right, char *t, int tlen)
{
    int i;
    int maps[0x7f];

    if (right - left + 1 < tlen) {
        return 0;
    }
    memset(maps, 0, sizeof(maps));
    for (i = left; i <= right; i++) {
        maps[s[i] - '\0']++;
    }
    for (i = 0; i < tlen; i++) {
        maps[t[i] - '\0']--;
        if (maps[t[i] - '\0'] < 0) {
            return 0;
        }
    }
    return 1;
}

char * minWindow(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    int left = 0, right = tlen - 1;
    int minSize = INT_MAX;
    int minLeft, minRight;
    int tmaps[0x7f];
    int i;

    if (tlen == 0 || slen < tlen) {
        return "";
    }
    memset(tmaps, 0, sizeof(tmaps));
    for (i = 0; i < tlen; i++) {
        tmaps[t[i] - '\0']++;
    }
    while (left < slen && tmaps[s[left] -'\0'] == 0) {
        left++;
    }
    right = left + tlen  - 1;
    if (right >= slen) {
        return "";
    }
    while (*(s + right) != '\0') {
        while (left < right && tmaps[s[left] -'\0'] == 0) {
            left++;
        }
        if (isContains(s, left, right, t, tlen)) {
            if (right - left + 1 < minSize) {
                minSize = right - left + 1;
                minLeft = left;
                minRight = right;
            }
            left++;
        }
        else {
            right++;
        }
    }
    if (minSize != INT_MAX) {
        char *res = (char*)malloc(minSize + 1);
        strncpy(res, s + minLeft, minSize);
        res[minSize] = '\0';
        return res;
    }
    else {
        return "";
    }
}
#else
/*
int isContains(char *values, int left, int right, int *tmaps)
{
    int i;
    int smaps[0x7f];

    memset(smaps, 0, sizeof(smaps));
    for (i = left; i <= right; i++) {
        smaps[values[i] - '\0']++;
    }
    for (i = 0; i < 0x7f; i++) {
        if (smaps[i] < tmaps[i]) {
            return 0;
        }
    }
    return 1;
}

char * minWindow(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    int *indexs;
    char *values;
    int size = 0;
    int tmaps[0x7f];
    int i;
    int left, right;
    int minSize = INT_MAX;
    int minLeft, minRight;
    char *res;

    if (tlen == 0 || slen < tlen) {
        return "";
    }
    memset(tmaps, 0, sizeof(tmaps));
    for (i = 0; i < tlen; i++) {
        tmaps[t[i] - '\0']++;
    }
    indexs = (int*)malloc(sizeof(int) * slen);
    values = (char*)malloc(sizeof(char) * slen);
    for (i = 0; i < slen; i++) {
        if (tmaps[s[i] - '\0'] != 0) {
            indexs[size] = i;
            values[size] = s[i];
            size++;
        }
    }
    if (size < tlen) {
        return "";
    }
    left = 0;
    right = tlen - 1;
    while (right < size) {
        if (isContains(values, left, right, tmaps)) {
            if (indexs[right] - indexs[left] + 1 < minSize) {
                minSize = indexs[right] - indexs[left] + 1;
                minLeft = indexs[left];
                minRight = indexs[right];
            }
            left++;
        }
        else {
            right++;
        }
    }
    if (minSize != INT_MAX) {
        char *res = (char*)malloc(minSize + 1);
        strncpy(res, s + minLeft, minSize);
        res[minSize] = '\0';
        return res;
    }
    else {
        return "";
    }
}
*/
void mySubstr(char* s, char* res, int start, int len){
    for (int i = 0; i < len; i++){
        res[i] = s[i + start];
    }
    res[len] = '\0';
}

char * minWindow(char * s, char * t){
    int ls = strlen(s), lt = strlen(t);

    if (ls < lt || ls == 0)
        return "";
    int map[128] = {0};
    for (int i = 0; i < lt; i++){
        map[t[i]]++;
    }
    int left = 0, mlen = INT_MAX, idx = 0;
    int cnt = 0;
    for (int i = 0; i < ls; i++){
        map[s[i]]--;
        if (map[s[i]] >= 0){
            cnt++;
        }
        while (cnt == lt){
            if (mlen > i - left + 1){
                mlen = i - left + 1;
                idx = left;
            }
            map[s[left]]++;
            if (map[s[left]] > 0){
                cnt--;
            }
            left++;
        }
    }
    if (mlen == INT_MAX)
        return "";
    char* res = (char*)malloc(sizeof(char) * (mlen + 1));
    mySubstr(s, res, idx, mlen);
    return res;
}
#endif


// @lc code=end

