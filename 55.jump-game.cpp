/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 
 方法一：动态规划
 × Time Limit Exceeded
  × 74/75 cases passed (N/A)
  最后一个测试样例是从25000一直递减到0的一个长度为25003的数组。（最后几位是 3，2，1，1，0，0）
  我的这个方法在LEETCODE上已经是出于比较优秀的方法了。详情可以看中文leetcode上对不断演进的几种算法的时空复杂度分析，挺有收获的。

方法二：回溯（来自leetcode官方解法） 回溯是低效的动态规划
 × Time Limit Exceeded
  × 74/75 cases passed (N/A)
错误同上。

方法三：贪心！
75/75 cases passed (12 ms)
Your runtime beats 72.02 % of cpp submissions
Your memory usage beats 92.11 % of cpp submissions (9.9 MB)
记录的是最后一个出现True的位置，这样空间就省了，时间也少了。时间o(n),空间o(1)
来自leetcode
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump1(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        flag[nums.size()-1] = true;
        jump1(nums,flag);
        return flag[0];
    }
    void jump1(vector<int>& nums, vector<bool>& flag) {
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

    bool canJump2(vector<int>& nums) {
        return canJumpFromPosition(0, nums);
    }
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) {
            return true;
        }
        int furthestJump =  (nums.size() - 1 <= position + nums[position]) ? nums.size() - 1 : position + nums[position];
        for (int nextPosition = furthestJump; nextPosition > position; nextPosition--) { // 遍历方向可能会有小小的优化
        //for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }
        return false;
    }

    bool canJump3(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }


    bool canJump(vector<int>& nums) {
        return canJump3(nums);
    }

};

