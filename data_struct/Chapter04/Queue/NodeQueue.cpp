#include "NodeQueue.h"

Queue::Queue(){
    front = NULL;
    rear = NULL;
}

bool Queue::empty()const{
    if(rear == NULL) return true;
    return false;
}

int Queue::size()const{
	if(front == NULL) return 0;
	int count = 0;
	Node *window = front;
	if(window != NULL){
		++ count;
		window = window->next;
	}
	return count;
}

Error_code Queue::append(const Queue_entry &item){
    Node *new_rear = new Node(item);
    if(new_rear == NULL) return overflow;
    if(rear == NULL) {
		front = new_rear;
		rear = new_rear;
	}
    else{
        rear->next = new_rear;
        rear = new_rear;
    }
    return succeed;        
}

Error_code Queue::serve(){
    if(front == NULL) return underflow;
    Node *old_front = front;
    front = old_front->next;
    if(front == NULL) rear = NULL;
    delete old_front;
    return succeed;
}

Error_code Queue::retrieve(Queue_entry &item)const{
    if(front == NULL) return underflow;
    item = front->entry;
    return succeed;
}

Queue::~Queue(){
    while(front != NULL) {
        Node *old_front = front;
        front = old_front->next;
        delete old_front;
    }
    front =rear = NULL;
}

void Queue::operator=(const Queue &original){
    Node *new_front, *new_copy , *original_node = original.front;
    if(original_node == NULL) new_front =  NULL;
    else{
        new_copy = new_front = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
        }
        while(!empty()){
            serve();
        }
        front = new_front;
    }
}

Queue::Queue(const Queue &original){
    Node *new_copy, *original_node = original.front;
    if(original_node == NULL){
    	front = NULL;
		rear = NULL;
	} 
    else{
        front = new_copy = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
        }
    }
}

void Queue::print()const
{
	Node *window = front;
	int count = 0;
	while(window != NULL && count < 2){
		cout << " " << window->entry ;
		window = window->next;
		++ count;
	}
	cout << endl;
}

