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

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *result = new ListNode();
        ListNode *temp = result;

        while(list1 && list2)
        {
            if(list1 -> val <= list2 -> val) {
                result -> next = list1;
                list1 = list1 -> next;
            }
            else {
                result -> next = list2;
                list2 = list2 -> next;
            }

            result = result -> next;
        }

        result -> next = list1 ? list1 : list2;

        return temp -> next;
    }

    ListNode *mergeLists(vector<ListNode*> &lists, int start, int end)
    {
        if(start >= end) return lists[start];
        int mid = (start + (end - start)/2);
        return merge(mergeLists(lists, start, mid), mergeLists(lists, mid+1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(!lists.size()) return NULL;
        return mergeLists(lists, 0, lists.size()-1);
    }
};