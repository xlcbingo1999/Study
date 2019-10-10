#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> charw;
    char str[10] = "IloveC++!";
    for(int i = 0 ; i < 10 ; ++ i){
        charw.push(str[i]);
    }
    while(!charw.empty()){
        cout << charw.top() << " ";
        charw.pop();
    }
}