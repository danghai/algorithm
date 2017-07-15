# Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

1. First way: 

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(0);
        ListNode * current = result;
        while(1)
        {
            if (l1 == NULL)                 // If list1 null --> Take all element in list2
            {
                current -> next = l2;
                break;
            }
            else if (l2 == NULL)            // list 2 null --> take all element in list1
            {
                current -> next = l1;
                break;
            }
            else
            {
                if (l1 -> val <= l2 -> val) 
                {
                    current -> next = l1;
                    current = current -> next;
                    l1 = l1 -> next;
                }
                else
                {    
                    current -> next = l2;
                    l2 = l2 -> next;
                    current = current -> next;
                }
            }
        }
        result = result -> next;
        return result;
    }
};

```

2. Second way: Recursion

```C++
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

```
