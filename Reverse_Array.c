#include <stdio.h>

int main() {
    int num, i;
    printf("Enter the size of the array: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d elements: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Reversed array: ");
    for (i = num - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}