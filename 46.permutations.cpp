/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;
/*
方法一：
25/25 cases passed (8 ms)
Your runtime beats 98.71 % of cpp submissions
Your memory usage beats 94.03 % of cpp submissions (9.2 MB)
一次过，回溯法果然牛逼。这道题基于39题的思路写的。
刚开始我以为对于vector的频繁的插入和删除指定位置元素的操作很费时，但是最后看来时间耗费也挺好。
方法二：
25/25 cases passed (8 ms)
Your runtime beats 98.71 % of cpp submissions
Your memory usage beats 94.03 % of cpp submissions (9.2 MB)
https://blog.csdn.net/Ethan95/article/details/84593429
该方法是我的方法一的改良，通过引入flag数组来标记nums里的元素是否被用到。避免了频繁的删除插入。
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute3(nums);
    }

    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        backtracking1(nums,ret,temp);
        return ret;
    }

    void backtracking1(vector<int>& nums, vector<vector<int>>& ret, vector<int>& temp){
        if (nums.size()==0) return ret.push_back(temp); 
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            backtracking1(nums,ret,temp);
            nums.insert(nums.begin()+i,temp[temp.size()-1]);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute2(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> temp;
		vector<bool> flags(nums.size(), false);
		backtracking2(nums, ret, temp, flags);
		return ret;
	}

	void backtracking2(vector<int>& nums, vector<vector<int>>& ret, vector<int>& temp, vector<bool>& flags) {
		if (nums.size() == temp.size()) ret.push_back(temp);
		else {
			for (int i = 0; i < nums.size(); ++i) {
				if (flags[i]) continue;
				temp.push_back(nums[i]);
				flags[i] = true;
				backtracking2(nums, ret, temp,flags);
				flags[i] = false;
				temp.pop_back();
			}
		}
	}

    vector<vector<int>> permute3(vector<int>& nums) {
		vector<vector<int>> ret;
		backtracking3(nums, ret, 0);
		return ret;
	}

	void backtracking3(vector<int>& nums, vector<vector<int>>& ret,int begin) {
		if (begin>=nums.size()) {
			ret.push_back(nums);
		}
		else {
			for (int i = begin; i < nums.size(); ++i) {
				swap(nums[begin], nums[i]);
				backtracking3(nums, ret, begin + 1);
				swap(nums[begin], nums[i]);
			}
		}
	}

};
// @lc code=end

