/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (43.68%)
 * Total Accepted:    33K
 * Total Submissions: 75.4K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */


bool wordPattern(char * pattern, char * s){
    char *maps[26];
    char *end = s;

    if (pattern == NULL || s == NULL)
        return false;
    while (*end != '\0') {
        if (*end == ' ')
            *end = '\0';
        end++;
    }
    memset(maps, 0, sizeof(maps));
    while (*pattern != '\0') {
        if (maps[*pattern - 'a'] == NULL) {
            int i;
            for (i = 0; i < 26; i++) {
                if (maps[i] != NULL && strcmp(maps[i], s) == 0) {
                    return false;
                }
            }
            maps[*pattern - 'a'] = s;
        }
        else if (strcmp(maps[*pattern - 'a'], s) != 0) {
            return false;
        }
        pattern++;
        while (s != end && *s != '\0') {
            s++;
        }
        if (s == end) {
            return *pattern == '\0';
        }
        s++;
    }
    return s == end;
}
