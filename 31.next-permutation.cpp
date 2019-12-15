/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
/*
一开始没看懂。但是看到网上解释后还是很好写的：
 8 4 7 6 5 3 1。从后往前找第一个不是升序排列的数字4（因为从高位到低位如果是按照递减排列，那么该数就是最大的数了），那么下一个比他大的数字在该位置上的数字应该大于4，故从后往前找第一个比他大的数5并交换位置，交换位置后，该位置的5已经保证了他要比之前的数字大了（即保证了交换位置后7 6 4 3 1是递减的），因此将其后的升序序列反序（反序后将原来递增的变成了递减的，即该序列对应的数字是最小的了），变成8 5 1 3 4 6 7。
原文链接：https://blog.csdn.net/aikudexue/article/details/88952069

注意：由此引入的vector元素交换和倒序的函数使用：
swap,iter_swap,reverse。后两者是针对iterator使用的。

reverse当然也可以手动写，就是两两交换而已。
Runtime: 8 ms, faster than 76.06% of C++ online submissions for Next Permutation.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Next Permutation.
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                for (int j = nums.size()-1; j > i; --j) {
                    if (nums[j] > nums[i]){
                        swap(nums[j],nums[i]);
                        reverse(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};

