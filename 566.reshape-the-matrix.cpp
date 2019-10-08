/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape1(vector<vector<int>>& nums, int r, int c) {
/*
56/56 cases passed (36 ms)
Your runtime beats 60.97 % of cpp submissions
Your memory usage beats 8 % of cpp submissions (13.6 MB)
我还以为自己这种利用vector整体拷贝的功能会更快一些···
*/
        int r0 = nums.size(),c0 = nums[0].size();
        if (r0*c0 !=r*c) return nums;
        vector<int> mid;
        for (vector<vector<int>>::iterator vec = nums.begin();vec!=nums.end();vec++){
            mid.insert(mid.end(), vec->begin(), vec->end());
        }
        vector<vector<int>> ret;
        for (int i = 0 ;i < r;++i) {
            vector<int>* a = new vector<int>;
            a->assign(mid.begin()+c*i,mid.begin()+c*i+c);
            ret.push_back(*a);
        }
        return ret;
    }
    vector<vector<int>> matrixReshape2(vector<vector<int>>& nums, int r, int c) {
/*
56/56 cases passed (36 ms)
Your runtime beats 60.97 % of cpp submissions
Your memory usage beats 68 % of cpp submissions (11.7 MB)
https://www.cnblogs.com/grandyang/p/6804753.html
*/
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c)); //这种初始化方法是可行的！！
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int k = i * c + j; //将指标拉成直线！而不用真正的搞出一个一维vector！
                res[i][j] = nums[k / n][k % n];
            }
        }
        return res;
    }
    vector<vector<int>> matrixReshape3(vector<vector<int>>& nums, int r, int c) {
/*
56/56 cases passed (32 ms)
Your runtime beats 93.36 % of cpp submissions
Your memory usage beats 60 % of cpp submissions (11.7 MB)
https://www.cnblogs.com/grandyang/p/6804753.html
上一种方法的变种，更直接
*/
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; ++i) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        return matrixReshape1(nums,r,c);
    }
};
// @lc code=end

