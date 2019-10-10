#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;


int getIntNum(string &s)
{
    istringstream iss(s);
    int num, res = 0;
    int sum = 0;
    while(iss >> num){
        res++;
        sum += num * num;
    }
    cout << sum << endl;
    fstream dataFile;
    dataFile.open("row.txt",ios::out);
    dataFile << sum << endl;
    return res;
}

int main(){
    ifstream infile("row.txt");
    string s;
    int row;
    getline(infile, s);
    istringstream iss(s);
    iss >> row;
    while(row-- && getline(infile, s))
    {
        getIntNum(s);
    }
    
    return 0;
}
