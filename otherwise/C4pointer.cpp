/* 
    讲一下new的东西
*/

#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int * pt;
    int **pt1;
    pt = new int;
    pt1 = new int*;

    *pt = a;
    cout << *pt << endl;

    *pt = 12;
    cout << *pt << endl;
    cout << a << endl;  

    pt = &a;
    *pt = 24;
    cout << *pt << endl;
    cout << a << endl;

    pt1 = &pt;
    **pt1 = 5678; // C++ 中应该理解 &*pt1
    cout << **pt1 << endl;
    cout << *pt << endl;
    cout << a << endl;

    delete pt;
    delete pt1;
    cout << *pt << endl;
}