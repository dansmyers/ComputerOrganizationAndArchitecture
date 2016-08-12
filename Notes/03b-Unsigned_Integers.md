# Unsigned Integers

### Binary Numbers

Think about a number, any number. I like 4326. You can represent this number as a sum:

```
4326 = 4000 + 300 + 20 + 6
```

Each digit of the number corresponds to a multiple of a power of 10:

```
4326 = 4 * 10^3 + 3 * 10^2 + 2 * 10^1 + 6 * 10^0
```

Our traditional decimal number system, where each digit corresponds to a power of 10, is called the **base-10 number system**. We could also call it a "positional number system with radix 10." Ten is a good base for a number system, because humans (with the exception of my high school shop teacher, Mr. Ledford) have ten fingers.

Actually, lest I besmirch his memory, I should point out that Mr. Ledford was a great teacher, that I loved shop class, and that he lost his finger in an accident that nothing to do with woodworking.

There's no reason, however, to restrict ourselves to a base-10 number system. Computers use a **base-2 number system** also called the **binary system**. Each position in a binary number corresponds to a power of 2, and each digit can take one of two values, 0 or 1.

For example, the unsigned binary number 10111 can be converted into a decimal number by adding up the appropriate powers of 2:

```
10111 = 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0
      = 16 + 4 + 2 + 1
      = 23
```

Try writing down a few strings of zeros and ones and converting them from binary to decimal, like in the example above.

Suppose you have an N digit unsigned binary number. What values can it represent?

Answer: 0 to 2^N - 1, because an N-bit sequence can represent 2^N distinct values.

**Distinguishing Between Decimal and Binary**

Suppose you see a number like 1011&mdash;is it decimal one-thousand-and-eleven, or binary eleven? The difference will often be clear just from the context, but if it isn't, it's conventional to append a little subscript to identify the base of the number.

```
1011_2 --> binary number with a 2 subscript
1011_10 --> decimal number with a 10 subscript
```

### The Four-Digit Unsigned Binary Numbers

```
Binary    Decimal
------    -------
0000       0
0001       1
0010       2
0011       3
0100       4
0101       5
0110       6
0111       7

The rest of the table is left as an exercise...
```


### Binary Arithmetic

### Converting Decimal to Binary

### Hex and Octal
