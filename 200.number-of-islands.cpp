/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
方法一：我自己的DFS（一开始并没有意识到这是DFS）
47/47 cases passed (16 ms)
Your runtime beats 63.68 % of cpp submissions
Your memory usage beats 28.09 % of cpp submissions (11.3 MB)

方法二：官方网站的DFS
https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
47/47 cases passed (12 ms)
Your runtime beats 92.89 % of cpp submissions
Your memory usage beats 64.04 % of cpp submissions (10.9 MB)
相比之于方法一，优化点在于，访问过的点直接改的是grid里的数（改成'0'），而不需要再引入一个外在的二维数组来记录。这样极大地减少了DFS函数访问的次数，提升效率。

方法三：官方网站的BFS
47/47 cases passed (12 ms)
Your runtime beats 92.89 % of cpp submissions
Your memory usage beats 22.47 % of cpp submissions (11.4 MB)

https://blog.csdn.net/yueguangmuyu/article/details/100046125
这篇博客里详细分析了DFS BFS的各自的特点。
“一般情况下，深度优先搜索法占内存少但速度较慢，广度优先搜索算法占内存多但速度较快，在距离和深度成正比的情况下能较快地求出最优解。因此在选择用哪种算法时，要综合考虑。决定取舍。”

方法四：并查集！！！第一次出现这类题目！
https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
47/47 cases passed (20 ms) --递归路径压缩
Your runtime beats 28.2 % of cpp submissions
Your memory usage beats 12.36 % of cpp submissions (12 MB)
47/47 cases passed (16 ms) --非递归路径压缩

Your runtime beats 63.63 % of cpp submissions
Your memory usage beats 12.36 % of cpp submissions (12 MB)

 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class UnionFind {
public:


    int find_recrusive(int i) { // path compression
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    int find_non_recursive(int i) { // 非递归的find写法，可防止溢出栈，推荐。
        int r = i;
        while (parent[r] != r) r = parent[r]; // r为根节点
        
        int k = i;
        int j;
        while (k != r) { // 路径压缩
            j = parent[k];  //用j暂存parent[k]的父节点
            parent[k] = r;  //parent[x]指向跟节点
            k = j;          //k移到父节点
        }
        return r;
    } 
    int find(int i) {
        // return find_recrusive(i);
        return find_non_recursive(i);
    }
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }
    void Union(int x, int y) { // union with rank
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
            else {
                parent[rooty] = rootx; 
                rank[rootx] += 1;
            }
            --count;
        }
    }
    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count; // # of connected components
};

// ---------------------------Solution--------------------
class Solution {
public:
    int numIslands4(vector<vector<char>>& grid) { // 并查集
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf (grid);
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
          if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
          if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
        }
      }
    }
    return uf.getCount();
    }

    int numIslands1(vector<vector<char>>& grid) {
        if (grid.size()==0) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]=='1' && visited[i][j]==false) {
                    search(grid, visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void search(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i-1>=0) {
            if (grid[i-1][j]=='1' && visited[i-1][j]==false) {
                visited[i-1][j] = true;
                search(grid, visited,i-1,j);
            }
        }
        if (i+1<grid.size()) {
            if (grid[i+1][j]=='1' && visited[i+1][j]==false) {
                visited[i+1][j] = true;
                search(grid,visited,i+1,j);
            }
        }
        if (j-1>=0) {
            if (grid[i][j-1]=='1' && visited[i][j-1]==false) {
                visited[i][j-1] = true;
                search(grid,visited,i,j-1);
            }
        }
         if (j+1<grid[0].size()) {
            if (grid[i][j+1]=='1' && visited[i][j+1]==false) {
                visited[i][j+1] = true;
                search(grid,visited,i,j+1);
            }
        }       
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

    int numIslands2(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }

    int numIslands3(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }
    return num_islands;
    }

    int numIslands(vector<vector<char>>& grid) {
        return numIslands4(grid);
    }
};
// @lc code=end

