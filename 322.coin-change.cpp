/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> count(amount,0);
        for (int i = 1; i < coins[0]; i++) {
            count[i] = -1;
        }
        count[0] = 0;
        sort(coins.begin(),coins.end());
        return dp(count, coins, amount);;
    }

    int dp(vector<int> & count, vector<int>& coins, int remain){
        if (remain == 0) return 0;
        if (remain > 0 && count[remain] > 0) return count[remain];

        min_value = INT_MAX;
        bool flag = false;
        for (int i=coins.size()-1;i>=0;--i) {
            if (remain >= coins[i]) {
                int temp = dp(count,coins,remain - coins[i]);
                if (temp != -1) {
                    int min_value = min(dp(count,coins,remain - coins[i]), min_value);
                    flag = true;
                }
                else continue;
            } 

        }
        if (flag) {
            count[remain] = min_value + 1;
            return count[remain];
        }
        return -1;
    }
};
// @lc code=end

