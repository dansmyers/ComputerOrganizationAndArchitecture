# Integers, Arrays, and Pointers

## Due Thursday, 9/29

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

Use this knowledge to compute the following bitwise operations. Give your answers in hexadecimal and show your work:

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

## Magic squares

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/D%C3%BCrer_Melancholia_I.jpg/1280px-D%C3%BCrer_Melancholia_I.jpg" width="50%" />

Albrecht Dürer, *Melancholia I*, 1514

### Method

A **magic square** is a square matrix where all rows, columns, and diagonals sum to the same value. For example, the Dürer etching shown above includes the following 4 x 4 magic square with sum 34.

<img src="https://upload.wikimedia.org/wikipedia/commons/7/7e/Albrecht_D%C3%BCrer_-_Melencolia_I_%28detail%29.jpg" width="33%" />

There are a number of methods, some of ancient origin, for generating magic squares. [The Wikipedia article has extensive information](https://en.wikipedia.org/wiki/Magic_square). The most well-known is called the **Siamese method**. It was brought to Europe by the French diplomat
Simon de la Loubère in 1688 who learned of it during his trip as an ambassador to the Kingdom of Siam. The method probably originated in India; 
De la Loubère returned from Siam with documents describing other aspects of Indian science, including some of the first information on Indian
astronomy ever brought to Europe. Again, [Wikipedia has you
covered](https://en.wikipedia.org/wiki/Siamese_method) if you want more details.

The Siamese method generates an *n* x *n* magic square where *n* is odd. By default, the square is filled with the numbers from 1 to *n*<sup>2</sup>.

The method proceeds as follows:

1. Initialize the empty *n* x *n* square.

2. Start in the center of the top row and place a 1 there.

3. Move **up and to the right** to find the next square to fill. If moving up and to the right moves you off of the grid, wrap around to the other side.

4. If moving up and to the right would cause you to land on a square that is already occupied, move down by one square instead of moving up and right.

5. Continue this process, placing the numbers in sequential order until the entire square is filled.

Here is the illustration of the 3 x 3 square:

<img src="https://upload.wikimedia.org/wikipedia/commons/7/77/SiameseMethod.gif" width="33%" />

Here is an explanation of the first five steps:

1. Place a 1 in the center of the top row.

2. Move up and to the right, wrapping around to the bottom to place 2 in the lower-right square.

3. Move up and to the right, wrapping around to the left side to place 3 in the middle-left position.

4. Moving up and to the right from the 3 square would land on the 1 square, so move down one square instead and place 4 in the bottom left square.

5. Move up and right from the 4 square to place 5 in the center position.

And so forth.

### Code

Write a program called `magic.c` that uses a 2-D array to implement the Siamese method for constructing magic squares.

- Use `scanf` to read the value of *n* from the terminal. If *n* is not odd, exit the program immediately.

- Initialize an *n* by *n* 2-D array of `int` values.

- Loop through the values 1 to *n*<sup>2</sup>, placing each in the appropriate position according to the magic square rules. Always start in the center of the top row.

- Print the complete square at the end.

Wrapping around the square while moving up and right is relatively easy. The following pseudocode uses two variables, `row` and `col` to keep track of the next position to fill. The steps calculate the next position that would be obtained by moving up and right (wrapping around if necessary), then either place the next value there, or move down if the up-and-right position is occupied.

```
int row = 0;
int col = n / 2;

for (int i = 1; i <= n * n; i++) {

  // Calculate the position that would be found if we moved up
  // and right, wrapping around if necessary

  // Check if that square is occupied
  
  // If it's not, put the current value of i there and
  // update row and col to the new position
  
  // If it is occupied, move down instead, put the current
  // value of i there, and update row and col
  
}

// Print the complete square
```

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
