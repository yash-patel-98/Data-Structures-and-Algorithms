#include<iostream>
#include "Stack.h"

using namespace std;

int main(void){
    Stack stack;
    int choice = 0;
    int val;
    while(choice != 7){
        cout << "Enter 1 to PUSH" << endl;
        cout << "Enter 2 to SEARCH" << endl;
        cout << "Enter 3 to POP" << endl;
        cout << "Enter 4 to PRINT" << endl;
        cout << "Enter 5 to GET SIZE" << endl;
        cout << "Enter 6 to GET ELEMENT AT INDEX" << endl;
        cout << "Enter 7 to EXIT" << endl;
        cout << "Enter Choice" << endl;
        scanf("%d",&choice);
        switch (choice)
        {
            int result;
        case 1:
            cout << "Enter value to be inserted" << endl;
            cin >> val;
            stack.push(val);
            break;
        
        case 2:
            cout << "Enter value to search" << endl;
            cin >> val;
            result = stack.contains(val);
            if(result == - 1)
                cout << "Value not present in list" << endl;
            else if(result == -2)
                cout << "No elements in stack" << endl;
            else
                cout << "Value found at index " << result << endl;
            break;
        case 3:
            result = stack.pop();
            if(result != -1)
                cout << result << " popped" << endl;
            else
                cout << "Underflow" << endl;
            break;
        case 4:
            stack.printStack();
            break;
        case 5:
            cout << "Size of stack = " << stack.size() << endl;
            break;
        case 6:
            int index;
            cout <<"Enter index" << endl;
            cin >> index;
            result = stack.elementAt(index);
            if(result != -1){
                cout << "Element at index = " << index << " is " << result << endl;
            }
            else{
                cout << "Invalid Index" << endl;
            }
        case 7:
            break;
        default:
            break;
        }
    }
}