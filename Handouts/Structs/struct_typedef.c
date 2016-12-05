// Using typedef with struct declarations
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>

// Typedef creates aliases for complex types
//
// Three parts:
//   1. typedef keyword
//   2. a type declaration: in this case, "struct point_t {...}""
//   3. the alias name, "point" in this case
//
// It is not required, but some sources like an uppercase letter for the
// alias name, to emphasize that it's not a basic type
typedef struct point_t {
    double x;
    double y;
} Point;


int main() {
    
    // Use point without struct keyword
    Point *p = malloc(sizeof(Point));
    
    p->x = 3.14;
    p->y = p->x * 3;
    
    printf("p = (%f, %f)\n", p->x, p->y);
    
    return 0;
}