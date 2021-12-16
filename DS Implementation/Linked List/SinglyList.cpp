#include "SinglyList.h"
#include<iostream>

using namespace std;

SinglyList::SinglyList(){
    this->head = NULL;
    this->tail = NULL;
}
void SinglyList::insert(int val){
    if(this->head == NULL){
        this->head = new Node;
        Node* tmp = new Node;
        tmp->value = val;
        this->head->next = tmp;
        tmp->next = this->tail;
    }
    else{
        Node *tmp = this->head;
        while(tmp->next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = new Node;
        tmp = tmp->next;
        tmp->value = val;
        tmp->next = tail;
    }
}
int SinglyList::search(int val){
    Node* tmp = this->head;
    int count = 1;
    while(tmp->next != NULL){
        tmp = tmp->next;
        if(tmp->value == val)
            return count;
        count++;
    }
    // If value not found return -1 else return index
    return -1;
}
int SinglyList::remove(int val){
    Node* tmp = this->head;
    Node* previous = tmp;
    while(tmp->next != NULL){
        tmp = tmp->next;
        if(tmp->value == val){
            previous->next = tmp->next;
            delete tmp;
            return 1;
        }
        previous = tmp;
    }
    // If value found and deleted return 1
    // Else return 0
    return 0;
} 
void SinglyList::printList(){
    Node* tmp = this->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
        cout << tmp->value <<" --> ";
    }
    cout << endl;
}
