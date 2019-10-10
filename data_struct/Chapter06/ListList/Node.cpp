#include "Node.h"

Node::Node(){
    next = NULL;
}

Node::Node(Node_entry item,Node *link){
    entry = item;
    next = link;
}

