/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array

方法一：使用小顶堆。
直接用优先级队列。（第三个参数默认为小于，即大顶堆）。传入“大于”，则是小顶堆。
32/32 cases passed (12 ms)
Your runtime beats 78.53 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.3 MB)
时间复杂度： O(Nlogk)； 空间复杂度： O(N)

方法二：quick select 快速选择算法（和快排同源）
32/32 cases passed (28 ms)
Your runtime beats 28.01 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.6 MB)
耗费时间需要优化。选取枢纽时需要随机选取， 以应对最坏算例（逆序）

在加入随机选取枢纽后速度大大提升！牛掰啊！
32/32 cases passed (8 ms)
Your runtime beats 97.86 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.5 MB)

方法三：
方法二的另一种写法。这种写法是我最熟悉的快排的写法。

注意high取size()及size()-1时的不同。（是否作为哨兵）
 */

// @lc code=start
// #include <priority_queue>
#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int findKthLargest2(vector<int>& nums, int k) {
        int high = nums.size();
        int low = 0;
        while (low < high) {
            int i = low;
            int j = high-1;
            if (high - low > 2) {
                int index = low + rand()%(high-low-1);
                swap(nums[low],nums[index]);
            }
            int pivot = nums[low];
            while (i <= j) {
                while (i <= j && nums[i] >= pivot) i++;
                while (i <= j && nums[j] < pivot) j--;
                if (i < j) swap(nums[i++],nums[j--]);
            }
            swap(nums[low],nums[j]);
            if (j == k-1) return nums[j];
            else if (j < k-1) low = j+1;
            else high = j;   
        }
        return 0;
    }

    int findKthLargest3(vector<int>& nums, int k) {
        int findKthLargest(vector<int>& nums, int k) {
        if (nums.size()==1) return nums[0];
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int i = low, j = high;
            if (high - low > 2) {
                int index = low + rand()%(high-low-1);
                swap(nums[low],nums[index]);
            }
            int pivot = nums[low];
            while (i < j) {
                while (i < j && nums[j] < pivot) j--;
                if (i<j) nums[i++] = nums[j];
                while (i < j && nums[i] >= pivot) i++;
                if (i < j) nums[j--] = nums[i];
            }
            nums[i] = pivot;
            if (i == k-1) return nums[i];
            else if (i < k-1) low = i+1;
            else high = i-1;   
        }
        return 0;
    }


    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest2(nums,k);
    }
};
// @lc code=end

