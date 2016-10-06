// Getting (and not getting) the lengths of arrays
// DSM, 2016

#include <stdio.h>

int main() {
    
    // The sizeof operator returns the number of bytes in a data type
    // Its return value is a long type, use %ld to print it
    int x;
    double d;
    printf("Number of bytes in an int = %ld\n", sizeof(x));
    printf("Number of bytes in a double = %ld\n", sizeof(d));
    
    // sizeof returns the number of bytes in an *array*
    char str[] = "Yokohama"; // Compiler can figure out size from declaration
    printf("Number of bytes in s = %ld\n", sizeof(str));
    
    // Note: this is the number of BYTES in the array, not the number of non-
    // null characters in the string!
    
    // You can use this to get the length of an ARRAY
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int arrayLength = sizeof(a) / sizeof(int);
    printf("Number of elements in a = %d\n", arrayLength);
    
    // What about pointers?
    char *sPtr = "Osaka";
    printf("Number of bytes in sPtr = %ld\n", sizeof(sPtr));
    
    return 0;
}