#include "ListArray.hpp"
#include "Define.hpp"

List::List()
{
    count = 0;
}

int List::size() const
{
    return count;
}

bool List::full()const
{
    if(count >= max_list) return true;
    return false;
}

bool List::empty()const
{
    if(count == 0) return true;
    return false;
}

void List::clear()
{
    count = 0;
}

void List::print()const
{
    for(int i = 0 ; i < count ; ++i)
        cout << entry[i] << " " ;
    cout << endl;
}

void List::traverse(void (*visit)(List_entry &))
{
    for(int i = 0; i < count ; ++i)
        visit(entry[i]);
}

Error_code List::retrieve(int position,List_entry &x)const
{
    if(position < 0 || position > max_list) return range_err;
    x = entry[position];
    return success;
}

Error_code List::replace(int position , const List_entry &x)
{
    if(position < 0 || position > max_list) return range_err;
    entry[position] = x;
    return success;
}

Error_code List::remove(int position, List_entry &x)
{
    if(empty()) return underflow;
    if(position < 0 || position > max_list) return range_err;
    for(int i = position ; i < count - 1 ; ++i){
        entry[i] = entry[i+1];
    }
    -- count;
    return success;
}

Error_code List::insert(int position, const List_entry &x)
{
    if(full()) return overflow;
    if(position < 0 || position > max_list) return range_err;
    for(int i = count - 1 ; i >= position ; --i){
        entry[i + 1] = entry[i];
    }
    entry[position] = x;
    ++count;
    return success;
}
