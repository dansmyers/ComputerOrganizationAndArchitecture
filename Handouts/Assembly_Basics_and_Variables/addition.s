// Adding two numbers

.global main

main:
    push {ip, lr}

    // Load immediate values into r0 and r1
    mov r0, #2
    mov r1, #3

    // r0 <- r0 + r1
    // dest reg <- src reg 1 + src reg 2
    add r0, r0, r1

    // Return
    pop {ip, pc}
