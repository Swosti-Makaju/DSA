#include <stdio.h>
int sequentialSearch(int array[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key) {
            return i; 
        }
    }
    return -1; 
}
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int array[] = {4, 2, 7, 1, 9, 3};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 7;
    printf("Array: ");
    printArray(array, n);
    int result = sequentialSearch(array, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
