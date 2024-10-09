#include <iostream>
using namespace std;


//Made By Arnav Rana 23/SE/35



void displayMenu() {
    cout << "Array Operations" << endl;
    cout << "----------------" << endl;
    cout << "1. Delete an element" << endl;
    cout << "2. Find smallest and largest elements" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int a = 0; a < n; a++) {
        cin >> arr[a];
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int k;
                cout << "Enter the position of element to be deleted: ";
                cin >> k;
                int temp = arr[k - 1];
                for (int a = k - 1; a < n - 1; a++) {
                    arr[a] = arr[a + 1];
                }
                arr[n - 1] = temp;
                n--;
                cout << "New array after deletion is:" << endl;
                for (int a = 0; a < n; a++) {
                    cout << arr[a] << " ";
                }
                cout << endl;
                break;
            }
            case 2: {
                int temp = arr[0];
                int temp2 = arr[0];
                for (int a = 0; a < n; a++) {
                    if (arr[a] <= temp) {
                        temp = arr[a];
                    } else if (arr[a] >= temp2) {
                        temp2 = arr[a];
                    } else {
                        continue;
                    }
                }
                cout << "The smallest element is: " << temp << endl;
                cout << "The largest element is: " << temp2 << endl;
                break;
            }
            case 3:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}