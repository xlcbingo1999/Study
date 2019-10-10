#include<iostream>
using namespace std;

int cale(int data){
    int sum = 0;

    if(data == 0) return 0;
    else if(data < 0){
        cout << "Please a valid number (number >= 0):" << endl;
        cin >> data;
        cale(data);
    }
    else{
        while(data != 0){
            sum += (data % 10) * (data % 10) * (data % 10);
            data /= 10;
        }
        return sum;
    }
}

int main(){
    int num;
    int fin = 1;

    while(fin){
        cin >> num;
        fin = cale(num);
        if(!fin) break;
        else cout << fin << endl;
    }
    
    return 0;
}
