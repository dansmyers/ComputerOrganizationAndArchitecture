# Signed Integers and Two's Complement

We now leave behind the simple, verdant world of unsigned integers and venture into the dark mysterious undercaverns of **signed** numbers.

There are two basic challenges to encoding signed integers:
  - How to represent a negative value as a sequence of bits?
  - How to make arithmetic involving negative values as easy as unsigned arithmetic?

## Sign-and-Magnitude Representation

In conventional written notation, a negative value is indicated by placing a negative sign in front of the number:

```
-5
```

Boom! It can't get much easier than that.

Sign-and-magnitude notation converts the concept of a negative sign into a bit-based integer encoding.

Suppose we have *N* bits available to encode a number. Choose one bit, typically the leftmost, to represent the sign.

```
leftmost bit is 0 --> number is positive
leftmost bit is 1 --> number is negative
```

The remaining *N - 1* bits indicate the magnitude of the number. For example, using a 5-bit representation,

```
Decimal    Sign-and-magnitude
-------    ------------------
      1                 00001
     -1                 10001
      5                 00101
     -5                 10101
     10                 01010 
    -10                 11010 
     15                 01111
    -15                 11111
```

In each case, the lower 4 bits encode the magnitude of the number.

Sign-and-magnitude seems easy, but suffers from a few implementation details. First, there are two zeros. In a 4-bit encoding, `0000` and `1000`.

More seriously, adding sign-and-magnitude numbers is complex. The adder's logic must check the sign of each number and interpret the operation correctly for all four possible combinations of signs. Straightforward unsigned arithmetic won't work:

```
  0101
+ 1101
-------
 10010  <--- Not zero!
```

An ideal system would allow adding signed ints using the same algorithm as unsigned ints. The **two's complement number system** has this property.

## Two's Complement

To represent a negative number in *N*-bit two's complement encoding,

  1. Write down the positive equivalent of the number **using all** ***N*** **bits**.
  2. Flip all of the bits.
  3. Add 1.

For example, to represent -5 in 4-bit two's complement:

  1. Write down positive five using all four bits: 0101
  2. Flip all the bits: 1010
  3. Add 1: 1011

Two's complement has the special property that unsigned and signed addition can be performed using the algorithm. For example, adding 5 and -5 and ignoring any final carry-out yields 0:

```
  0101
+ 1011
-------
 10000
 ^^^^^
 |||||
 |-----------Lower 4-bits are zero!
 |
Ignore final carry-out
```

**Make sure to use all of the available bits when encoding your answers!**

The two's complement representation is always encoded with respect to a given number of bits. When I ask you to work with two's complement numbers, I will always give you the number of bits to use.

**Negative Values Start with 1**

Two's complement is different from sign-and-magnitude encoding, but the leading bit will always tell you the sign of the number. A leading 1 indicates a negative value and a leading 0 indicates a positive value.


**Why Does Two's Complement Work?**

It's possible, of course, to formally prove the validity of the two's complement encoding, but here's an intuitive reason why adding a number and its negation in two's complement always yields 0.

Take any binary number, flip its bits, and add the original and bit-flipped versions. You're guaranteed to get all 1's. Adding one more 1 yields zero with a carry-out of 1.

```
  100010110
+ 011101001
------------
  111111111
+         1
------------
 1000000000
```

**Another Example**

Let's use the power of two's complement to add 3 and -12 in a 5-bit representation, then convert the result back to show that the sum is correct.

First, convert 3 to 5-bit binary:
```
3 --> 00011
```

Second, convert -12, using the algorithm from the previous section:

```
1. Write +12 using all 5 bits: 01100
2. Flip the bits: 10011
3. Add 1: 10100
```

Third, add the two values using normal binary addition:

```
   00011
+  10100
---------
   10111
```

What is `10111`? It starts with `1`, so it's a negative number.

The two's complement algorithm works both ways. To check the result of the sum, flip `10111` back to its positive equivalent: it had better be 9.

```
Flip the bits: 01000
Add 1: 01001
```

`01001` is 9! Therefore, the result is correct and -12 + 3 = -9, exactly as it should.

## Overflow

Suppose you want to add 7 and 1 using 4-bit two's complement representation. What's the result?

```
  0111
+ 0001
-------
  1000  
```

The leading bit is now 1, which indicates a **negative** value! `1000` is actually the 4-bit two's complement encoding of -8.

Consider what just happened. Adding two positive values **wrapped around** the entire number system to result in the maximum possible negative value.

This is called **overflow**.

An *N*-bit two's complement number can only represent positive values from 0 to 2 ^ *N* - 1. A sum that goes beyond this range will oveflow and give a negative result.

We often don't think about overflow, but it's always a concern when adding large integers.

**Example: Binary Search**

Recall the binary search algorithm. Here's a basic implementation.

```
// Search a sorted int array for a target value
//
// Inputs:
//   a: sorted int array
//   target: the target value for the search
//   n: number of elements in a
//
// Returns: the index where target occurs or -1 if the search fails

int binarySearch(int[] a, int target, int n) {
  int left = 0;
  int right = n - 1;
  
  while (left < right) {
    int middle = (left + right) / 2;
  
    if (a[middle] > target) {
      right = middle - 1;  // Search left half
    } else if (a[middle] < target) {
      left = middle + 1;  // Search right half
    } else {
      return middle;  // Target found
    }
  }
  
  return -1;  // Search has failed
}
```

Consider the line

```
int middle = (left + right) / 2;
```

Suppose `left` and `right` are very large. **This sum could overflow**, resulting in a negative index and an out-of-bounds array access.

In a system with 32-bit integers (like Java and most C implementations) this bug only occurs if the sum of the two values exceeds 2 ^ 31 - 1, which is more than 2 billion. Nonetheless, it **is** a bug.

In fact, this bug was in the Java standard library for many years and is in the majority of published binary search implementations.

How can you avoid overflow? Joshua Bloch, Google software engineer, [suggests](https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html)

```
int middle = left + ((right - left) / 2);
```

