// Examples of variable addresses
// DSM, 2016

#include <stdio.h>

// Variables declared outside any function are global to all functions in 
// the same source file
int g;

int main() {
    int x;
    int y;
    int z;
    
    // The & operator gets the address of a memory location
    // Use %p to print addresses
    printf("Address of x = %p\n", &x);
    printf("Address of y = %p\n", &y);
    printf("Address of z = %p\n", &z);

    // How are addresses of global variables different from local variables?
    printf("Address of global variable g = %p\n", &g);
    
    // You can also print the address of a function
    printf("Address of main = %p\n", main);
    
    return 0;
}