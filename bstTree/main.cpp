#include "bstTree.h"
int main()
{
    bstTree tree;
    int value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on BST (Binary Search Tree)"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the BST"<<endl;
        cout<<"2.Search element from the BST"<<endl;
        cout<<"3.Delete element at a BST"<<endl;
        cout<<"4.Display all element in the BST following traversal"<<endl;
        cout<<"5.Remove the maximum value in the BST" << endl;
        cout<<"6.Total element in BST" << endl;
        cout<<"7.Display BST following tree form" << endl;
        cout<<"8.Others (PART3)" <<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            tree.add(value);
            break;
        case 2:
            cout<<"Enter element to be searched: ";
            cin>>value;
            if (!tree.search(value))
            {
	               cout<<"! No element " << value <<" found at BST "<<endl;
	               continue;
	           }
             else
                cout << "! Found " << value << " at BST " <<endl;
            break;
        case 3:
            cout<<"Enter element to be delete: ";
            cin>>value;
            tree.remove(value);
            break;
        case 4:
            int choice1;
            cout<< "You want to display tree with following format: " << endl;
            cout<< "1. Preorder || 2.Inorder || 3.Postorder" << endl;
            cout<<"Enter your choice: ";
            cin >>choice1;
            cout<<"Information in BST: " << endl;
            switch(choice1)
            {
              case 1:
                cout << "Preorder information: ";
                tree.preorderPrint();
                break;
              case 2:
                cout << "Inorder information: ";
                tree.inorderPrint();
                break;
              case 3:
                cout << "Postorder information: ";
                tree.postorderPrint();
                break;
              default:
                   cout<<"\nEnter correct option\n";
            }
          //  tree.display_all();
            break;
        case 5:
            cout<<"Remove maximum value in BST"<< endl;
            tree.remove_max();
            break;
        case 6:
            cout<<"Total element in BST now: " << tree.size() << endl;
            break;
        case 7:
            cout<<"Tree form (Vertical): " << endl;
            tree.display_all();
            break;
        case 8: // PART 3
          int choice2;
          cout<<"\n-------------------------------------------------------------------"<<endl;
          cout<< "You want to operate method ?: " << endl;
          cout<< "1.Count left node of BST: " << endl;
          cout<< "2.Count empty branches in BST: " << endl;
          cout<< "3.Count depth sum of BST: " << endl;
          cout<< "4.Count even branches in BST" << endl;
          cout<< "5.Print the value at level in BST" << endl;
          cout<< "6.Print the leaves in a BST from right to left" <<endl;
          cout<< "7.Check BST is full or not: " <<endl;
          cout<< "8.Double all data values greater than 0 in BST " <<endl;
          cout<< "9.Changes data following number node (pre-order)" <<endl;
          cout<< "10.Remove the leaves from BST " <<endl;
          cout<< "11.Complete to level the BST" <<endl;
          cout<< "12.Trim BST " <<endl;
          cout<< "13.Eliminates branch nodes that have only one child " <<endl;
          cout<< "14.Exit" << endl;
          cout<<"\n-------------------------------------------------------------------"<<endl;
          cout<<"Enter your choice: ";
          cin >>choice2;
          cout<<"Information in BST: " << endl;
          switch(choice2)
          {
          case 1:
            cout << "Number of left children in the tree: "<< tree.countLeftNodes() << endl;
            break;
          case 2:
            cout << "Number of empty branches in a tree: " << tree.countEmpty() << endl;;
            break;
          case 3:
            cout << "Sum of the values stored in a binary of integers weight: "<< tree.depthSum() << endl;
            break;
          case 4:
            cout << "Number of even branches in BST "<< tree.countEvenBranches() << endl;
            break;
          case 5:
            int level;
            cout<<"Enter the level: ";
            cin >> level;
            cout << "All value at level " <<level<<" in BST: " << endl;
              tree.printLevel(level);
              break;
          case 6:
              cout << "All leaves in a BST from right to left: "<< endl;
              tree.printLeaves();
              break;
          case 7:
              cout << "!BST : ";
              if(tree.isFull())
                cout << "Full" << endl;
              else
                cout << "Not Full" << endl;
              break;
          case 8:
              cout << "!BST: " << endl;
              tree.display_all();
              cout<< endl;
              cout<< "After double all data values greater than 0 in BST: " << endl;
              tree.doublePositives();
              tree.display_all();
              break;
          case 9:
              int result;
              cout << "!BST: " << endl;
              tree.display_all();
              cout<< endl;
              cout<< "After change number nodes" << endl;
              result=tree.numberNodes();
              tree.display_all();
              cout<< "!Number nodes: " << result <<endl;
              break;
          case 10:
              cout << "!BST: " << endl;
              tree.display_all();
              cout<< endl;
              cout<< "After removing leaves in BST " << endl;
              tree.removeLeaves();
              tree.display_all();
              break;
          case 11:
              int level1;
              cout<<"Enter the level: ";
              cin >> level1;
              cout << "!BST: " << endl;
              tree.display_all();
              cout<< endl;
              cout<< "After completing to level" << endl;
              tree.completeToLevel(level1);
              tree.display_all();
              break;
          case 12:
              int min,max;
              cout<<"Enter the min: ";
              cin >> min;
              cout<<"Enter the max: ";
              cin >> max;
              cout << "!BST: " << endl;
              tree.display_all();
              cout<< endl;
              cout<< "After trimming in BST " << endl;
              tree.trim(min,max);
              tree.display_all();
              break;
          case 13:
            cout << "!BST: " << endl;
            tree.display_all();
            cout<< endl;
            cout<< "After tighten in BST " << endl;
            tree.tighten();
            tree.display_all();
            break;
          case 14:
                exit(1);
          default:
               cout<<"\nEnter correct option\n";
        }
      //  tree.display_all();
        break;
        case 9:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
