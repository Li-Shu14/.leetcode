/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
/*
  ✔ Your runtime beats 15.23 % of cpp submissions
  ✔ Your memory usage beats 93.73 % of cpp submissions (9.2 MB)
  Written by others
*/
        vector<int> v;
        for (int i=0; i < nums.size();i++){
            for (int j=i+1; j < nums.size();j++){
                if (nums[i]+nums[j]==target) {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
/*
  ✔ Your runtime beats 92.54 % of cpp submissions
  ✔ Your memory usage beats 57.22 % of cpp submissions (9.8 MB)
  Written by others
*/
		vector<int> v(2,0);
		// val+id
		unordered_map<int, int> hash;
		// we can search num and insert it to hash map at same time
		// and current num must be not in hash map
		for (int i = nums.size(); i--; hash[nums[i]] = i) //注意hash[nums[i]] = i是在循环结束时执行。美极了！
		{
			if (hash.find(target - nums[i]) == hash.end())
				continue;
			v[0] = i;           // the index from 0 to n-1
			v[1] = hash[target - nums[i]];
			return v;
		}
		return v;                   // no answer return {0,0}
	}
    vector<int> twoSum(vector<int>& nums, int target) {
		return twoSum1(nums, target);
	}
};


