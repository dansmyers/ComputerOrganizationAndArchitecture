# Integers, Arrays, and Pointers

## Due Friday, 10/6

## Overview

The following questions will allow you to practice working with number formats, two's complement, and continuing to write C programs using arrays and pointers for user input.

Put all of your work into the Assignment 2 workspace on repl.it. **Include a `Makefile` to automatically build your C programs**.

## Conversions

Write the following decimal numbers in their unsigned binary, hex, and octal representations. Put your answers in the text file named `conversions.txt` in
the repl.it workspace.

- 255
- 64
- 42
- 111

Tip: remember that each hex digit can be thought of as four binary digits. Each octal digit can be thought of as three binary digits.

## Sums

Convert the following decimal sums into their **8-bit two's complement representations**. Perform the sum using binary arithmetic, then
(for the problems with non-zero results) convert the result back from two's complement to decimal to show that your answer is correct. Put your
answers in the text file named `sums.txt` on the repl.it workspace.

- `20 + -20`
- `100 + -50`
- `-100 + 50`
- `77 + - 55`

## Bitwise operators

C supports **bitwise operators** that *operate directly on the underlying bits* of a variable. I've give you a short summary below. Read [this note](https://github.com/dansmyers/ComputerOrganizationAndArchitecture/blob/master/Notes/03f-Bitwise_Operators.md) for a more detailed overview and a discussion of bit shifting operators.

Suppose that you declare a variable:

```
int a = 0xFA
int b = 0x87
```

We can think of `a` and `b` as containers that hold collections of bits. In bit form:

```
a = 11111010

b = 10000111
```

The **bitwise AND* operator performs an AND operation on the corresponding bits of its two inputs. For example, to compute `a & b`, write down their underlying bits and take the AND of each pair:
```
a =       11111010
b =       10000111
------------------
a & b =   10000010
```
In hex form, the result is 0x82.

There are three other bitwise operators:

- `|` is the bitwise OR operator, it performs an OR operation on corresponding bits. In our example above, `a | b = 0xFF`.

```
a =       11111010
b =       10000111
------------------
a & b =   11111111
```

- `~` is the bitwise inverse, which inverts the bits of one variable. In the example above, `~a = 0x05`.

- `^` is the **bitwise exclusive OR** (XOR) operator. It output a 1 if the two bits are different and a 0 if they're the same. In the example above, `a ^ b = 0x7D`.

```
a =       11111010
b =       10000111
------------------
a & b =   01111101
```

Use this knowledge to compute the following bitwise operations. Give your answers in hexadecimal and show your work. Put your answers in a file called `bitwise.txt`.

- `0xC7 | 0xA8`
- `0xC7 & 0xA8`
- `~0xC7`
- `0xC7 ^ 0xA8` (where ^ is the exclusive-or operator)

## Bit twiddling

Bitwise operators enable a number of fun manipulations. Suppose that you have a `char c` that's an uppercase letter, `A` to `Z`. What's the effect of the following calculations? What if `c` is a lowercase character?

```
c | ' '  // Bitwise OR with space

c & '_'  // Bitwise AND with underscore
```

Tip: look at the ASCII table and think about the underlying bits of characters like `'A'` and `' '`, then reason about what character results when you do the bitwise operation.

What does the following bit-hack do if `c` is an upper or lower case letter?

```
c ^ ' '  // bitwise XOR with space
```

You're now ready to read about the greatest function ever written: the [Fast Inverse Square Root method](https://en.wikipedia.org/wiki/Fast_inverse_square_root) used in *Quake III Arena*.


## Caesar cipher

One of the classic ciphers of pre-modern cryptography, the Caesar cipher obscures a message by rotating each letter a set number of positions in the alphabet. The cipher is named after Julius Caesar, who allegedly used a three-position rotation to encrypt is personal communications. For example,

```
ATTACKATDAWN
------------
CWWCFNCWGCZQ
```

More generally, the rotation can be any number of positions. *ROT13* is a thirteen-position rotation, often used to obscure spoilers or hints on the old Internet.

Write a C program called `caesar.c` with functions called `encrypt` and `decrypt` that perform rotational encryption and decryption.

- `encrypt` takes a `char *` representing the message string and an `int n` representing the number of positions to rotate.
- `decrypt` takes the same input and performs the reverse rotation.

You can assume the message consists of only uppercase letters, `'A'` through `'Z'`, and no spaces or punctuation, which is common for cryptography messages. Here's some starting code:

```
/**
 * Caesar-style rotational cipher
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * encrypt(char *msg, int n) {
  // Allocate memory for the output string
  //
  // Use malloc to allocate a number of bytes equal to the length
  // of the input message
  char* output = malloc(strlen(msg));

  // Do the encryption

  return output;
}

char * decrypt(char *msg, int n) {
  // Allocate memory for the output string
  char* output = malloc(strlen(msg));

  // Do the decryption

  return output;
}

int main(void) {
  char *cipher = encrypt("ATTACKATDAWN", 5);
  printf("%s\n", cipher);

  char *plaintext = decrypt(cipher, 5);
  printf("%s\n", plaintext);
}
```

Use character arithmetic to compute the position of a character in the alphabet:
```
char pos = c - 'A';
```
You can reverse this operation to turn an alphabet position into a letter, assuming that `pos` is a `char` variable in the range 0 to 25.
```
char c = pos + 'A';
```
Think about how to use a loop over the string, get the position of every character, then calculate the shifted position and turn it back into a letter. Remember to loop around the alphabet if you go beyond `'Z'`.


### Treblecross

**Treblecross** is a one-dimensional tic-tac-toe variant. Both players take turns marking X's on a line of *n* squares. The object is to be the first player
to complete a grouping of three X's:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Treblecross.svg/440px-Treblecross.svg.png" width="20%" />

Implement a C program to play Treblecross. Your program should

- Prompt for the size of the playing array using `scanf`
- Quit if the input value is negative.
- Allocate an appropriately sized 1-D array of `char`.
- Print the board and read input on each turn. You can decide how to print the board, but make it legible.
- Successfully alternate between the two players.
- Detect the winning condition and declare the appropriate player the winner.

The easiest way to check for a win is to loop over the array and check if `a[i]`, `a[i + 1]`, and `a[i + 2]` are all X's.

```
if (a[i] == 'X' && a[i + 1] == 'X' && a[i + 2] == 'X') {
  // Winner, winner, chicken dinner
}
```

But pay attention to the end of the array!
