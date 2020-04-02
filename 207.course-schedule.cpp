/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule


方法一：广度优先（入度表）
42/42 cases passed (160 ms)
Your runtime beats 4.77 % of cpp submissions
Your memory usage beats 5.45 % of cpp submissions (81.4 MB)
(一次过，但还没有进行任何优化)

方法二：同上，直接抄的leetcode官方题解。我的入度表是2维的，这里是1维的。相当于节省了空间，建表过程也比我的稍微好一些。
46/46 cases passed (1712 ms)
Your runtime beats 5.01 % of cpp submissions
Your memory usage beats 5.45 % of cpp submissions (465.4 MB)

方法三：深度优先搜索（要构建二维的邻接矩阵）
40/46 cases passed (N/A)
Time Limit Exceeded
奇怪···后面再看吧。
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int sum(vector<int>& a) {
        int s = 0;
        for (int i = 0; i < a.size(); ++i) {
            s += a[i];
        }
        return s;
    }
    
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector <int>> intable(numCourses, vector<int>(numCourses, 0));
        queue<int> q;
        int num = numCourses;

        for (auto li : prerequisites) {
            intable[li[0]][li[1]] = 1;
        }
        vector<int> _sum(numCourses,0);
        for (int i = 0; i < numCourses; ++i) {
            _sum[i] = sum(intable[i]);
            if (_sum[i]==0) q.push(i);
        } //其实这里可以优化，产生_sum数组并不需要在完整的n*n邻接矩阵基础上搞定。

        while(!q.empty()) {
            int p = q.front();
            q.pop();
            num--;
            for (int i = 0; i < numCourses; ++i) {
                if (intable[i][p] == 1) {
                    intable[i][p] = 0;
                    _sum[i]--;
                    if (_sum[i]==0) q.push(i);
                }
            }
        }
        return (num==0);
    }

    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses,0);
        for(auto cp : prerequisites) indegrees[cp[0]]++;
        queue<int> queue;
        for(int i = 0; i < numCourses; i++){
            if(indegrees[i] == 0) queue.push(i);
        }
        while(!queue.empty()) {
            int pre = queue.front();
            queue.pop();
            numCourses--;
            for(auto req : prerequisites) {
                if(req[1] != pre) continue;
                if(--indegrees[req[0]] == 0) queue.push(req[0]);
            }
        }
        return (numCourses == 0);
    }

    bool canFinish3(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacency(numCourses, vector<int>(numCourses, 0));;
        vector<int> flags(numCourses,0);
        for(auto cp : prerequisites)
            adjacency[cp[1]][cp[0]] = 1;
        for(int i = 0; i < numCourses; i++){
            if(!dfs(adjacency, flags, i)) return false;
        }
        return true;
    }

    bool dfs(vector<vector <int>> adjacency, vector<int> flags, int i) {
        if(flags[i] == 1) return false;
        if(flags[i] == -1) return true;
        flags[i] = 1;
        for(int j = 0; j < adjacency.size(); j++) {
            if(adjacency[i][j] == 1 && !dfs(adjacency, flags, j)) return false;
        }
        flags[i] = -1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinish2(numCourses,prerequisites);
        
    }
};
// @lc code=end

