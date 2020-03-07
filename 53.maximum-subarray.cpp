/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include<vector>
using namespace std;

/*
方法一想的太多。失败了。总有案例跑不通：[8,-19,5,-4,20]
力扣说可以左右各扫一遍.改成双向后有越界错误。先放一放吧。

方法二：
来自力扣中文网。
202/202 cases passed (8 ms)
Your runtime beats 74.49 % of cpp submissions
Your memory usage beats 66.67 % of cpp submissions (9.3 MB)
该方法关键地成功规避了方法一各种令人头疼的问题：if (nums[i - 1] > 0) nums[i] += nums[i - 1];

方法三：贪心：
202/202 cases passed (8 ms)
Your runtime beats 72.27 % of cpp submissions
Your memory usage beats 66.67 % of cpp submissions (9.3 MB)

方法四：如果要输出这个子数组的起止位置呢？
https://blog.csdn.net/godric_star/article/details/77529908
这个代码有点像方法二和三的结合，也许能够反映这类问题的本质？
202/202 cases passed (4 ms)
Your runtime beats 98.61 % of cpp submissions
Your memory usage beats 31.37 % of cpp submissions (9.4 MB)


*/
class Solution {
public:
    int maxSubArray1(vector<int>& nums) {

        int l = nums.size();
        if (l==1) return nums[0];
        vector<int> s;
        vector<int> t;
        int r = 0;
        s.push_back(nums[0]);
        t.push_back(0);
        int temp1,temp2;
        for (int i = 1; i < l; ++i) {
            temp1 = s[i-1] + t[i-1] + nums[i];
            temp2 = t[i-1] + nums[i];
            if (s[i-1]>temp1 && s[i-1] > nums[i] && s[i-1] >temp2){
                t.push_back(t[i-1]+nums[i]);
                s.push_back(s[i-1]);
            }
            else {
                r = i;
                t.push_back(0);
                s.push_back(max(temp1,max(temp2,nums[i])));
            }
        }
        vector<int> s2;
        vector<int> t2;
        r = l-1;
        s2.push_back(nums[0]);
        t2.push_back(0);
        for (int i = 1; i < l; ++i) {
            temp1 = s[i-1] + t[i-1] + nums[l-1-i];
            temp2 = t[i-1] + nums[l-1-i];
            if (s[i-1]>temp1 && s[i-1] > nums[l-1-i] && s[i-1] >temp2){
                t.push_back(t[i-1]+nums[l-1-i]);
                s.push_back(s[i-1]);
            }
            else {
                r = l-1-i;
                t.push_back(0);
                s.push_back(max(temp1,max(temp2,nums[l-1-i])));
            }
        }
        return max(s[l-1],s2[l-1]);
    }


    int maxSubArray2(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0];
        for(int i = 1; i < n; ++i) {
            if (nums[i - 1] > 0) nums[i] += nums[i - 1];// 惊为天人的一个预处理！
            maxSum = max(nums[i], maxSum);
        }
        return maxSum;
    }

    int maxSubArray3(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0],currSum = nums[0];
        for(int i = 1; i < n; ++i) {
            currSum = max(nums[i], currSum + nums[i]);// 惊为天人的一个预处理！
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maxSubArray4(vector<int>& nums) { //其实把start、end去掉后简化可以成为方法三
        int maxSum = nums[0],currSum = nums[0];
        int start = 0, end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (currSum > 0) currSum += nums[i];
            else if (nums[i] > currSum) { //确定子数组起始位置
                start = i;
                currSum = nums[i];    //即使数组全为负，也能得到最大值
            } //为什么可以这么确定？有没有可能是，如果currSum>0,但还是需要改变start位置的情况呢？
            if (currSum > maxSum) { //确定子数组结束位置
                maxSum = currSum;
                end = i;
            }   
        }
        return maxSum;
    } 
    int maxSubArray(vector<int>& nums) {
      return maxSubArray4(nums);
  }

};
// @lc code=end

