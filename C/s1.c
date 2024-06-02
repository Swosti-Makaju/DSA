 #include <stdio.h> 
void traversal(int arr[], int size) {
 printf("-------------------Traversal Operation------------------- \n");
 for (int i = 0; i < size; i++) {
 printf("arr[%d] = %d \n", i, arr[i]);
 }
 }
int main() {
 int arr[5] = { 1, 3, 5, 7, 9 };
 int size = sizeof(arr) / sizeof(arr[0]);
 printf("Size of array is : %d \n", size);
 traversal(arr, size);
 }