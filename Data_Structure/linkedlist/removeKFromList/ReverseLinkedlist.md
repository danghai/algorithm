# Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = NULL;
      while(head != NULL)
      {
          ListNode * next = head -> next;   // Take out the first node, next Node keep the rest of the node
          head -> next = pre;  // Put the head at the end;
          pre = head;           // Update the pre (reverse)
          head = next;          // Proceed to the new node
      }
        return pre;
    }
};
```
