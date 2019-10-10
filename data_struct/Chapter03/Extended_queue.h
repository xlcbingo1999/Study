#ifndef EXTENDED_QUEUE_H
#define EXTENDED_QUEUE_H
#include <iostream>
#include "Queue.h"
using namespace std;


class Extended_queue:public Queue{
public:
    bool full()const;
    int size()const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};

#endif

