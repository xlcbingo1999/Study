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

/*        if (strchr("?=+-/*q%c",command)!=NULL){
            waiting = false;
        }
等价于判断command是否是?=+等等字符
定义在<cstring>
*/
#include "C2Stack.h"
#include "C2Stack.cpp"
#include <iostream>
#include <cctype>
#include <system_error>
#include <cstring>
#include <float.h>
#include <math.h>
typedef int Code_way; 

char get_command(){
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter> " << endl << "[+][-][*][/][%][p-print][c-change][?-input a number][q-quit]" << endl;
    while(waiting){
        cin >> command;
        command = tolower(command);
        // if(command == '?' || command == '+' || command == '-' ||
        //     command == '*' || command == '/' || command == '=' ||
        //     command == 'q' || command == '%' || command == 'c'){
        //         waiting = false;
        //     }
        if (strchr("?=+-*/qp%c",command)!=NULL){
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

bool do_command(char command , Stack<Code_way> &numbers){
    Code_way p , q;
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
        if(q - (double)((int)q) < DBL_MIN ){
            cout << "Can do it" << endl;
            numbers.push(p);
            break;
        }
        else{
            numbers.pop(); // 弹出第二个数，使得栈中无数
            //numbers.print();
            if(numbers.size() >= maxstack){
                cout << "overstack2" << endl;
                break;
            }
            numbers.push(fmod(p,q)); // 推入一个数，使得栈中有数
            //numbers.print();
            break;
        }
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
    case 'p':
        numbers.print(); 
        break;
    }

    return true;
}
int main(){
    Stack<Code_way> stored_numbers;
    while(do_command(get_command(),stored_numbers)); // 循环体是空的
    return 0;
}