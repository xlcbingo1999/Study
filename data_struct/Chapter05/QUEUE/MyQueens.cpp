#include <iostream>
#include "MyQueens.hpp"
using namespace std;

Queens::Queens(int size): available(true), squares(size), norm(squares - 1)
{
    int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal = new bool[squares * 2 - 1];
    rightDiagonal = new bool[squares * 2 - 1];
    for(i = 0 ; i < squares ; ++i) positionInRow[i] = -1;
    for(i = 0 ; i < squares ; ++i) column[i] = available;
    for(i = 0 ; i < squares * 2 - 1 ; ++i) leftDiagonal[i] = rightDiagonal[i] = available;
    count = 0;
}

void Queens::print()
{
    count++;
    cout << count << " way is:" <<endl;
    for(int i = 0 ; i != squares ; ++i){
        for(int j = 0 ; j != squares ; ++j)
            queen_square[i][j] = '1';
    }
    for(int row = 0 ; row != squares; ++row)
        queen_square[row][positionInRow[row]] = '*';
    for(int i = 0 ; i != squares ; ++i){
        for(int j = 0 ; j != squares ; ++j)
            cout << queen_square[i][j];
        cout << endl;
    }
    cout << endl;
}

void Queens::insert(int row)
{
    for(int col = 0 ; col < squares ; ++col){
        if(column[col] == available &&
           leftDiagonal[row + col] == available &&
           rightDiagonal[row - col + norm] == available)
        {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;
            rightDiagonal[row - col + norm] = !available;
            if(row < squares - 1)
                insert(row + 1);
            else print();
            column[col] = available;
            leftDiagonal[row + col] = available;
            rightDiagonal[row - col + norm] = available;
        }
    }
}

void Queens::Delete()
{
    delete[]column;
    delete[]positionInRow;
    delete[]leftDiagonal;
    delete[]rightDiagonal;
}

void Queens::findSolutions()
{
    insert(0);
    cout << count << " solutions found." << endl;
    Delete();
}


