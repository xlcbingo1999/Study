#ifndef NODESTACK_H
#define NODESTACK_H

#include "Node.h"
#include "define.h"
typedef int Queue_entry;

class Queue{
protected:
    Node *front, *rear;
public:
    Queue();
    bool empty()const;
    int size() const;
    Error_code append(const Queue_entry &item);
    Error_code serve();
    Error_code retrieve(Queue_entry &item) const;
    ~Queue();
    void operator=(const Queue &original);
    Queue(const Queue &original);
    void print() const;
};

#endif
