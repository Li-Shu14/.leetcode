/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 * Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
 */

// @lc code=start
#include <vector>

using namespace std;
/*
方法一 DFS
https://www.jianshu.com/p/79b05c2bfdbc
Runtime: 16 ms, faster than 56.81% of C++ online submissions for Combination Sum.
Memory Usage: 9.4 MB, less than 94.44% of C++ online submissions for Combination Sum.
是否对candidates进行排序不太影响最后的效率。可能是因为提供的数据总是顺序的。原博客认为排序可以避免重复结果。

排序后仍然有资源的浪费。
*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> temp;
        //sort(candidates.begin(),candidates.end()); // 排序避免重复搜索
        combin(candidates,target,0,temp,ret);
        return ret;
    }

    void combin(vector<int>& candidates, int target, int index, vector<int> &temp, vector<vector<int>>& ret) {
        if (target < 0) return;
        else if (target == 0) ret.push_back({temp});
        else {
            for (int i=index; i<candidates.size(); i++) {
                temp.push_back(candidates[i]);
                combin(candidates,target-candidates[i],i,temp,ret); // 仍然有浪费？
                temp.pop_back();
            }
        }
    }
};
// @lc code=end
