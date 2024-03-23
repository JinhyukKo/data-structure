struct Node{
    int data;
    Node* next;
    Node* prev;
};


class DoublyList { 
    private:
        Node* head;
        Node* tail;
    public:
        DoublyList():head{NULL},tail{NULL}{};
        ~DoublyList();
        void insert(int data);
        void insert(int data, int index);
        void remove(int index);
        void print();
        int getSize();
        bool isEmpty();
        int get(int index);
        void set(int data, int index);
        int indexOf(int data);
        bool contains(int data);
        void clear();
};