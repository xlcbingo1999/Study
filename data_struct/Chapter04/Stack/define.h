#ifndef DIFINE_H
#define DIFINE_H

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


const int maxstack = 10;
const int maxqueue = 10;

typedef int Code_way; 
typedef int Stack_entry;
typedef int Node_entry;
typedef int Queue_entry;

enum Error_code
{
    succeed , overflow , underflow
};

#endif
