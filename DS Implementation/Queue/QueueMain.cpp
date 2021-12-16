#include<iostream>
#include "Queue.h"

using namespace std;

int main(void){
    Queue queue;
    int choice = 0;
    int val;
    while(choice != 8){
        cout << "Enter 1 to ENQUEUE" << endl;
        cout << "Enter 2 to SEARCH" << endl;
        cout << "Enter 3 to DEQUEUE" << endl;
        cout << "Enter 4 to PRINT" << endl;
        cout << "Enter 5 to CHECK IF EMPTY" << endl;
        cout << "Enter 6 to REMOVE" << endl;
        cout << "Enter 7 to PEEK" << endl;
        cout << "Enter 8 to EXIT" << endl;
        cout << "Enter Choice" << endl;
        scanf("%d",&choice);
        switch (choice)
        {
            int result;
        case 1:
            cout << "Enter value to be inserted" << endl;
            cin >> val;
            queue.push_back(val);
            break;
        
        case 2:
            cout << "Enter value to search" << endl;
            cin >> val;
            result = queue.contains(val);
            if(result == - 1)
                cout << "Value not present in list" << endl;
            else if(result == -2)
                cout << "No elements in queue" << endl;
            else
                cout << "Value found at index " << result << endl;
            break;
        case 3:
            result = queue.pop_front();
            if(result != -1)
                cout << result << " popped" << endl;
            else
                cout << "Underflow" << endl;
            break;
        case 4:
            queue.print();
            break;
        case 5:
            if(queue.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 6:
            int index;
            cout <<"Enter value to remove" << endl;
            cin >> index;
            result = queue.remove(index);
            if(result){
                cout << "Element removed" << endl;
            }
            else if(result == 0){
                cout << "Elemet doesn't exist" << endl;
            }
            else{
                cout << "Queue is Empty" << endl;
            }
            break;
        case 7:
            cout << "First element is : " << queue.peek() << endl;
            break;
        default:
            break;
        }
    }
}