#include <iostream>
using namespace std;

void hanoi(int count, int start, int finall ,int temp)
{
    if(count > 0){
        hanoi(count - 1 , start , temp , finall);
        cout << count << ":" << start << "->" <<finall <<endl;
        hanoi(count - 1 , temp , finall , start);
    }

}

int main()
{
    hanoi(10,1,2,3);

    return 0;
}
