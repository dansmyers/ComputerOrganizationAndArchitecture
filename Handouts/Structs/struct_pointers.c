// Using pointers to structures
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>

struct point {
    double x;
    double y;
};  // <-- semicolon is required


/*** Distance between two points ***/
double distance(struct point *p1, struct point *p2) {
    
    // Calculate Euclidean distance between p1 and p2
    
}


int main() {
    
    // Declare a pointer to a struct
    // Remember: allocate memory using malloc!
    struct point *p = malloc(sizeof(struct point));
    
    // Use -> to access members of a struct via a pointer
    // p->x is equivalent to (*p).x
    p->x = 45.45;
    p->y = 90.90;
    
    printf("p = (%f, %f)\n", p->x, p->y);
    
    return 0;
}