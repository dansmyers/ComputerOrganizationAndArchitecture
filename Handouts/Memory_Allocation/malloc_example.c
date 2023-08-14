// Allocating memory with malloc
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 64

// malloc allocates a block of memory of a given size on the *heap* and returns
// a pointer to the beginning of the block

// The input to malloc is the size of the memory block in *bytes*
// Commonly expressed using sizeof the underlying data type

// The main use of malloc is to create space for dynamic arrays and structures
// that need to persist beyond the scope of a single function call

// C has no garbage collector! When you are done with malloc'ed memory, you
// need to explicitly free it

int main() {
    
    // Allocate a buffer using malloc
    // The return type is void *, a generic pointer
    // void * is automatically promoted to the type on the left hand side
    char *buf = malloc(BUFFER_LEN * sizeof(char));
    
    // Common pattern: read an entire line with fgets, then parse out values
    // sscanf is like scanf, but operates on a string
    int x, y, z;
    printf("Enter three numbers: ");
    fgets(buf, BUFFER_LEN, stdin);
    sscanf(buf, "%d %d %d", &x, &y, &z);
    
    printf("x = %d    y = %d    z = %d\n", x, y, z);
    
    // If you love some memory, set it free
    // Un-free memory is automatically deallocated when the program ends
    free(buf);
    
    return 0;
}