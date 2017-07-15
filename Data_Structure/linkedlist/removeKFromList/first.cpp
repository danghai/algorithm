// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    if (l == nullptr)
        return nullptr;
    else
    {
        while (l->value == k)   // If head has data == k, delete all
        {
            l = l -> next;
            if (l == nullptr)
                return nullptr;
        }
        ListNode <int> *current;
        current = l;
        while(current->next != nullptr)
        {
            if(current->next->value == k)
            {
                current -> next = current -> next ->next;
            }
            else
                current = current -> next;
        }
         return l;
    }
}
