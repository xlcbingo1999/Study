/*
    2019年9月23日完成链式栈的构建
    请下次完成swap函数
*/
#include <iostream>
#include <cctype>
#include <system_error>
#include <cstring>
#include <float.h>
#include <math.h>
using namespace std;

const int maxstack = 10;

typedef int Code_way; 
typedef int Stack_entry;
typedef int Node_entry;
enum Error_code
{
    succeed , overflow , underflow
};


struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item,Node *add_on = NULL);
};

Node::Node()
{
    next = NULL;
}

Node::Node(Node_entry item,Node *add_on)
{
    entry = item;
    next = add_on;
}



class Stack
{
protected:
    Node* top_node;
    int size;
public:
    Stack();
    bool empty()const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    int Getsize()const;
    Error_code top(Stack_entry &item) const;
    ~Stack();
    void operator=(const Stack &original); // overload
    Stack(const Stack &original); // copy constructor
    void print() const;
};

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

char get_command(){
    char command;
    bool waiting = true;
    cout << endl << "Select command and press <Enter> " << endl << "[+][-][*][/][%][p-print][c-change][?-input a number][q-quit]" << endl;
    while(waiting){
        cin >> command;
        command = tolower(command);
        if (strchr("?=+-*/qp%",command)!=NULL){
            waiting = false;
        }
        else
        {
            cout << "Please enter a valid command:" << endl;
            cout << "[?] push to stack [=] print top" << endl;
            cout << "[+][-][*][/][%]" << endl;
            cout << "[q]uit" << endl;
            cout << "[c]hange" << endl;
            cout << "[p]rint all" << endl;
        }
    }
    return command;
}

bool do_command(char command , Stack &numbers)
{
    Code_way p , q;
    switch (command)
    {
    case '?':
        cout << "Enter a real number:" << endl;
        cin >> p;
        if(numbers.Getsize() >= maxstack){
            cout << "overstack1" << endl;
        }
        numbers.push(p);
        break;
    case '=':
        if(numbers.empty()){
            cout << "understack0" << endl;
            break;
        }
        numbers.top(p);
        cout << p << endl;
        break;
    case '+':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); 
        if(numbers.Getsize() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(p+q);
        break;
    case '-':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); 
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); 
        if(numbers.Getsize() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(q - p);
        break;
    case '*':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); 
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); 
        if(numbers.Getsize() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(p * q);
        break;
    case '/':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); 
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); 
        if(numbers.Getsize() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(q / p); 
        break;
    case '%':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); 
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        if(q - (double)((int)q) < DBL_MIN ){
            cout << "Can do it" << endl;
            numbers.push(p);
            break;
        }
        else{
            numbers.pop();
            if(numbers.Getsize() >= maxstack){
                cout << "overstack2" << endl;
                break;
            }
            numbers.push(fmod(p,q)); 
            break;
        }
    case 'q':
        cout << "finished" << endl;
        return 0;
    case 'p':
        numbers.print();
        break;
    }
    return true;

}

int main(){
    Stack stored_numbers;
    while(do_command(get_command(),stored_numbers)); // 循环体是空的
    return 0;
}