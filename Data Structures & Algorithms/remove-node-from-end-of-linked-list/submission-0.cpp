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
        // 1. reverse the list
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr; // cannot assign nextNode = head->next, otherwise it will be nullptr->next
        while (currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode; 
        }
        head = prevNode; // save the new head so it can reverse back

        // 2. find the node
        ListNode* target = head;
        prevNode = nullptr;
        for(int i = 0; i < n - 1; i++) {
            prevNode = target;
            target = target->next;
        }

        // 3. remove the node
        nextNode = target->next;
        if(!prevNode) {
            head = nextNode;
        }   else {
            prevNode->next = nextNode;
        }
        delete target;
        

        // 4. reverse the list again
        currNode = head;
        prevNode = nullptr;
        nextNode = nullptr;
        while (currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode; 
        }
        return prevNode;
    }
};
