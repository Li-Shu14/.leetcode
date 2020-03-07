/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number

方法一：
16/16 cases passed (24 ms)
Your runtime beats 27.4 % of cpp submissions
Your memory usage beats 19.75 % of cpp submissions (11.7 MB)
注意，我已开始遇到的问题是忘记在最后加上return 0。不加会报编译错误！编译器会认为如果循环没法进去，则循环体内的return有可能得不到执行。这样会导致整个函数没有return的风险。

方法二：异或算法！时间O(n),空间O(1)，官方解法。
16/16 cases passed (16 ms)
Your runtime beats 70.94 % of cpp submissions
Your memory usage beats 79.01 % of cpp submissions (9.7 MB)
https://leetcode-cn.com/problems/single-number/solution/yyxue-xi-bi-ji-7-by-yang-yang-yang-73/

方法三：哈希表
16/16 cases passed (24 ms)
Your runtime beats 27.4 % of cpp submissions
Your memory usage beats 11.11 % of cpp submissions (11.8 MB)
从map改成unordered_map之后：
16/16 cases passed (20 ms)
Your runtime beats 41.25 % of cpp submissions
Your memory usage beats 25.93 % of cpp submissions (11.4 MB)
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        unordered_map<int,int>a;
        for (int i = 0; i< nums.size(); ++i) {
            a[nums[i]]++;
        }
        for (int i = 0; i<nums.size(); ++i) {
            if (a[nums[i]]==1) return nums[i];
        }
        return 0;
    }

    int singleNumber2(vector<int>& nums) {
            //采用官方的异或操作
            int ans=nums[0];
            for(int i=1;i<nums.size();i++){
                ans=ans^nums[i];
            }
            return ans;
        }

    int singleNumber3(vector<int>& nums) {
        //类似官方哈希表方法，使用map键值对的方法来操作。
        //时间复杂度O(n),空间复杂度O(n)
        unordered_map<int,int>a;
        for(int i=0;i<nums.size();++i){
            if(a[nums[i]]==1) a.erase(nums[i]); // 如果存在该key,则说明该key截至目前出现了两次，不妨直接删掉。
            else a[nums[i]]++; // 如果不存在该key,则插入该元素并加到1.
        }
        unordered_map<int,int>::iterator it=a.begin();
        return it->first;
    }

    int singleNumber(vector<int>& nums) {
        return singleNumber3(nums);
    }


};
// @lc code=end

