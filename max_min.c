#include<stdio.h>
// Q3
// Max Min in an array
void main(){
    int arr[] = {1,23,-34,-2,112,10,21,0};
    int max=-1e7,min=1e7;
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("Max = %d\n",max);
    printf("Min = %d",min);
}