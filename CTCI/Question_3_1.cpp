#include<iostream>

using namespace std;

struct Node{
    int val;
    struct Node* next;
};


class Stack{
    public:
        struct Node* head;
        struct Node* minStackHead;
        Stack(){
            head = NULL;
            minStackHead = NULL;
        }
        void push(int val){
            if(head == NULL){
                struct Node* newNode;
                struct Node* minStackNewNode;
                newNode->val = val;
                newNode->next = NULL;
                head -> next = newNode;
                minStackNewNode->val = min(val,INT32_MAX);
                minStackHead->next = minStackNewNode;
                minStackNewNode->next = NULL;
            }
            else{
                struct Node* newNode;
                newNode->val = val;
                newNode->next = head->next;
                head->next = newNode;
                if(newNode->val < minStackHead->val){
                    struct Node* newMinStackNode;
                    newMinStackNode->val = newNode->val;
                    newMinStackNode->next = minStackHead->next;
                    minStackHead->next = newMinStackNode;
                }
            }
        }
        int pop(){
            if(head -> next != NULL){
                struct Node* temp;
                temp = head->next;
                int val = temp->val;
                head->next = temp->next;
                delete temp;
                if(val == minStackHead->next->val){
                    // This works only if duplicate elements are not entered into the stack.
                    // If duplicate elements are pushed then better to keep a track of all 
                    // the mins as new elements are entered into the stack
                    struct Node* temp;
                    temp = minStackHead -> next;
                    minStackHead->next = temp->next;
                    delete temp;
                }
                return val;
            }
            else{
                return -1;
            }
        }
        int peek(){
            if(head->next != NULL)
                return head->next->val;
            else
                return -1;
        }
};

int main(void){

}