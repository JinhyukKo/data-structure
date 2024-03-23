
#include <algorithm>    
#include <iostream>
using namespace std;
class Heap{
    private:
        int heap[1000];
        int size;
    public:
        Heap():size{0}, heap{0} {};
        int peek(){
            return heap[1];
        };

        void insert(int data){
            if(size == 0){
                heap[1] = data;
                size++;
            }
            else{
                heap[++size] = data;// add to end of array
                int i = size;
                while(i > 1){
                    if(heap[i] > heap[i/2]){// if child is greater than parent
                        int temp = heap[i]; 
                        heap[i] = heap[i/2]; // swap
                        heap[i/2] = temp;
                        i /= 2;
                    }
                    else{// if child is less than parent
                        break;
                    }
                }
            }
        };
        int remove(){
            int root = heap[1];
            heap[1] = heap[size];
            int i = 1;
            while(i < size){
                if(heap[i] < heap[i*2] || heap[i] < heap[i*2+1]){
                    if(heap[i*2] > heap[i*2+1]){
                        int temp = heap[i];
                        heap[i] = heap[i*2];
                        heap[i*2] = temp;
                        i *= 2;
                    }
                    else{
                        int temp = heap[i];
                        heap[i] = heap[i*2+1];
                        heap[i*2+1] = temp;
                        i = i*2+1;
                    }
                }
                else{
                    break;
                }
            }
            return root;
        };

        
        void print(){
            for(int i = 1; i <= size; i++){
                cout << heap[i] << " ";
            }
            cout << endl;
        };

        int getSize(){
            return size;
        };
        // bool isEmpty();
        // int get(int index);
        // void set(int data, int index);
        // int indexOf(int data);
        // bool contains(int data);
        // void clear();
};
