# Introducing C

### Why C?
  
C is the default language of systems programming. It's been around since the early 1970's and is intimately connected to the UNIX
operating system and, by extension, modern Linux and Mac systems.

Many popular and critical projects are written primarily in C, including:

  - The Windows, Mac OS, and Linux kernels
  - The Perl, Ruby, and Python reference implementations
  - The Apache and nginx webservers and the sendmail e-mail server
  - Doom
  
C is an exceptionally portable language that transfers easily to new platforms. This features has made it a popular choice for 
embedded systems development. Further, given that it compiles down to native machine code and adds relatively little overhead for
abstractions, C is often a competitive choice for high-performance applications.

### C vs. Java

Here's what one of my teachers told me when I was learning C:

  > C is like the surgeon's scalpal. It gives you great power, but lets you do a lot of damage if you aren't careful. Java is like
  > those chunky scissors you give to toddlers so they can pretend to cut construction paper without hurting themselves.
  
C assumes that you know what you want to do and then allows you do it. Unfortunately, this philosophy means that C won't prevent you
from writing code with hard-to-find bugs and critical security flaws. Good C programmers are always a little bit paranoid about the
code they write.

Java, through the JVM, aims to create an abstract, idealized programming environment, so you can write cross-platform code that is
independent of the underlying system. Features like garbage collection and automated memory management support this abstration and
reduce the work that you as a programmer need to perform to work with objects.

C is arguably the "high level" language that provides the thinnest abstraction on top of assembly language---in fact, 
some would argue that C isn't a "high level" language at all, at least by modern standards. C tends to be used when you *need* 
an awareness of the underlying system. C also requires you, the programmer, to handle tasks like memory management that Java 
automates.

On the one hand, C's lack of abstraction and support for things like garbage collection is a pain. On the other hand, it forces
you to really understand the basic programming environment provided by the OS, particularly the way that programs use memory.

### Hello, World!

The noble and most ancient example problem.

```
// Print Hello, World! to the console
// DSM, 2016

#include <stdio.h>

int main() {
  printf("Hello, World!\n");
  return 0;
}
```

**C Lacks `class`**

Coming from a Java background, the first thing you may notice is the lack of `public class` and `public static void`.

C was created back in the days (1972) when people wrote programs by making scratches on narwhal bones. This mostly predates the 
concept of object-oriented programming as we understand it today. Smalltalk, one of the first true object-oriented languages, was
introduced at about the same time as C, but OOP didn't really take off until the late 1980's and early 1990's.

C programs, therefore, don't have classes, or use declarations like `public` and `private`. C does have the concept of a `struct`, which
can be used to group related data items together, but a C `struct` is more primitive than a Java object and can't contain methods. More
on that later.

**The `main` Function**

Every C program must have a function named `main`, which serves as the entry point for the program. It is possible for `main` to take
input arguments from the command line; we'll talk about this later.

By convention, `main` returns 0 if the program completed successfully or a non-zero value on an unsuccessful completion or error.

**Printing**

Use `printf` to output a string to the console. C strings, like Java strings, are enclosed in double quotes.

`printf` does not automatically advance to the next line; use `\n` to print a newline. The other familiar special
characters are also accepted: `\t` for tab, `\\` for literal backslash, and `\"` for a literal quote.

**Headers**

Like Java's `import` statment, C has a way of loading additional files to incorporate useful functions into your program. These
files are called *header files* have the `.h` extension. The `stdio.h` header contains definitions of several useful I/O functions,
including `printf`.

```
#include <stdio.h>
```

Statements beginning with `#` are *preprocessor directives*. They instruct the C preprocessor, the first phase of the compiler, to 
perform certain action.

In this case, the `#include` statement instructs the preprocessor to locate the file called `stdio.h` and
insert its contents into the source file. The angle brackets tell the preprocessor to look in the system's standard header file
location, which is usually `/usr/include`. Use quotes if the header file is in a local directory:

```
#include "local.h"
```

**Constants**

Another useful preprocessor directive is `#define`, which declares a constant.

```
#define PI 3.14159
```

This instructs the preprocessor to replace every occurence of `PI` in the source code with `3.14159`. C constants are capitalized, as in
Java.

Aside: an accurate double value of PI is available in `math.h`.

### Variables, Functions, and Conditionals

Here's another simple program that uses a function to test if a number is even.

```
// Example: test if numbers are even
// DSM, 2016

// Function: isEven
//
// int n: the integer to test
// returns: 1 if n is even, 0 otherwise
int isEven(int n) {
  if (0 == n % 2) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    if (isEven(i)) {
      printf("%d is even.\n", i);
    }
  }
  
  return 0;
}
```

**Printing Variables**

*Format specifiers* are used to print variables. Each format specifier begins with a `%` sign and serves as a placeholder for a
value that will be incorporated into the output string. When the string prints, `printf` substitutes the variable's value in place
of the specifier.

The format specifier for integer values is `%d`, as in "decimal".

```
printf("%d is even.\n", i);
```

You can print multiple values in one statement: just include multiple format specifiers and list each variable as 
an argument to `printf`. For example (using `%f` as the format specifier for floating point values):

```
double r = 5.0;
double area = 3.14 * pi * pi;
printf("The area of a circle with radius %f is %f.\n", r, area);
```

The format specifier can also control things like the number of digits printed after the decimal point. You'll get more
practice using these features later.

**Variables, Names, and Types**

C supports primitive types that are familiar to Java programmers:

  - `int`
  - `char`
  - `long`
  - `short`
  - `float`
  - `double`

The rules for variable naming and the preferred style are the same as Java's:

```
int numberOfHarryPotterBooks = 7;
char firstLetter = 'D';
double notQuitePi = 3.14;
```
  
There are, however, a few important differences between C and Java types:

  - Java guarantees the sizes of all its data types. A Java `int` will always be 32 bits and support signed values
    from -2,147,483,648 to 2,147,483,647. 
    
    C only guarantees that its `int` will be at least 16 bits. It will, in practice, be
    either 32 or 64 bits on modern systems, but the language doesn't mandate it. We'll talk more about this issue when we discuss
    data representations.
    
  - A Java `char` is 16 bits and can hold values from 0 to 65535. The C `char` is only 8 bits (one byte) and can represent values
    from 0 to 255. Again, we'll talk more about this when we discuss text encodings.
  
  - Java guarantees that new variables are initialized to 0. C doesn't: you might get 0, or you might get a seemingly 
    random initial value based on the contents of memory. The only way to guarantee that a new variable will be 0 is to assign the
    value yourself.

**Conditionals**

C's `if` statements look the same as Java's, but there is one important difference: *C does not have a Boolean data type*. There 
are no `true` or `false` values in C. Instead, `0` is treated as `false` and anything nonzero is treated as `true`.

```
int x = 1;
if (x) {
  printf("Looks true to me.\n");
}
```

Note that `isEven` in the example above returns either `0` or `1`. In general, though, you should never assume that function that
performs a logical comparison will always return `1` for a true result. Always test for equality or inequality with respect to `0`.

This behavior is also responsible for one of the all-time classic C bugs: what happens if you accidentally type a single `=` instead
of `==`?

```
int x = 0;
if (x = 1) {
  printf("Looks true to me.\n");
}
```
Assignment in C is actually an *expression*, not a statement, so you are allowed to write `if (x = 1)`.
C, assuming that you are doing what you want to do, assigns 1 to `x`, which then guarantees that the conditional always evaluates as
true and the `if` body always executes. Note that it also changes the value of `x`, which might lead to more bugs later in the program.

To defend against this bug, place the variable on the *right side* of the comparison:

```
0 == x % 2
```

If you accidentally type `=` you'll have an invalid assignment with `0` on the left-hand side:

```
0 = x % 2  // Syntax error
```

### Arrays

**C vs. Java Arrays**

Java arrays and C arrays might look and feel similar, but they're actually quite different. Java arrays are objects, created using
the `new` keyword. A C array, by contrast, is just a block of contiguous memory with a label that identifies the beginning of the
block.

**Array Basics**

Declare an array of known size like this:

```
int a[10];  // Declares space for 10 ints
```

If you know the initial values you can specify them with curly braces:

```
int primes[5] = {2, 3, 5, 7, 11};
```

Individual elements are accessed with square braces and indexed from 0, just like in Java.

```
int firstPrime = primes[0];
int sumOfFirstTwoPrimes = primes[0] + primes[1];
```

**You Can't Do That With Arrays**

A C array declaration permanently associates the variable name with the allocated block of memory. Any operation that would change
that association, like assigning the array name to another array, is not permitted.

For example, to create two arrays that have the same values, you might try something like this:

```
int a[5] = {1, 2, 3, 4, 5};
int b[5];

b = a;  // Not allowed!
```

**Danger Zone**

There is one thing you must never forget: **C DOES NOT PERFORM BOUNDS CHECKING ON ARRAY ACCESSES.**

Consider the following code:

```
int a[5];

for (int i = 0; i < 10000000; i++) {
  a[i] = i;
}
```

Trying to run code like this in Java would result in an `ArrayIndexOutOfBounds` exception at the moment you attempt to access `a[5]`.

C, however, does not check that index is within the allocated size of the array. An array is simply a block of memory and an index is
just a location beyond the start of the array, so reading and writing beyond the declared size is permitted.

Writing beyond the end of an array will overwrite whatever values were stored in the memory location you access. The consequences of
clobbering memory this way are unpredictable: your program may continue to work fine, it may crash, it may corrupt other data, or it
may do one of these things some of the time and other things at other times, depending on the state of the system.

In certain circumstances, this behavior can be exploited by malicious hackers to launch a *buffer overflow attack*, which can allow 
an attacker to gain control of your system and execute arbitrary code. Buffer overflows have led to hundreds of serious security
problems on high profile systems.

### What's Next

This note has explained some of the key concepts of C programming, with an emphasis on the features of C that are different from Java. 
The next note covers compiling and running C programs in the terminal environment.

The next time we visit C, we'll take a look at what is arguably its most important and challenging feature: pointers.
