/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
// [0,0,0,0,1,1,2] target = 1
// [0,1,1,1,1,1,2] 
// @lc code=start
#include <vector>
using namespace std;
/*
方法一：
88/88 cases passed (12 ms)
Your runtime beats 34.47 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (10.2 MB)
官网打分：
Runtime: 4 ms, faster than 99.38% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
二分法的变体：边界软放缩。
注意整除的向下取整和向上取整应该是对称的，所以需要区分使用：
(l+r)>>1 和 (l+r+1)>>1
方法二：
88/88 cases passed (8 ms)
Your runtime beats 85.75 % of cpp submissions
Your memory usage beats 5.49 % of cpp submissions (10.7 MB)
来自leetcode官网。
P.S. 方法二的官网打分和VScode打分是一致的。但是方法一不一致。为什么呢？
*/
class Solution {
public:
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> ret {searchleft(nums,target),searchright(nums,target)};
        return ret;
    }

    int searchleft(vector<int>& a, int target) {
        int l = 0, r = a.size() - 1, mid;
        while(l<=r) {
            mid = (l+r) >> 1;
            if (l == r) {
                if (a[mid] == target) return mid;
                else return -1;
            }
            if (a[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return -1; //虽然感觉这句话没用。但是删掉会报错。具体原因可以继续分析。
    }

    int searchright(vector<int>& a, int target) {
        int l = 0, r = a.size() - 1, mid;
        while(l<=r) {
            mid = (l+r+1) >> 1;
            if (l == r) {
                if (a[mid] == target) return mid;
                else return -1;
            }
            if (a[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return -1;
    }
    //---------------------------------------------
    vector<int> searchRange2(vector<int>& nums, int target) {
        vector<int> ret {-1, -1};
        int leftIdx  = extremeInsertionIndex(nums,target,true);
        int rightIdx = extremeInsertionIndex(nums,target,false)-1;
        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.size() || nums[leftIdx] != target) return ret;
        ret[0] = leftIdx;
        ret[1] = rightIdx;
        return ret;
    }
    int extremeInsertionIndex(vector<int> a, int target, bool left) {
        int l = 0, r = a.size(), mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if (a[mid] > target || (left && target == a[mid])) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    //---------------------------------------------
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange1(nums,target);
    }
};
// @lc code=end

