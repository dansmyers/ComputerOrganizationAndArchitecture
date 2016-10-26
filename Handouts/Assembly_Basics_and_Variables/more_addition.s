// More addition

.global main

main:
    push {ip, lr}

    // Calculate a sum of three values
    // Use four registers

    mov r0, #1  // r0 <- 1
    mov r1, #2  // r1 <- 2
    mov r2, #3  // r2 <- 3

    add r4, r0, r1  // r4 <- r0 + r1
    add r4, r4, r2  // r4 <- r4 + r2

    // Move return value to r0
    mov r0, r4  // r0 <- r4

    // Return
    pop {ip, pc}
