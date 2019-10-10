#include "ListList.hpp"
#include "Define.hpp"

List::List()
{
    count = 0;
    head = nullptr;
}

List::List(const List &copy)
{
    Node *new_head , *new_copy , *origin_node = copy.head;
//    cout << "orig:" << origin_node->entry << endl;
    if(origin_node == NULL) head = NULL;
    else{
        clear();
        new_head = new_copy = new Node(origin_node->entry);
        while(origin_node->next != NULL){
            origin_node = origin_node->next;
            new_copy->next = new Node(origin_node->entry);
            new_copy = new_copy->next;
        }
        count = copy.count;
        head = new_head;
    }
}

List::~List()
{
    while(head != nullptr){
        Node *old = head;
        head = head->next;
        delete old;
    }
    count = 0;
}

int List::size()const
{
    return count;
}

bool List::empty()const
{
    if(count == 0) return true;
    return false;
}

void List::clear()
{
    while(head != nullptr){
        Node *old = head;
        head = head->next;
        delete old;
    }
    count = 0;
}

void List::print()const
{
    Node *ptr = head;
    int count = 0;
    while(ptr != nullptr && count <= max_list){
        cout << ptr->entry << " " ;
        ptr = ptr->next;
        ++ count;
    }
    cout << endl;
}

void List::operator= (const List &copy)
{
    Node *new_head , *new_copy , *origin_node = copy.head;
//    cout << "orig:" << origin_node->entry << endl;
    if(origin_node == NULL) head = NULL;
    else{
        if(!empty()) clear();
        new_head = new_copy = new Node(origin_node->entry);
//        cout << "new_head:" << new_head->entry << endl;
        while(origin_node->next != NULL){
            origin_node = origin_node->next;
            new_copy->next = new Node(origin_node->entry);
            new_copy = new_copy->next;
        }
        count = copy.count;
        head = new_head;
    }
}

Node* List::set_position(int position)const
{
    Node *ptr = head;
    for(int i = 0 ; i < position ; ++i){
        ptr = ptr->next;
    }
    return ptr;
}

Error_code List::retrieve(int position,List_entry &x)const
{
    if(position < 0 || position > count) return range_err;
    x = (set_position(position))->entry;
    return success;
}

Error_code List::replace(int position , const List_entry &x)
{
    if(position < 0 || position > count - 1) return range_err;
    Node *ptr = set_position(position);
    ptr->entry = x;
    return success;
}

Error_code List::remove(int position, List_entry &x)
{
    if(position < 0 || position > count) return range_err;
    Node *prev, *old;
    Node *old_head = head;
    if(position == 0){
        head = head->next;
        delete old_head;
    }
    else{
        prev = set_position(position - 1);
        old = prev->next;
        prev->next = old->next;
        delete old;
    }
    --count;
    return success;
}

Error_code List::insert(int position, const List_entry &x)
{
    if(position < 0 || position > count) return range_err;
    Node *prev, *following , *new_node;
    if(position == 0){
        following = head;
    }
    else{
        prev = set_position(position - 1);
        following = prev->next;
    }
    new_node = new Node(x, following);
    if(new_node == nullptr) return overflow;
    if(position == 0) head = new_node;
    else prev->next = new_node;
    ++count;
    return success;
}

Error_code List::reverse()
{
    if(head == NULL || head->next == NULL) return success;
    int count = size();
    Node *tail;
    tail = new Node(head->entry,NULL);

    Node *begin = NULL;
    Node *temp = tail;

    while(--count)
    {
        Node *del = head;
        head = head->next;

        delete del;
        begin = new Node(head->entry);
        begin->next = temp;

        tail->next = NULL;
        temp = begin;
//        cout << i << "begin:" << begin->entry << endl;
//        cout << i << "begin->next:" << begin->next->entry << endl;
//        cout << i << "begin->next->next:" << begin->next->next->entry << endl;
//        cout << i << "begin->next->next->next:" << begin->next->next->next->entry << endl;
    }
    head = begin;
    return success;
}
