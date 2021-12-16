struct Node{
    int value;
    struct Node* next;
    struct Node* previous;
};

class Stack{
    private:
        Node* head;
        Node* tail;
        int count;
    public:
        Stack();
        void push(int val);
        int pop();
        int size();
        int elementAt(int index);
        int contains(int value);
        void increaseSize();
        void decreaseSize();
        void printStack();
};