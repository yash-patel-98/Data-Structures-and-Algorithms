/*
    Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
    the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
    that node.
*/

#include<iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            this->val = data;
        }
};

void deleteMiddleNode(struct Node* node){
    struct Node* temp = node;
    while(temp->next != NULL){
        temp -> val = temp->next->val;
        temp = temp -> next;
    }
    delete temp;
}


int main(void){
    Node n1(5);
}