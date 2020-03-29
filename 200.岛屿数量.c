/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.62%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 148.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
struct unionSet {
    int parent;
    int weight;
};

struct unionSet *create(int capacity)
{
    int i;
    struct unionSet *sets;

    sets = (struct unionSet *)malloc(sizeof(struct unionSet) * capacity);
    for (i = 0; i < capacity; i++) {
        sets[i].parent = i;
        sets[i].weight = 1;
    }
    return sets;
}

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

int numIslands(char** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n;
    struct unionSet *sets;
    int i, j;

    if (!grid || gridSize == 0 || !gridColSize) {
        return 0;
    }
    n = *gridColSize;
    sets = create(m * n);
    count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                count++;
                if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                    merge(sets, i * n + j, (i - 1) * n + j);
                }
                if (i + 1 < m && grid[i + 1][j] == '1') {
                    merge(sets, i * n + j, (i + 1) * n + j);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                    merge(sets, i * n + j, i * n + j - 1);
                }
                if (j + 1 < n && grid[i][j + 1] == '1') {
                    merge(sets, i * n + j, i * n + j + 1);
                }
            }
        }
    }
    return count;
}


// @lc code=end

