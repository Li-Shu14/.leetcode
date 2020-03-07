/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
/*
  ✔ Your runtime beats 82.23 % of cpp submissions
  ✔ Your memory usage beats 75.12 % of cpp submissions (9.7 MB)
*/
        vector<int> vec; //维系一个临时向量
        vector<int>::iterator find_mem;
        int len = 0, max_len = 0, index = 0;
        for (int i=0;i<s.length();i++){
            find_mem = find(vec.begin( ),vec.end( ), s[i]); //查找
            if ( find_mem == vec.end() ) {
                vec.push_back(s[i]);
                len++;
            }
            else {
                // index = &*find_mem - &vec[0];
                vec.erase(vec.begin(),find_mem+1); //比如['a','n','f','y']这时又来了一个'f'就把从'a'到'f'清除掉，然后再push新的'f'
                vec.push_back(s[i]);                
                len = vec.size();
            }
            max_len = (len > max_len)? len : max_len;
        }
        return max_len;       
    }
    int lengthOfLongestSubstring2(string s) {
/*
  ✔ Your runtime beats 47.55 % of cpp submissions
  ✔ Your memory usage beats 91.04 % of cpp submissions (9.2 MB)
  此法不推荐
*/
        int hash[127];
        memset(hash,-1,sizeof(hash));
        int len = 0, max_len = 0, index = 0,num = 0,count = 0;
        for (int i=0;i<s.length();i++){
            num = int(s[i]);
            if ( hash[num] == -1 ) { //将方法一的find替换为了哈希表，优化查找速度，但最终速度竟然下降了？！
                hash[num] = i;
                len++;
            }
            else {
                int threshold = hash[num]+1;
                for (int j=0;j<127;j++){        
                    if (hash[j]<threshold and hash[j] != (-1)){
                        hash[j] = -1;
                        count++;
                        }
                }
                hash[num] = i;               
                len = len-count+1;
                count = 0;
            }
            max_len = (len > max_len)? len : max_len;
        }
        return max_len;       

    }

    int lengthOfLongestSubstring3(string s) {
/*
  ✔ Your runtime beats 94.31 % of cpp submissions
  ✔ Your memory usage beats 77.61 % of cpp submissions (9.5 MB)
  written by LuJJ
*/
        int l=s.length();
            if(l==0)
            {
                return 0;
            }
            int head=0,tail=-1;
            int maxl=0;
            int ans=0;
            bool *table=new bool[127];
            for(int i=0;i<127;i++)
            {
                table[i]=false;
            }
            while(tail<l-1)
            {
                if(table[s[tail+1]]==false)
                {
                    table[s[tail+1]]=true;
                    tail++;
                    maxl++;
                }
                if(ans<maxl)ans=maxl;
                if(table[s[tail+1]]==true)
                {
                    table[s[head]]=false;
                    head++;
                    maxl--;
                }
            }
            return ans;
    }
    int lengthOfLongestSubstring4(string s) {
/*
  ✔ Your runtime beats 20.35 % of cpp submissions
  ✔ Your memory usage beats 16.92 % of cpp submissions (15.9 MB)
  Written by others
*/
        set<char> t;
        int res = 0, left = 0, right = 0;
        while (right < s.size()) {
            if (t.find(s[right]) == t.end()) {
                t.insert(s[right++]);
                res = max(res, (int)t.size());
            }  else {
                t.erase(s[left++]);
            }
        }
        return res;
    }

    int lengthOfLongestSubstring5(string s) {
/*
  ✔ Your runtime beats 94.31 % of cpp submissions
  ✔ Your memory usage beats 67.66 % of cpp submissions (10.6 MB)
  Written by others 
  超级牛逼的O(n)算法
*/
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring5(s);
    }
};

