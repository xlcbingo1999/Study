#include <iostream>
#include <climits>
using namespace std;

int func(int n)
{
    if(n == 0) return 0;
    if(n % 2 == 0) return func(n/2);
    if(n % 2 != 0) return (1 + func(n-1));
}

int main()
{
    cout << func(INT_MAX);
}
