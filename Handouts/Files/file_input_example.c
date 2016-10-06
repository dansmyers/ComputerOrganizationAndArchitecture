// Reading from a file one line at a time
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 1024

//*** Prints the contents of a file to the console ***//
//
// Input: the string containing the filename
//
// Returns: nothing
void printFile(char *fileName) {
    
    // Open the file for reading
    // Always check return codes on I/O operations!
    FILE *f = fopen(fileName, "r");
    if (f <= 0) {
        perror("fopen"); // prints an error message
        exit(1);
    }
    
    // Allocate a buffer
    char line[BUFFER_LEN];
    
    // Standard pattern: read lines with fgets in a loop
    // fgets returns NULL when it reaches the end of the file
    while (fgets(line, BUFFER_LEN, f) != NULL) {
        printf("%s", line);
    }
    
    return;
}


int main(int argc, char *argv[]) {
    printFile(argv[1]);
    return 0;
}