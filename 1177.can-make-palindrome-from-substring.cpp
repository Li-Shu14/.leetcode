/*
 * @lc app=leetcode id=1177 lang=cpp
 *
 * [1177] Can Make Palindrome from Substring
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<bool> canMakePaliQueries1(string s, vector<vector<int>>& queries) {
/*
超时
*/
        vector<bool> ret;
        for (vector<vector<int>>::iterator q = queries.begin(); q != queries.end();++q) {
			int len = q->at(1)+1 - q->at(0);
			string str = s.substr(q->at(0), len);
            int count = 0;
            vector<int> vec(26,0);
            for (int i =0;i<len;++i) {
                vec[str[i]-'a']++;
            }
            for (int i =0;i<26;++i) {
                count += (vec[i]%2);
            }
            ret.push_back((count-(len%2))/2<=q->at(2));
        }
        return ret;
    }
    vector<bool> canMakePaliQueries2(string s, vector<vector<int>>& queries) {
/*
Runtime: 372 ms, faster than 36.52% of C++ online submissions for Can Make Palindrome from Substring.
Memory Usage: 120.2 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
leetcode讨论区：flameshimmer :C++ easy to understand
*/
        vector<vector<int>> maps;
        vector<int> map(26, 0);
        maps.push_back(map);
        for (char c : s) {
            map[c - 'a']++;
            maps.push_back(map);
        }
        vector<bool> result;
        for (vector<int>& q : queries) {
            int low = q[0];
            int high = q[1];
            int k = q[2];
            int diff = 0;
            int oddCount = 0;
            for (int i = 0; i < 26; i++) {
                diff = maps[high + 1][i] - maps[low][i];
                oddCount += diff % 2;
            }
            result.push_back(oddCount / 2 <= k);
        }
        return result;
    }

    vector<bool> canMakePaliQueries3(string s, vector<vector<int>>& queries) {
/*
Runtime: 276 ms, faster than 61.96% of C++ online submissions for Can Make Palindrome from Substring.
Memory Usage: 64.2 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
leetcode讨论区：woziji :C++ solution
*/
        int mask = 0;
        vector<int> stats = {0};
        for (int i = 0; i < s.size(); ++i) {
            mask ^= (1 << (s[i]-'a'));
            stats.push_back(mask);
        }
        vector<bool> result;
        for (int i = 0; i < queries.size(); ++i) {
            int temp = (stats[queries[i][1]+1] ^ stats[queries[i][0]]);
            int counter = 0;
            for (int j = 0; j < 26; ++j)
                if ((temp >> j) & 1 == 1)
                    ++counter;
            result.push_back(queries[i][2] >= counter/2);      
        }
        return result;
    }

    vector<bool> canMakePaliQueries4(string s, vector<vector<int>>& queries) {
/*
Runtime: 424 ms, faster than 25.95% of C++ online submissions for Can Make Palindrome from Substring.
Memory Usage: 112.3 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
https://blog.csdn.net/reigns_/article/details/100744896
*/
        int n = queries.size();
        int l = s.length();
        vector<bool> res;
        vector<vector<int>> cnt(l + 1, vector<int>(26, 0));
        for (int i = 1; i <= l; i++) {
           cnt[i] = cnt[i - 1];
           cnt[i][s[i - 1] - 'a'] = cnt[i - 1][s[i - 1] - 'a'] + 1;
        }
        for (int i = 0; i < n; i++) {
            int dif = 0;
            for (int j = 0; j < 26; j++) {
                if ((cnt[queries[i][1] + 1][j] - cnt[queries[i][0]][j]) % 2 != 0){
                    dif++;
                }
            }
            dif /= 2;
            if (queries[i][2] >= dif) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }

    vector<bool> canMakePaliQueries5(string s, vector<vector<int>>& queries) {
/*
Runtime: 288 ms, faster than 53.67% of C++ online submissions for Can Make Palindrome from Substring.
Memory Usage: 62.6 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
https://blog.csdn.net/reigns_/article/details/100744896
采用位运算
*/
        int n = queries.size();
        int l = s.length();
        vector<bool> res;
        vector<int> cnt(l + 1, 0);
        for (int i = 1; i <= l; i++) {
           cnt[i] = cnt[i - 1] ^ (1 << s[i - 1] - 'a');
        }
        for (int i = 0; i < n; i++) {
            int dif = 0;
            int x = cnt[queries[i][1] + 1] ^ cnt[queries[i][0]];
            while (x != 0) {
                if (x & 1 != 0) {
                    dif++;
                }
                x >>= 1;
            }
            dif /= 2;
            if (queries[i][2] >= dif) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }


    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        return canMakePaliQueries4(s,queries);
    }
};
// @lc code=end

