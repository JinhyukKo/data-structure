#include <iostream>
using namespace std;

class Queue{
        int size;
        int *queue;
        int front;
        int rear;
        int capacity;

    public:
        Queue(int maxSize = 10):size{maxSize},front{-1},rear{-1}{
            queue = new int[size];
        };
        ~Queue(){
            delete [] queue;
        };

        void enqueue(int data){
            if(isFull()){
                cout << "Queue is full" << endl;
            } else{
                queue[++rear] = data;
            }
        };

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }else{
                return queue[front++];
            }
        };
        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }
            for (int i = front+1; i <= rear; i++)
            { 
                cout << queue[i] << " ";
            }
        };
        bool isEmpty(){
            return front == rear;
        };
        bool isFull(){
            return rear == size - 1;
        };
};

