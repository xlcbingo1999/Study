#ifndef NODE_H
#define NODE_H

#include "Define.hpp"

struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item,Node *link = NULL);
};

#endif
