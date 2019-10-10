#include "NodeExtendedQueue.h"

bool Extended_Queue::full() const{
//	if(size() >= maxqueue) return true;
	return false;
}
int Extended_Queue::size()const{
    Node *window = front;
    int count = 0;
    while(window != NULL){
        ++ count;
        window = window->next;
    }
    return count;
}

Error_code Extended_Queue::serve_and_retrieve(Queue_entry &item){
    if(front == NULL) return underflow;
    item = front->entry;
    Node *old_front = front;
    front = old_front->next;
    if(front == NULL) rear = NULL;
    delete old_front;
    return succeed;
}

void Extended_Queue::clear(){
    while(front != NULL) {
        Node *old_front = front;
        front = old_front->next;
        delete old_front;
    }
    front =rear = NULL;
}
