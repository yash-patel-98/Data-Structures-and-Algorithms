struct Node
{
    int value;
    struct Node* next;
    struct Node* previous;
};
class DoublyList{
    private:
        struct Node* head;
        struct Node* tail;
    public:
        DoublyList();
        void insert(int val);
        int search(int val);
        int remove(int val);
        void printList();
};