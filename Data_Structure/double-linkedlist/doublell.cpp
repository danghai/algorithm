#include  "doublell.h"

doublell::doublell()
{
  front = NULL;
}

doublell::~doublell()
{

}
bool doublell::isEmpty()
{
 return (front==NULL);
}

void doublell::display_dlist()
{
   node *current;
  if (front == NULL)
  {
      cout<<"List empty,nothing to display"<<endl;
      return;
  }
  current = front;
  cout<<"The Doubly Link List is :"<<endl;
  while (current != NULL)
  {
      cout<<current->data<<" <-> ";
      current =current->next;
  }
  cout<<"NULL"<<endl;
}

// Add the tail doublell
void doublell::create_list(int value)
{
 node *current, *temp;
 temp = new node;
 temp->data = value;
 temp->next = NULL;
 if (front == NULL)
 {
     temp->prev = NULL;
     front = temp;
 }
 else
 {
     current = front ;
     while (current->next != NULL)
         current = current->next;
     current->next = temp;
     temp->prev = current;
 }
}

void doublell::add_begin (int value)
{
  if (front == NULL)
   {
       cout<<"First Create the list."<<endl;
       return;
   }
   node *temp;
   temp = new node;
   temp->prev = NULL;
   temp->data = value;
   temp->next = front;
   front->prev = temp;
   front = temp;
   cout<<"Element Inserted"<<endl;
}

void doublell::add_after(int value, int position)
{
  if (front == NULL)
{
    cout<<"First Create the list."<<endl;
    return;
}
node *tmp, *current;
int i;
current = front;
for (i = 0;i < position - 1;i++)
{
    current = current->next;
    if (current == NULL)
    {
        cout<<"There are less than ";
        cout<<position<<" elements."<<endl;
        return;
    }
}
// add
tmp = new node;
tmp->data = value;
if (current->next == NULL)
{
    current->next = tmp;
    tmp->next = NULL;
    tmp->prev = current;
}
else
{
    tmp->next = current->next;
    tmp->next->prev = tmp;
    current->next = tmp;
    tmp->prev = current;
}
cout<<"Element Inserted"<<endl;
}

void doublell::delete_element(int value)
{
  node *tmp, *current;
 /*first element deletion*/
if (front->data == value)
{
    tmp = front;
    front = front->next;
    front->prev = NULL;
    cout<<"Element Deleted"<<endl;
    free(tmp);
    return;
}
current = front;
while (current->next->next != NULL)
{
    /*Element deleted in between*/
    if (current->next->data == value)
    {
        tmp = current->next;
        current->next = tmp->next;
        tmp->next->prev = current;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return ;
    }
    current = current->next;
}
 /*last element deleted*/
if (current->next->data == value)
{
    tmp = current->next;
    free(tmp);
    current->next = NULL;
    cout<<"Element Deleted"<<endl;
    return;
}
cout<<"Element "<<value<<" not found"<<endl;
}

void doublell::search_element(int value)
{

}

int doublell::count()
{
   node *current = front;
    int cnt = 0;
    while (current != NULL)
    {
        current = current->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
    return cnt;
}

void doublell::reverse()
{

}
