/*
   Name: Hai Dang Hoang
*/
#include "stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list
//as the data structure

// constructor
stack::stack()
{
    top = NULL;
}

stack::~stack()
{

}
bool stack::isEmpty()
{
    if (top == NULL)
      return true;
    else
      return false;
}

//Add a new item to the top of stack
void stack::push(int new_value)
{
    node *new_node = new node;        // Create the element
    new_node ->data = new_value;
    new_node ->next = top;
    top = new_node;                   // update the top
}

//Remove the top of stack
int stack::pop ()
{
  int result;
   if(isEmpty())  // Stack is empty
      cout << "! Stack is now empty. " <<endl;
   else
   {
      node * current = top; // Set current point to the top
      top = top -> next ;    // update position after pop
      result = current->data; // Take value top of stack
      delete current;       // delete the top node
   }
   return result;
}

int stack::peek()
{
    return top->data;
}

void stack::reset()
{
  if(isEmpty())
      cout << "! Stack is now empty. " <<endl;
  else
    while(!isEmpty())
      pop();
}

void stack::display_all()
{
  node * current = top;
  if (top == NULL)
    cout << "! Stack is empty " << endl;
  else
  {
    cout << "STACK from [TOP -- BOTTOM]: ";
    while (current != NULL)
    {
      cout << current->data << " ";
      current = current -> next;
    }
    cout << endl;
  }
}

/* Method reverse stack
*/
void stack::reverse(stack & from)
{
  while(from.top!=NULL)
    push(from.pop());
}


/* Method stutter stack
  [1 2 3] --> [1 1 2 2 3 3]
*/
void stack::stutter(stack & from)
{
  // Method ignores empty situation
  stack temp;
  temp.reverse(from); // Take reverse from parameter stack
  while (temp.top!=NULL)
  {
    int value = temp.pop();
      push(value);
      push(value);
      from.push(value);  // Back up from
  }
}
/* Method collapse stack
  bottom - top [1 2 3 4 5] --> [3 7 5]
  bottom - top [1 2 3 4 ] --> [3 7]
*/
void stack::collapse(stack & from)
{
  // Method ignores empty situation
  int value1, value2;
  stack temp;
  temp.reverse(from);
  while(temp.top!=NULL)
  {
    value1 = temp.pop();    // Take the first value
    if(temp.isEmpty())  // Look at the top to check stack is empty or not
    {
      // If stack is empty
      push(value1);         // push this value into stack
      break;
    }
    value2 = temp.pop();    // Take the second value
    push(value1 + value2);  // Push sum the value 1 and value 2
  }
}
/* Method equal stack
   Return True --> 2 stack are the same
   Return False --> 2 stack are different
*/
 bool stack::equal(stack stack1, stack stack2)
 {
   if (stack1.isEmpty() & stack2.isEmpty())  // 2 stack are empty
    return true;
   else if (stack1.isEmpty()) // Stack2 is not empty, but stack 1 is empty
    return false;
   else if (stack2.isEmpty()) // Stack1 is not empty, but stack 2 is empty
    return false;
   else   // Stack 1 and stack 2 are not empty
   {
      int value1, value2;
      stack backup1, backup2; // Use for backup stack 1 and stack 2
                              // It also use for equal algorithm
      backup1.reverse(stack1);
      backup2.reverse(stack2);
      while(backup1.top!=NULL)
      {

        if(backup2.top == NULL)  // stack 2 empty, but stack 1 is not empty --> return false
          return false;
        value1 = backup1.pop(); // Take the first value
        stack1.push(value1);    // back up for stack 1
        value2 = backup2.pop(); // Take the second value
        stack2.push(value2);    // back up for stack 2
        if(value1 != value2)
        {
            while(backup1.top!=NULL)      // back up stack 1 for the rest of value
              stack1.push(backup1.pop());
            while(backup2.top!=NULL)      // back up stack 2 for the rest of value
              stack2.push(backup2.pop());
            return false;
        }
      }

      if(backup2.top!=NULL) // stack 1 empty, but stack 2 not empty after while operation
      {
          while(backup2.top!=NULL)      // back up stack 2 for the rest of value
            stack2.push(backup2.pop());
          return false;
      }
      return true;
   }

 }

 /*
    Method findMin
 */

 int stack::findMin()
 {
   stack backup;
   int min = peek();
   // Reverse, find the min value
   while(top != NULL)
   {
     int value = pop();
     if (value < min)
      min = value;
    backup.push(value);
   }

   while(backup.top!=NULL)
   {
      int value = backup.pop();
      if (value != min)
        push(value);
   }
   return min;
 }

 void stack::mirror()
 {
   stack backup, copy;
   while(top!= NULL)
     backup.push(pop());
   // Reverse backup and tmp --> copy
   while(backup.top!= NULL)
   {
     int share = backup.pop();
     push(share);
     copy.push(share);
   }

   while(copy.top != NULL)
    push(copy.pop());
 }
void stack::copy(stack & from)
{
  //if (!isEmpty())       // If stack is not empty --> reset all element
  //  reset();
  //if (from.top == NULL) // If stack copy is NULL --> assign NULL
  //  top == NULL;
//  else
//  {

//  }
}
