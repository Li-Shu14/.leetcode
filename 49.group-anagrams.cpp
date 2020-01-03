/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 方法一：
   √ 101/101 cases passed (52 ms)
  √ Your runtime beats 37.47 % of cpp submissions
  √ Your memory usage beats 86.57 % of cpp submissions (18.9 MB)
 https://leetcode-cn.com/problems/group-anagrams/solution/cji-jian-shi-xian-fu-jie-guo-he-si-lu-by-haru-8/
 方法二：
 √ Accepted
  √ 101/101 cases passed (56 ms)
  √ Your runtime beats 29.85 % of cpp submissions
  √ Your memory usage beats 7.46 % of cpp submissions (25.2 MB)
方法一的改良：把nlogn的排序过程替换成了一个计算字母出现次数的O(n)的算法。竟然变得这么差？！
方法三：
√ Accepted
  √ 101/101 cases passed (52 ms)
  √ Your runtime beats 37.47 % of cpp submissions
  √ Your memory usage beats 7.46 % of cpp submissions (24.5 MB)
  在方法二基础上将key从一个vector换成string，速度快了一些，但是空间效率仍然很差。
方法四：
  √ Accepted
  √ 101/101 cases passed (40 ms)
  √ Your runtime beats 79.52 % of cpp submissions
  √ Your memory usage beats 8.96 % of cpp submissions (24.3 MB)
基于方法三，把map换成unordered_map，时间效率惊人地提高了！因为unordered_map才是真正的hashmap
方法五：
√ Accepted
  √ 101/101 cases passed (36 ms)
  √ Your runtime beats 92.09 % of cpp submissions
  √ Your memory usage beats 92.54 % of cpp submissions (17.9 MB)
  转换为质数乘法作为key，效率真特么高！
  注意需要控制int范围：单纯的int（或者long==int)无法满足要求，需要用unsigned int。
  如果把unordered_map转换为map则总时间为40ms，只能打败79.52 %的人。
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        map<string,vector<string> > ma;
        vector<vector<string>> res;
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            ma[tmp].push_back(str);
        }
        for(const auto& m:ma)
            res.push_back(m.second);
        return res;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        map<vector<int>,vector<string>> ma; //这里用unordered_map会报错。因为vector不能作为key，除非像方法三一样转换为字符串
        vector<vector<string>> res;
        for(auto str:strs){
            vector<int> tmp(26,0);
            for (auto c : str){
                tmp[c-'a'] = tmp[c-'a'] + 1;
            }
            ma[tmp].push_back(str);
        }
        for(const auto& m:ma)
            res.push_back(m.second);
        return res;
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        map<string,vector<string>> ma;
        vector<vector<string>> res;
        for(auto str:strs){
            vector<int> tmp(26,0);
            for (auto c:str){
                tmp[c-'a'] = tmp[c-'a']+1;
            }
            string tmp_str;
            for (int i=0;i<26;++i) {
                tmp_str+=(char)tmp[i];
            }
            ma[tmp_str].push_back(str);
        }
        for(const auto& m:ma)
            res.push_back(m.second);
        return res;
    }

    vector<vector<string>> groupAnagrams4(vector<string>& strs) {
        unordered_map<string,vector<string>> ma;
        vector<vector<string>> res;
        for(auto str:strs){
            vector<int> tmp(26,0);
            for (auto c:str){
                tmp[c-'a'] = tmp[c-'a']+1;
            }
            string tmp_str;
            for (int i=0;i<26;++i) {
                tmp_str+=(char)tmp[i];
            }
            ma[tmp_str].push_back(str);
        }
        for(const auto& m:ma)
            res.push_back(m.second);
        return res;
    }

    vector<vector<string>> groupAnagrams5(vector<string>& strs) {
        vector<int> unique{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        unordered_map<unsigned int,vector<string>> ma;
        vector<vector<string>> res;
        for(auto str:strs){
            unsigned int tmp = 1;
            for (auto c:str){
                tmp = tmp * unique[c-'a'];
            }
            ma[tmp].push_back(str);
        }
        for(const auto& m:ma)
            res.push_back(m.second);
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return groupAnagrams5(strs);
    }
};

