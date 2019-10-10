#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i = 0 ; i < 10 ; ++i)
        cin >> arr[i];
    for(int i = 0 ; i < 10 ; ++i){
        for(int j = i - 1 ; j >= 0 ; --j){
            if(a[j] < a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0 ; i < 10 ; ++i)
        cout << arr[i];
}