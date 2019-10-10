#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "Define.hpp"
class List
{
public:
    List();
    int size()const;
    bool full()const;
    bool empty()const;
    void clear();
    void print()const;
    void traverse(void (*visit)(List_entry &));
    Error_code retrieve(int position, List_entry &x)const;
    Error_code replace(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code insert(int position, const List_entry &x);
protected:
    int count;
    List_entry entry[max_list];
};

#endif // LISTARRAY_H
