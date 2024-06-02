#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i which is an index in array[]
// n is size of heap
void heapify(int array[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&array[i], &array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// Function to build a max-heap from the given array
void buildHeap(int array[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(array, n, i);
    }
}

// Function to print the array representation of Heap
void printHeap(int array[], int n) {
    printf("Array representation of Heap:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function to test above functions
int main() {
    int array[] = {4, 10, 3, 5, 1};
    int n = sizeof(array) / sizeof(array[0]);

    buildHeap(array, n);

    printHeap(array, n);

    return 0;
}
