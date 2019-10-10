#pragma once

#include "D:\Work and study\code_work\data_struct\Chapter3\targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <cctype>
#include <system_error>

using namespace std;

enum Error_code {
	success, overflow, underflow
};

//typedef int  Stack_Entry;
typedef int  Queue_entry;

#define maxQueue 10
