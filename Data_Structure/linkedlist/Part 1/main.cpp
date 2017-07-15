/*
  Name: Hai Dang
  Email: goldsea5191@gmail.com
*/
#include "linkedlist.h"
using namespace std;

int main()
{   int count, count1;      //return value for sum_total iteratively
    int result;     //return value for sum_total recursively


    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();              // Test method build
    my_list.display_all();        // Test method display_all
    count = my_list.sum_total();  // Test method sum_total
        cout << "TEST sum_total! Total data in a linear linked list is: "
             << count << endl;

    count1= my_list.sum_total(my_list.get_head());  // Test method sum_total recursion
    cout << "TEST sum_total Recursion! Total data in a linear linked list is: "
         << count1 << endl;

    // Test method Sum)value
    int sum, sum1;
    sum = my_list.sum_value();  // Test method sum_value
        cout << "TEST sum_value! Total sum in a linear linked list is: "
             << sum << endl;

   sum1= my_list.sum_value(my_list.get_head());  // Test method sum_total recursion
    cout << "TEST sum_value Recursion! Total sum in a linear linked list is is: "
         << sum1 << endl;



    // Test Method remove_last number in list
   my_list.remove_last();
   my_list.display_all();

   // Create new list 2 to test 1 element
   list my_list1;
   my_list1.insert(7);
   cout << "LIST 1: ";
   my_list1.display_all();
   cout << "TEST remove list with 1 element: " << endl;
   my_list1.remove_last();
   my_list1.display_all();

   cout << "TESTING METHOD REMOVE LAST RECURSION WITH EMPTY LIST" << endl;
   if(!my_list1.remove_last(my_list1.get_head()))
      cout << "CORRECT! List 1 now is empty. We cannot delete the node " << endl;
   else
      cout << "FAIL TEST!" << endl;

      cout << "-------------------------------------------------------------------------" << endl;
    // Testing method remove_all
    cout << "TESTING METHOD REMOVE ALL RECURSION WITH ALTERNATIVE WAY" << endl;
    if(my_list.remove_all())
       cout << "CORRECT! List now is empty. We cannot delete the node " << endl;
    else
       cout << "FAIL TEST!" << endl;
    cout << "Display the output of LIST after remove all element: " << endl;
    my_list.display_all();

    // Testing method find_item
    my_list.build();        // Rebuild the list
    my_list.display_all();
    cout << "TESTING METHOD FIND ITEM" << endl;
    if (my_list.find_item(my_list.get_head(),7))
      cout << "CORRECT ! List has element with value 7" << endl;
    else
      cout << "FAIL TEST"<< endl;

      if (!my_list.find_item(my_list.get_head(),11))
        cout << "CORRECT ! List does not have element with value 11" << endl;
      else
        cout << "FAIL TEST"<< endl;

    cout << "TESTING METHOD FIND ITEM RECURSION !" << endl;
    if (my_list.find_item(7))
      cout << "CORRECT ! List has element with value 5" << endl;
    else
      cout << "FAIL TEST"<< endl;

      if (!my_list.find_item(10))
        cout << "CORRECT ! List does not have element with value 10" << endl;
      else
        cout << "FAIL TEST"<< endl;

    // Test case copy method
    cout << "-------------------------------------------------------------------------" << endl;
    list my_list2;
    cout << "TESTING METHOD COPY, It will copy the list from my_list" << endl;
    if (my_list2.copy(my_list2))
    {
      cout <<"CORRECT! Successfully copy" <<endl;
      cout << "My list: "; my_list.display_all(); cout << endl;
      cout << "My list 2 is copied: "; my_list.display_all(); cout << endl;
    }
    else
      cout << "!FAIL TEST" << endl;

    cout << "! Testing the case if my_list is empty " << endl;
    my_list1.remove_all();        // Remove all element my_list1
    if (my_list2.copy(my_list1))
    {
      cout <<"CORRECT! Successfully copy" <<endl;
      cout << "My list: "; my_list1.display_all(); cout << endl;
      cout << "My list 2 is copied: "; my_list2.display_all(); cout << endl;
    }
    else
      cout << "!FAIL TEST" << endl;

    // Test copy using recursion
    cout << "TESTING METHOD COPY BY RECURSION " << endl;
    if (my_list2.copy(my_list.get_head()))
    {
      cout <<"CORRECT! Successfully copy" <<endl;
      cout << "My list: "; my_list.display_all(); cout << endl;
      cout << "My list 2 is copied: "; my_list2.display_all(); cout << endl;
    }
    else
      cout << "!FAIL TEST" << endl;
    // Recursion with empty list
      cout << "! Testing RECURSION with the case if my_list is empty " << endl;
      my_list1.remove_all();        // Remove all element my_list1
      if (my_list2.copy(my_list1.get_head()))
      {
        cout <<"CORRECT! Successfully copy" <<endl;
        cout << "My list: "; my_list1.display_all(); cout << endl;
        cout << "My list 2 is copied: "; my_list2.display_all(); cout << endl;
      }
      else
        cout << "!FAIL TEST" << endl;
    return 0;
}
