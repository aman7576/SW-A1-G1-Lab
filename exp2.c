#include<stdio.h>
// Q4
/*
Create a menu driver program that will take input
from the user to I. enter elements in a one
dimensional array 2. delete element in a one
dimensional array (have all conditions, beginning,
last, middle index) 3, Find the largest element 4. Find
the smallest element
Submit and show the demo in the class. Do not leave
the lab without submitting and showing the demo
Lab files needs to be maintained each lab
Form: https://forms.gle/VIGV1m3MSK6iC7QFA
*/
void main(){
    printf("Please Enter len of array\n");
    int len;
    scanf("%d",&len);
    int arr[len+1];
    int size=0;
    int flag=1;

    while(flag){
        printf("Please Select an input \n");
        printf("1. Enter elements in a one dimensional array \n");
        printf("2. delete element in a one dimensional array (have all conditions, beginning, last, middle index)  \n");
        printf("3, Find the largest element \n");
        printf("4. Find the smallest element \n");
        printf("5. To exit \n");
        int a;
        scanf("%d",&a);
        if(a==1){
        printf("Please Enter idx \n");
        int idx,num;
        scanf("%d",&idx);
        printf("Please Enter num \n");
        scanf("%d",&num);
        for(int i=0;i<size+1;i++){
            if(i>=idx){
                int temp=arr[i];
                arr[i]=num;
                num=temp;
            }
        }
        size++;
        }
        else if(a==2){
            printf("Please Enter idx \n");
            int idx;
            scanf("%d",&idx);
            for(int i=0;i<size-1;i++){
                if(i>=idx){
                    arr[i]=arr[i+1];
                }
            }
            size--;
        }
        else if(a==3){
            int max=-1e7;
            for(int i=0;i<size;i++){
                if(arr[i]>max) max=arr[i];
            }
            printf("Max = %d\n",max);
        }
        else if(a==4){
            int min=1e7;
            for(int i=0;i<size;i++){
                if(arr[i]<min) min=arr[i];
            }
            printf("Min = %d",min);
        }
        else{
            flag=0;
        }


        for(int i=0;i<size;i++){
            printf("%d,",arr[i]);
        }
        printf("\n");

    }
    
}