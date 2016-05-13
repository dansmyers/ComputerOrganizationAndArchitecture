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
*compile* `area.c` into a low-level machine language program.

GCC (the GNU Compiler Collection) is a popular free software tool created by the GNU Project. I'll usually refer to GCC as "the 
compiler," but it's actually a suite of programs that do the work of transforming an input source code file into an output executable.
The compilation process has four main phases:

  1. The C preprocessor, which scans the input and deals with statements like `#include` and `#define`. The output of this phase is
     another C source code file with some of the text transformed.

  2. The compiler proper, which takes the preprocessed source code file as input and produces an *assembly language* program,
     containing the actual sequence of low-level machine instructions that make up the program in a (more or less) human-readable form. The compiler does a lot of work, including examining the syntax and structure of the source file to ensure that it's a valid C
     program. The compiler may also *automatically optimize* the program before generating its final output.

  3. The assembler, which takes the assembly language program produced in step (2) as its input and produces a binary *object file* as
     its output. The object file contains the same instructions as the assembly language file, but encoded in a binary format the CPU
     can understand.

  4. The linker `ld`, which takes the object file produced in step (3) and converts it into an actual executable program. If necessary,
     the linker also handles the work of combining multiple object files into one program or incorporating code from pre-compiled
     libraries into the final executable.
  

