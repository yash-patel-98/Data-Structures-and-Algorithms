#include "Queue.h"
#include<iostream>

using namespace std;

Queue::Queue(){
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}
void Queue::increaseSize(){
    this->size++;
}
void Queue::decreaseSize(){
    this->size--;
}
bool Queue::isEmpty(){
    if(this->size == 0)
        return true;
    return false;
}
void Queue::push_back(int val){
    if(this->head == NULL){
        this->head = new Node;
        this->tail = new Node;
        Node* temp = new Node;
        this->head->next = temp;
        this->tail->next = temp;
        temp->next = NULL;
        temp->previous = head;
        temp->value = val;
        cout << "Element Inserted" << endl;
        Queue::increaseSize();
    }
    else{
        Node* temp = this->tail->next;
        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
        this->tail->next = newNode;
        cout << "Element Inserted" << endl;
        Queue::increaseSize();
    }
}
int Queue::pop_front(){
    if(!Queue::isEmpty()){
        int value;
        Node* temp = this->head->next;
        value = temp->value;
        this->head->next = temp->next;
        delete temp;
        Queue::decreaseSize();
        return value;
    }
    else{
        cout << "Cannot remove element. Queue empty" << endl;
    }
} 
int Queue::peek(){
    return this->head->next->value;
}
int Queue::contains(int value){
    if(!Queue::isEmpty()){
        Node* temp = this->head;
        int c = 1;
        while(temp->next != NULL){
            temp = temp->next;
            if(temp->value == value)
                return c-1;
            c++;
        }
        return -1;
    }
    else
        return -2;
}
int Queue::remove(int value){
    if(!Queue::isEmpty()){
        Node* temp = this->head;
        while (temp->next != NULL){
            if(temp->value == value){
                temp->previous->next =  temp->next;
                temp->next->previous = temp->previous;
                delete temp;
                return 1;
            }
        }
        return 0;
    }
    return -1;
}
void Queue::print(){
    cout << "FRONT";
    Node* temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
        cout << " <-- " << temp->value;
    }
    cout << " <-- BACK" << endl;
}