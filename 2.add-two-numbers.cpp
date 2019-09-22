/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
 */
#include <string>
# include <iostream>

using namespace std;

// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(NULL) {}
//   };

class Solution {
public:
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
/*
  ✔ Your runtime beats 63.61 % of cpp submissions
  ✔ Your memory usage beats 45.14 % of cpp submissions (10.5 MB)
*/
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    };


    ListNode *addTwoNumbers3(ListNode *l1, ListNode *l2) {
/*
  ✔ Your runtime beats 63.61 % of cpp submissions
  ✔ Your memory usage beats 92.57 % of cpp submissions (10.1 MB)
*/
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, *t=NULL;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            if (h==NULL){
                h = new ListNode(sum%10);
                t = h;
            }
            else{
                t->next = new ListNode(sum%10);
                t = t->next;
            }
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            t->next = node;
            t = t->next;
        }

        return h;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers2(l1, l2);
        // return s;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }

};


