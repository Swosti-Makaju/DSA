#include <stdio.h>
int binarySearch(int array[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == key)
            return mid;
        if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 7;
    printf("Array: ");
    printArray(array, n);
    int result = binarySearch(array, 0, n - 1, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
