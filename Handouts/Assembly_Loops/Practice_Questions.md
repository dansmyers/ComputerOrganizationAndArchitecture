# Loop Practice Questions

Translate the following C programs into ARM. Implement your solutions on the CPUlator and verify they work as expected.

## Multiply

The program below uses a loop to implement multiplication by repeated addition.

```
// Multiply two integers in a loop
//
// while (b > 0) {
//     prod += a;
//     b--;
// }

.global _start

/*** Text section ***/
.text

_start:
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

Copy the program into CPUlator and verify that it works for different settings of the initial values.

## Divide

Modify the multiplication program to write a program that performs integer division by repeated subtraction. Copy/Paste your program to Mimir. The output of your program should be the integer quotient. For example,

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

## Break on through to the other side

```
int x = 6;
while(x < 10) {
  if (x == 8) {
    break;
  }
  x++;
}
```

The `break` statement makes you immediately leave the current loop. Think about how to implement that using ARM branching instructions.


## Logical AND

```
int x = value of your choice;
int y = 0;

if(x > 5 && x < 20) {
  y = 2 + x;
} else {
  y = 5 + x;
}
```

Strategy: rewrite the compound if statement as a pair of nested if statements. Then label the sections of code and translate these to blocks of code in assembly.
Pay special attention to branching around/over blocks of code which should not logically be executed.

Note that ARM does have an `and` instruction, but it performs bitwise AND on two registers, so it's not what you want in this case.

