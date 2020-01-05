/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 * 
 方法一：
 169/169 cases passed (20 ms)
Your runtime beats 74.07 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (12.3 MB)
 https://www.cnblogs.com/grandyang/p/4370601.html
注意对于vector<vector<int>>的sort方法的可拓展性！！
参见：https://stackoverflow.com/questions/14419520/sort-vector-of-vectors
可以在外面定义一个比较函数（或者cost)函数，也可以采用匿名函数的形式直接传进sort.
（如果不指定比较函数的话，默认采用第一位元素大小进行比较）
另外：intervals.empty() 这个要会用！不要每次都用.size()==0来判断空。

知识点一：关于匿名函数或者lambda函数的更多讨论可见此贴：
https://www.cnblogs.com/pzhfei/archive/2013/01/14/lambda_expression.html

知识点二：push_back和emplace_back的区别：（后者更高效，前提是容器里的元素自带构造函数）
https://blog.csdn.net/zhouguoqionghai/article/details/47414551
以后都用emplace_back替代push_back吧! (还可以用emplace替代insert)

其他方法：官网上还给出了一个图算法，但是代码比较冗长。也许是个不错的模板。（尚未仔细阅读）
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool static sortFunc(const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
    } // 必须加static，否则报错。如果把该函数放到merge1函数内则不需要static

    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), sortFunc);
        //sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];}); //匿名函数也可以。
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return merge1(intervals);
    }
};
// @lc code=end

