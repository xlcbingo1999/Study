#include <iostream>
using namespace std;
#include "Extended_queue.h"
// #include "Queue.cpp"

int Extended_queue::size()const{
    return count;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item){
    Error_code outcome = success;
    if(count <= 0)  {
        outcome = underflow;
    }
    item = entry[front];
    --count;
    front = ((front + 1) == maxQueue) ? 0 : (front + 1); 
    return outcome;
}
// 此处应该讨论front的位置
bool Extended_queue::full()const{
    if(count == maxQueue){
        return true;
    }
    return false;
}

void Extended_queue::clear(){
    count = 0;
    front = 0;
    rear = 0;
}