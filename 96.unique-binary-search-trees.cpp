/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees

方法一：动态规划（启发来自于leetcode：G(n)函数）
19/19 cases passed (4 ms)
Your runtime beats 53.42 % of cpp submissions
Your memory usage beats 90.91 % of cpp submissions (8.2 MB)

方法二：方法二：数学演绎法
事实上 G(n)的值被称为 卡塔兰数​	
19/19 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.1 MB)

 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees1(int n) {
        if (n==0 || n ==1) return 1;
        vector<int> g;
        g.push_back(1); // g0 = 1
        g.push_back(1); // g1 = 1
        for (int i=2;i<=n;i++) {
            int temp_sum = 0;
            for (int j=0; j<i; ++j) {
                temp_sum+=g[j]*g[i-j-1];
            }
            g.push_back(temp_sum);
        }
        return g[n];
    }

    int numTrees2(int n) {
        long int C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) C;
    }
    int numTrees(int n) {
        return numTrees2(n);
    }
};
// @lc code=end

