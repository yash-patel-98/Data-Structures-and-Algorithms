/*

Remove Dups! Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?

*/

#include <iostream>
#include <vector>
#include <set>

struct Node{
    int val;
    struct Node* next;
};

using namespace std;

void removeDupsUsingMap(struct Node* head){
    struct Node* temp = head->next;
    struct Node* previous = temp;
    set<int> map;
    while(temp -> next != NULL){
        if(map.find(temp->val) != map.end()){
            previous->next = temp->next;
            delete temp;
            temp = previous;
        }
        else{
            map.insert(temp->val);
            previous = temp;
        }
        temp = temp -> next;
    }
}

void removeDupsWithoutMap(struct Node*head){
    struct Node* temp = head->next;
    struct Node* previous = NULL;
    struct Node* pointer2 = temp;
    while(temp->next != NULL){
        pointer2 = temp->next;
        previous = NULL;
        while(pointer2 -> next != NULL){
            if(temp-> val == pointer2->val){
                previous->next = pointer2->next;
                delete pointer2;
                pointer2 = previous;
            }
            else{
                previous = pointer2;
            }
            pointer2 = pointer2->next;
        }
        temp = temp->next;
    }
}

//Main Function not written.
int main(void){

}