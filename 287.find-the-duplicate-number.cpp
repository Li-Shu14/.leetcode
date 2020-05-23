/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
方法一：哈希表记录
执行用时 :
20 ms, 在所有 C++ 提交中击败了42.48%的用户
内存消耗 :
11 MB, 在所有 C++ 提交中击败了13.33%的用户

方法二：用set。
执行用时 :
56 ms, 在所有 C++ 提交中击败了5.77%的用户
内存消耗 :
12.8 MB, 在所有 C++ 提交中击败了6.67%的用户
真差劲啊······

方法三：
FLoyd算法。两阶段双指针法。（第一阶段快慢指针，第二阶段俩慢指针）

快慢指针题型说明：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/qian-duan-ling-hun-hua-shi-tu-jie-kuai-man-zhi-z-3/
这里回顾了141，142，287等题目。

转换成142题的思路。至于为什么可以这样转换。画个图看看。
具体来说如果这个数组里存在几个数自成环，那么假如没有重复数字，则从第0个元素开始找时，是不可能进入这个自环的，因此自环不影响本题的结论。

执行用时 :
16 ms, 在所有 C++ 提交中击败了63.77%的用户
内存消耗 :
10.8 MB, 在所有 C++ 提交中击败了13.33%的用户
 */

// @lc code=start
class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        vector<int> mem(nums.size()+1,0);
        for (int i = 0; i < nums.size(); ++i) {
            if (mem[nums[i]] == 1) return nums[i];
            else mem[nums[i]]++;
        }
        return 0;
    }
    int findDuplicate2(vector<int>& nums) {
        set<int> s;
        for (int i=0;i<nums.size();++i) {
            if (set.find(nums[i])!=set.end()) return nums[i];
            else set.insert(nums[i]);
        }
        return 0;
    }

    int findDuplicate3(vector<int>& nums) {
        int IS = 0, IF = 0; //index_slow, index_fast
        while (1) {
            IS = nums[IS];
            IF = nums[IF];
            IF = nums[IF];
            if (IS == IF) {
                IS = 0;
                break;
            }
        }
        while(IS != IF ) {
            IS = nums[IS];
            IF = nums[IF];
        }
        return IS;
    }
    int findDuplicate(vector<int>& nums) {
        return findDuplicate3(nums);
    }
};
// @lc code=end

