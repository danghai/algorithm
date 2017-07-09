/*
      Name: Hai Dang
      Email: goldsea5191@gmail.com
*/
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>


//The data structure is a linear linked list of integers
//with a head AND tail pointer!
struct node
{
       int  data;
       node * next;
};

class list
{
      public:
             //These functions are supplied for you
             list();
             ~list();
             void build();
             void display_all();


             //****************************************************
             //Write each of these functions Iteratively and Recursively
             void insert(int new_data);   // Insert a new value

             node * get_head();
             node * get_tail();

             int sum_total();		      //Iterative  total number
             int sum_total(node * head);  // Recursive

             int sum_value();		      //Iterative    // Total sum all number
             int sum_value(node * head);  // Recursive

	           bool remove_last();          //Iterative
             bool remove_last(node * head);  //Recursive

             bool remove_all();                 //Iterative
             node * remove_all(node * &ead);    //Recursive

             bool find_item(int item_to_find);  //Iterative
             bool find_item(node * head, int item_to_find);   //Recursive

             bool copy(list & from);            //Iterative
             bool copy( node * head_source);
             bool copy(node * &new_head, node * head_source); //Recursive

             // PART 3 Method
             void insertSort();
             void ShuffleMerge(node * list1_head, node * list2_head); // Iterative
             node * ShuffleMerge_recursion (node * list1_head, node * list2_head); // Recursive
             void SortedMerge(list list1_head, list list2_head); // Iterative
             node * SortedMerge_recursion (node * list1_head, node * list2_head); // Recursive
             node * findMin();
             void bubbleSort();

      private:
             //Notice there is BOTH a head and tail pointer
             //Make sure to keep both properly maintained
              node * head;
	            node * tail;

};
