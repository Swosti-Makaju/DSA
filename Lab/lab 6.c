#include <stdio.h>
int reverse(int num) {
    static int reversedNum = 0;
    if (num == 0)
        return 0;
    int lastDigit = num % 10;
    reversedNum = reversedNum * 10 + lastDigit;
    reverse(num / 10);
    return reversedNum;
}
int main() {
    int num;
    printf("Enter an integer number to reverse: ");
    scanf("%d", &num);
    int reversed = reverse(num);
    printf("Reversed number: %d\n", reversed);
    return 0;
}
