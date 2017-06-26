/*
  File: hashTable.h
  Author: Hai Dang Hoang
  email: danghai@pdx.edu
*/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};
class hashTable
{
      public:
             //These functions have ALREADY been written for you
             hashTable(void);
             ~hashTable(void);
             int HashFunc(int key);           // Function for chaining
             void insert(int key, int value); // Insert a new value in a key, at tail
             bool search(int key, int value); // Return true if this key has this value
             void remove(int key);           // Delete a value in a key at tail
             void display_key(int key);       // Display all element in a key
             void display_all();              // Display all information


      private:
              node **table;

};

#endif
