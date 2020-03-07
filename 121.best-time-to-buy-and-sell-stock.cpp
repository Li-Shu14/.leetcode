/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
方法一：愚蠢的O(n2)方法。
200/200 cases passed (1224 ms)
Your runtime beats 5.01 % of cpp submissions
Your memory usage beats 14.68 % of cpp submissions (9.7 MB)

方法二：状态机（DP Table) 一个大佬的讲解，解决了这类题型。（包括122、123等好几道题）
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
200/200 cases passed (4 ms)
Your runtime beats 98.48 % of cpp submissions
Your memory usage beats 74.31 % of cpp submissions (9.6 MB)

方法三：
200/200 cases passed (8 ms)
Your runtime beats 70.36 % of cpp submissions
Your memory usage beats 5.51 % of cpp submissions (9.9 MB)
将求差问题转换为求和问题（有点像是导函数的积分等价于的原函数的做差）
！！即：原数组两个元素的最大差等于求差的数组的最大连续子数组和！！！ （leetcode 53 maximum subarray)
核心思想参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-dp-7-xing-ji/

方法四是方法三的精简版，节约了很多空间。代码直接来源于上述网址。
200/200 cases passed (8 ms)
Your runtime beats 70.36 % of cpp submissions
Your memory usage beats 53.21 % of cpp submissions (9.6 MB)

方法五：
200/200 cases passed (4 ms)
Your runtime beats 98.52 % of cpp submissions
Your memory usage beats 24.77 % of cpp submissions (9.7 MB)
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/dui-zhe-ge-ti-de-yuan-li-lai-ge-jian-dan-de-zheng-/
利用了直接关于本题的数学原理分析。分析过程见网址。
这个方法很直观很直观。也许是最推荐的！
 */

// @lc code=start
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:

    int maxProfit1(vector<int>& prices) {
        vector<int> sorted;
        sorted = prices;
        sort(sorted.begin(),sorted.end());
        int res = 0;     
        for (int c:sorted) {
            int index = find(prices.begin(),prices.end(),c) - prices.begin();
            for (int i = index+1; i < prices.size();++i){
                if (prices[i] - c > res) res = prices[i] - c;
            }
        }
        return res;
    }

    int maxProfit2(vector<int>& prices) {
        return maxProfit_k_1(prices);
    }

    int maxProfit_k_1(vector<int>& prices) {
        // 这是优化了空间复杂度的动态规划，完整版本可以参考网站。
        int n = prices.size();
        // base case: dp[-1][0] = 0, dp[-1][1] = -infinity
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            // dp[i][1] = max(dp[i-1][1], -prices[i])
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }

    int maxProfit3(vector<int>& prices) {
        if (prices.size()<=1) return 0;
        vector<int> nums;
        for (int i = 0; i < prices.size()-1; ++i) {
            nums.push_back(prices[i+1]-prices[i]);
        }
        return max(maxSubArray(nums),0);
    }


    int maxSubArray(vector<int>& nums) { // 来自leetcode 53
        int n = nums.size(), maxSum = nums[0],currSum = nums[0];
        for(int i = 1; i < n; ++i) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maxProfit4(vector<int>& prices) {
        if (prices.size()<=1) return 0;
        int currSum = 0, maxSum = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            int temp_num = prices[i+1] - prices[i];
            currSum = max(temp_num, currSum + temp_num);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }

    int maxProfit5(vector<int> prices) {
        int minimum = INT_MAX, maximum = 0;
        for (int i = 0; i < prices.size(); i++) {
            minimum = min(minimum,prices[i]);
            maximum = max(maximum,prices[i] - minimum);
        }
        return maximum;
    }



    int maxProfit(vector<int>& prices) {
        return maxProfit2(prices);
    }

};
// @lc code=end

