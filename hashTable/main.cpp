#include "hashTable.h"
int main()
{
    hashTable hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Display all element in a key"<<endl;
        cout<<"5.Display all information in hash table" << endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.insert(key, value);
            break;
        case 2:
            cout<<"Enter element to be searched: ";
            cin>>value;
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
          //  cout<<"Element at key "<<key<<" : ";
            if (!hash.search(key,value))
            {
	               cout<<"No element " << value <<"found at key "<<key<<endl;
	               continue;
	           }
             else
                cout << "! Found " << value << " at key " << key << endl;
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.remove(key);
            break;
        case 4:
            cout<<"Enter key of the element to be displayed: ";
            cin>>key;
            hash.display_key(key);
            break;
        case 5:
            cout<<"Information in hash table"<< endl;
            hash.display_all();
            break;
        case 6:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
