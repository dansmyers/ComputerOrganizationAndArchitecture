// The duality between pointers and arrays
// DSM, 2016

#include <stdio.h>

int main() {
    
    int a[5] = {0, 1, 2, 3, 4};
    
    // An array's name functions like a pointer to its first element
    printf("a = %p\n", a);
    printf("a[0] = %d\n", a[0]);
    printf("*a = %d\n\n", *a);
    
    // Adding to the pointer access additional elements of the array
    printf("*(a + 1) = %d\n", *(a + 1));
    printf("*(a + 2) = %d\n", *(a + 2));
    printf("*(a + 3) = %d\n\n", *(a + 3));
    
    // a is a pointer to the beginning of the array
    // a + 1 is a pointer to the second element of the array
    // a + 2 is a pointer to the third element of the array
    // and so forth
    
    // What about other types?
    // The "+ 1" relationship holds regardless of the array type
    // Arithmetic on pointers automatically accounts for data size
    double dArray[3] = {1.11, 2.22, 3.33};
    printf("*d = %f\n", *dArray);
    printf("*(d + 1) = %f\n", *(dArray + 1));
    printf("*(d + 2) = %f\n\n", *(dArray + 2));
    
    // A pointer variable can be assigned to an array
    int *p = a;
    printf("*p = %d\n", *p);
    printf("p[0] = %d\n", p[0]);
    
    // Change the array using the pointer
    *p = 100;
    printf("Changed first value = %d\n", a[0]);
    
    // Key difference between pointer variables and arrays:
    // An array can't be reassigned
    // The array name is *fixed* to always point to its declared array
    int b[5] = {6, 7, 8, 9, 10};
    
    // p is a pointer to an int, so it can be reassigned to point to b
    p = b;
    
    // a is an array, it can't be reassigned
    // This line generates a compiler error
    a = b;

    return 0;
}