#include <stdio.h>

void sortArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortOddOrEven(int arr[], int size, char choice) {
    int filtered[100], filteredSize = 0;
    for (int i = 0; i < size; i++) {
        if ((choice == 'O' && arr[i] % 2 != 0) || (choice == 'E' && arr[i] % 2 == 0)) {
            filtered[filteredSize++] = arr[i];
        }
    }
    sortArray(filtered, filteredSize);
    int k = 0;
    for (int i = 0; i < size; i++) {
        if ((choice == 'O' && arr[i] % 2 != 0) || (choice == 'E' && arr[i] % 2 == 0)) {
            arr[i] = filtered[k++];
        }
    }
}
int main() {
    int arr[100], size;
    char choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Do you want to sort Odd (O) or Even (E) numbers? ");
    scanf(" %c", &choice);

    if (choice == 'O' || choice == 'E') {
        sortOddOrEven(arr, size, choice);
        printf("Array after sorting %s numbers:\n", (choice == 'O') ? "Odd" : "Even");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid choice. Please enter 'O' for Odd or 'E' for Even.\n");
    }

    return 0;
}
