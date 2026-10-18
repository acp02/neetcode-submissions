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
        vector<ListNode*> listNode;
        while(head) { // don't use !head, which means only when head == nullptr, this while loop will run which is wrong
            listNode.push_back(head); // store all the nodes in the list
            head = head->next;
        }
        int left = 0;
        int right = listNode.size() - 1;
        while(left < right) {
            listNode[left]->next = listNode[right];
            left++;
            if(left == right) { // to avoid a cycle
                listNode[left]->next = nullptr; // for last node pointing to nullptr, the size of list is EVEN number
                break;
            }
            listNode[right]->next = listNode[left];
            right--;
            listNode[left]->next = nullptr; // for last node pointing to nullptr, the size of list is ODD number
        }
    }
};
