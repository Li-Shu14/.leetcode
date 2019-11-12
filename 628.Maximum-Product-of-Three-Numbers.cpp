#include <algorithm> 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        return maximumProduct2(nums);
    }
    
    int maximumProduct1(vector<int>& nums) {
/*
Runtime: 44 ms, faster than 93.42% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Maximum Product of Three Numbers.
考虑到负数的情况，其实也不难：排序后，返回array[n]*array[n-1]*array[n-2]和array[0]*array[1]*array[n]中的最大值。
这里手写了排序，基本是o(n)的方法。
*/
        vector<int> ma {-1001,-1001,-1001}, mi {1001,1001};
        for (int i=0;i<nums.size();++i) {
            if (nums[i] > ma[2]) {
                ma[2]=nums[i];
                check(ma);
            }
            if (nums[i] < mi[1]) {
                mi[1]=nums[i];
                check(mi);
            }    
        }
        return max(ma[2]*ma[1]*ma[0],mi[0]*mi[1]*ma[0]);
    }
    
    int maximumProduct2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return max(nums[n-1]*nums[n-2]*nems[n-3],nums[0]*nums[1]*nums[n-1]);
    }
    
    
    void swap(int& a,int &b) {
        int c = b;
        b = a;
        a = c;
    }
    void sort(vector<int>& ma) {
        if (ma[2]>ma[1]) swap(ma[2],ma[1]);
        if (ma[1]>ma[0]) swap(ma[1],ma[0]);
        if (ma[2]>ma[1]) swap(ma[2],ma[1]);
    }
    void check(vector<int>& ma) {
        if (ma.size()==3) {
            if (ma[2]>ma[1]) {
                swap(ma[2],ma[1]);
                if (ma[1]>ma[0]) {
                    swap(ma[1],ma[0]);
                }
            }
        }
        else {
            if (ma[1]<ma[0]) swap(ma[1],ma[0]);
        }
    }
};