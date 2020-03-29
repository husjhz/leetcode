/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 朋友圈
 *
 * https://leetcode-cn.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.52%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    31.3K
 * Total Submissions: 56.2K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是
 * C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 * 
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j
 * 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * 输出: 2 
 * 说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
 * 第2个学生自己在一个朋友圈。所以返回2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * 输出: 1
 * 说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
 * 
 * 
 * 注意：
 * 
 * 
 * N 在[1,200]的范围内。
 * 对于所有学生，有M[i][i] = 1。
 * 如果有M[i][j] = 1，则有M[j][i] = 1。
 * 
 * 
 */

// @lc code=start
struct unionSet {
    int parent;
    int weight;
};

int find(struct unionSet *sets, int x)
{
    while (sets[x].parent != x) {
        x = sets[x].parent;
    }
    return x;
}

static int count = 0;
void merge(struct unionSet *sets, int i, int j)
{
    int xparent = find(sets, i);
    int yparent = find(sets, j);

    if (xparent != yparent) {
        if (sets[xparent].weight > sets[yparent].weight) {
            sets[yparent].parent = xparent;
            sets[yparent].weight = sets[xparent].weight;
        }
        else {
            sets[xparent].parent = yparent;
            sets[xparent].weight += sets[yparent].weight;
        }
        count--;
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int i, j;
    struct unionSet *sets = (struct unionSet *)malloc(sizeof(struct unionSet) * MSize);

    for (i = 0; i < MSize; i++) {
        sets[i].parent = i;
        sets[i].weight = 1;
    }
    count = MSize;
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < *MColSize; j++) {
            if (M[i][j] == 1) {
                merge(sets, i, j);
            }
        }
    }
    free(sets);
    return count;
}


// @lc code=end

