#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

class CircularList{
    Node* head;
    public:
    CircularList():head{NULL}{};
    void insert(int num){
        Node* newNode = new Node;
        newNode->data = num;
        newNode->link = NULL;
        if(head == NULL){
            head = newNode;
            newNode->link = newNode;
        }else{
            Node* current = head;
            while(current->link != head){
                current = current->link;
            }
            current->link = newNode;
            newNode->link = head;
        }
    };
    void insertAt (int num, int index){
        Node* newNode = new Node;
        newNode->data = num;
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
    }
    ~CircularList(){
        Node* current = head;
        while(current->link != head){
            Node* link = current->link;
            delete current;
            current = link;
        }
    };
    void remove(){
        Node* previous = NULL;
        Node* current = head;
        while(current->link != head){
            previous = current;
            current = current->link;
        }
        previous->link = head;
        delete current;

    }
    void remove(int value){
        Node* current = head;
        Node* previous = NULL;
        while(current->data !=value){
            previous = current;
            current = current->link;
            if (current == head){
                cout << "Value not found" << endl;
                return;
            }
        }
        previous->link = current->link;
        delete current;
    }
    
    void display(){
        Node* current = head;
        while(current->link != head){
            cout<< current->data << "->";
            current = current->link;
        }
        cout<< current->data << endl;
    }
};