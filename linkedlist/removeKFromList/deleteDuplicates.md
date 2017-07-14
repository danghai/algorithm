# Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head -> next == NULL)
            return head;
        while(head->val == head -> next -> val) // Remove all duplicate at head
        {
            head  = head -> next;
            if(head -> next == NULL)
                return head;
        }
        
        ListNode *current = head;
        while(current -> next != NULL)
        {
            if(current -> val == current -> next -> val)
                current -> next = current -> next -> next;
            else
                current = current -> next;
        }
        return head;
    }
};
```
