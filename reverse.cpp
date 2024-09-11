#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(int *arr){
    int i=0,j=4;
    while(j>i){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    reverse(arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}