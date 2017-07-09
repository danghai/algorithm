/*
      Name: Hai Dang
      Email: goldsea5191@gmail.com
*/
#include "linkedlist.h"
using namespace std;

int main()
{
    //First try this out as is. Then start adding in your function calls!
    list my_list1, my_list2;
    list result;

    // Test method ShuffleMerge
    cout << "! TESTING method ShuffleMerge " << endl;
    // Initial list 1 : 2 4 6 8
    my_list1.insert(2); my_list1.insert(4); my_list1.insert(6); my_list1.insert(8);
    // Initial list 2 : 3 5 7 9
    my_list2.insert(3); my_list2.insert(5); my_list2.insert(7); my_list2.insert(9); my_list2.insert(11); my_list2.insert(13);
    cout << " LIST 1: "; my_list1.display_all();
    cout << " LIST 2: "; my_list2.display_all();
    result.ShuffleMerge(my_list1.get_head(), my_list2.get_head());
    cout << " LIST 3: "; result.display_all();


    cout << "! TESTING method ShuffleMerge with recursion" << endl;
    list result_recursion;
    list my_list3, my_list4;
    my_list3.insert(2); my_list3.insert(4); my_list3.insert(6); my_list3.insert(8);
    my_list4.insert(3); my_list4.insert(5); my_list4.insert(7); my_list4.insert(9); my_list4.insert(11); my_list4.insert(13);
    result_recursion.ShuffleMerge_recursion(my_list3.get_head(),my_list4.get_head());
    cout << " LIST 1: "; my_list3.display_all();
    cout << " LIST 2: "; my_list4.display_all();
    cout << " LIST 3: "; result_recursion.display_all();
    cout << "--------------------------------------------------------------------------" << endl;


    cout << "! TESTING method SortedMerge " << endl;
    // Reset variable
    my_list1.remove_all(); my_list2.remove_all(); result.remove_all();
    // Initial list 1 : 10 15 7 8 12 20 1
    my_list1.insert(10); my_list1.insert(15); my_list1.insert(7); my_list1.insert(8); my_list1.insert(12); my_list1.insert(20); my_list1.insert(1);
    cout << " LIST 1: "; my_list1.display_all();
    cout << " SORT --> LIST 1:"; my_list1.insertSort(); my_list1.display_all();
    // Initial list 2: -3 9 4 14 18
    my_list2.insert(-3); my_list2.insert(9); my_list2.insert(4); my_list2.insert(14); my_list2.insert(18);
    cout << " LIST 2: "; my_list2.display_all();
    cout << " SORT --> LIST 2:"; my_list2.insertSort(); my_list2.display_all();

    result.SortedMerge (my_list1,my_list2);
    cout << " LIST 3: "; result.display_all();
  /*
      cout << "--------------------------------------------------------------------------" << endl;
    my_list1.remove_all();
    my_list1.insert(10); my_list1.insert(15); my_list1.insert(7); my_list1.insert(8); my_list1.insert(12); my_list1.insert(20);
    cout << " LIST 1: "; my_list1.display_all();
    cout << " SORT --> LIST 1:"; my_list1.bubbleSort(); my_list1.display_all();

    cout <<"! TESTING method SortedMerge with recursion" << endl;
    // Reset variable
      my_list1.remove_all(); my_list2.remove_all(); result.remove_all();
      my_list1.insert(2); my_list1.insert(4); my_list1.insert(6); my_list1.insert(8);
      my_list2.insert(3); my_list2.insert(5); my_list2.insert(7); my_list2.insert(9); my_list2.insert(11); my_list2.insert(13);
      cout << " LIST 1: "; my_list1.display_all();
      cout << " LIST 2: "; my_list2.display_all();
      result.SortedMerge_recursion(my_list1.get_head(),my_list2.get_head());
      cout << " LIST 3: "; result.display_all();
      cout << " LIST 1: "; my_list1.display_all();
      cout << " LIST 2: "; my_list2.display_all();
*/
    return 0;
}
