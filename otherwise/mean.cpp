#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

double get_mean(vector<double> nums){
    double sum = accumulate(nums.begin(),nums.end(),0.0);
    double mean = sum / nums.size();
    return mean;
}

double get_stdev(vector<double> nums){
    double mean = get_mean(nums);
    vector<double>::iterator i;
    double accum = 0.0;
    for(i = nums.begin() ; i != nums.end() ; ++ i){
        double temp = (( *i - mean) * ( *i - mean));
        accum += temp;
    }
    double stdev = sqrt(accum / nums.size());
    return stdev;
}

int main(){
    vector<double> nums;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; ++ i){
        double temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << get_mean(nums) << endl << get_stdev(nums) << endl;
}