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
	ChessBoard();    // 8 x 8 chessboard;�Զ��幹�캯��
	ChessBoard(int); // n x n chessboard;���в����Ĺ��캯��
	void findSolutions();
    void putQueen(int);
	void printBoard();
	void initializeBoard();
	void Delete();//�ͷ�new����Ķ�̬�ڴ�
private:
	const bool available;
	const int squares, norm;//squares�������̸�ı߳���norm��������2��(4)�����ᵽ
	bool *column, *leftDiagonal, *rightDiagonal;//�����У���б���Լ���б��
	int  *positionInRow, howMany;//�������Լ�����������
	char m[10][10];//��¼���̸�

};
#endif // QUEENS_H
