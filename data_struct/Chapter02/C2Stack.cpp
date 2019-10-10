#include "C2Stack.h"
#include <iostream>
#include <cctype>
#include <system_error>
#include <cstring>
using namespace std;
template<typename Stack_entry>
Stack<Stack_entry>::Stack(){
    count = 0;
}

template<typename Stack_entry>
int Stack<Stack_entry>::size(){
    return count;
}

template<typename Stack_entry>
void Stack<Stack_entry>::print()const{
    for(int i = 0 ; i < count ; ++ i){
        cout << " " << entry[i] ; 
    }
    cout << endl;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item){
    Error_code outcome = success;
    if(count >= maxstack) {
        outcome = success;
    }
    else {
        entry[count ++] = item;
    }
    return outcome;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::pop(){
    Error_code outcome = success;
    if(count == 0)  {
        outcome = underflow;
    }
    else  {
        --count;
    }
    return outcome;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item) const{
    Error_code outcome = success;
    if(count == 0) {
        outcome = underflow;
    }
    else {
        item = entry[count - 1];
    }
    return outcome;
}

template<typename Stack_entry>
bool Stack<Stack_entry>::empty()const{
    bool outcome = true;
    if(count > 0) {
        outcome = false;
    }
    return outcome;
}

template<typename Stack_entry>
void Stack<Stack_entry>::change(){
    Stack_entry temp1;
    Stack_entry temp2;
    top(temp1);
    pop();
    top(temp2);
    pop();
    push(temp1);
    push(temp2);
}