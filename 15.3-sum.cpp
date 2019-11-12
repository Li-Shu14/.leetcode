#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum1(vector<int>& nums) {
/*
runtime error......
hashmap

*/
    	vector<vector<int>> ret;
		quicksort(nums, 0, nums.size() - 1);
        //sort(num.begin(),num.end()); //在算法不要求手写快排的时候还是推荐这种方式。
		int offset;
		offset = (nums[0]<0) ? -nums[0] : 0;
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] += offset;
		}
		//int map[nums[nums.size()]];这样是不对的，其长度必须为定值。
		int* map = new int[nums[nums.size() - 1]+1]{ 0 };
		for (int i = 0; i < nums.size(); ++i) {
			map[nums[i]] += 1;
			cout << map[nums[i]] << endl;
        }
		int lasti = -1,int lastj = -1;
		for (int i = 0; i <nums.size(); ++i) {
			if (nums[i] == lasti) continue;
			map[nums[i]] -= 1; //取出
			for (int j = i + 1; j< nums.size(); ++j) {
				if (nums[j] == lastj) continue;
				map[nums[j]] -= 1; //取出
				int res = 3 * offset - nums[i] - nums[j];
				if (res <= nums[nums.size() - 1] && res >= nums[j] && map[res]> 0) {
					vector<int> temp { nums[i] - offset,nums[j] - offset, res-offset };
					ret.push_back(temp);
				}
				map[nums[j]] += 1; //放回
				lastj = nums[j];
			}
			map[nums[i]] += 1; //放回
			lasti = nums[i];
		}
        delete []map;
		return ret;

    vector<vector<int>> threeSum1(vector<int>& nums) {
/* 推荐！双指针法！o(NlogN) + o(n2)的时间福复杂度
Runtime: 100 ms, faster than 71.54% of C++ online submissions for 3Sum.
Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for 3Sum.
参考地址：https://www.cnblogs.com/wangkundentisy/p/9079622.html 原文的方法二太啰嗦了，我简化了写法。
*/
        vector<vector<int>> rs;
        int len = nums.size();
        if(len == 0) return rs;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len; i++) {
            int j = i + 1, k = len - 1;
            if(i != 0 && nums[i] == nums[i - 1]) continue;//避免重复考虑
            while(j < k) {//对于每一个num[i]从i之后的元素中,寻找对否存在三者之和为0的情况
                if(nums[i] + nums[j] +nums[k] == 0) {//当三者之和为0的情况
                    rs.push_back({nums[i],nums[j++],nums[k--]}); //可以直接这样初始化！！！好方便啊！
                    while(j < k && nums[j] == nums[j - 1])  j++;//避免重复考虑
                    while(j < k && nums[k] == nums[k + 1])  k--;//避免重复考虑       
                }
                else if(nums[i] + nums[j] + nums[k] < 0) j++;//num[j]太小，需要向后移动
                else k--; //num[k]太大，需要向前移动
            }
        }
        return rs;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSum1(nums);
	}

private:
	void quicksort(vector<int> &a, int start, int end) {
		if (start >= end) return;
		int i = start, j = end, pivot = a[i];
		while (i < j) {
			while (a[j] >= pivot && i < j) j--;
			if (i < j) a[i++] = a[j];
			while (a[i] < pivot  && i < j) i++;
			if (i < j) a[j--] = a[i];
		}
		a[i] = pivot;
		quicksort(a, start, i - 1);
		quicksort(a, i + 1, end);
	}
};


