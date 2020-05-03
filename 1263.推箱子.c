/*
 * @lc app=leetcode.cn id=1263 lang=c
 *
 * [1263] 推箱子
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/
 *
 * algorithms
 * Hard (43.07%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    1.1K
 * Total Submissions: 2.6K
 * Testcase Example:  '[["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#",".","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]'
 *
 * 「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。
 * 
 * 游戏地图用大小为 n * m 的网格 grid 表示，其中每个元素可以是墙、地板或者是箱子。
 * 
 * 现在你将作为玩家参与游戏，按规则将箱子 'B' 移动到目标位置 'T' ：
 * 
 * 
 * 玩家用字符 'S' 表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。
 * 地板用字符 '.' 表示，意味着可以自由行走。
 * 墙用字符 '#' 表示，意味着障碍物，不能通行。 
 * 箱子仅有一个，用字符 'B' 表示。相应地，网格上有一个目标位置 'T'。
 * 玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。
 * 玩家无法越过箱子。
 * 
 * 
 * 返回将箱子推到目标位置的最小 推动 次数，如果无法做到，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [
 * ["#","#","#","#","#","#"],
 * ⁠["#","T","#","#","#","#"],
 * ["#",".",".","B",".","#"],
 * ["#",".","#","#",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * 输出：3
 * 解释：我们只需要返回推箱子的次数。
 * 
 * 示例 2：
 * 
 * 输入：grid = [
 * ["#","#","#","#","#","#"],         
 * ["#","T","#","#","#","#"],
 * ["#",".",".","B",".","#"],
 * ["#","#","#","#",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [
 * ["#","#","#","#","#","#"],
 * ["#","T",".",".","#","#"],
 * ["#",".","#","B",".","#"],
 * ["#",".",".",".",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * 输出：5
 * 解释：向下、向左、向左、向上再向上。
 * 
 * 
 * 示例 4：
 * 
 * 输入：grid = [
 * ["#","#","#","#","#","#","#"],
 * ["#","S","#",".","B","T","#"],
 * ["#","#","#","#","#","#","#"]]
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 20
 * 1 <= grid[i].length <= 20
 * grid 仅包含字符 '.', '#',  'S' , 'T', 以及 'B'。
 * grid 中 'S', 'B' 和 'T' 各只能出现一个。
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

struct Node {
    int px;
    int py;
    int bx;
    int by;
};
typedef struct Node ElemType;

struct dqueue {
    ElemType *array;
    int capacity;
    int size;
    int front;
    int rear;
};

struct dqueue *create(int capacity)
{
    struct dqueue *dq;

    dq = (struct dqueue *)malloc(sizeof(struct dqueue));
    dq->array = (ElemType *)malloc(sizeof(ElemType) * capacity);
    dq->capacity = capacity;
    dq->size = 0;
    dq->front = 0;
    dq->rear = 0;
    return dq;
}

void push_back(struct dqueue *dq, ElemType e)
{
    dq->array[dq->rear] = e;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->size++;
}

void push_front(struct dqueue *dq, ElemType e)
{
    dq->front = (dq->front + dq->capacity - 1) % dq->capacity;
    dq->array[dq->front] = e;
    dq->size++;
}

ElemType pop_front(struct dqueue *dq)
{
    int front = dq->front;
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return dq->array[front];
}

ElemType pop_back(struct dqueue *dq)
{
    dq->rear = (dq->rear + dq->capacity - 1) % dq->capacity;
    dq->size--;
    return dq->array[dq->rear];
}

ElemType front(struct dqueue *dq)
{
    return dq->array[dq->front];
}

ElemType back(struct dqueue *dq)
{
    int rear = (dq->rear + dq->capacity - 1) % dq->capacity;
    return dq->array[rear];
}

int size(struct dqueue *dq)
{
    return dq->size;
}

int empty(struct dqueue *dq)
{
    return dq->size == 0;
}

static inline ElemType makeElem(int ax, int ay, int bx, int by)
{
    ElemType x = {
        ax,
        ay,
        bx,
        by
    };
    return x;
}

static inline int ABS(int a)
{
    return a > 0 ? a : -a;
}

int minPushBox(char** grid, int gridSize, int* gridColSize){
    int i, j, k;
    int px, py, bx, by, tx, ty;
    int m, n;
    struct dqueue *dq;
    int flags[21][21][21][21];
    int xpos[4] = {-1, 1, 0, 0};
    int ypos[4] = {0, 0, -1, 1};

    if (grid == NULL ||  gridSize == 0 || gridColSize == NULL) {
        return -1;
    }
    m = gridSize;
    n = *gridColSize;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 'S') {
                px = i;
                py = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    printf("(%d, %d), (%d, %d), (%d, %d)\n", px, py, tx, ty, bx, by);
    dq = create(m * n);
    memset(flags, 255, sizeof(flags));
    push_back(dq, makeElem(px, py, bx, by));
    printf("+(%d, %d, %d, %d)\n", px, py, bx, by);
    flags[px][py][bx][by] = 0;
    while (!empty(dq)) {
        ElemType e = pop_front(dq);
        printf("-(%d, %d, %d, %d)\n", e.px, e.py, e.bx, e.by);
        if (e.bx == tx && e.by == ty) {
            return flags[e.px][e.py][e.bx][e.by];
        }
        for (k = 0; k < 4; k++) {
            int npx = e.px + xpos[k];
            int npy = e.py + ypos[k];
            if (npx < 0 || npx >= m || npy < 0 || npy >= n || grid[npx][npy] == '#') {
                continue;
            }
            if (npx == e.bx && npy == e.by) {
                continue;
            }
            if (flags[npx][npy][e.bx][e.by] >= 0) {
                continue;
            }
            flags[npx][npy][e.bx][e.by] = flags[e.px][e.py][e.bx][e.by];
            printf("++(%d, %d, %d, %d)\n", npx, npy, e.bx, e.by);
            push_front(dq, makeElem(npx, npy, e.bx, e.by));
        }
        if (ABS(e.px - e.bx) + ABS(e.py - e.by) == 1) {
            int nbx, nby;
            for (k = 0; k < 4; k++) {
                int npx = e.px + xpos[k];
                int npy = e.py + ypos[k];
                if (npx == e.bx && npy == e.by) {
                    break;
                }
            }
            nbx = e.bx + xpos[k];
            nby = e.by + ypos[k];
            if (nbx >= 0 && nbx < m && nby >= 0 && nby < n && 
                grid[nbx][nby] == '.' &&flags[e.bx][e.bx][nbx][nby] < 0) {
                flags[e.bx][e.by][nbx][nby] = flags[e.px][e.py][e.bx][e.by] + 1;
                printf("+(%d, %d, %d, %d)\n", e.bx, e.by, nbx, nby);
                push_back(dq, makeElem(e.bx, e.by, nbx, nby));           
            }
        }
    }
    return -1;
}

// @lc code=end

