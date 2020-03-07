/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */


// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        for (int i=2;i<n;i++){
            a.push_back(a[i-1]+a[i-2]);
        }
        return a[n-1];
    }
};
// @lc code=end

