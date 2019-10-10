#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "Node.h"
#include "define.h"
typedef int Queue_entry;.

class Queue{
protected:
    Node *front , *rear;
public:
    Queue();
    bool empty()const;
    Error_code append(const Queue_entry &item);
    Error_code serve();
    Error_code retrieve(Queue_entry &item) const;
    ~Queue();
    void operator = (const Queue &original);
    Queue(const Queue &original);
};

class Extend_Queue: public Queue{
public:
    // bool full() const;
    int size() const;
    void clear() ;
    Error_code serve_and_retrieve(Queue_entry &item);

}

#endif