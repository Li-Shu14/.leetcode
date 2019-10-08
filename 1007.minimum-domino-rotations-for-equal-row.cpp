/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
	int minDominoRotations1(vector<int>& A, vector<int>& B) {
/* 
84/84 cases passed (132 ms)
Your runtime beats 25.25 % of cpp submissions
Your memory usage beats 16.67 % of cpp submissions (32.6 MB)
感觉自己写这道题的时候真蠢啊···写出来的判定太多不好debug，花了很多时间。人工debug还是很重要的，不能每次都依靠IDE调试
*/
		vector<vector<int>*> aa(6, nullptr), bb(6, nullptr);
		int ret = -1;
		int temp_ret = -1;
		for (int j = 0; j<6; ++j) {
			aa[j] = new vector<int>;
			bb[j] = new vector<int>;
		}
		int len = A.size();
		for (int i = 0; i<len; ++i) {
			aa[A[i]-1]->push_back(i);
			bb[B[i]-1]->push_back(i);
		}
		for (int j = 0; j<6; ++j) {
			if (aa[j]->size() + bb[j]->size() < len) continue;
			int pa = 0, pb = 0;
			for (int i = 0; i<len; ++i) {
				if (pa<aa[j]->size() && aa[j]->at(pa) == i) {
					pa++;
                    if (pb < bb[j]->size() && bb[j]->at(pb) == i) pb++;
				}
				else if (pb<bb[j]->size() && bb[j]->at(pb) == i) {
					pb++;
				}
				else break;
				if (i == len - 1) {
					temp_ret = len - max(aa[j]->size(), bb[j]->size());
					ret = (ret > temp_ret) ? ret : temp_ret;
					//if (i == len - 1) ret = len - max(aa[j]->size(), bb[j]->size());
				}
			}
		}
		return ret;
	}
    int minDominoRotations2(vector<int>& A, vector<int>& B) {
/*
84/84 cases passed (136 ms)
Your runtime beats 20.25 % of cpp submissions
Your memory usage beats 83.33 % of cpp submissions (19 MB)
https://blog.csdn.net/weixin_41968820/article/details/88379766
*/
        vector<int> nums;
        int min=0;
        for(int i = 1; i <= 6; i++)
        {
            int changeA=0,changeB=0;
            for(int j = 0; j < A.size(); j++)
            {
                if(A[j] != i && B[j] !=i)
                {break;}
                if(A[j] == i && B[j] !=i)
                    changeB++;
                if(A[j] != i && B[j] ==i)
                    changeA++;
                if(j == A.size()-1)
                {
                    nums.push_back(i);
                    min = changeA<changeB?changeA:changeB;
                }
            }
        }
        if(nums.empty()) return -1;
        return min;
    }

        int minDominoRotations3(vector<int> &A,vector<int> &B) {
/*
84/84 cases passed (132 ms)
Your runtime beats 25.25 % of cpp submissions
Your memory usage beats 50 % of cpp submissions (19.2 MB)
https://blog.csdn.net/Cold_Sun_/article/details/100688013
*/
        vector<int> num(6),numa(6),numb(6);
        int length=A.size();
        for(int i=0;i<length;i++)
        {
            if(A[i]==B[i])
                num[A[i]-1]++;
            else
            {
                num[A[i]-1]++;
                num[B[i]-1]++;
                numa[B[i]-1]++;
                numb[A[i]-1]++;
            }
        }
        for(int i=0;i<6;i++)
        {
            if(num[i]==length)
                return min(numa[i],numb[i]);
        }
        return -1;
    }

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        return minDominoRotations2(A,B);
    }
};

// @lc code=end

