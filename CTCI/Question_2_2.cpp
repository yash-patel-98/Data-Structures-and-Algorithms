#include <iostream>
#include <vector>
#include <set>

struct Node{
    int val;
    struct Node* next;
};

using namespace std;


//trivial solution
struct Node* kthElementFromLast(struct Node* head, int k){
    struct Node* temp = head->next;
    if(head == NULL)
        return NULL;
    int size = 1;
    while(temp->next != NULL){
        temp = temp ->next;
        size++;
    }
    int x = size - k;
    size = 0;
    temp = head->next;
    while(size < x){
        temp = temp->next;
        size++;
    }   
    return temp;
}

//Non trivial solution
/*
    A more optimal, but less straightforward, solution is to implement this iteratively. We can use two pointers,
    pl and p2. We place them k nodes apart in the linked list by putting p2 at the beginning and moving pl
    k nodes into the list. Then, when we move them at the same pace, pl will hit the end of the linked list after
    LENGTH - k steps. At that point, p2 will be LENGTH - k nodes into the list, or k nodes from the end. 
*/

struct Node* kthElementFromLastNonTrivial(struct Node* head,int k){
    struct Node* p1 = head -> next;
    struct Node* p2 = head->next;
    for(int i = 0; i < k;i++){
        if(p1 == NULL)
            return NULL;
        p1 = p1->next;
    }
    while(p1 != NULL){
        p1 = p1->next;
        p2 = p2 ->next;
    }
    return p2;
}

//Main Function not written.
int main(void){

}