// Arrays of strings
// DSM, 2016

#include <stdio.h>

// One of the main advantages of arrays of pointers over static 2-D arrays
// is that each row may have a different length (sometimes called "ragged
// arrays"). This is very useful when working with strings.

int main() {
    
    char *months[] = {"January", "February", "March", "April", "May",
                      "June", "July", "August", "September", "October",
                      "November", "December"};
    
    // Recall: sizeof gets the number of bytes in the array
    int numElements = sizeof(months) / sizeof(char *);     
                      
    // Print
    int i;
    for (i = 0; i < numElements; i++) {
        printf("%s\n", months[i]);
    }
    
    // Create a char ** variable to point to the array of pointers
    char **ptrToStrArray = months;
    printf("ptrToStrArray[0] = %s\n", ptrToStrArray[0]);
    printf("ptrToStrArray[1] = %s\n", ptrToStrArray[1]);
    printf("ptrToStrArray[2] = %s\n", ptrToStrArray[2]);

    return 0;
}
