# Conditionals and Loops in Assembly

## Previously on Assembly Language Programming

This lab will give you a chance to practice writing programs with conditional control flow in ARM assembly.

First, lets recall some important facts about conditional execution.

The **Application Program Status Register** (APSR) maintains a set of 1-bit **flags** that keep track of the results produced by instructions as they execute. For our purposes, the most important flags are:

  - *N*, the negative bit, which is set to 1 when a comparison produces a negative result and 0 otherwise. Recall that, in the two's-complement system, a negative value has a leading 1 in its most-significant bit. Therefore, the *N* flag is set whenever a comparison produces a result with a leading 1.
  
  - *Z*, the zero bit, which is set to 1 when a comparison produces all zeros and 0 otherwise. Note that the bit is **set to 1** to indicate a zero value; don't let the zero bit's name confuse you!
  
The basic instruction for implementing relational comparisons is `cmp`, which takes the difference of its two arguments and sets the appropriate APSR flags based on the result, but **doesn't modify any registers**.  Examples:

```
// Calculate r0 - 5 and set flags; r0 is unchanged
cmp r0, #5

// Calculate r5 - r3 and set flags; both remain unchanged
cmp r5, r3

// Calculate 0 - r8
cmp #0, r8
```

It's possible for instructions other than `cmp` to modify the APSR flags. In particular, arithmetic and logical operations, like `add` will update the flags. We're not going to worry about using any instruction other than `cmp` to set up conditional branches.

There are six basic conditional branching instructions:

  - `beq`: take branch if the last comparision was equal to zero (the *Z* bit is set)
  - `bne`: take branch if the last comparison was not equal to zero (*Z* bit is not set)
  - `bgt`: take branch if the last comparison was strictly positive (*Z* not set and *N* not set)
  - `blt`: take branch if the last comparison was strictly negative (*Z* not set and *N* set)
  - `bge`: take branch if the last comparision was greater than or equal to zero (*Z* set or *N* not set)
  - `ble`: take branch if the last comparison was less than or equal to zero (*Z* set or *N* set)
  
## If

Here is a complete example that uses `cmp` and conditional branching:

```
// Branching on a greater-than condition

// Key code fragment:
// if (x >= 1) {
//     x = 1;
// }

.global main

/*** Data section ***/
.data
x: .word 11

/*** Text section ***/
.text

main:
    push {ip, lr}

    // r0 <- x
    ldr r0, =x
    ldr r0, [r0]

    // Calculate r0 - 1 and set flags
    cmp r0, #1

    // Branch on opposite quality
    // if x < 0, jump around if body
    blt done

    // Body: x <- 0
    mov r0, #1
    ldr r1, =x
    str r0,[r1] 

  done:

    // Return
    ldr r0, =x
    ldr r0, [r0]

    pop {ip, pc}
```

Compile and run the program, then verify that it prints 1 using `echo $?`.

**The Basic Branch Formula**

Use this four-step procedure to convert C `if` statements into their assembly equivalents:

  1. Compare (with `cmp`) the left and right sides of the relational operation
  
  2. Branch **on the opposite quality** of the C `if` statement. For example, if the C statement uses `>`, you would
  use `ble` in the assembly program. Always use the opposite quality because you're deciding whether you need to **jump around** the
  body, which is the opposite behavior from the normal C `if` statement.
  
  3. Write down a label for the point after the `if` statement and make it the target of the branch instruction from step 2. Note that the label can be any name and you can only use a single label name once.
  
  4. Fill in the body of the `if` statement.

**Practice**

Convert this program to assembly language.

```
int x = 10;
int y = 0;

int main() {
    if (x > 0) {
        if (y <= 0) {
            x = 0;
        }
    }
    
    return x;
}
```

Run your program with a few different initializations of `x` and `y` and make sure that it works correctly in all cases.

## If-Else

The `if-else` pair is similar to the basic conditional statement.

  1. Compare the left and right sides of the relation.
  
  2. Branch (on the opposite quality) to the beginning of the `else` block.
  
  3. At the end of the `if` body, add an **unconditional branch** that goes **around** the `else` body. Recall that `b` is the instruction for an unconditional branch.
  

```
// if-else statement

// if (a > b) {
//     c = a;
// } else {
//     c = b;
// }

.global main

/*** Data section ***/
.data
a: .word 4
b: .word 14
c: .word 0

/*** Text section ***/
.text

main:
    push {ip, lr}

    // r0 <- a
    ldr r2, =a
    ldr r0, [r2]

    // r1 <- b
    ldr r3, =b
    ldr r1, [r3]

    // Pre-load c's address
    ldr r4, =c

    // Compare
    cmp r0, r1

    // Branch on opposite quality
    // if a <= b, jump to else
    ble else

  if:
    // c <- a
    str r0, [r4]

    // Done with if body, branch AROUND else
   b done

  else:
    // c <- b
    str r1, [r4]
    
    // No need to branch at end of else, program keeps running down to next statement

  done:
    // return c;
    ldr r0, [r4]

    pop {ip, pc}
```

**Practice**

Convert this program to assembly language:

```
int a = -5;
int b;

int main() {
    if (a < 0) {
        b = -a;  // implement as 0 - a
    } else {
        b = a
    }
    
    return b
}
```

## While Loop

The `while` loop is like a repeated `if` statement. When the program reaches the end of the loop body, it **jumps back to the top** to 
test the loop condition again. This jump is implemented with an unconditioal branch.

Here's a fragment that illustrates the basic concept:

```
// while (a > 0) {
//   a--;
// }

// Assume a in r0

while:
  cmp r0, #0
  
  // Branch around body on opposite quality
  ble endwhile
  
  // Loop body
  sub r0, r0, #1
  
  // Unconditional branch back to top
  b while

endwhile:
  // Code after loop goes here
```

**Multiplication**

Here's an example program that uses a loop to multiply two values and then returns their product.

```
// Multiply two integers in a loop
//
// while (b > 0) {
//     prod += a;
//     b--;
// }

.global main

/*** Text section ***/
.text

main:
    push {ip, lr}

    // Register assignments:
    //  r0: product
    //  r1: a
    //  r2: b

    // Initial loads
    mov r0, #0
    mov r1, #3
    mov r2, #5

  while:
    // Test b > 0
    cmp r2, #0

    // Branch on opposite quality
    // if b <= 0, jump around loop body
    ble end

    // Loop body
    add r0, r0, r1  // prod += a
    sub r2, r2, #1  // b--

    b while // unconditional branch back to top

  end:
    // Return -- product is in r0
    pop {ip, pc}
```

Try a few different initial assignments and verify that it works.

**Practice**

Modify the multiplication program to write a program that performs integer division by repeated subtraction. The output of your program should be the integer quotient. For example,

```
12 / 3 should yield 4
7 / 3 should yield 2
15 / 2 should yield 7
```

Here is a pseudocode implementation of the core of the program:

```
// Integer division a / b
remainder = a;
quotient = 0

while (b <= remainder) {
   remainder -= b;
   quotient += 1;
}
```

Next, re-write the multiplication program to use a `for` loop with an index variable instead of a `while` loop.

```
for (i = 0; i < b; i++) {
    prod += a;
}
```

This is almost the same as the `while` loop version. Think about how to implement the condition check for the loop in terms of `i` and `b` and how and where to implement `i++`.
