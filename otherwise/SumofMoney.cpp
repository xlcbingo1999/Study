/*  2019.8.30
输入一个分钱的方式数的总和，得到分钱的钱数。
*/

/*

*/
#include <iostream>
#include <Queue>
#include <cctype>
#include <system_error>
using namespace std;
int main(){
    int sum;
    cin >> sum;
    for(int n = 0 ; n < 1000 ; ++n){
        int k = n / 5;
        if(sum == (2 * k + 2 + n * (k + 1) - 5 * k * (k + 1) / 2 - (k + 1) / 2) / 2)
            cout << n << endl;
    }
    

    return 0;
}