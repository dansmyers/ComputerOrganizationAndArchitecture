// Swapping values of two variables
// DSM, 2016

#include <stdio.h>

// This version of swap operates with pointers to the memory locations where
// the two values are stored.
void swapWithPointers(int *aPtr, int *bPtr) {
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
    
    return;
}

// This version of swap operates on the *values* of its input arguments
// Does it work?
void swapWithValues(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    
    return;
}

int main() {
    int x = 101;
    int y = 202;
    printf("Values before calling swap.  x = %d  y = %d\n\n", x, y);
    
    // Try to swap x and y
    swapWithValues(x, y);
    printf("Values after calling swapWithValues.  x = %d  y = %d\n\n", x, y);

    // Try to swap x and y by passing *pointers* to each value
    // Remember: & gets the memory address where a variable is stored
    // Therefore, &x is a pointer to x
    swapWithPointers(&x, &y);
    printf("Values after calling swapWithPointers.  x = %d  y = %d\n", x, y);
    
    return 0;
}