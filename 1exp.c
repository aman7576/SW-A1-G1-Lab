#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    char arr[n];
    getchar();
    printf("Enter the elements you want in the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%c", &arr[i]);
        getchar(); 
    }
    printf("Elements of array before reversal are:\n");
    for(int i = 0; i < n; i++) {
        printf("%c   ", arr[i]); 
    }
    printf("\n"); 
    for(int i = 0; i < n / 2; i++) {
        char temp = arr[i]; 
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Elements of array after reversal are:\n");
    for(int i = 0; i < n; i++) {
        printf("%c   ", arr[i]);
    }
    printf("\n"); 
    return 0;
}
