// A 2-D point struct
// DSM, 2016

#include <stdio.h>

struct point {
    int x;
    int y;
};  // <-- semicolon is required


int main() {
    
    // Declare struct with "struct" keyword
    struct point p;
    
    // Access members with dot notation
    p.x = 180;
    p.y = 220;
    
    // Can also assign values at declaration, like an array
    struct point p2 = {8, 12};
    
    printf("p = (%d, %d)\n", p.x, p.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);
    
    return 0;
}