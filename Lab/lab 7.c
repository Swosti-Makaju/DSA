#include <stdio.h>
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);   
}  }
void printFibonacciSeries(int n) {
    int i;
    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printFibonacciSeries(n);
    return 0;
}
