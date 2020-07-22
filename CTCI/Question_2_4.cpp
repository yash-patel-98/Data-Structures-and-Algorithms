/*
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
*/

#include<iostream>

using namespace std;

struct Node{
    int val;
    struct Node* next;
};

void performParition(struct Node* head, int x){
    struct Node* temp = head;
    struct Node* part2 = NULL;struct Node* part1 = NULL;struct Node* part1Head = NULL; struct Node* part2Head = NULL;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->val < x){
            if(part1 == NULL){
                part1->next = NULL;
                part1->val = temp->val;
                part1Head->next = part1;
            }
            else{
                struct Node* newNode;
                newNode->next = part1->next;
                newNode->val = temp->val;
                part1->next = newNode;
                part1 = part1->next;
            }
        }
        else{
            if(part2 == NULL){
                part2->next = NULL;
                part2->val = temp->val;
                part2Head->next = part2;
            }
            else{
                struct Node* newNode;
                newNode->next = part2->next;
                newNode->val = temp->val;
                part2->next = newNode;
                part2 = part2->next;
            }
        }
    }
    head->next = part1Head->next;
    part1->next = part2Head->next;
}

int main(void){

}