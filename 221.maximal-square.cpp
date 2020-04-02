/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 * 
 * 
方法二：dp 空间复杂度O(n2)，方法一是此法的优化版。
69/69 cases passed (20 ms)
Your runtime beats 75.95 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.8 MB)
 */

// @lc code=start
class Solution {
public:
    int maximalSquare1(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<int> dp(cols + 1,0);
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == 1) {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }

    int maximalSquare2(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int res = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        return maximalSquare2(matrix);
    }
};
// @lc code=end

