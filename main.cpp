#include <iostream>
// #include "array.h"<
// #include "linkedlist.h"
// #include "stack.h"
// #include "queue.h"
#include "heap.h"
// #include "circularlist.h"
using namespace std;


int main()
{
    Heap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.insert(40);
    heap.print();
    heap.remove();
    heap.print();
    heap.remove();
    heap.print();
    heap.remove();
    heap.print();
    
    return 0;
}
