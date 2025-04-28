#include <stdio.h>

int arr[50];
int x, i, j;

void input() {
    printf("Enter number of values in the array: \n");
    scanf("%d", &x);
    for (i = 0; i < x; i++) {
        printf("Enter the %d value: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void insertionSort() {
    for (i = 1; i < x; i++) {
        int key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array using Insertion Sort: ");
    for (i = 0; i < x; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort() {
    for (i = 0; i < x - 1; i++) {
        for (j = 0; j < x - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array using Bubble Sort: ");
    for (i = 0; i < x; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    input();
    insertionSort();
    bubbleSort();
    return 0;
}
