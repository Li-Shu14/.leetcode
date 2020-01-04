/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 
 方法一：动态规划
 × Time Limit Exceeded
  × 74/75 cases passed (N/A)
  最后一个测试样例是从25000一直递减到0的一个长度为25003的数组。（最后几位是 3，2，1，1，0，0）
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        flag[nums.size()-1] = true;
        jump(nums,flag);
        return flag[0];
    }
    void jump(vector<int>& nums, vector<bool>& flag) {
        for (int i = nums.size()-2; i >=0; --i) {
            if (nums[i]==0) continue;
            if (i + nums[i] >= nums.size() - 1){
                flag[i] = true;
                continue;
            }
            for (int j = i+1; j<=i+nums[i] ;++j) {
                if (flag[j]) {
                    flag[i] = true;
                    continue;
                }
            }
        }
    }
};

