#include <iostream>
#include "ListList.hpp"
#include "Define.hpp"
using namespace std;

int main()
{
    List_entry arr[4] = {1,2,4,8};
    List li;
    for(int i = 0 ; i < 4 ; ++i){
        li.insert(i,arr[i]);
    }
//    cout << li.head.entry << endl;
    li.print();
//
//    li.replace(2,13);
//    li.print();
//
//    List_entry x;
//    li.retrieve(0,x);
//    cout << x << endl;
//
//    li.remove(0,x);
//    li.print();
//    cout << li.size() <<endl;
//
//    li.insert(2,x);
//    li.print();
//    cout << li.size() << endl;
//
//    List li2;
//    li2.insert(0,3);
//    li2.insert(1,4);
//    li2.insert(2,1555);
//    li2 = li;
//    li2.print();
//    cout << li2.size() << endl;
//
//    li = li2;
//    li.print();
//
//    li2.reverse();
//    cout << li2.size() << endl;
//    li2.print();
//
//    List li3(li2);
//    li3.print();
//
//    li2.clear();
//    cout <<"is_empty: " <<li2.empty() << endl;
//    cout << "size: "<< li2.size() << endl;

}
