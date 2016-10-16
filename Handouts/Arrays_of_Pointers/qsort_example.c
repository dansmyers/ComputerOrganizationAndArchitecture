// Sorting with qsort
// DSM, 2016

#include <stdio.h>
#include <string.h>  // For strcmp
#include <stdlib.h>  // For qsort


//*** The comparison function takes two data items and returns an int ***//
//
// The input types are required to be const void *: generic pointers to the
// individual data items being compared.
//
// In this case, the data items have type char *, so each generic void * is
// really a char **, a pointer to a char *.
//
// The return value is an int. Because the data items in this example are 
// strings, compare is only a wrapper around strcmp.
int compare(const void *a, const void *b) {
    
    // Each input argument is a pointer to a data item. The data items are
    // char *, so the true underlying type of inputs a and b is char **.
    //
    // *(char **) a casts a from void * to char **, then dereferences that
    // char ** to obtain the real char * data item that can be used as input
    // to strcmp
    
    return strcmp(*(char **) a, *(char **) b);
}


int main() {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November",
                      "December"};
    
    // qsort takes four arguments:
    //
    // 1. the array to sort
    // 2. the number of items in the array
    // 3. the size of each data item -- each item of the months array is type
    //    char *, so the size is sizeof(char *)
    // 4. a *function pointer* to a function that compares data items
    qsort(months, 12, sizeof(char *), compare);
    
    int i;
    for (i = 0; i < 12; i++) {
        printf("%s\n", months[i]);
    }
    
    return 0;
}