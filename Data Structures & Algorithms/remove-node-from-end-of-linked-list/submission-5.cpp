/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        // establish the window according to n, if n = 1, windows size will be 2, because we will account for node deletion
        while(n > 0 && right) {
            right = right->next;
            n--;
        }

        // shift the window to the end;
        while(right) {
            right = right->next;
            left = left->next;
        }

        // delete the desired node
        ListNode* target = left->next;
        left->next = left->next->next;
        delete target; // prevent memory leak
        
        ListNode* newHead = dummy->next;
        delete dummy; // prevent memory leak
        return newHead;
    }
};
