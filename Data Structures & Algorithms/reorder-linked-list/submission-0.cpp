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
    ListNode* findMiddleNode(ListNode* head)
    {
        ListNode *slowPtr = head, *fastPtr = head;
        while(fastPtr && fastPtr -> next && fastPtr -> next -> next)
        {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }

        ListNode *middleNode = slowPtr -> next;
        slowPtr -> next = NULL;
        return middleNode;
    }

    ListNode *reverseList(ListNode* prev, ListNode *curr)
    {
        while(curr)
        {
            ListNode *temp = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    void merge2Lists(ListNode *head1, ListNode *head2)
    {
        while(head1 && head2)
        {
            ListNode *temp = head1 -> next;
            head1 -> next = head2;

            head2 = head2 -> next;
            head1 -> next -> next = temp;
            head1 = temp;
        }
    }

    void reorderList(ListNode* head) {
        
        // 1. Find the middle
        ListNode *middleNode = findMiddleNode(head);

        // 2. Reverse the second half
        ListNode *dummyNode = NULL;
        ListNode *secondHead = reverseList(dummyNode, middleNode);

        // 3. Merge 2 halfs
        merge2Lists(head, secondHead);
    }
};