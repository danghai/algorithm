/*
      Name: Hai Dang
      Email: goldsea5191@gmail.com
*/

#include "linkedlist.h"
using namespace std;

// Constructor
list::list()
{
  head = NULL;
  tail = head;
}

list::~list()
{

}
// List insert a new value in list
void list::insert(int new_data)
{
  //  new node value
  node *newNode;
  newNode = new node;
  newNode->data = new_data; // Assign new value
  newNode->next = NULL;

  if(head==NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
}

// List build to create a list with 10 numbers
void list::build()
{
  for (int i = 0;i<10; i++)
    insert(i);
}

// List display number
void list::display_all()
{
  if (head==NULL)
    cout << "List is empty !" << endl;
  else
  {
    cout << "LIST: ";
    node *current;
    current = head;
    while (current != NULL)
    {
      cout << current->data <<" ";
      current = current -> next;
    }
    cout <<endl;
  }
}

// Method get head
node *list::get_head()
{
  return head;
}

// Method get tail
node *list::get_tail()
{
  return tail;
}


//Sum  all of the data together in a LLL
int list::sum_total()
{       int count = 0;
        node * current = head;
        if (head == NULL)
                return 0;
        else
        {
          while (current != NULL)
          {
                current = current->next;
                count++;
          }
        return count;
       }
}

//Now implement the function recursively!
int list::sum_total(node * head)
{
        if (head == NULL)
                return 0;
        return sum_total(head->next) + 1;

}

//Sum  all of the data together in a LLL
int list::sum_value()
{       int sum = 0;
        node * current = head;
        if (head == NULL)
                return 0;
        else
        {
          while (current != NULL)
          {
                sum =  sum + current->data;
                current = current->next;
          }
        return sum;
       }
}

//Now implement the function recursively!
int list::sum_value(node * head)
{
        if (head == NULL)
                return 0;
        return  head->data + sum_value(head->next);
}



// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        bool remove = false;


        if (head == NULL)
                return remove;
        else
        {
            node * current = head->next;
            if ( current == NULL)
            {
                delete current;
                tail = NULL;
                head = NULL;
                remove = true;
            }
            else
            {

                // Move the node to before the last node
                while (current->next -> next != NULL)
                   current = current -> next;

                current -> next = NULL;
                tail = current;
                remove = true;
            }
        }
        return remove;
}

//Now implement the function recursively!
bool list::remove_last(node * head)
{
    // Base case
    if (head == NULL)
      return false;
    else if ((head->next->next) == NULL)
    {
      head->next= NULL;     // Link the previous tail to NULL
      tail = head;          // Update tail
      return true;
    }

    // Recursive
    else
      return remove_last(head->next);
}


// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
    if (remove_all(head)==NULL)
      return true;
    else
      return false;
}

//Now implement the function recursively!
node * list::remove_all(node* &head)
{
    // base case
    if (head == NULL)
        return NULL;
    // recursively
    else
    {
       head  = remove_all (head-> next);
       return NULL;
    }
}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Write your code here
        bool search = false;
        node * current = head;
        if (head == NULL)
                return search;
        else
        {
                while (current != NULL && !search)
                {
                        if (current->data == item_to_find)
                                search = true;
                        else
                                current = current->next;
                }
        }
        return search;
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
        // base case
        if (head == NULL)
                return false;
        else if (head->data == item_to_find)
                return true;

        // recursive
        else
                return find_item(head->next, item_to_find);

}



// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
      if (from.head == NULL)               // Case NULL
      {
        head = NULL;
        tail = NULL;
        return true;
      }
      else if (from.head->next == NULL)    // Case 1 element
      {
        head = from.head;
        tail = from.tail;
        return true;
      }
      else
      {
        node * current = from.head;
        while (current != NULL)
        {
          insert(current->data);        // Insert the new value from new List
          current = current -> next;
        }
        return true;
      }
    return false;
}

bool list::copy(node * head_source)
{
  return copy (head, head_source);
}

//Now implement the function recursively
bool list::copy(node * & head, node * head_source)
{
  // base case
  if (head_source == NULL)
  {
      head = NULL;
      return true;
  }
  // Recursive
  else
  {
     head = new node;             // Create new node to link for each element in recursive
     head->data = head_source-> data;
     head->next =  NULL;
     return copy (head->next, head_source->next);
  }
  return false;

}

/* Method ShuffleMerge
Implement Method ShuffleMerge Given two lists, merge their nodes together t
// o make one list, taking nodes alternately between the two lists. So ShuffleMerge()
with {1, 2, 3} and {7, 13, 1} should yield {1, 7, 2, 13, 3, 1}.  */

void list::ShuffleMerge(node * list1_head, node * list2_head)
{
  // Important ! Initial the 1st memory for head and tail
  tail = new node;
  tail -> next = NULL;
  head = tail;

  while (1)
  {
    if (list1_head == NULL)
    {
        tail-> next = list2_head;     // Case list 1 Null, Assign tail for the rest of value of list 2
        break;
    }
    else if (list2_head == NULL)
    {
        tail -> next  = list1_head;     // Case list 2 Null, Assign tail for the rest of value of list 1
        break;
    }
    else                               // list1_head and list2_head not NULL
    {
        tail -> next = list1_head;
        tail = list1_head;    // Take the first value of list 1
        list1_head = list1_head -> next; // Move the next position of list 1
        tail -> next = list2_head;    // Take the first value of list 2
        tail = list2_head;            // Update new position tail
        list2_head= list2_head -> next; // Move the next position of list 2


    }
  }
        node * current = head;
        head = head -> next;  // Delete the first node
        delete current;
}


// Method ShuffleMerge Using Recursion
node * list::ShuffleMerge_recursion (node * list1_head, node * list2_head)
{

   // Base case
   if (list1_head == NULL)
      return list2_head;
   else if (list2_head == NULL)
      return list1_head;
    // Recursive
   else
   {

     tail = ShuffleMerge_recursion (list1_head -> next, list2_head -> next);
     head = list1_head;                // Take one noe from list 1
     list1_head->next = list2_head;    // Take one node from b
     list2_head->next = tail;
     return head;
   }

}

/*  Methodo SortedMerge
    SortedMerge method that takes two list, each of which is sorted in increasing order
    and merges the two together into one list which is in increasing order
*/
void list::SortedMerge(list list1, list list2)
{
    tail = new node;
    tail -> next = NULL;
    head = tail;
    while (1)
    {
      if (list1.head == NULL)
      {
          tail -> next = list2.head;     // Case list 1 Null, Assign tail for the rest of value of list 2
          break;
      }
      else if (list2.head == NULL)
      {
          tail -> next = list1.head;     // Case list 2 Null, Assign tail for the rest of value of list 1
          break;
      }
      else
      {
          if (list1.head->data <= list2.head->data) // If elelemnt list 1 < list 2 --> take this into the list
          {
              tail -> next = list1.head;    // Take the element from list 1
              tail = list1.head;            // update the tail
              list1.head = list1.head -> next; // Update the next element for list 1
          }
          else // list 1 > list 2
          {
              tail -> next = list2.head;        // Take the element from list 2
              tail = list2.head; // Update the tail
              list2.head = list2.head -> next;   // Update the next element for list 2
          }
      }
    }

    node * current = head;
    head = head -> next;  // Delete the first node
    delete current;
}

/* SortedMerge_recursion
    Implement SortedMerge by Recursion
*/
node * list::SortedMerge_recursion (node * list1_head, node * list2_head)
 {

    // Base case
    if (list1_head == NULL)
      return list2_head;
    else if (list2_head == NULL)
      return list1_head;
    // Recursive
    else
    {

            if(list1_head->data <= list2_head->data)  // Value of list 1 <= Value of list 2
            {
              head = list1_head;

            //head = list1_head
              head  -> next = SortedMerge_recursion(list1_head->next, list2_head);
            }
            else    // Value of list 1 > value of list 2
            {
              head  = list2_head;
              //head = list2_head;
              head -> next = SortedMerge_recursion(list1_head, list2_head->next);
            }
        return head;
    }
 }

 /* InsertSort Alogithm
    Sorting list following increasing order
 */

 void list::insertSort()
 {
    node * lastInOrder;
    node * firstOutOfOrder;
    node * current;
    node * preCurrent;

    lastInOrder = head; // Assign the head node
    if (head == NULL)
        cout << "Cannot sort an empty list " << endl;
    else if (head -> next == NULL)
        cout << "Cannot sort an list with one element" << endl;
    else
        while (lastInOrder -> next != NULL)
        {
            firstOutOfOrder = lastInOrder -> next;  // firstOutOfOrder is next element of lastInOrder
            if (firstOutOfOrder->data < head->data) // If this element < head
            {
                lastInOrder-> next = firstOutOfOrder-> next;  // Move this element before first
                firstOutOfOrder -> next = head;
                head = firstOutOfOrder;
            }
            else
            {
                preCurrent = head;          // Set preCurrent at first
                current = head -> next;     // current is next element
                while (current->data < firstOutOfOrder-> data) // Find element < the element of FirstOutOfOrder
                {
                    preCurrent = current;
                    current = current -> next;
                }
                // Important: check current with firstOutOrder
                if (current != firstOutOfOrder)
                {
                    // insert firstOutofOrder between current and preCurrent
                    lastInOrder->next = firstOutOfOrder->next;
                    firstOutOfOrder->next = current;
                    preCurrent->next= firstOutOfOrder;
                }
                else // firstOutOfOrder is already at the first place
                    lastInOrder = lastInOrder->next;
            }
        } // end while
 } // end Sort


/*  findMin Method
    find the min value in list and return the node Min
*/
node * list::findMin()
{
  node * current = head;
  node * min = head;
    if (head ==NULL)
        return NULL;
    else if (head->next ==NULL)
        return head;
    else
    {

        while (current != NULL)
        {
            if (min ->data >= current->data)
              min = current;
            current = current -> next;
        }
    }
    return min;
}

/* bubbleSort Method
   Implement bubbleSort method in list with following increasing order
*/
void list::bubbleSort()
{
  if (head == NULL)
      cout << "Cannot sort an empty list " << endl;
  else if (head -> next == NULL)
      cout << "Cannot sort an list with one element" << endl;
  else
  {
      node * current = head;
      node * pre;
      node * iter_current;
      int count = 0;
      while (current != NULL)
      {
          iter_current = current->next;
          pre = current;

          while (iter_current->next!= NULL)
          {

            if (current -> data >= iter_current -> data)  // swap head
            {
                pre -> next = iter_current -> next;
                iter_current-> next = current;
                current = iter_current;
                count ++;
                    cout << count<< endl;
            }
            iter_current = iter_current->next;
            pre = pre->next;
          }
          current = current -> next;
      }
  }
}
