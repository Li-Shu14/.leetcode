/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
本题是53题的变式。53方法四具有普适性。
dan

方法一：（leetcode官方解法）
https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/
184/184 cases passed (4 ms)
Your runtime beats 89.71 % of cpp submissions
Your memory usage beats 65 % of cpp submissions (9.2 MB)

方法二：（网上的某博客，这个方法看似是错误的，但它应该是有一定数学原理的！可以设计几组数据试试！）
再思考：假设数组中没有0，那么最终一定是这种情况：[A,B]，其中A是最大乘积子序列，内含偶数个负数，B最左侧是一个负数，且B仅有这一个负数。剩下的树乘积小于A.
或者是这种情况[B,A]，A是最大乘积子序列，B最右侧是一个负数且B仅有这一个负数。
如果有0，就一定要中断，否则应该尽可能多地吸收数据进来。正反两个方向各扫一遍保证了不会有遗漏。
https://blog.csdn.net/Zolewit/article/details/91401264
184/184 cases passed (4 ms)
Your runtime beats 89.71 % of cpp submissions
Your memory usage beats 77.5 % of cpp submissions (9.1 MB)

 */

// @lc code=start
class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        int maxProd = INT_MIN, imax = 1, imin = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){ 
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            
            maxProd = max(maxProd, imax);
        }
        return maxProd;
    }

int maxProduct2(vector<int>& nums) {
    int cur = 1;
    int maxProd = INT_MIN;
    for(int i=0;i<nums.size();++i){
        cur*=nums[i];
        maxProd=(cur>maxProd) ? cur : maxProd;
        cur=(nums[i]==0)?1:cur;
    }
    cur=1;
    for(int i=nums.size()-1;i>=0;--i){
        cur*=nums[i];
        maxProd=(cur>maxProd) ? cur : maxProd;
        cur=(nums[i]==0)?1:cur;
    }
    return maxProd;
}

int maxProduct(vector<int>& nums) {
    return maxProduct1(nums);
}

};
// @lc code=end

