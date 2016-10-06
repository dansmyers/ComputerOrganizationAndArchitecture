// Returning a pointer from a function
// DSM, 2016

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//*** Read and return a string from the console ***//
//
// Returns: a pointer to a char buffer holding the input string
char * getUserInput() {
    
    // Declare an input buffer
    // Question: where in memory is this buffer placed?
    char buf[64];
    
    printf("Type something: ");
    fgets(buf, sizeof(buf), stdin);
    
    // Strip off the terminating newline
    buf[strlen(buf) - 1] = '\0';
    
    return buf;
}


int main() {
    char *firstInput = getUserInput();
    printf("First user input = %s\n", firstInput);
    
    char *secondInput = getUserInput();
    printf("Second user input = %s\n", secondInput);
    
    // What does this line print? Why?
    printf("First user input after getting second input = %s\n", firstInput);

    return 0;
}