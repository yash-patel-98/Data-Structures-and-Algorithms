#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}
void Stack::increaseSize(){
    this->count++;
}
void Stack::decreaseSize(){
    this->count--;
}
int Stack::size(){
    return this->count;
}
void Stack::push(int val){
    if(this->head == NULL){
        this->head = new Node;
        this->tail = new Node;
        Node* temp = new Node;
        /**
         * Stack will look something like 
         *  NULL <- head -> <-> value1 <-> value2 <-> value3 <-> <- tail -> NULL
        */
        this->head->next = temp;
        this->head->previous = NULL;
        this->tail->previous = temp;
        this->tail->next = NULL;
        temp->value = val;
        temp->previous = this->head;
        temp->next = this->tail;
        Stack::increaseSize();
    }
    else{
        Node* temp = new Node;
        // Last element will be added from the tail  end
        temp->value = val;
        temp->next = this->tail;
        temp->previous = this->tail->previous;
        temp->previous->next = temp;
        this->tail->previous = temp;
        Stack::increaseSize();
    }
}
int Stack::pop(){
    if(Stack::size() == 0)
        return -1;
    else{
        Node* temp = new Node;
        temp = this->tail->previous;
        int val = temp->value;
        this->tail->previous = temp -> previous;
        temp->previous->next = this->tail;
        delete temp;
        Stack::decreaseSize();
        if(Stack::size() == 0){
            this->head = NULL;
            this->tail = NULL;
        }
        return val;
    }
}
int Stack::elementAt(int index){
    if(index < Stack::size()){
        Node* temp = this->head->next;
        for(int i = 0; i < index;i++){
            temp = temp->next;
        }
        return temp->value;
    }
    else
        return -1;
}
int Stack::contains(int value){
    if(Stack::size() > 0){
        Node* temp = this->head;
        int c = 1;
        while(temp->next != NULL){
            temp = temp->next;
            if(temp -> value == value)
                return c-1;
            c++;
        }
        return -1;
    }
    return -2;
}
void Stack::printStack(){
    Node* temp = this->tail;
    cout << "\tTOP" << endl;
    if(head != NULL){
        while(temp->previous->previous != NULL){
            temp = temp->previous;
            cout << "\t" << temp->value << endl;
        }
    }
    cout << "\tBOTTOM" << endl;
}