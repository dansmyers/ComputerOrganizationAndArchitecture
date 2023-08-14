// Arrays of pointers
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int nRows = 3;
    int nCols = 5;
    
    // Declare an array of pointers
    // The declaration only allocates memory for the individual pointers
    int *p[nRows];
    
    // Allocate memory for the 1-D subarrays
    int i, j;
    for (i = 0; i < nRows; i++) {
        p[i] = malloc(nCols * sizeof(int));
    }
    
    // Print initial values
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            printf("%d   ", p[i][j]);
        }
        printf("\n");
    }
    
    // Create a *pointer to a pointer* variable
    int **dblPtr = p;
    
    // Recall: p is the name of an array, which behaves like a pointer to the
    // first element of the array
    // dblPtr is assigned the memory location where p begins in memory
    printf("dblPtr = %p    p = %p\n", dblPtr, p);
    
    // dblPtr can be used with square brackets, just like p
    dblPtr[0][0] = 101;
    dblPtr[1][1] = 202;
    dblPtr[2][2] = 303;

    printf("p[0][0] = %d\n", p[0][0]);
    printf("p[1][1] = %d\n", p[1][1]);
    printf("p[2][2] = %d\n", p[2][2]);
    
    // What about pointer arithmetic?
    // *dblPtr is the first element of p, which is itself a pointer
    // *(dblPtr + 1) is the second element of p, which is another pointer
    // Therefore, **dblPtr is equivalent to p[0][0]
    // *(*(dblPtr + 1) + 1) is equivalent to p[1][1]
    // etc.
    printf("**dblPtr = %d\n", **dblPtr);
    printf("*(*(dblPtr + 1) + 1) = %d\n", *(*(dblPtr + 1) + 1));
    printf("*(*(dblPtr + 2) + 2) = %d\n", *(*(dblPtr + 2) + 2));

    return 0;
}