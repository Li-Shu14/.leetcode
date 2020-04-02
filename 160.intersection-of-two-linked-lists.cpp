/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 

方法三：双指针法
45/45 cases passed (40 ms)
Your runtime beats 98.72 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (15.7 MB)
 */
#include<unordered_map>
using namespace std;
class Solution {
public:
    // ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    //     if (headA==NULL || headB==NULL) return NULL;
    //     unordered_map<ListNode *,int> m;
    //     ListNode* p1 = headA;
    //     ListNode* p2 = headB;
    //     while(p1!=NULL) {
    //         m.insert(p1,p1->val);
    //         p1 = p1->next;
    //     }
    //     while(p2!=NULL) {
    //         if (m.at(p2)!=NULL) return true;
    //         p2 = p2->next;
    //     }
    //     return false;
    // }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        unordered_set<ListNode *> m;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=NULL) {
            m.insert(p1);
            p1 = p1->next;
        }
        while(p2!=NULL) {
            if (m.find(p2)!=m.end()) return p2;
            p2 = p2->next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        bool flag1 = true, flag2 = true; // 还没跑完第一轮。
        while(true){
            if (p1!=p2) {
                p1 = p1->next;
                p2 = p2->next;
                if (p1==NULL) {
                    if (flag1) {
                        p1 = headB;
                        flag1 = false;
                    }
                    else return NULL;
                }
                if (p2==NULL) {
                    if (flag2) {
                        p2 = headA;
                        flag2 = false;
                    }
                    else return NULL;
                }
            }
            else return p1;
        }
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return getIntersectionNode2(headA,headB);
    }
};
// @lc code=end

