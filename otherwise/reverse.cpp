#include <iostream>
using namespace std;
int reverseInteger(int number) {
        // write your code here
        int fin = 0;
        int count = 0;
        int num[5];
        for(count = 0 ; number != 0 ; ++ count){
            num[count] = number % 10;
            number = number / 10;
        }
        for(int i = count ; i > 0 ;  -- i){
            fin += num[i];
        }
        return fin;
    }

int main(){
    int num;
    cin >> num;
    cout << reverseInteger(num);

}