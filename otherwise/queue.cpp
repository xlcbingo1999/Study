#include <iostream>
#include <array>
#include <queue>
using namespace std;

int main(){

    queue<int> myqueue;
    for(int i = 0 ; i < 10 ; ++ i)
        myqueue.push(i);
    
    while(!myqueue.empty()){
        cout << myqueue.front() << endl;
        myqueue.pop();
    }
    int num;
    cin >> num;
    for(auto it = myqueue.front() ; it != myqueue.back() ; ++ it ){
        it += 1; 
    }
    while(!myqueue.empty()){
        cout << myqueue.front() << endl;
        myqueue.pop();
    }
}