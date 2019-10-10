#include <iostream>
#include <cstring>
using namespace std;

const int maxstack = 10;


enum Error_code
{
    succeed , overflow , underflow
};

class Polynomial
{
private:
    double value;
public:
    // void read();
    void print();
    void equals_sum(Polynomial p, Polynomial q);
    // void equals_difference(Polynomial p ,Polynomial q);
    // void equals_product(Polynomial p , Polynomial q);
    // Error_code equals_quotient(Polynomial p, Polynomial q);
    double getvalue()const;
};

void Polynomial::equals_sum(Polynomial p,Polynomial q)
{
    value = p.value + q.value;
}

double Polynomial::getvalue() const{
    return value;
}

void Polynomial::print(){
    cout << getvalue() ;
}

typedef Polynomial Stack_entry;
typedef Polynomial Node_entry;

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
        cout << p->entry.getvalue() << " " ;
        p = p->next;
    }
    cout << endl;
}



char get_command()
{
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

bool do_command(char command, Stack &stored_polynomials)
{
    Polynomial p,q,r;
    switch (command)
    {
    case '?':
        // p.read();
        if(stored_polynomials.push(p) == overflow)
            cout << "Error: stack full,lost polynomial" << endl;
        break;
    case '=':
        if(stored_polynomials.empty())
            cout << "stack empty" << endl;
        else{
            stored_polynomials.top(p);
            p.print();
        }
        break;
    case '+':
        if(stored_polynomials.empty())
            cout << "stack empty" << endl;
        else{
            stored_polynomials.top(p);
            stored_polynomials.pop();
            if(stored_polynomials.empty()){
                cout << "stack has just one polynomial" << endl;
                stored_polynomials.push(p);
            }
            else{
                stored_polynomials.top(q);
                stored_polynomials.pop();
                r.equals_sum(q,p);
                if(stored_polynomials.push(r) == overflow)
                    cout << "Error: stack full,lost polynomial" << endl;
            }
        }
        break;
    case 'q':
        cout << "finished" << endl;
        return false;
    }
    return true;
}

int main()
{
    Stack stored_polynomials;
    while(do_command(get_command(),stored_polynomials));
}
