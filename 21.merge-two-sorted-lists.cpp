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
/*
208/208 cases passed (8 ms)
Your runtime beats 77.56 % of cpp submissions
Your memory usage beats 93.44 % of cpp submissions (8.8 MB)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL && l2==NULL) return NULL;
        ListNode *p = NULL;
        ListNode h(0);
        while(l1!=NULL || l2!=NULL) {  // 等价于  while(l1 || l2)
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

