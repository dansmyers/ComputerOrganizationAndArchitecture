# Assembly Practice

## Subtraction

Write a program that calculates the difference `55 - 12`. Put the final result in `r0` at the end of the program. You can use the instruction

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

My son Scott created his own unit of measurement, the Scottometer, to "measure the size of the solar system". One Scottometer is defined to be 99 miles. Write a program to calculate the number of miles in
99 Scottometers.

You can use the `MUL` instruction to perform 32-bit integer multiplication:

```
// rA <-- rB * rC
MUL rA, rB, rC
```

As before, remember to have the final result of the program in `r0` when the final `pop` instruction executes.


## Translate

We've talked about registers being the storage locations that the CPU uses for data that it's actively operating on. Frequently, the compiler will also use registers to store the values of local variables in a program. If the CPU has enough registers, it may be possible to simply keep most of the program's data stored in registers and avoid the need to read and write values between the CPU and memory. It turns out that there is a bit of art to determining the most efficient mappings between variables and registers, and compiler researchers have developed several algorithms for that purpose (graph coloring!).

https://en.wikipedia.org/wiki/Register_allocation

Translate the following C program to assembly, using registers to keep track of the values of the variables and the intermediate calculation results.

```
int main(int argc, char *argv[]) {

  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  
  return (a * b) + (c * d);
}
```

Tip: you may want to start out by storing the value of `a` into `r0`, but remember that you'll need that location for the final result. Write your program so that the values of `a`, `b`, `c`, and `d` are preserved; don't overwrite a variable with a temporary expression result.


## Var Swap

Write a program that declares two variables:

```
int x = 101;
int y = 11;
```

Write assembly instructions to load, swap, and then store the values of `x` and `y`.

## Translate II

Translate the following code fragment into ARM:

```
int x = 5;
int y = 10;
int z = 15;

int d = x + y + z;

return d;
```
