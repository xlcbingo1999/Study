#include <iostream>
using namespace std;

void merge(int *data , int str ,int mid , int end ,int *result){
    int i = str;
    int j = mid;
    int k = 0;
    while(i <= mid && j <= end){
        if(data[i] <= data[j]){
            result[k++] = data[i++];
        }
        else
        {
            result[k++] = data[j++];
        }   
    }
    while(i <= mid){
        result[k++] = data[i++];
    }
    while(j <= end){
        result[k++] = data[j++];
    }
    for(i = 0 ; i < k ; ++ i){
        data[i] = result[i];
    }
}