#include<iostream>
#include<cmath>
using namespace std;
double multi(double arr[]) {
    double sum = 0;
    for(int i = 0 ; i < 10 ; ++i){
        sum += (arr[i] * arr[i]);
    }
    return sum;
}
int main()
{
    double arr[10];
    for(int i = 0 ; i < 10 ; ++i){
        cin >> arr[i];
    }
    double  sum_of_multi  = multi(arr);
    double fin = sum_of_multi - (sum_of_multi * sum_of_multi) / 10;
    cout << fin << endl;
    return 0;
}
