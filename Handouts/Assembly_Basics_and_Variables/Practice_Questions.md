# Assembly Practice

## Subtraction

Write a program that calculates the sum `55 - 12`. Put the final result in `r0` at the end of the program. You can use the instruction

```
sub rA, rB, rC
```

to compute `rB - rC` and store the result in register `rA`, where `A`, `B`, and `C` are the numbers of general-purpose registers.


## Swap

Write a program that loads the value 101 into `r0` and the value 11 into `r1`, then use `r2` to exchange the values. You can use

```
mov rA, rB
```

to move the value of `rB` into `rA`; the value in `rB` remains unchanged.


## Super addition

Write a program that calculates the sum `1 + 2 + 3 + 4 + 5` and places the final result in `r0` at the end of the program. You can decide what combination of registers to use.


## Scottometers

My son Scott created his own unit of measurement, the Scottometer, to "measure the size of the solar system". One Scottometer is defined to be 999,999 miles. Write a program to calculate the number of miles in
99 Scottometers.

You can use the `MUL` instruction to perform 32-bit integer multiplication:

```
// rA <-- rB * rC
MUL rA, rB, rC
```

As before, remember to have the final result of the program in `r0` when the final `pop` instruction executes.
