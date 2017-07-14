# Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        while (head -> val == val)    // Case element at head
        { 
            head = head -> next;
            if (head == NULL)
                return NULL;
        }
        ListNode * current = head;
        while(current -> next != NULL)
        {
            if(current -> next -> val == val)
                current -> next = current -> next -> next;            
            else            
               current = current -> next;            
        }
        if ((head -> next == NULL) && (head ->val ==  val)) 
            return NULL;
        else
            return head;
    }
};
```
