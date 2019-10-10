#include<iostream>
#include<cmath>
using namespace std;
double fun(double x) {
    return (exp(x) - 2 - x);
}
int main()
{
    double a0 = -2.4;
    double b0 = -1.6;
    int count = 0;
    while(fun(a0) * fun(b0) < 0 && count <= 4){
        double c = b0 - fun(b0) * (b0 - a0) / (fun(b0) - fun(a0));
        cout << "c" << count << " = " << c << endl;
        ++ count;
        if(fun(a0) * fun(c) < 0){
            cout << "f(a):" << fun(a0) << "  " << "f(b0):" << fun(b0) << "  f(c):" << fun(c) << endl;
            cout << "b0 changes to c"<<endl;
            b0 = c;
        }
        if(fun(c) * fun(b0) < 0){
            cout << "f(a):" << fun(a0) << "  " << "f(b0):" << fun(b0) << "  f(c):" << fun(c) << endl;
            cout << "a0 changes to c"<< endl;
            a0 = c;
        }
    }
    return 0;
}
