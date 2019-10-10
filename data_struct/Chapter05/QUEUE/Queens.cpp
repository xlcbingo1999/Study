#include <iostream>
#include "Queens.hpp"
using namespace std;

/*Queens::Queens(int size)
{
    available = true;
    squares = size;
    norm = squares - 1;
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
    cout << count + 1 << " way is:" <<endl;
    for(int i = 0 ; i < squares ; ++i){
        for(int j = 0 ; j < squares ; ++j)
            queen_square[i][j] = '1';
    }
    for(int row = 0 ; row < squares; ++row)
        queen_square[row][positionInRow[row]] = '*';
    for(int i = 0 ; i < squares ; ++i){
        for(int j = 0 ; j < squares ; ++j)
            cout << queen_square[i][j];
        cout << endl;
    }
    cout << endl;
}

void Queens::insert(int row)
{
    for(int col = 0 ; col < squares ; ++col){
        if(column[col] == available && leftDiagonal[row + col] != available &&
           rightDiagonal[row - col + norm] != available)
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

Queens::~Queens()
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
*/

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares - 1) {
	initializeBoard();
}
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares - 1) {
	initializeBoard();
}
void ChessBoard::initializeBoard() {
	register int i;//������i�Ĵ�����Ŀ��ʹ���������
	column = new bool[squares];
	positionInRow = new int[squares];
	leftDiagonal = new bool[squares * 2 - 1];//��б�ߵ���Ŀ
	rightDiagonal = new bool[squares * 2 - 1];//��б�ߵ���Ŀ
	for (i = 0; i < squares; i++)
		positionInRow[i] = -1;//positionInRow��һ�����飬i�����±������������
							//positionInRow[i]�����ֵΪ������
	for (i = 0; i < squares; i++)
		column[i] = available;//��ÿһ�ж�����Ϊ���Է��ûʺ�����
	for (i = 0; i < squares * 2 - 1; i++)
		leftDiagonal[i] = rightDiagonal[i] = available;
	howMany = 0;
}
void ChessBoard::printBoard() {
	howMany++;//
	cout << howMany << " way is:" << endl;
	//Ϊ���̸�ֵΪ1
	for (int i = 0;i != squares;i++) {
		for (int j = 0;j != squares;j++)
			m[i][j] = '1';
	}
	//���ʺ��λ�������̸�����'*'��־����
	for (int row = 0;row != squares;row++)
		m[row][positionInRow[row]] = '*';
	//��ӡ���̸�
	for (int i = 0;i != squares;i++) {
		for (int j = 0;j != squares;j++)
			cout << m[i][j];
		cout << endl;
	}
	cout << endl;
}

//�������������
void ChessBoard::putQueen(int row) {
	for (int col = 0; col < squares; col++) {
		if (column[col] == available &&
			leftDiagonal[row + col] == available &&
			rightDiagonal[row - col + norm] == available)
		{
			positionInRow[row] = col;
			column[col] = !available;
			leftDiagonal[row + col] = !available;
			rightDiagonal[row - col + norm] = !available;
			if (row < squares - 1)
				putQueen(row + 1);
			else printBoard();
			column[col] = available;
			leftDiagonal[row + col] = available;
			rightDiagonal[row - col + norm] = available;
		}
	}
}
void ChessBoard::Delete() {
	delete[]column;
	delete[]positionInRow;
	delete[]leftDiagonal;
	delete[]rightDiagonal;
}
void ChessBoard::findSolutions() {
	putQueen(0);
	cout << howMany << " solutions found.\n";
	Delete();
}
