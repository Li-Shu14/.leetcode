/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL && l2==NULL) return NULL;
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *p = NULL;
        ListNode h(0);
        while(l1!=NULL || l2!=NULL) {
            if (l1==NULL || (l2!=NULL && l1->val >= l2->val)) {
                if (h.next == NULL) {
                    h.next = l2;
                    p = h.next;
                }
                else {
                    p->next = l2;
                    p = p->next;
                }
                l2 = l2->next;
                continue; //没有这个会有些错误。
            }
            if (l2==NULL || (l1!=NULL && l1->val < l2->val)) {
                if (h.next == NULL) {
                    h.next = l1;
                    p = h.next;
                }
                else {
                    p->next = l1;
                    p = p->next;
                }
                l1 = l1->next;
            }
        }
        return h.next;
    }
};
// @lc code=end

