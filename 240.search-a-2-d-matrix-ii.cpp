/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
方法一：
O(n+m) O(1） 折线法
129/129 cases passed (116 ms)
Your runtime beats 34.29 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (10.9 MB)

其他采用二分的方法也值得探索。
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        int i = m - 1, j = 0;
        while (i>=0 && j <= n-1) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] >  target) i--;
            else j++;
        }
        return false;
    }
};
// @lc code=end

