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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;// think about post order, not pre or in order
        // go to the end of the list first;
        ListNode* newHead = reverseList(head->next);
        
        if(head->next == nullptr) { // This is only for the last node of the original list, locate the new head location
            newHead = head;
        }   else { // this is for reverse the normal node
            head->next->next = head;
            head->next = nullptr;
        }
        return newHead;
    }
};
