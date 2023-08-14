// Basic pointer operations
// DSM, 2016

#include <stdio.h>

int main() {
    
    int x = 101;
    int y = 202;
    
    // A pointer is a variable that holds the memory location where another
    // variable is stored
    int *ptr_to_x = &x;
    
    // If you don't set an initial value, it's common to set pointers to NULL
    // NULL is a special macro that's equal to 0
    int *ptr_to_y = NULL;
    ptr_to_y = &y;
    
    // The * operator dereferences a pointer: "that which is pointed to by"
    printf("Value of x = %d\n", *ptr_to_x);
    printf("Value of y = %d\n", *ptr_to_y);
    
    // The * operator can also be used in assignment
    *ptr_to_x = 1001;
    *ptr_to_y = 2002;
    printf("New value of x = %d\n", *ptr_to_x);
    printf("New value of y = %d\n", *ptr_to_y);
    
    // What is printed by the following operations?
    int firstOp = *ptr_to_x + y;
    int secondOp = x + *ptr_to_y;
    int thirdOp = *ptr_to_x + *ptr_to_y;
    printf("Values of three ops = %d %d %d\n", firstOp, secondOp, thirdOp);
    
    return 0;
}