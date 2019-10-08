/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> hitBricks1(vector<vector<int>>& grid, vector<vector<int>>& hits) {
/*
16/16 cases passed (152 ms)
Your runtime beats 70.28 % of cpp submissions
Your memory usage beats 50 % of cpp submissions (32.8 MB)
别人的方法：DFS + HashSet
https://www.cnblogs.com/grandyang/p/9362777.html

建议直接参考684题（ Redundant Connection ）。这道题也是通过DFS或者并查集Union Find的方法来做的，是专门处理群组问题的一种算法
*/
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k);
        unordered_set<int> noDrop;
        for (int i = 0; i < k; ++i) grid[hits[i][0]][hits[i][1]] -= 1;
        for (int i = 0; i < n; ++i) {
            if (grid[0][i] == 1) check(grid, 0, i, noDrop);
        }
        for (int i = k - 1; i >= 0; --i) {
            int oldSize = noDrop.size(), x = hits[i][0], y = hits[i][1];
            if (++grid[x][y] != 1) continue;
            if ((x - 1 >= 0 && noDrop.count((x - 1) * n + y)) 
                || (x + 1 < m && noDrop.count((x + 1) * n + y))
                || (y - 1 >= 0 && noDrop.count(x * n + y - 1))
                || (y + 1 < n && noDrop.count(x * n + y + 1))
                || x == 0) {
                check(grid, x, y, noDrop);
                res[i] = noDrop.size() - oldSize - 1;
            }
        }
        return res;
    }
    void check(vector<vector<int>>& grid, int i, int j, unordered_set<int>& noDrop) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || noDrop.count(i * n + j)) return;
        noDrop.insert(i * n + j);
        check(grid, i - 1, j, noDrop);
        check(grid, i + 1, j, noDrop);
        check(grid, i, j - 1, noDrop);
        check(grid, i, j + 1, noDrop);
    }


    vector<int> hitBricks2(vector<vector<int>>& grid, vector<vector<int>>& hits) {
/*
16/16 cases passed (272 ms)
Your runtime beats 28.48 % of cpp submissions
Your memory usage beats 12.5 % of   cpp submissions (41.4 MB)
别人的方法：并查集  
https://www.cnblogs.com/grandyang/p/9362777.html
另外，在leetcode官网给出的Java解法里还引入了DSU的类用来处理，可进一步借鉴。
*/
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k), root(m * n, -1), count(m * n, 1), t(m * n, 0);
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < k; ++i) grid[hits[i][0]][hits[i][1]] -= 1;
        for (int i = 0; i < n; ++i) t[i] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    int x = find(root, i * n + j), y = find(root, (i + 1) * n + j);
                    if (x != y) {root[y] = x; count[x] += count[y]; t[x] = t[y] = (t[x] | t[y]);}
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    int x = find(root, i * n + j), y = find(root, i * n + j + 1);
                    if (x != y) {root[y] = x; count[x] += count[y]; t[x] = t[y] = (t[x] | t[y]);}
                }
            }
        }
        for (int i = k - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1], a = find(root, x * n + y), cnt = 0;
            if (++grid[x][y] != 1) continue;
            for (auto dir : dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 1) continue;
                int b = find(root, newX * n + newY);
                if (a == b) continue;
                if (!t[b]) cnt += count[b];
                root[b] = a; count[a] += count[b]; t[a] = t[b] = (t[a] | t[b]);
            }
            if (t[a]) res[i] = cnt;
        }
        return res;
    }
    int find(vector<int>& root, int x) {
        return (root[x] == -1) ? x : find(root, root[x]);
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        return hitBricks2(grid,hits);
    }
};
// @lc code=end

