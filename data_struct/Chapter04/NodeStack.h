#ifndef NODESTACK_H
#define NODESTACK_H

#include "Node.h"
#include "define.h"
typedef int Stack_entry;

class Stack{
protected:
    Node* top_node;
public:
    Stack();
    bool empty()const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    ~Stack();
    operator=(const Stack &original);
    Stack(const Stack &original);
};

#endif