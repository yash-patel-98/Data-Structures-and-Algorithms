#include "DoublyList.h"
#include <iostream>

using namespace std;

DoublyList::DoublyList(){
    this->head = NULL;
    this->tail = NULL;
}
void DoublyList::insert(int val){
    if(this->head == NULL){
        this->tail = new Node;
        this->head = new Node;
        Node* temp = new Node;

        this->head->previous = NULL;
        this->head->next = temp;

        temp->value = val;
        temp->previous = head;
        temp->next = tail;

        tail->previous = temp;
        tail->next = NULL;
    }
    else{
        Node* temp = new Node;
        temp->previous = this->tail->previous;
        temp->previous->next = temp;
        temp->next = this->tail;
        this->tail->previous = temp;
        temp->value = val;
    }
}
int DoublyList::search(int val){
    Node* temp = this->head;
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->value == val)
            return count;
        count++;
    }
    return -1;
}
int DoublyList::remove(int val){
    Node* temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->value == val){
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
            delete temp;
            return 1;
        }
    }
    return 0;
}
void DoublyList::printList(){
    Node* temp = this->head;
    while(temp->next->next != NULL){
        temp = temp->next;
        cout << temp->value << " <--> ";
    }
    cout << endl;
}