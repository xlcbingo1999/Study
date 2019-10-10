#ifndef QUEENS_H
#define QUEENS_H

/*const int max_board = 30;

class Queens
{
public:
    Queens(int size);
    void print();
    void insert(int row);
    //~Queens();
    void Delete();
    void findSolutions();
private:
    const bool available;
    const int squares , norm;
    bool *column , *leftDiagonal , *rightDiagonal;
    int *positionInRow,count;
    char queen_square[10][10];
};*/
class ChessBoard {
public:
	ChessBoard();    // 8 x 8 chessboard;自定义构造函数
	ChessBoard(int); // n x n chessboard;带有参数的构造函数
	void findSolutions();
    void putQueen(int);
	void printBoard();
	void initializeBoard();
	void Delete();//释放new分配的动态内存
private:
	const bool available;
	const int squares, norm;//squares代表棋盘格的边长，norm的意义在2、(4)中有提到
	bool *column, *leftDiagonal, *rightDiagonal;//定义列，左斜线以及右斜线
	int  *positionInRow, howMany;//定义行以及方法的数量
	char m[10][10];//记录棋盘格

};
#endif // QUEENS_H
