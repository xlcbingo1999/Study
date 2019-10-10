#include <cmath>
#include <iostream>
using namespace std;

double f(double n)
{
    if(n <= 0) return 1;
    return n * f(n-1);
}

double jiecheng(double n, double cishu)
{
    double sum = 1;
    for(int i = 0 ; i < cishu ; ++i)
    {
        sum *= n;
    }
    return sum;
}

double pos(double x , double miu = 5)
{
    double fin = 0;
    if(x == 0) return 1;
    double sum;
    for(int i = 0 ; i <= x ; ++i){
        sum =  exp(-5) * jiecheng(5,x) / f(x);
        fin += sum;
    }
    return fin;
}

int main()
{
    cout << pos(8,5);
}
