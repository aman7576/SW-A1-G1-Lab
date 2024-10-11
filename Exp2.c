/*Create a menu driven program that will take input from user to 
1. Enter elemtnt in a 1D array
2. Delete element from 1D array(have all conditions beginnig,last,middle index)
3. Find Largest element
4. Find smallest array
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int size=0,ele,flag=1,index=0;
    int *arr=NULL;
    printf("Enter size of array: ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    if (arr==NULL){
        printf("Memory not allocated");
        return 0;                                                               //1
    }
    else printf("Memory allocated succesfully to the array");
    printf("%d",sizeof(arr));
    printf("\n1. Enter elements in a 1D array\n2. Delete element from 1D array\n3. Find Largest element\n4. Find smallest array\n5. Exit\n\n");
    int choice;
    while(flag==1){
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            for(int i=0;i<size;i++){
                printf("Enter element %d: ",i+1);
                scanf("%d",&ele);
                arr[i]=ele;
            }
            printf("Array: ");
            for(int i=0;i<size;i++){
                printf("%d\t",arr[i]);
            }
            break;
        case 2:
            printf("Enter the index of element to be deleted: 0 to %d\n",size-1);
            scanf("%d", &index);

            if (index >= 0 && index < size) {
                for (int i = index; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                arr = (int*)realloc(arr, size * sizeof(int)); // Adjust memory size
                if (arr == NULL && size > 0) {
                    printf("Memory reallocation failed!\n");
                    return 1;
                }

                printf("Updated Array: ");
                for (int i = 0; i < size; i++) {
                    printf("%d\t", arr[i]);
                }
            } else {
                printf("Invalid index!\n");
            }
            break;
        case 3:
        if(size==0){
            printf("Empty Array\n");
            return 0;
        }
        int max = arr[0];
            for(int i = 1; i < size; i++)
                if(arr[i] > max){
                    max = arr[i];
                }
                

            printf("Max Element: %d", max);
            break;
        case 4:
            if (size == 0) {
                printf("Array is empty!\n");
                break;
            }

            int min = arr[0];
            for (int i = 1; i < size; i++) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            printf("Min Element: %d\n", min);
            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    }
    free(arr);
    
    return 0;
}