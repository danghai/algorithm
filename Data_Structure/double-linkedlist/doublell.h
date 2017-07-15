/*
  File: doublell.h
  Author: Hai Dang Hoang
  email: danghai@pdx.edu
*/

#ifndef DOUBLELL_H_
#define DOUBLELL_H_

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
    node *prev;
};
class doublell
{
      public:
             //These functions have ALREADY been written for you
             doublell(void);
             ~doublell(void);
              void  display_dlist() ;
              void create_list (int value);
              void add_begin (int value);
              void add_after (int value, int position);
              void delete_element (int value);
              void search_element (int value);
              int count();
              void reverse ();
	      bool isEmpty();


      private:
              node * front;

};

#endif
