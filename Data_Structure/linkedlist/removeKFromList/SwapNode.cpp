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
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL)
           return NULL;
        if (head -> next == NULL)
           return head;

        ListNode * result = new ListNode(0);
        ListNode * new_current = result;
        ListNode * current = head;
        while(current -> next != NULL)
        {
            // Swap
            new_current -> next = current -> next;
            new_current = new_current -> next;
            current -> next = current -> next -> next;
            new_current -> next = current;
            new_current = new_current -> next;
            current = current -> next;
            if (current == NULL)
                return result -> next;
        }

        return result -> next;

    }
};
