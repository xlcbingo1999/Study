#include <iostream>
#include <array>
#include <cstring>

using namespace std;

void print(std::array<int,10> arr){
    for(int i = 0 ; i < arr.size() ; ++ i)
        cout << arr[i] << " ";
}

int main(){
    array<int,10> arr;
    for(int i = 0 ; i < arr.size() ; ++ i){
        arr[i] = i * 10;
    }
    print(arr);
    cout << endl;
    for(auto it = arr.begin() ; it != arr.end() ; ++ it )
        *it += 1;
    print(arr);
    cout << endl;
    
    // array<string,10> str;
    // for(int i = 0 ; i < str.size() ; ++ i)
    //     cin >> str[i]; 
    // print(str);
}