/*  2019.8.30
假设一个算术表达式中可以包含三种括号：圆括号“(”和“)”，方括号“[”和“]”和花括号“{”和“ ”，且这三种括号可按任意的次序嵌套使用（如：…[…{… …[…]…]…[…]…(…)…)。编写判别给定表达式中所含括号是否正确配对出现的算法。输出结果YES 或者 NO。
Input
5+{[2X5]+2}
Output
YES
Sample Input
8-[{2+7]}
Sample Output
NO

*/

/* 2019.8.30
 (symbol = cin.get() ) == '\n' 
 这个语句注意括号，不然无法进行判断
*/
#include "C2Stack.h"
#include <iostream>
#include <cctype>
#include <system_error>
using namespace std;

int main(){
    Stack<char> brancket;
    bool is_match = true;
    char symbol;
    int brancket_count = 0;
    while(is_match){
        if( (symbol = cin.get() ) == '\n'){
            cout << brancket_count << endl;
            is_match = false;
        }
        if(symbol == '{' || symbol == '[' || symbol == '('){
            brancket.push(symbol);
        }
        if(symbol == '}' || symbol == ']' || symbol == ')'){
           // cout << "a" << endl;
            if(brancket.empty()){
                cout << "No match NO.1" << endl;
                is_match = false;
            }
            else{
                char match;
                brancket.top(match);
                brancket.pop();
                is_match = (match == '(' && symbol == ')')
                ||(match == '{' && symbol == '}')
                ||(match == '[' && symbol == ']');
                if(is_match){
                    ++ brancket_count;
                }
                if(!is_match){
                    cout << "No match NO.2" << endl;
                }
            }
        }
    }
    if(!brancket.empty()){
        cout << "No match NO.3" << endl;
    }
}
