#include <iostream>
#include "MyQueens.hpp"
using namespace std;

int main()
{
    Queens board(4);
	board.findSolutions();
    return 0;
}
