#include <stdio.h>
int is_prime(int n, int i) {
    if (n <= 2)
        return (n == 2);
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
        return is_prime(n, i + 1);
}
int main() {
    int num;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &num);
        if (is_prime(num, 2))
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);
    return 0;
}
