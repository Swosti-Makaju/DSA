#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int array[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}
void buildHeap(int array[], int n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(array, n, i);
    }
}
void heapSort(int array[], int n) {
    buildHeap(array, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}
void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Original array:\n");
    printArray(array, n);
    heapSort(array, n);
    printf("Sorted array:\n");
    printArray(array, n);
    return 0;
}
