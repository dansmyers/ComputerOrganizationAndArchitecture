// Using scanf for formatted input
// DSM, 2016

// scanf takes a format string like printf's
// Each input value is converted according to the format string and stored into
// the memory location associated with a variable

#include <stdio.h>

int main() {
    int value;

    // Basic example: read a single integer
    printf("Enter an integer: ");
    scanf("%d", &value);  // &value is the memory location of the variable value
    printf("You entered %d.\n", value);
    
    // You can use multiple format specifiers in a single call to scanf
    int arg1, arg2, arg3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &arg1, &arg2, &arg3);
    printf("You entered: %d %d %d.\n", arg1, arg2, arg3);
    
    // Other format specifiers can be used for other types
    double d;
    printf("Enter a double value: ");
    scanf("%lf", &d);  // Use %lf ("long float") to read a double
    printf("You entered: %lf.\n", d);
    
    // But what about strings?
    
    return 0;
}