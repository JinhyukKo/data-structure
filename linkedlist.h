#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* link;
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
        LinkedList():head{NULL},tail{NULL}{};
        ~LinkedList(){
            Node* current = head;
            while(current != NULL){
                Node* link = current->link;
                delete current;
                current = link;
            }
        };
        void insert(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->link = NULL;
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->link = newNode;
                tail = newNode;
            }
        };
        void insertAt(int data, int index){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->link = NULL;
            if(index == 0){
                newNode->link = head;
                head = newNode;
            }else{
                Node* current = head;
                for(int i = 0; i < index-1; i++){
                    current = current->link;
                }
                newNode->link = current->link;
                current->link = newNode;
            }
        };
        int getHead(){
            return head->data;
        };
        int getTail(){
            return tail->data;
        };
        Node* remove(){
            Node* current = head;
            while(current->link->link != NULL){
                cout<<current->data;
                current = current->link;
            }
            Node* temp = current->link;
            tail = current;
            current->link = NULL;
            return temp;
        };
        

        void display(){
            Node* current = head;
            while(current != NULL){
                cout << current->data << "->";
                current = current->link;
            }
        };

};
