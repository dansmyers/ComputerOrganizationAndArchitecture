// Using variables in ARM

.global main

/*** Global vars and static data ***/
.data

// A global variable is a label with some reserved space
//
// The .word command instructs the assembler to reserve
// four bytes of space for a value
x: .word 0  // x is initially 0


/*** Code goes in the text section ***/
.text

main:
    push {lr}

    // r0 <- 5
    mov r0, #5

    // Store happens in two steps
    //   1. Load the address of x
    //   2. Store the value of a register at that address

    // Use = to get the address of a label
    // =x is like &x in C
    ldr r1, =x

    // The address of x is now in r1
    // Use [r1] to store to the address held in r1
    str r0, [r1]

    // Load uses the same two steps
    //   1. Load the address of x
    //   2. Load the value there into a register
    ldr r1, =x
    ldr r0, [r1]

    // r0 <- r0 + 1
    add r0, r0, #1

    // Return
    pop {lr}
    bx lr
