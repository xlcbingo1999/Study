#include <iostream>
#include <cmath>
using namespace std;

double fcn(double stuff){
    double error = 1e-15;
    // = stuff;
    if(stuff < 0)
        return 0;
    double temp = stuff;
    while(abs(temp - stuff/temp) > error * temp){
        temp = (stuff / temp + temp) / 2.0;
    }
    return temp;
}

int main(){
    double num ;
    cin >> num;
    cout << fcn(num);
}