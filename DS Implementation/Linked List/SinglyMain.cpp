#include<iostream>
#include "SinglyList.h"

using namespace std;

int main(void){
    SinglyList ls ;
    cout << "Enter 1 to INSERT" << endl;
    cout << "Enter 2 to SEARCH" << endl;
    cout << "Enter 3 to REMOVE" << endl;
    cout << "Enter 4 to PRINT" << endl;
    cout << "Enter 5 to EXIT" << endl;
    int choice = 0;
    int val;
    while(choice != 5){
        cout << "Enter Choice" << endl;
        scanf("%d",&choice);
        switch (choice)
        {
            int result;
        case 1:
            cout << "Enter value to be inserted" << endl;
            cin >> val;
            ls.insert(val);
            break;
        
        case 2:
            cout << "Enter value to search" << endl;
            cin >> val;
            result = ls.search(val);
            if(result != - 1)
                cout << "Value found at index " << result << endl;
            else
                cout << "Value not present in list" << endl;
        case 3:
            cout << "Enter value to remove" << endl;
            cin >> val;
            result = ls.remove(val);
            if(result)
                cout << "Value removed successfully" << endl;
            else
                cout << "Value not found hence not deleted" << endl;
            break;
        case 4:
            ls.printList();
        case 5:
            break;
        default:
            break;
        }
    }
}