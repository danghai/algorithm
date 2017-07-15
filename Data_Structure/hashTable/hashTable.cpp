#include "hashTable.h"
const int TABLE_SIZE = 5;
hashTable::hashTable()
{
  table = new node*[TABLE_SIZE];  // dynamically create 5 key
  for(int i=0;i<TABLE_SIZE;i++)   // initial NULL for each key
    table[i] = NULL;
}

hashTable::~hashTable()
{

  for(int i=0;i<TABLE_SIZE;i++)
  {
      node *key_entry = table[i];  // Take entry key in table to delete each element in key
      while(key_entry != NULL )    // Traversal each linklist in a key
      {
        node *current = key_entry;
        key_entry = key_entry -> next;
        delete current;
      }
  }
  delete[] table;               // delete all NULL table

}

void hashTable::display_key(int key)
{
   int hash_val = HashFunc(key);  // Chaining the key by functions
   node *key_entry = table[hash_val];
   if (key_entry== NULL)
   {
     cout<< "KEY " << hash_val<< ": ";
     cout << "! KEY is now empty" << endl;
   }
   else
   {
      cout<< "KEY " << hash_val<< ": ";
      node *current = key_entry;
      while(current!= NULL)
      {
          cout << current->data <<" ";
          current = current -> next;
      }
      cout << endl;
   }
}

void hashTable::display_all()
{
   for(int i=0;i<TABLE_SIZE;i++)
    display_key(i);
}

int hashTable::HashFunc(int key)
{
    return key % TABLE_SIZE;
}

void hashTable::insert(int key, int value)
{
    int hash_val = HashFunc(key);       // Chaining the key by functions
    node *key_entry = table[hash_val]; // Take key entry from hash value
    node *new_value;
    new_value = new node;              // create new value
    new_value ->data = value;        // Assign value
    new_value -> next = NULL;
    if (key_entry == NULL)          // if currently key entry is NULL
      table[hash_val] = new_value;  // initial the first value in KEY
    else // not NULL
    {
       node * current = key_entry;
       while(current->next!=NULL)  // traversal to last element
          current = current -> next;
       current -> next = new_value;     // Add new value at tail
    }
}

bool hashTable::search(int key, int value)
{
  int hash_val = HashFunc(key);       // Chaining the key by functions
  node *key_entry = table[hash_val]; // Take key entry from hash value
  if (key_entry == NULL)
  {
    cout<< "KEY " << hash_val<< ": ";
    cout << "! KEY is now empty" << endl;
    return false;
  }
  else
  {
      node * current = key_entry;
      while(current != NULL)
      {
        if (current -> data == value)
          return true;
        else
          current = current -> next;
      }
      return false;
  }
}

void hashTable::remove(int key)
{
    int hash_val = HashFunc(key);       // Chaining the key by functions
    node *key_entry = table[hash_val]; // Take key entry from hash value
    if (key_entry == NULL)
    {
      cout<< "KEY " << hash_val<< ": ";
      cout << "! KEY is now empty" << endl;
    }
    else
    {
      node * current = key_entry;
      while (current -> next -> next != NULL)
        current = current -> next;
      current -> next = NULL;
    }
}
