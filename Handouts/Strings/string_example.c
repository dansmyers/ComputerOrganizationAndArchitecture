// A string is a null-terminated character array
// DSM, 2016

#include <stdio.h>


int main() {
    
    // A string is a null-terminated array of characters
    // The null byte marks the end of the string
    
    // The following two statements are equivalent
    char sQuotes[6] = "Tokyo";
    char sArray[6] = {'T', 'o', 'k', 'y', 'o', '\0'};
    
    // Question: why is the array of length 6?
    
    // Because of the symmetry between arrays and pointers, the char * type is
    // frequently used for strings
    char *sPointer = sArray;
    
    printf("sQuotes = %s    sArray = %s    sPointer = %s\n", sQuotes, sArray,
              sPointer);
              
    // Access individual elements of a string using [ ]
    printf("sQuotes[0] = %c\n", sQuotes[0]);
    
    sArray[0] = 'K';
    sArray[1] = 'y';
    sArray[2] = 'o';
    sArray[3] = 't';
    printf("New value of sArray = %s\n", sArray);
    
    // Question: what will the following line print?
    printf("sPointer = %s\n", sPointer);
              
    return 0;
}