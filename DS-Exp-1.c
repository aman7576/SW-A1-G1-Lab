#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    char arr[size];
    for (int i=0; i < size; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    int first = 0, last = size - 1;
    while (first < last) {
        char temp = arr[last];
        arr[last] = arr[first];
        arr[first] = temp;

        first++;
        last--;
    }
    printf("The reversed array: ");
    for (int i=0; i < size; i++) {
        printf("%c", arr[i]);
    }
    return 0;
}