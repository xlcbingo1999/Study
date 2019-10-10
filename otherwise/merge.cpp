#include <iostream>
using namespace std;

void merge(int *data , int start , int mid , int end , int * result){
    int i, j , k ;
    i = start ;
    j = mid + 1;
    k = 0;
    while(i <= mid && j <= end){
        if(data[i] <= data[j])
            result[k++] = data[i++];
        else
            result[k++] = data[j++];
    }
    while(i <= mid)
        result[k++] = data[i++];
    while(j <= end)
        result[k++] = data[j++];
    for(i = 0 ; i < k ; ++ i)
        data[start + i] = result[i];
}

void merge_sort(int *data , int start , int end, int *result){
    if(start < end){
        int mid = start + (end - start)/2;
        merge_sort(data,start,mid,result);
        merge_sort(data,mid+1,end,result);
        merge(data,start,mid,end,result);
    }
}

void amalgamation(int *data1,int *data2,int *result){
    for(int i = 0 ; i < 10 ; ++ i)
        result[i] = data1[i];
    for(int i = 0 ; i < 10 ; ++ i)
        result[i + 10] = data2[i];
}

int main(){
    int data1[10] = {1,7,6,4,9,14,19,100,55,10};
    int data2[10] = {2,6,8,99,45,63,102,556,10,41};
    int *result = new int[20];
    int *result1 = new int[20];
    amalgamation(data1,data2,result);
    for(int i = 0 ; i < 20 ; ++ i){
        cout << result[i] << " ";
    }
    cout << endl;
    merge_sort(result,0,19,result1);
    for(int i = 0 ; i < 20 ; ++ i){
        cout << result1[i] << " ";
    }
    cout << endl;
    delete[] result;
    delete[] result1;
    return 0;
}