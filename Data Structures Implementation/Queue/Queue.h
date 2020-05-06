struct Node{
    int value;
    struct Node* next;
    struct Node* previous;
};
class Queue{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        Queue();
        void push_back(int value);
        int pop_front();
        int peek();
        int contains(int value);
        int remove(int value);
        bool isEmpty();
        void increaseSize();
        void decreaseSize();
        void print();
};