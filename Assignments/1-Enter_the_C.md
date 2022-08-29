# Assignment 1: Enter the C

## Due Wednesday, September 7

## What is the Pirate's Favorite Programming Language?

You'd think it would be R, but his first love is the C.

## Overview

This assignment is all about getting comfortable writing basic C programs in the online environment. Instructions are as follows:

- Use the link that I sent by e-mail to join our class teamspace on Replit

- Once you're in the team, you can load the workspace for Assignment 1. Do all of your work for this assignment in that workspace. **Do not put your homework solutions in the workspace you use for in-class examples**. I won't be able to see them there.

- Create a separate `.c` file for each problem. Follow the instructions given below.

- When you are done, use the Submit button in the upper-right of the workspace to hand in your project.


## Submission and Grading

I will load your workspace and run your programs. If you produce correct output for each problem, as described below, you'll get full credit for the assignment.

**You must create a `Makefile` to automatically compile your programs**. Note that I will not grade submissions that do not compile. Let me say that again: **I will not grade submissions that do not compile**.

Put each one of your programs in a separate file (not all in the same file) and follow the naming instructions given for each problem.


### Problems


### Look on my works, ye mighty, and despair!




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

### Binet's formula and linking with libraries

Recall the famous Fibonacci sequence, where each term is the sum of the previous two terms.

```
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Suppose you would like to calculate the Nth Fibonacci number. How could you do that? One way is to start at the base case and grind your way up through the sequence until you've calculated N total terms. 

It turns out there is a single formula that will calculate the terms of the Fibonacci sequence. This is weird and suprising, because it seems unlikely that such a highly structured sequence, where each term depends on all the previous terms, could be represented in closed form.

The result is know as Binet's formula and it says that the Nth Fibonacci number `F_n` is

<img src="https://latex.artofproblemsolving.com/8/6/d/86d486c560727727342090b432e23ba85ac098b1.png" width="10%"/>

Gnarly.

The number `(1 + sqrt(5)) / 2` is the famous golden ratio, the most aesthetically pleasing of all proportions. It's sometimes denoted by the Greek letter φ (phi) after the ancient architect and sculptor Phidias, who used it in planning the design of the Parthenon.

<img src="https://lp-cms-production.imgix.net/2019-09/ab57ac3775d90a72da514d158401bd47-parthenon.jpg" width="35%" />

(much columns  such proportions)

Implement a function called `binet` that takes an `int n` as input and returns the corresponding term in the Fibonacci sequence. Test your program by writing a `main` with a `for` loop that calculates and prints the first 20 numbers of the sequence.

But wait!



