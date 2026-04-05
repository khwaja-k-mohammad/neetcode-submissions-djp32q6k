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
        
        int totalNodes = 0;

        ListNode *temp = head;

        while(temp) {
            totalNodes += 1;
            temp = temp -> next;
        }

        ListNode *dummy = new ListNode();
        dummy -> next = head;

        temp = dummy;
        for(int i=0;i<totalNodes - n;i++) temp = temp -> next;

        ListNode *nextNode = temp -> next -> next;

        temp -> next = nextNode;

        return dummy -> next;
    }
};
