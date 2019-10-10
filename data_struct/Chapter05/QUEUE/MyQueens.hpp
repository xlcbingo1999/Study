#ifndef MYQUEENS_H
#define MYQUEENS_H

const int max_board = 30;

class Queens
{
public:
    Queens(int size);
    void print();
    void insert(int row);
    void Delete();
    void findSolutions();
private:
    const bool available;
    const int squares , norm;
    bool *column , *leftDiagonal , *rightDiagonal;
    int *positionInRow,count;
    char queen_square[10][10];
};

#endif // MYQUEENS_H
