/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 * 
 方法一：动态规划。（思想还是labuladong的解法，但是他关于无穷次操作的解释不够好。原话为“如果 k 为正无穷，那么就可以认为 k 和 k - 1 是一样的”，但是我觉得解释是，当可以不限操作次数的时候，可以从概念上直接忽略当前操作的次数k这样一个参数，也是能够行的通的。
 所以不要盲目套用模板哦！
 这道题直接简单的用动态规划就行了呀！见方法二。
 方法一卡在测试案例[1,2]上面。

 方法二：更直接的动态规划。
201/201 cases passed (8 ms)
Your runtime beats 64.9 % of cpp submissions
Your memory usage beats 82.54 % of cpp submissions (9.5 MB)


方法三：abuladong的做法。
201/201 cases passed (8 ms)
Your runtime beats 64.9 % of cpp submissions
Your memory usage beats 84.13 % of cpp submissions (9.5 MB)

 */

// @lc code=start
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0; // 只有一位也会出问题
        if (n==2) return max(0,prices[1]-prices[0]);
        if (n==3) return max(0,max(prices[1]-prices[0],max(prices[2]-prices[1],prices[2]-prices[0])));
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n/2,vector<int>(2,0))); // 初始化三维数组
        int INT_MIN2 = -214748364; // 直接用INT_MIN再做一次减法就越界了。
        int max_k = n/2+1;
        // 初始化边界
        for (int i = 0; i < n; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN2;
        }
        
        for (int k = 1; k < max_k; ++k) {
            dp[0][k][0] = INT_MIN2;
            dp[0][k][1] = INT_MIN2;
        }
        dp[0][1][1] = -prices[0];

        // 递推
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k < max_k; ++k) {
                dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        int max_profit = 0;
        for (int k = 0; k< max_k; ++k) {
            max_profit = max(max_profit,dp[n-1][k][0]);
        }
        return max_profit;
    }

    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0; // 如果没有这句话会超时！！是哪里有影响呢！
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0]; //-prices[0];
        for (int i = 1; i < n; ++i) {
            int temp0 = dp_i_0;
            int temp1 = dp_i_1;
            dp_i_0 = max(temp0, temp1+prices[i]);
            dp_i_1 = max(temp1, temp0-prices[i]);
        }
        return dp_i_0;
    }

    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit3(prices);
    }
};
// @lc code=end

