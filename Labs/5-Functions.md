# Functions in ARM

## Things to Remember

Functions may take up to four arguments in `r0`-`r3`. The first argument is passed in `r0`, the second in `r1`, and so forth. Additional arguments must be passed on the stack.

The return value is always passed in `r0`.

The **called function** (the *callee*) is allowed to change `r0`-`r3`. If the **caller** wants to preserve values in those registers, it must save them by pushing on the stack before the function call and restore them by popping after the function returns.

If the **callee** wants to modify `r4`-`r12`, it must save their original values and restore them before returning.

This calling convention is particularly important when making calls to `printf` in the middle of a program. Always save `r0`-`r3` before calling `printf` and restore them afterwards, except in the special case where you know you don't need to preserve the values!

## Countdown

Here's an example of a recursive ARM program. The program counts down from 5, then prints `Blastoff!` when it reaches 0:

```
5
4
3
2
1
Blastoff!
```

**Type** the program, run it, and verify that it works as expected. Then change the program so that it starts at 10 and stops at 5.

```
// A recursive program
.global main
.global countdown
.extern printf

/*** Data section ***/
.data
format: .asciz "%d\n"
blastoff: .asciz "Blastoff!\n"

/*** Text section ***/
.text

/*** Recursive countdown to zero ***/
//
// Input: count in r0
// Returns: nothing
//
// void countdown(int count) {
//     if (count <= 0) {
//         printf("Blastoff!\n");
//     } else {
//         printf("%d\n", count);
//         countdown(count - 1);
//     }
//     return;
// }

countdown:
    push {ip, lr}

    // Test if n <= 0
  if:
    cmp r0, #0

    // Branch on opposite
    // if count > 0, skip base case
    bgt else

    // Base case: print "Blastoff!"
    ldr r0, =blastoff  // Load string address
    bl printf
    b done

  else:
    // Recursive case

    // Setup args for printf
    mov r1, r0  // Move count to r1
    ldr r0, =format  // Load format string address

    // Calling convention states that r0-r3 may change
    // Save value of n before calling printf
    push {r1}

    bl printf

    // Set r0 <- count - 1
    pop {r0}  // Pop saved valued of n back into r0
    sub r0, r0, #1

    // Recursive call
    bl countdown

  done:
      pop {ip, pc}


/*** Main ***/
main:
    push {ip, lr}

    mov r0, #5  // Pass argument in r0
    bl countdown

    pop {ip, pc}
```

## Multiplication II

Here's a program that performs multiplication in a loop. The two factors are passed in `r0` and `r1` and the product is returned in `r0.

Implement the program and add a main function that sets up two arguments, calls `multiply`, and prints the result using `printf`.

```
.global main
.extern printf

/*** Data section ***/
.data
format: .asciz "%d x %d = %d\n"

/*** Text section ***/
.text

// multiply(a, b): multiply two values in a loop
//   Inputs: a in r0, b in r1
//   Outputs: product in r0
multiply:
    push {ip, lr}
    
    // mov a and b to r1 and r2
    // Use r0 for the product
    mov r2, r1
    mov r1, r0
    mov r0, #0
  
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

## Real Ultimate Power

Modify your multiplication program by adding a `power` function. The function should take two arguments, `p` in `r0` and `q` in `r1`, and return `p` raised to the power `q` in `r0`. Use a loop that calls `multiply` to calculate the answer.



