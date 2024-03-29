# Floating Point

## Fractional Binary Numbers

Recall our previous discussion on positional number systems, where each digit corresponds to a power of some base value. In the decimal number system, values to the right of a decimal point correspond to negative powers of 10.

```
3.14 = 3 + .1 + .04
^ ^^  
| ||------- 10 ^ -2 place
| |
| |------- 10 ^ -1 place
|
|--- 10 ^ 0 place
```

The same concept can apply to any base. In base-2, digits to the right of the "binary point" corrrespond to negative powers of 2.

```
1.101 = 1 + .5 + .125
```

Scientific notation provides a compact way of representing large and small numbers.

```
3.5678 * 10 ^ 5 = 356780
```

Binary numbers can also be written in scientific notation with a power of two as the exponential term.

```
1.001 * 2 ^ -3 = .001001
```

The part of the number with fractional values is called the **significand**. The general form for a binary scientific notation number is

```
(-1) ^ sign * significand * 2 ^ exponent
```

Here, the `sign` value is either 0 or 1, making the overall value positive or negative, respectively.

The floating point representation encodes a number in binary scientific notation using a sequence of bits. The format for floating point values has been standardized by the IEEE, a major international professional association, as the IEEE 754 standard.

## Floats and Doubles

The `float` type represents a 32-bit floating point number:
  
  - 1 bit is used for the sign
  - 8 bits are used for the exponent
  - 23 bits are used for the significand
  
The `double` type (short for "double precision") is a 64-bit number:

  - 1 bit is used for the sign
  - 11 bits are used for the exponent
  - 52 bits are used for the significand
  
A `float` type offers about 7 digits of precision. A `double` type offers about 15 digits of precision.

## More Detail on the Floating Point Format

The precise bit-level representation is slightly more complicated than described above. The complete formula for a `float` is

```
(-1) ^ sign * 1.f_22 f_21 f_ 20 ... f_0 * 2 ^ (exponent - 127)
```

Here, `f_22 f_21 f_20 ... f_0` represents the 23 bits of the significand encoded in the `float` value. The implicit leading 1 increases the number's precision.

The offset exponent allows the `float` to represent both large positive and large negative exponents with only 8 bits.

The format for the `double` type is similar.


## Numerical Errors

Many values cannot be represented exactly in the floating point format. 

This is not really surprising, since base-10 has the same property. Consider 1/3: it can only be written approximately using any finite number of digits:

```
1/3 ~ .3333333333
```

The following program illustrates that .2 can't be represented exactly by a float:

```
#include <stdio.h>

int main() {
    float f = .2;
    printf("f = %.10f\n", f);
    
    return 0;
}
```

The format specifier `%.10f` instructs `printf` to print 10 digits to the right of the decimal point. The output of the program is

```
f = 0.2000000030
```

This imprecision means that calculations involving floating point value can have accumulated error. Here is a somewhat extreme example:

```
float sum = 0.0;
int i;

for (i = 0; i < 1000000; i++) {
  sum += .2;
}

// sum should be .2 * 1000000 = 200000

printf("sum = %.10f\n", sum);
```

The output of the program is

```
sum = 201916.6875000000
```

Yikes!

## Special Types

Consider the following expression:

```
float f = 1.0 / 0.0;
```

This isn't, of course, the kind of thing you'd normally write in a program, but you might accidentally generate float division by 0.0 during a series of numerical calculations. If you run a program with that statement and print `f`, you'll find that it has a special value: `inf`.

The IEEE 754 standard reserves special bit patterns for `float` and `double` types to represent positive and negative infinity. As you'd expect, the result of a calculation involving `inf` remains `inf`.

```
float f = 1.0 / 0.0 * 100000.0;  // still inf
```

Note, however, that this only applies to floating point types. A similar expression involving integers would generate a compiler error:

```
int divideByZero = 1 / 0;  // Compiler error!
```

How about this undefined expression?

```
float f = 0.0 / 0.0;
```

If you print `f`, you'll see that it's assigned the special value `nan`, which is short for **not-a-number**. NaNs are generated by undefined expressions. Like `inf`, any calculation involving `nan` automatically results in a `nan`. Therefore, they have the nasty habit of propagating through your calculations. If you see `nan` as the output of a function, go back and look for operations that might have generated an undefined value.

## Overflow and Underflow

We previously discussed the problem of **overflow** in two's complement integer representations. Recall the problem of adding 7 + 1 using 4-bit two's complemnt:

```
  0111
+ 0001
-------
  1000
```

The leading bit is 1, so this is a **negative** value. In fact, `1000` is -8 in the 4-bit two's complement system. Therefore, adding two positive numbers can actually **wrap around** the entire number system and yield a **negative** result.

```
   --------
  |       |
  |       |
0111      |
          | Overflow "wraps around" the
          | two's complement space
1000      |
  ^       |
  |       |
  --------        
```

A similar problem exsits with floating point values. A floating point number has only a finite number of bits to encode values, so it's possible to generate results that are too large (in either the positive or negative direction) to represent in the space of a `float` or `double`. Going beyond the maximum value in either direction results in a **floating point overflow**.

A similar problem exists for values close to zero. It's possible for operations on small values to return a result that **too close to zero** to represent in the available number of bits. This result is said to **underflow** and will usually be clamped to zero, which may not be what the programmer intended. 

The IEEE 754 standard includes provision for special **denormalized numbers** that allow for the representation of fractional values closer to zero that would be possible with the encoding described above.

The maximum value for a `double` is about `1.7976931348623157 × 10 ^ 308`. The value closest to zero, using denormalized numbers, is about `5 × 10 ^ −324`.
