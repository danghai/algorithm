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
  tail = NULL;
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
