/*
    这个是一个模板栈的类
    请在定义的时候声明：Stack<int> Stack<double>
*/
#ifndef S_H
#define S_H
#include <iostream>
#include <cctype>
#include <system_error>
#include <cstring>
using namespace std;

enum Error_code{success , overflow , underflow, rangeerror, too_many,
                found, non_found, null_func, duplication};

const int maxstack = 10;

template<typename Stack_entry>
class Stack{
public:
    Stack();
    int size();
    bool empty()const ;
    Error_code pop();
    Error_code top(Stack_entry &) const;
    Error_code push(const Stack_entry &); 
    void print()const;
    void change();
private:
    int count;
    Stack_entry entry[maxstack];
};


#endif