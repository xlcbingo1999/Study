#include <iostream>
using namespace std;
#include "Queue.h"
//#include "Extended_queue.h"

Queue::Queue(){
    count = 0;
    rear = maxQueue - 1;
    front = 0;
}
void Queue::print()const{
    for(int i = front ; i < front + count ; ++ i){  // 打印请从front到front+count
        cout << " " << entry[i] ; 
    }
    cout << endl;
}

Error_code Queue::append(const Queue_entry &item){
    Error_code outcome = success;
    if(count >= maxQueue) {
        outcome = overflow;
    }
    count ++;
    rear = ((rear + 1) == maxQueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return outcome;
}
Error_code Queue::serve(){
    Error_code outcome = success;
    if(count <= 0)  {
        outcome = underflow;
    }
    --count;
    front = ((front + 1) == maxQueue) ? 0 : (front + 1); 
    return outcome;
}
Error_code Queue::retrieve(Queue_entry &item) const{
    Error_code outcome = success;
    if(count <= 0) {
        outcome = underflow;
    }
    else {
        item = entry[front];
    }
    return outcome;
}
bool Queue::empty()const{
    bool outcome = true;
    if(count > 0) {
        outcome = false;
    }
    return outcome;
}