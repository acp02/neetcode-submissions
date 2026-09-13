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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) { // need fast->next so it makes sure it's not nullptr for next line
            fast = fast->next->next;
            slow = slow->next;
            if(fast == nullptr) return false;
            // fast = fast->next;
            // if(fast == nullptr) return false;
            if(fast == slow) return true;
        }
        return false;
    }
};
