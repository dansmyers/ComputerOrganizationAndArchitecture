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

There are six basic conditional branching instructions:

  - `beq`: take branch if the last comparision was equal to zero (the *Z* bit is set)
  - `bne`: take branch if the last comparison was not equal to zero (*Z* bit is not set)
  - `bgt`: take branch if the last comparison was strictly positive (*Z* not set and *N* not set)
  - `blt`: take branch if the last comparison was strictly negative (*Z* not set and *N* set)
  - `bge`: take branch if the last comparision was greater than or equal to zero (*Z* set or *N* not set)
  - `ble`: take branch if the last comparison was less than or equal to zero (*Z* set or *N* set)
  
