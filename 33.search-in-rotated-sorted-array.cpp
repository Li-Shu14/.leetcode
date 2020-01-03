/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>
using namespace std;
class Solution {
public:
/*
√ Accepted
  √ 196/196 cases passed (4 ms)
  √ Your runtime beats 80.78 % of cpp submissions
  √ Your memory usage beats 74.7 % of cpp submissions (8.8 MB)
  从左向右，如果左边的点比右边的点小，说明这两个点之间是有序的。如果左边的点比右边的点大，说明中间有个旋转点，所以一分为二后，肯定有一半是有序的。所以还可以用二分法。不过先要判断左边有序还是右边有序，如果左边有序，则直接将目标与左边的边界比较，就知道目标在不在左边，如果不在左边肯定在右边。
  仍然是变体二分法：每次从中分开，先判断哪边有序，然后判断有序的这一边是否包含目标值（比较边界很方便），然后继续循环。
  https://www.cnblogs.com/zle1992/p/8996225.html
*/
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n -1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == target) return mid;

            if (nums[lo] <= nums[mid]) { //左半有序
                if (nums[lo] <= target && target <= nums[mid]) {
                    hi = mid - 1; // 目标值在左半边
                }
                else {
                    lo = mid + 1;
                }
            }
            else { //右半有序
                if (nums[mid] <= target && target <= nums[hi]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        return -1; 
    }
};

