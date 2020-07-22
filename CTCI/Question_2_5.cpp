/*

Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 - > 1 -> 2. That is, 912.

*/

#include<iostream>

using namespace std;

struct Node{
    int val;
    struct Node* next;
};

//Original Question
struct Node* sumList(struct Node* head1, struct Node* head2){
    int carry = 0;
    struct Node* list1 = head1;
    struct Node* list2 = head2;
    struct Node* sumListHead;
    struct Node* sumList = NULL;
    int addition;
    while(list1->next != NULL && list2->next != NULL){
        list1 = list1->next;
        list2 = list2->next;
        addition = list1->val + list2->val;
        if(addition > 10){
            carry = 1;
            addition = addition % 10 + carry;
            carry = 0;
        }    
        if(sumList == NULL){
            struct Node* newNode;
            newNode->val = addition;
            sumList = newNode;
            sumList->next = NULL;
            sumListHead->next = sumList;
        }
        else{
            struct Node* newNode;
            newNode->val = addition;
            sumList->next = newNode;
            sumList = sumList->next;
            sumList->next = NULL;
        }
    }
    return sumListHead;
}

// Follow Up Question
// Idea. Push elements of both the lists to stack and pop each element.
// Add them and check for carry


int main(){

}