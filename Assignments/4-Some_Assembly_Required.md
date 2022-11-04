# Assignment 4: Some Assembly Required

## Due

## You may work with a partner to complete this project

## Overview

## Submission Instructions

Code your programs on the CPUlator and verify that they work correctly. After you've finished each program, copy it into the appropriate file on the repl.it workspace I've created for this assignment. Note that you can't **run** your programs on repl.it; the workspace is only for the submission.

I will open up your workspace and check your programs by copying them to the CPUlator.

- Make sure that each program compiles.
- The final return value of the program should be in `r0` at the end of execution.
- Use the `push` and `pop` sandwich to mark the beginning and end of the main method.

Note that you can complete every question using only one main method. Don't write any additional functions or use the `bl` instruction to branch and link to a function (wait for the next assignment).

## Problems

The programs below use a mix of global and local variables.

- Global variables are declared outside of `main` in the C program and are created in the `.data` section of the ARM program. All assignemnts to and from global variables should use the appropriate `ldr` and `str` instructions in the ARM program.

- Local variables are declared inside `main` and are mapped to registers. You can decide how to allocate registers for the different global variables.

### The Basics

```
// Add up three global variables

// Global variables declared in .data section
int a = 10;
int b = 20;
int c = 30;

void main() {
  // Use registers for local variables defined in main
  int sum = a + b + c;
  return sum;
}

```

### Triple Max

```
int main() {
  // Use registers for local variables declared in main
  int x = 10;
  int y = 5;
  int z = 20;
  
  // max will hold the maximum of x, y, and z
  int max = x;

  if (y > max) {
    max = y;
  }

  if (z > max) {
    max = z;
  }

  return max;
}
```

### Pythagorean Theorem

Write an ARM program that declares two global variables *a* and *b*, then return the value
*c*<sup>2</sup> = *a*<sup>2</sup> + *b*<sup>2</sup>


### Mod in a loop

```
// Return remainder after integer division

// Global variables
int a = 4;
int b = 30;

int main() {
  // Use registers for local variables
  int remainder;
  int divisor;
  
  if (a > b) {
    remainder = a;
    divisor = b;
  } else {
    remainder = b;
    divisor = a;
  }

  while (remainder >= divisor) {
    remainder -= divisor;
  }
  
  return remainder;
}
```

### Fibonacci in a loop

```
// Calculate the 10th Fibonacci number in a loop

// Global variables
int fib = 1;
int prev = 0;

int main() {
  // Use registers for local variables
  int n = 1;
  int sum = 0;

  while (n <= 10) {
    sum = fib + prev;
    prev = fib;
    fib = sum;
    n++;
  }

  return fib;
}
```


### The Euclidean Algorithm

The **greatest common divisor** of two numbers *a* and *b*, written *gcd*(*a*, *b*), is the
largest integer that evenly divides both.

The Euclidean algorithm, named after the ancient Greek mathematician,  is
the Grandaddy of Them All: the oldest documented algorithm that
still has a practical application today. It finds
the gcd by exploiting the fact that

```
gcd(a, b) = gcd(a - b, b)
```

where *a* is the larger of the two values. This is not obvious, but arises from the
fact that any number that divides *a* and *b* must also divide *a* - *b*. Let *d* be a
common divisor of both *a* and *b*; it must be possible to write
```
a = dm
b = dn
```
for some numbers *m* and *n*. Therefore,
```
a - b = d(m - n)
```
and *d* is also a divisor of *a* - *b*.

Therefore, you can  find the gcd of two integers by repeatedly subtracting the
smaller from the larger until the two values are equal, as in the code below. Try
some example values and verify that it works. Note that if *gcd*(*a*, *b*) = 1 the
numbers are **coprime**: they have no common divisors.



```
// Return gcd of a and b
int a = 60;
int b = 25;

int main() {
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
}
```
