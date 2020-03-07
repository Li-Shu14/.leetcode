/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
方法一： 简单扩充,循环枚举
10/10 cases passed (4 ms)
Your runtime beats 97.78 % of cpp submissions
Your memory usage beats 94.92 % of cpp submissions (9 MB)

方法二： 利用位运算
10/10 cases passed (8 ms)
Your runtime beats 58.34 % of cpp submissions
Your memory usage beats 86.44 % of cpp submissions (9.1 MB)

方法三：回溯法
10/10 cases passed (4 ms)
Your runtime beats 97.78 % of cpp submissions
Your memory usage beats 52.54 % of cpp submissions (9.3 MB)
https://leetcode-cn.com/problems/subsets/solution/liang-chong-fang-fa-qiu-jie-zi-ji-by-tangzixia/

方法四：DFS
10/10 cases passed (8 ms)
Your runtime beats 58.34 % of cpp submissions
Your memory usage beats 10.17 % of cpp submissions (17.7 MB)
出处同上

方法五：二叉树深度搜多
10/10 cases passed (20 ms)
Your runtime beats 9.67 % of cpp submissions
Your memory usage beats 8.48 % of cpp submissions (17.8 MB)
https://leetcode-cn.com/problems/subsets/solution/ji-bai-996-4msyong-shi-er-cha-shu-shen-sou-fang-fa/
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        if (nums.size()==0) return res;
        for (int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                res.push_back(res[j]);
                res[res.size()-1].push_back(nums[i]);
            }
        }
        return res;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        int S = nums.size();
        int N = 1 << S;
        vector<vector<int> > res;
        for (int i = 0; i < N; ++i) {
            vector<int> v;
            for (int j = 0; j < S; ++j)
                if (i & (1 << j))
                    v.push_back(nums[j]);
            res.push_back(v);
        }
        return res;
    }

    vector<vector<int>> subsets3(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        backtracking(res,tmp,nums,0);
        return res;
    }
    void backtracking(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
        if(tmp.size()<=nums.size()){
            res.push_back(tmp);
        }
        for(int i=level;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtracking(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }    

    vector<vector<int>> subsets4(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        DFS(res, tmp, nums, 0);
        return res;
    }
    void DFS(vector<vector<int> >& res, vector<int> tmp, vector<int>& nums, int level) {
        if (level >= nums.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[level]);
        DFS(res, tmp, nums, level + 1);
        tmp.pop_back();
        DFS(res, tmp, nums, level + 1);
    }

    vector<vector<int>> subsets5(vector<int>& nums) {
        result.push_back({});
        treeDFS(0, nums, {});
        return result;
    }
    vector<vector<int>> result;
    void treeDFS(int i, vector<int> &nums, vector<int> &&item){
        if(i>=nums.size()){
            return;
        }
        treeDFS(i + 1, nums, PushBack(item, nums[i]));
        result.push_back(item);
        treeDFS(i + 1, nums, PoPBack(item));
    }

    vector<int> PushBack(vector<int> &item,int num){
        item.push_back(num);
        return item;
    }
    vector<int> PoPBack(vector<int> &item){
        item.pop_back();
        return item;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets5(nums);
    }
};
// @lc code=end

