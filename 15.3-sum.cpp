/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int i=0;i<nums.size()-2;++i) {
            for (int j=i+1;j<nums.size()-1;++j) {
                for (int k=j+1;k<nums.size();++k) {
                    if (nums[i]+nums[j]+nums[k]==0) {
                        vector<int> list = {nums[i],nums[j],nums[k]};
                        // vector<int> *a = new vector<int> a{nums[i],nums[j],nums[k]};
                        ret.push_back(list);
                    } 
                }
            }
        }
        return ret;
    }
};

