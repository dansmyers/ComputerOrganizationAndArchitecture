# Compiling and Running Programs

### An Example Program

Here's an example program that calculates the area of a circle. Let's suppose you've written this program in a text
editor and saved it as `area.c`.

```
// Calculate the area of a circle
// DSM, 2016

#include <stdio.h>

#define APPROX_PI 3.14159

double area(double radius) {
  return radius * radius * APPROX_PI;
}

int main() {
  double r = 5.0;
  printf("area(%f) = %f\n", r, area(r));
}
```

### Compiling with GCC

`area.c` is a source code file, but C source code means nothing to the CPU: it's just text. In order to run the program, we need to 
convert `area.c` into a low-level machine language program that the CPU can execute.

