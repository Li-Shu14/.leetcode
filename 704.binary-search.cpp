/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
using namespace std;
/*
方法一超时？？
方法二就没问题···
*/
class Solution {
public:
    int search1(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        if (nums[l] == target) return l;
        return -1;
    }
    int search2(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
        mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
        }
        return -1;
    }   
    
    int search(vector<int>& nums, int target) {
        return search2(nums, target);
    }
};
// @lc code=end

int search(vector<int> & a, int target) {
    int l=0,r=a.size(),mid;
    while(l<=r) {
        mid = (l+r) >> 1;
        if (target == a[mid]) return mid;
        else if (target < a[mid]) r = mid-1;
        else  l = mid+1;
    }
    return -1;
}
