#include<iostream>
using namespace std;
int add(int a, int b) {
        int sum = 0;
        int up = 1;
        int fin = 0;
        sum = a ^ b;
        up = a & b;
        up = up << 1;
        fin = sum ^ up;
        return fin;
    }
int main(){
    int a,b;
    cin >> a >> b;
    int fin = add(a,b);
    cout << fin;
    return 0;
}
