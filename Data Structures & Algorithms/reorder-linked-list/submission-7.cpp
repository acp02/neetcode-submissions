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
    void reorderList(ListNode* head) {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) { //while(head && head->next) also work
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half of the list
        ListNode* second = slow->next; // second portion of the list
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        slow->next = nullptr;
        while(second) { // only focus on the second portion of the list, ask gemini for example if don't understand, or check reverse linked list easy question
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        
        // merge two list
        ListNode* first = head;
        second = prev;
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        while(second) { // think about odd and even numbers of elements of list
        // when it's odd number list, the loop exits because second will reach nullptr quicker than first. While we already assigned the last element->next = nullptr of the first portion in previus section, so the whole thing works
            temp1 = first->next;
            first->next = second;
            temp2 = second->next;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
