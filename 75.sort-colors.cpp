/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 方法一：最简单的双次遍历方法。
 87/87 cases passed (8 ms)
Your runtime beats 7.15 % of cpp submissions
Your memory usage beats 87.72 % of cpp submissions (8.6 MB)
方法二：三指针发，超级牛逼。来自官网解答
87/87 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 98.25 % of cpp submissions (8.5 MB)
https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode/
 */

// @lc code=start
class Solution {
public:
    void sortColors1(vector<int>& nums) {
        int a=0,b=0,c=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==0) a++;
            else if (nums[i]==1) b++;
            else c++;
        }
        for (int i=0;i<a;i++) {
            nums[i]=0;
        }
        for (int i=0;i<b;i++) {
            nums[i+a]=1;
        }
        for (int i=0;i<c;i++) {
            nums[i+a+b]=2;
        }
    }

    void sortColors2(vector<int>& nums) {
        // 对于所有 idx < p0 : nums[idx < p0] = 0
        // curr 是当前考虑元素的下标
        int p0 = 0, curr = 0;
        // 对于所有 idx > p2 : nums[idx > p2] = 2
        int p2 = nums.size() - 1;
        while (curr <= p2) {
            if (nums[curr] == 0) swap(nums[curr++], nums[p0++]);
            else if (nums[curr] == 2) swap(nums[curr], nums[p2--]);
            else curr++;
        }
    }

    void sortColors(vector<int>& nums) {
        return sortColors2(nums);
    }
};
// @lc code=end

