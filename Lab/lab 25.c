#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;     }
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
void printHeap(int array[], int n) {
    printf("Array representation of Heap:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    int array[] = {4, 10, 3, 5, 1};
    int n = sizeof(array) / sizeof(array[0]);
    buildHeap(array, n);
    printHeap(array, n);   
     return 0; 
  }
