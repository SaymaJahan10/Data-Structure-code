#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
        if (minIndex != i) {
        swap(&arr[i], &arr[minIndex]);
    }
}
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
}
    printf("\n");
}
int main() {
    int arr[] = {90, 80, 30, 70, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array in ascending order: ");
    printArray(arr, n);
    return 0;
}

