#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#include "Node.h"
#include "NodeStack.h"
#include "define.h" 

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
//    case '%':
//        if(numbers.empty()){
//            cout << "understack1" << endl;
//            break;
//        }
//        numbers.top(p);
//        numbers.pop(); 
//        if(numbers.empty()){
//            cout << "understack2" << endl;
//            break;
//        }
//        numbers.top(q);
//        if(q - (double)((int)q) < DBL_MIN ){
//            cout << "Can do it" << endl;
//            numbers.push(p);
//            break;
//        }
//        else{
//            numbers.pop();
//            if(numbers.Getsize() >= maxstack){
//                cout << "overstack2" << endl;
//                break;
//            }
//            numbers.push(fmod(p,q)); 
//            break;
//        }
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
