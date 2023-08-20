# Assignment 1: Enter the C

<img src="https://imgs.xkcd.com/comics/compiling.png" width="40%" />

## Due Wednesday, September 6

## What is the Pirate's Favorite Programming Language?

You'd think it would be R, but his first love is the C.

## Overview

This assignment is all about getting comfortable writing basic C programs in the online environment. Instructions are as follows:

- Use the link that I sent by e-mail to join our class teamspace on Replit

- Once you're in the team, you can load the workspace for Assignment 1. Do all of your work for this assignment in that workspace. **Do not put your homework solutions in the workspace you use for in-class examples**. I won't be able to see them there.

- Create a separate `.c` file for each problem. Follow the instructions given below.

- When you are done, use the Submit button in the upper-right of the workspace to hand in your project.

## AI Guidelines

This assignment is about practicing core C programming concepts and develops skills that we'll use in future assignments. You must do all of these problems **by yourself**, without using any AI tools.

Remember that you **can** still use AI to engage with the course material and help you learn things, but don't use it to generate code for these questions.


## Submission and Grading

I will load your workspace and run your programs. If you produce correct output for each problem, as described below, you'll get full credit for the assignment.

**You must create a `Makefile` to automatically compile your programs**. Note that I will not grade submissions that do not compile. Let me say that again: **I will not grade submissions that do not compile**.

Put each one of your programs in a separate file (not all in the same file) and follow the naming instructions given for each problem.


## Problems

### Descending a staircase

<img src="https://upload.wikimedia.org/wikipedia/en/thumb/c/c0/Duchamp_-_Nude_Descending_a_Staircase.jpg/800px-Duchamp_-_Nude_Descending_a_Staircase.jpg" width="30%" />

Write a function called `stairs` that takes an `int n` as input and prints a staircase with `n` levels, like the following:
```
#
##
###
####
#####
```
Put your program in a file called `stairs.c` and write a `main` that prints a ten-level staircase.


### Triple min

Write a function named `tripleMin` that takes three `double` inputs and returns the minimum of the three. Don't use any built-in functions. Write an appropriate `main` to test your function and print results for the following cases:

```
double m = tripleMin(1, 2, 3);
printf("%f\n", m);

m = tripleMin(2, -1, 3);
printf("%f\n", m);

m = tripleMin(3, 3, 3);
printf("%f\n", m);
```

Put your solution in a file named `min.c`.


### Look on my works, ye mighty, and despair!

<img src="https://upload.wikimedia.org/wikipedia/en/1/1c/Iron_Maiden_-_Powerslave.jpg" width="25%" />

Write a function called `pyramid` that takes an `int n` as input and prints a pyramid of `n` levels. For example, if `n` is five, your program should print

```
    *
   ***
  *****
 *******
*********
```

Put your program in a file named `pyramid.c`. Write a `main` that uses your function to print a pyramid of 10 levels.

Tip: the top level has `n - 1` spaces and one star. The next level has `n - 2` spaces and three stars. You can use two variables `numSpaces` and `numStars` to keep track of the number of spaces and stars to print on the current line, then adjust them in a loop that iterates over the levels of the pyramid.

```
// Loop over thd pyramid levels
for (int level = 0; level < n; level++) {

  // Use a loop to print the spaces for level n
  
  // Use a loop to print the stars for level n
  
  // Go to the next line
}
```

Remember that `printf` doesn't automatically move to the next line, so you can print multiple characters on one line in a loop:
```
for (int s = 0; s < numStars; s++) {
  printf("*");
}
printf("\n");  // Move to the next line
```


### Hoard

Of course, my pyramid must be hollow to hold the precious objects that will accompany me to the Afterlife. Write a function called `hollow` that prints hollow pyramids of `n` levels. For example,
```
    *
   * *
  *   *
 *     *
*********
```
Notice that the bottom level is still full of stars.

Put your function in `pyramid.c` and add a line to the `main` to print a ten-level hollow pyramid after your print the ten-level solid pyramid. That is, `pyramid.c` should have two functions and print two different pyramids when it's run.


### McCarthy's 91 function

Mathematician John McCarthy and his colleagues defined the following function:

```
M(n) = 

    n - 10        if n > 100
    M(M(n + 11))  if n <= 100
```

This function is interesting because it evaluates to 91 for all inputs `n <= 100`. For larger values,

```
M(101) = 91
M(102) = 92
M(103) = 93

and so forth...
```

Implement the function `mccarthy(n)` to calculate McCarthy's 91 function. (No, you can't just make it return 91. You have to do the evaluation recursively.)

Put your answer in a file named `mcarthy.c`. Include a `main` with the following test cases:

```
printf("%d\n", mccarthy(1));
printf("%d\n", mccarthy(99));
printf("%d\n", mccarthy(101));
printf("%d\n", mccarthy(111));
```

### Ancient algorithms

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/5a/Complaint_tablet_to_Ea-Nasir_2020.jpg/1024px-Complaint_tablet_to_Ea-Nasir_2020.jpg" width="25%" />

*The complaint tablet to Ea-Nasir from ca. 1750 BC. It was written by a merchant named Nanni, complaining that Ea-Nasir's copper was not of the "finest quality" and that he had treated Nanni's messengers with "contempt". When archaeologists excavated Ea-Nasir's house they discovered that one of his rooms was filled with tablets, many of which were complaints from other merchants that he had saved for posterity.*

<img src="https://towardsthemoonblog.files.wordpress.com/2022/01/img_9026.jpg?w=768" width="25%" />

How do you actually implement numerical algorithms for things like square roots or trig functions? Here's one famous example, an ancient method for approximating square roots. It's traditionally called the Babylonian method, though it's unclear if Babylonian mathematicians actually used it, although they did have methods for working with roots and quadratic equations.

The method seeks to find the square root of a number `n` starting from an initial guess `x`. Intuitively, if `x` is smaller than the real root, then `n / x` will be *greater* than the real root. Likewise, if `x` is larger than the root, `n / x` will be smaller. The Babylonian method calculates a better approximation using the update rule
```
x = .5 * (x + n / x)
```
The initial value of `x` is a guess of the true root. For example, if we seek the root of `n = 144` starting from `x = 1`, the first update will be
```
x = .5 * (1 + 144 / 1) = 72.5
```
Subsequent iterations will yield roots of 37.243, 20.554, 13.780, 12.115, and 12.000. Despite a poor starting choice, the method converges quite quickly. (The Babylonian method is in fact a special case of Newton's method, which you may have seen in a Calculus class.)

Write a function called `root` that takes `double n` and `double x` as inputs, then performs the Babylonian square root algorithm. Return the result as a `double`. Put you result in a file named `roots.c` and add a `main` that estimates the square root of 2 and prints the result to **four decimal places**.

Tip: you need to determine when to step the root finding process. Define a tolerance value at the top of the program:
```
#define TOL .0001
```
Use a `while` loop that checks the difference between the old value of `x` and the next value in every iteration. Continue looping until the change in the estimate of the root becomes smaller than `TOL`.

```
// Start with a large diff for the first iteration
double diff = 100.0;

while (diff > TOL || diff < -TOL) {
  // Save the current value of x
  
  // Calculate new value using the update rule
  
  // Update diff
}
```

### Binet's formula and linking with libraries

Recall the famous Fibonacci sequence, where each term is the sum of the previous two terms.

```
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Suppose you would like to calculate the Nth Fibonacci number. How could you do that? One way is to start at the base case and grind your way up through the sequence until you've calculated N total terms. 

It turns out there is a single formula that will calculate the terms of the Fibonacci sequence. This is weird and suprising, because it seems unlikely that such a highly structured sequence, where each term depends on all the previous terms, could be represented in closed form.

The result is know as Binet's formula and it says that the Nth Fibonacci number `F_n` is

<img src="https://latex.artofproblemsolving.com/8/6/d/86d486c560727727342090b432e23ba85ac098b1.png" width="25%"/>

Gnarly.

The number `(1 + sqrt(5)) / 2` is the famous golden ratio, the most aesthetically pleasing of all proportions. It's sometimes denoted by the Greek letter φ (phi) after the ancient architect and sculptor Phidias, who used it in planning the design of the Parthenon.

<img src="https://lp-cms-production.imgix.net/2019-09/ab57ac3775d90a72da514d158401bd47-parthenon.jpg" width="35%" />

*much columns  such proportions*

Implement a function called `binet` that takes an `int n` as input and returns the corresponding term in the Fibonacci sequence. Test your program by writing a `main` with a `for` loop that calculates and prints the first 20 numbers of the sequence.

Put your solution in a file named `binet.c`.

But wait! You need the ability to calculate `sqrt` and `pow` functions. Both are defined in `math.h` and you can search the Internet to see how they're used.

To use the math functions, you'll need to `#include <math.h>` at the top of your program and also **link your code** with the math library. Libraries are pre-compiled collections of useful routines. The linking process merges this pre-compiled code into your executable.

By convention, all libraries start with the prefix `lib-`, followed by the name of
the library. The math library is called `libm.a` and lives in a subdirectory of
`/usr/lib`. Use the `-l`  flag to link a library, like so:
```
gcc -Wall -Werror -o binet binet.c -lm
```
`gcc` processes the `-l` flag by interpreting the rest of the flag (the letter `m` in this case)
as  the name of a library. It then uses that name to generate a library name in the
standard form (`libm.a`), looks up the library, and adds it to your program.



