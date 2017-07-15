/*
  File: stack.h
  Author: Hai Dang Hoang
  email: danghai@pdx.edu
*/

#ifndef STACK_H_
#define STACK_H_

#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
class stack
{
      public:
             //These functions have ALREADY been written for you
             stack(void);
             ~stack(void);


             int peek();

             void push(int value);

             int pop ();
             bool isEmpty();
             void reset();

             void copy(stack & from);
             void display_all();

             // Exercise
             void reverse(stack & from);
             void stutter(stack & from);
             void collapse (stack & from);
             bool equal(stack stack1, stack stack2);
             int findMin();
             void mirror();

      private:
              node * top;

};

#endif
