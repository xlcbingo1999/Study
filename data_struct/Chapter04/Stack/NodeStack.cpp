#include "NodeStack.h"
#include "define.h" 

int Stack::Getsize()const
{
    return size;
}

Stack::Stack()
{
    top_node = NULL;
    size = 0;
}

bool Stack::empty()const
{
    if(top_node == NULL) return true;
    return false;
}

Error_code Stack::push(const Stack_entry &item)
{
    Node *new_top = new Node(item, top_node);
    if(new_top == NULL) return overflow;
    top_node = new_top;
    ++ size;
    return succeed;        
}

Error_code Stack::pop()
{
    if(top_node == NULL) return underflow;
    Node *old_top = top_node;
    top_node = old_top->next;
    delete old_top;
    -- size;
    return succeed;
}

Error_code Stack::top(Stack_entry &item)const
{
    if(top_node == NULL) return underflow;
    item = top_node->entry;
    return succeed;
}

Stack::~Stack()
{
    while(top_node != NULL) 
    {
        Node *old_top = top_node;
        top_node = old_top->next;
        delete old_top;
    }
    size = 0;
}

void Stack::operator=(const Stack &original){
    Node *new_top, *new_copy , *original_node = original.top_node;
    if(original_node == NULL) new_top = NULL;
    else{
        new_copy = new_top = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
        }
        while(!empty()){
            pop();
        }
        top_node = new_top;
        size = original.size;
    }
}

Stack::Stack(const Stack &original){
    Node *new_copy, *original_node = original.top_node;
    if(original_node == NULL) top_node = NULL;
    else{
        top_node = new_copy = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
        }
        size = original.size;
    }
}

void Stack::print() const
{
    Node *p = top_node;

    if(empty()) cout << "Nothing" << endl;

    while(p != NULL){
        cout << p->entry << " " ;
        p = p->next;
    }
    cout << endl;
}

