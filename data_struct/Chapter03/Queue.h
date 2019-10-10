#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
// typedef double Error_code; 

// #define success 1;
// #define overflow 0;
// #define underflow -1; 
enum Error_code{success , overflow , underflow, rangeerror, too_many,
                found, non_found, null_func, duplication};
typedef double Queue_entry;

const int maxQueue = 10;

class Queue{
public:
    Queue();
    bool empty()const ;
    Error_code serve();
    Error_code retrieve(Queue_entry &x) const;
    Error_code append(const Queue_entry &x); 
    void print()const;
    void change();
protected:
    int count;
    int front,rear;
    Queue_entry entry[maxQueue];
};

#endif