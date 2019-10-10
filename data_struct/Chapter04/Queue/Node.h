#ifndef NODE_H
#define NODE_H

#include "define.h"

struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item,Node *add_on = NULL);
};

#endif
