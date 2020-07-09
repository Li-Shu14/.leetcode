/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 * 
方法一：双指针法（我独立想出来的！）
执行用时 :
4 ms, 在所有 C++ 提交中击败了97.03%的用户
内存消耗 :
8.1 MB, 在所有 C++ 提交中击败了100.00%的用户

 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0) return {0};
        if (num==1) return {0,1};
        
        vector<int> ret(num+1,0);
        ret[1] = 1;
        int j = 1;
        for (int i = 2; i<num+1; i++) {
            if ((i & i-1) == 0) { // 是2的整数幂
                ret[i] = 1;
                j = 1;
            }
            else ret[i] = ret[j++] + 1;
        }
        return ret;
    }

    vector<int> countBits(int num) {
        vector<int> ans(num + 1,0);
        for (int i = 1; i <= num; ++i) {
            ans[i] = ans[i >> 1] + (i & 1); // x / 2 is x >> 1 and x % 2 is x & 1
        }
        return ans;
  }
};
// @lc code=end

