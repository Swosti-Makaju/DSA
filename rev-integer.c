#include <stdio.h>

// Function to reverse a number recursively
int reverse(int num) {
    static int reversedNum = 0;
    
    // Base case: when there's no digit left
    if (num == 0)
        return 0;
    
    // Extract the last digit
    int lastDigit = num % 10;
    
    // Update the reversed number by appending the last digit
    reversedNum = reversedNum * 10 + lastDigit;
    
    // Recursive call to process remaining digits
    reverse(num / 10);
    
    return reversedNum;
}

int main() {
    int num;
    printf("Enter an integer number to reverse: ");
    scanf("%d", &num);
    
    // Call the reverse function
    int reversed = reverse(num);
    
    printf("Reversed number: %d\n", reversed);
    
    return 0;
}
