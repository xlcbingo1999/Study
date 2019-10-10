/*
    改良型的list，保存着当前位置的序号，可以节省一半的时间
*/

#ifndef LISTLIST_H
#define LISTLIST_H
#include "Define.hpp"
#include "Node.h"

class List
{
public:
    List();
    List(const List &copy);
    ~List();
    int size()const;
    bool empty()const;
    void clear();
    void print()const;
    void operator= (const List &copy);
    Error_code retrieve(int position, List_entry &x)const;
    Error_code replace(int position, const List_entry &x);
//    Error_code remove(int position, List_entry &x);
    Error_code insert(int position, const List_entry &x);
//    Error_code reverse();
protected:
    int count;
    mutable int current_position;
    Node *head;
    mutable Node *current;
    void set_position(int position)const;
};

#endif // LISTLIST_H
