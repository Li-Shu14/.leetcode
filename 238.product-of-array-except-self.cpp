/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
方法一：左右乘积列表
18/18 cases passed (36 ms)
Your runtime beats 96.76 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (10.6 MB)

方法二：方法一的空间优化，从o(n)->o(1)
18/18 cases passed (40 ms)
Your runtime beats 75.08 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (10.4 MB)
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> ret(n,1);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for (int i=1;i<n-1;++i) {
            left[i] = left[i-1]*nums[i];
            right[n-1-i] = right[n-i]*nums[n-1-i];
        }
        ret[0] = right[1];
        ret[n-1] = left[n-2];
        for (int i=1;i<n-1;++i) {
            ret[i] = left[i-1] * right[i+1]; 
        }
        return ret;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        // answer[i] contains the product of all the elements to the left
        // so the answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < n; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        // R contains the product of all the elements to the right
        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
            // For the index 'i', R would contain the 
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }
        return answer;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        return productExceptSelf2(nums);
    }

};
// @lc code=end

