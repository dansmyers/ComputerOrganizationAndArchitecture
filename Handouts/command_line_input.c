// Working with command line input
// DSM, 2016

#include <stdio.h>

// main can take two arguments
//
//   int argc reports the number of command line arguments, including the
//   name of the program
//
//   char *argv[] stores the strings of the arguments
//
// Notice that argv is an array that stores char * values, that is, an array
// of strings. We could also write char **argv, because of the symmetry between
// arrays and pointers.


int main (int argc, char *argv[]) {
    printf("Number of command line arguments = %d\n", argc);
    
    int i;
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    return 0;
}