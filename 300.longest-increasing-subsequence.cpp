/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence

方法一：最基础的动规。 O(n2)
执行用时 :
84 ms, 在所有 C++ 提交中击败了34.82%的用户
内存消耗 :
7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int max_len = 1;
        for (int i = 1; i<nums.size();++i){
            int max_num = 1;
            for (int j=0;j<i;++j) {
                if (nums[j]<nums[i]) {
                    max_num = max(max_num, dp[j]+1);
                }
            }
            dp[i] = max_num;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
// @lc code=end

