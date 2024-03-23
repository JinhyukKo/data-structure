#include <iostream>
using namespace std;

class Stack{
    int size;
    int *stack;
    int top;
    public:
        Stack(int size=10):top{-1} ,size{size}{
            stack = new int[size];
        };
        ~Stack(){
            delete [] stack;
        };
        void push(int data){
            if(isFull()){
                cout << "Stack is full" << endl;
            } else{
                stack[++top] = data;
            }
        };
    
        int pop(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }else{
                return stack[top--];
            }
        };
        void display(){  
            if(isEmpty()){
                cout << "Stack is empty" << endl;
            }
            for (int i = 0; i <= top; i++)
            { 
                cout << stack[i] << " ";
            }
        };
        bool isEmpty(){
            return top == -1;
        };
        bool isFull(){
            return top == size-1;
        };

};
