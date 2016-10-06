// Dereferencing uninitialized pointers
// DSM, 2016

#include <stdio.h>

int main() {
    int *p;
    
    printf("Memory address stored at p = %p\n", p);
    printf("That which is pointed to by p = %d\n", *p);
    
    return 0;
}