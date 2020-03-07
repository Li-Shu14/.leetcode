/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
方法一：我写的快慢指针
14/17 cases passed (N/A)
有一个很长的case不会通过。

方法二：leetcode的快慢指针
17/17 cases passed (8 ms)
Your runtime beats 97.67 % of cpp submissions
Your memory usage beats 75 % of cpp submissions (9.8 MB)
 */


class Solution {
public:
    bool hasCycle1(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            if (slow==NULL) return false;
            fast = (fast->next)->next;
            if (fast!=NULL && fast == slow) return true;
        }
        return false;
    }

    bool hasCycle2(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

    bool hasCycle(ListNode* head) {
        return hasCycle1(head);
    }
};
// @lc code=end

