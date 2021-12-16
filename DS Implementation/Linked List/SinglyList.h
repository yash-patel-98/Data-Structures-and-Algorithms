struct Node{
    int value;
    struct Node* next;
};
class SinglyList{
    private:
        struct Node* head;
        struct Node* tail;
    public:
        SinglyList();
        void insert(int val);
        int search(int val);
        int remove(int val);
        void printList();
};