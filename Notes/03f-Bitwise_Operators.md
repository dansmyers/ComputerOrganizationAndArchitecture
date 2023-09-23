# Bitwise Operators in C

The **bitwise operators** in C are operators that are designed to manipulate a binary pattern at the bit level.  That is, we think of the "+" operator (for example) of operating on two numerical values and the result is also a numerical value.  However, the bitwise operators change the bit pattern of the variables.  It is then up to the program to determine how to interpret the new bit pattern.

In this class, we'll be focusing on the following bitwise operators:
* `>>` - right shift (arithmetic or sign-extending)
* `>>>` - right sign (logical)
* `<<` - left shift
* `&` - bitwise and
* `|` - bitwise or
* `~` - bitwise negate

## Representing Bit Patterns
The first thing to know is that we can use an integer "container" to store a bit pattern in C without really caring about what **quantity** the bit pattern represents.  C (specifically, the `gcc` compiler) allows us to use different prefixes to specify a pattern when we don't really care to figure out the corresponding 2's complement pattern.

For example, the following 3 variables all store the same bit pattern internally.  Work out the values and representations if you need to to verify this fact.
```
int binary_pattern = 0b00001101;
int hex_pattern = 0x0D;
int numerical_value = 13;
```

You can also specify octal representations with a leading 0, but this is confusing and leads to hard to understand code, so we won't be covering it here.

There are also ways to print out bit patterns easily using `printf`.  For example, consider the following code which allows us to print the hex representation of an integer value.

```
int num = 32;
printf("int value: %d \t hex rep: %x \n", num, num);
```

Unfortunately, there is no print specifier which allows us to easily print binary representations.  You'll need to convert from hex to binary yourself or write your own function if you want that capability.

## Shift Operators
The operators `>>`, `>>>`, and `<<` shift, that is "push", a bit pattern right or left.  The operators need the bit pattern to be manipulated and the number of places to shift the value.  Thus, the usage is:

```
bit_pattern_var shift_operator num_places
```

This example shifts the bit pattern stored in `x` to the left by 2 places.
```
x << 2
```

Shift operators are like other mathematical operators in that they do not change the variable they operator on.  Instead, we must assign the new pattern to a variable:

```
int y = x << 2;
or
x = x << 2;
```

### Left Shift
The left shift is the easiest to understand.  In this case, the number of bits (specified by the 2nd operand) are removed from the left-most portion of the bit pattern and the same number of 0's are concatenated to the right side of the pattern.  

For example, consider the pattern `0b01000101` stored in a variable called `x`.  (We'll use 8 bits to demonstrate the concepts, but remember that integers actually contain 32 bits (usually)).  If we evaluate the expression `x << 3`, we remove the 3 bits on the leftmost side of the bit pattern, `010` in this example, and "shove" the rest of the bits to the left. This gives us the pattern `00101`.  We then concatenate the same number of 0's to the right end of the pattern, giving us the pattern `00101000`.  

This operator is relatively easy to remember, since the operator itself points the direction the bits move: `<<` points left which is how the bits shift.  If the operator points right, we have some slight differences to iron out.

### Right Shift (Logical)
The logical right shift, `>>>` operates just like the left shift describe above except that it shifts the bit pattern to the right and adds 0's to the left.

If we again use the bit pattern `0b01000101` and evaluate the expression `x >>> 3`, we end up with the pattern `00001000`.

### Right Shift (sign-extending or arithmatic)
The  `>>` operator shifts right as well, but it performs a **sign-extending shift**.  Remember that for integers in 2's complement format (which all modern computers use), negative numbers will have a 1 in the left-most bit position.  If we were to shift the number right, we could change the sign from a negative to a positive.  There are good reasons for wanting a negative number to remain negative, even if it is shifted.  Consider the following example (again, done in 8 bits for simplicity, but the same concept applies to 32 bit integers as well).

Assume `x` is the bit pattern `11111011`.  This represents the value -5 in 2's complement format (for 8 bits).  If we shift the pattern 1 place to the right and shift in 0's, we would have the bit pattern `01111101` (this would be a logical shift, as described in 13.2.2).  This value is not a negative number!  Now it represents the integer value 125.

However, a sign-extending shift would shift in a 1 if the leftmost bit was a 1 and 0 if it was a 0.  That is, it maintains the most signficant bit in the pattern.  The resulting bit pattern `11111101` is the equivalent of -3.

Summary (again, in 8 bits for simplicity): 
```
int x = 0b11111011;
printf("x: %d, x >> 1: %d\n", x, (x >> 1));    //prints x: -5, x >> 1: -3
printf("x: %d, x >>> 1: %d\n", x, (x >>> 1));  //prints x: -5, x >>> 1: 125
```

If the most significant bit is a 0, then 0's are added and the shift acts like the logical shift described previously.


## Logical Bitwise Operators
The bitwise logical operators, `&`, `|`, and `~` operate much like their counterparts, `&&`, `||`, and `!`.  However, they once again operate a lower, bit level on the pattern.

### Negate
The bitwise negation operator, `~` inverts ("flips") all the bits of the variable it operates on.  Assume a variable `x` has been initailized to 20.  The bit pattern for 20 is `00010100` (again, in 8 bits rather than 32).  The expression `~x` would evaluate to the inverse bit pattern, `11101011`.  Notice that this is **NOT** the same as converting `x` to the value -20.  `~` is a bitwise operator and inverts each bit individually while `-` negates the value mathematically.  The code snippet below shows these differences.

```
int x = 20;
printf("%d %d %d\n", x, -x, ~x);  // prints 20 -20 -21
printf("%x %x %x\n", x, -x, ~x);  // prints 0x14 0xffffffec 0xffffffeb
```

### Bitwise And
The bitwise and operator, `&` performs a logical and between two values, but again, it does it by applying the and operation to each pair of bits.  Let `x` be the value 20 (bit pattern `00010100`) and `y` be the value 12 (bit pattern `00001100`).  To calculate `x & y`, we compare each pair of bits: 1 from `x` and 1 from `y` and determine the logical result.  It often helps to rewrite the numbers vertically to more easily apply the logic to the pairs of bits:

```
x:      0 0 0 1 0 1 0 0
y:      0 0 0 0 1 1 0 0
------------------------
x & y:  0 0 0 0 0 1 0 0
```
We can see that the bitwise and operator only retains bits which are 1 for BOTH `x` and `y`.  Otherwise, the result is set to 0.

### Bitwise Or
Bitwise or, `|`, is like bitwise and but applys the "or" logic bit by bit.  Using the same values for `x` and `y` as above:

```
x:      0 0 0 1 0 1 0 0
y:      0 0 0 0 1 1 0 0
------------------------
x | y:  0 0 0 1 1 1 0 0
```

## Check Yourself
Complete the following chart, if `a = 60` and `b = 13`, and `c = -15`.  For simplicity, you can use 8-bit represenations rather than the full 32-bit representations.

| expression | resulting bit pattern |
|---------------|------------|
| `a & b` |
| `a \| b` |
| `~a` |
| `a << 2` |
| `c >> 2` | 
| `c >>> 2` |

## Why?
This are all wonderful new things to learn, but what is an actual application of bitwise operators?  When would we want to use them in practical programming?  The short answer is, when space (memory) matters.  We can use an `int` as an array of bits to represent 32 different things.

For example, suppose we write a program which has 32 command line flags which can be used to alter the behavior of the program.  We could read these flags in and store each of them in an integer:

```
...
int o_flag = 0;
int t_flag = 0;
int x_flag = 0;
...
if(o flag is set) {
  o_flag = 1;
}

if(t flag is set) {
  t_flag = 1;
}
...
```
However, if each `int` uses 4 bytes of space we have used `4 * 32` or 128 bytes just to store command line flags.  Instead, we could use 1 `int` and set each bit to represent a specific flag.  For example, we could say that bit 0 (the rightmost bit) represented the -o option, bit 1 represented the -t flag and so on.  Then our code would look more like:

```
int cmd_flags = 0;
if(o flag is set) {
  cmd_flags = cmd_flags | 0x1;
}
if(t flag is set) {
  cmd_flags = cmd_flags | 0x2;
} 
if(x flag is set) {
  cmd_flags = cmd_flags | 0x4;
}
...
```

Make sure you understand why the bitwise or operator sets specific bits in the above pseudo-code.

We can also use **bitmasking** to extract individual bits.  Say that we want to know if the x flag was set in our variable `cmd_flags`.  We can use the code:

```
int x_flag = cmd_flags & 0x4;
if(x_flag) {
  //change behavior of program
}
```

Again, make sure you understand why using the bitwise and operator would leave us with only the value of the x flag and would not include other flags in the variable `x_flag`. Any time we have options which can be treated independently of one another, using a bit array can be a good strategy for saving memory space (particularly valuable in embedded systems).
