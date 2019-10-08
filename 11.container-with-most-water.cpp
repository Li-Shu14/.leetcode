/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea1(vector<int> & height) {
/*
time limit exceeded!
*/
        int maxcon = 0, con = 0;
        int len = 0;
        len = height.size();
        cout<<len<<endl;
        for (int i=0; i<len;++i) { 
            for (int j = i+1; j<len;++j) {
                con = (j-i)*min(height[i],height[j]);
                maxcon = max(maxcon,con);
            }
        }
        return maxcon;
    }

    int maxArea2(vector<int> & height) {
/*
    ✔ 50/50 cases passed (20 ms) O(n)
  ✔ Your runtime beats 65.45 % of cpp submissions
  ✔ Your memory usage beats 100 % of cpp submissions (9.7 MB)
Approach 2: Two Pointer Approach 该方法的证明过程和思想请参考leetcode网站本题的讨论区。
*/
        int maxcon = 0, l = 0, r = height.size()-1;
        while(l<r) {
            maxcon = max(maxcon, min(height[l],height[r])*(r-l));
            if (height[l] <height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxcon;
    }

    int maxArea(vector<int> & height) {
        return maxArea2(height);
    }
};

