/*  2019.8.28
《C语言宏定义的几个坑和特殊用法》
网址:https://www.cnblogs.com/ralap7/p/9172226.html
宏定义下的分号吞噬问题:
#define SKIP_SPACES(p, limit)  
     { char *lim = (limit);         
       while (p < lim) {            
         if (*p++ != ' ') {         
           p--; break; }}}
假设有如下一段代码：
if (*p != 0)
   SKIP_SPACES (p, lim);
else ...
一编译，GCC报error: ‘else’ without a previous ‘if’。原来这个看似是一个函数的宏被展开后是一段大括号括起来的代码块，加上分号之后这个if逻辑块就结束了，所以编译器发现这个else没有对应的if。
这个问题一般用do ... while(0)的形式来解决：
#define SKIP_SPACES(p, limit)     
     do { char *lim = (limit);         
          while (p < lim) {            
            if (*p++ != ' ') {         
              p--; break; }}}          
     while (0)
*/

/*
2019.8.30
全部改完，保证正确性。
请31日完成第二个C++程序。
*/

/*
逆波兰计算器：《离散数学与结构》中二叉树的后序遍历
*/
#include <iostream>
#include <cctype>
#include <system_error>
#include <cstring>
using namespace std;
typedef  int Stack_entry;
// typedef  int Error_code; 
enum Error_code{success , overflow , underflow, rangeerror, too_many,
                found, non_found, null_func, duplication};

// #define success 1;
// #define overflow 0;
// #define underflow -1; 

const int maxstack = 10;

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
Stack::Stack(){
    count = 0;
}
void Stack::print()const{
    for(int i = 0 ; i < count ; ++ i){
        cout << " " << entry[i] ; 
    }
    cout << endl;
}

Error_code Stack::push(const Stack_entry &item){
    Error_code outcome = success;
    if(count >= maxstack) {
        outcome = success;
    }
    else {
        entry[count ++] = item;
    }
    return outcome;
}
Error_code Stack::pop(){
    Error_code outcome = success;
    if(count == 0)  {
        outcome = underflow;
    }
    else  {
        --count;
    }
    return outcome;
}
Error_code Stack::top(Stack_entry &item) const{
    Error_code outcome = success;
    if(count == 0) {
        outcome = underflow;
    }
    else {
        item = entry[count - 1];
    }
    return outcome;
}
bool Stack::empty()const{
    bool outcome = true;
    if(count > 0) {
        outcome = false;
    }
    return outcome;
}
int Stack::size(){
    return count;
}
void Stack::change(){
    Stack_entry temp1;
    Stack_entry temp2;
    top(temp1);
    pop();
    top(temp2);
    pop();
    push(temp1);
    push(temp2);
}

char get_command(){
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter> " << endl << "[+][-][*][/][%][?-input a number][q-quit]" << endl;
    while(waiting){
        cin >> command;
        command = tolower(command);
        // if(command == '?' || command == '+' || command == '-' ||
        //     command == '*' || command == '/' || command == '=' ||
        //     command == 'q' || command == '%' || command == 'c'){
        //         waiting = false;
        //     }
        if (strchr("?=+-*/q%c",command)!=NULL){
            waiting = false;
        }
        else
        {
            cout << "Please enter a valid command:" << endl;
            cout << "[?] push to stack [=] print top" << endl;
            cout << "[+][-][*][/][%]" << endl;
            cout << "[q]uit" << endl;
            cout << "[c]hange" << endl;
        }
    }
    return command;
}

bool do_command(char command , Stack &numbers){
    int p , q;
    switch (command)
    {
    case '?':
        cout << "Enter a real number:" << endl;
        cin >> p;
        if(numbers.size() >= maxstack){
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
        //numbers.print();
        cout << p << endl;
        break;
    case '+':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); // 弹出第一个数
        //numbers.print();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); // 弹出第二个数，使得栈中无数
        //numbers.print();
        if(numbers.size() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(p+q); // 推入一个数，使得栈中有数
        //numbers.print();
        break;
    case '-':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); // 弹出第一个数
        //numbers.print();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); // 弹出第二个数，使得栈中无数
        //numbers.print();
        if(numbers.size() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(q - p); // 推入一个数，使得栈中有数
        //numbers.print();
        break;
    case '*':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); // 弹出第一个数
        //numbers.print();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); // 弹出第二个数，使得栈中无数
        //numbers.print();
        if(numbers.size() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(p * q); // 推入一个数，使得栈中有数
        //numbers.print();
        break;
    case '/':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); // 弹出第一个数
        //numbers.print();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); // 弹出第二个数，使得栈中无数
        //numbers.print();
        if(numbers.size() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(q / p); // 推入一个数，使得栈中有数
        //numbers.print();
        break;
    case '%':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        }
        numbers.top(p);
        numbers.pop(); // 弹出第一个数
        //numbers.print();
        if(numbers.empty()){
            cout << "understack2" << endl;
            break;
        }
        numbers.top(q);
        numbers.pop(); // 弹出第二个数，使得栈中无数
        //numbers.print();
        if(numbers.size() >= maxstack){
            cout << "overstack2" << endl;
            break;
        }
        numbers.push(p % q); // 推入一个数，使得栈中有数
        //numbers.print();
        break; 
    case 'c':
        if(numbers.empty()){
            cout << "understack1" << endl;
            break;
        } 
        numbers.change();
        numbers.print();
        break;
    case 'q':
        cout << "finished" << endl;
        return 0;
    }
    return true;
}
int main(){
    Stack stored_numbers;
    while(do_command(get_command(),stored_numbers)); // 循环体是空的
    return 0;
}