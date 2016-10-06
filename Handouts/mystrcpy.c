// Copy a string to another location
// DSM, 2016

#include <stdio.h>


// Reimplementation of strcpy from the standard library
//
// WARNING: strcpy can be unsafe!
// We'll talk about why and how to deal with it in the next class


//*** Copies a string to another location ***//
//
// Inputs: two null-terminated strings, dest and source
//   assumes that dest is large enough to hold all of source
//   could this lead to problems?
//
// Returns: Nothing, changes are made to the underlying string buffers
void mystrcpy(char *dest, char *source) {
    int i = 0;
    
    while ((dest[i] = source[i]) != '\0') {
        i++;
    }
}


//*** Fancier version of strcpy ***//
//
// Question: what does *dest++ do?
void myfancystrcpy(char *dest, char *source) {
    while ((*dest++ = *source++))
        ;
}


int main () {
    char src[] = "Tokyo";
    char dest[6];

    mystrcpy(dest, src);
    printf("Destination after copy = %s\n", dest);
    
    return 0;
}