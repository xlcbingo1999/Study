#include <iostream>
using namespace std;

const int maxrow = 20 , maxcol = 60;

class Life{
public:
    void initialize();
    void print();
    void update();
private:
    int grid[maxrow + 2][maxcol + 2] ;  // allows two extra r/c
    int new_grid[maxrow + 2][maxcol + 2];
    int neighbor_count(int row,int col);
};


void Life::initialize(){
    //grid = new int[maxrow + 2];
    int row , col;
    for(row = 0 ; row < maxrow + 2 ; ++ row){
        for(col = 0 ; col < maxcol + 2 ; ++ col){
                grid[row][col] = 0;
        }
    }
    int num ;
    cin >> num;
    while(num--){
        int r ,c;
        cin >> r >> c;
        grid[r][c] = 1;
    }
}
void Life::print(){
    int row , col;
    for(row = 1 ; row < maxrow + 1 ; ++ row){
        for(col = 1 ; col < maxcol + 1 ; ++ col){
            if(grid[row][col] == 1)
                cout << "*" ;
            else if(grid[row][col] == 2)
                cout << "&";
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
}

int Life::neighbor_count(int row,int col)
/*Pre: 
  Post:
*/
{
    int i ,j ;
    int count = 0;
    for(i = row - 1 ; i <= row + 1 ; ++ i){
        for(j = col - 1 ; j <= col + 1 ; ++ j){
            count += grid[i][j];
        }
    }
    count -= grid[row][col];
    return count;
}

void Life::update(){
    int row , col;
    int new_grid[maxrow + 2][maxcol + 2] ;
    for(row = 1 ; row <= maxrow ; ++row)
        for(col = 1 ; col <= maxcol ; ++ col)
            switch (neighbor_count(row,col))
            {
            case 2:
                new_grid[row][col] = grid[row][col];
                break;
            case 1:
                new_grid[row][col] = 2;
                break;
            default:
                new_grid[row][col] = 1;
            }
    for(row = 1 ; row <= maxrow ; ++row)
        for(col = 1 ; col <= maxcol ; ++ col)
            grid[row][col] = new_grid[row][col];
}

int main(){
    Life user;
    user.initialize();
    user.print();
    user.update();
    user.print();
}