// Examples of string functions
// DSM, 2016

#include <stdio.h>


// This example is a re-implementation of strlen from the standard library
// Common string functions are in string.h
// Use the library functions in your own programs! Don't rewrite them!


//*** Returns the length of a string ***//
//
// Input:
//   char *s: null-terminated string
//   declaring input to be const char * is a bit of syntactic sugar indicating
//   that this function does not modify its input
//
// Ouput:
//   the number of non-null characters in s
int mystrlen(const char *s) {
    int c = 0;
    
    // Common pattern: loop over characters in a string until you find '\0'
    while (s[c] != '\0') {
        c++;
    }
    
    return c;
}


int main() {
    int length = mystrlen("Hokkaido");
    printf("Length = %d\n", length);
    
    return 0;   
}