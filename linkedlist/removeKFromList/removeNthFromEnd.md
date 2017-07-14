* Remove N th from the end
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        
        int count = 0 ; //  count number of number
        ListNode * current = head;
        while(current != NULL)
        {
            count++;
            current = current -> next;
        }
        current = head;
        // Traversal to the node previous
        
        if (count -n - 1 <0)   // Case: Delete at head (only 1 node in list)
        {
            head = head -> next;
            return head;
        }
        else
        {
            for (int i = 0 ; i< (count -n-1);i++)
                current = current -> next;
            
            if(current -> next == NULL)
                return NULL;
            else
            {
                current -> next = current -> next -> next; // remove it
                return head;
            }
        }
    }
};

```
