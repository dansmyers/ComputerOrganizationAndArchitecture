// Add two variables

.global _start

/*** Data section ***/
.data

x: .word 3
y: .word 4


/*** Code section ***/
.text

_start:
    push {ip, lr}

    // r0 <- x
    ldr r0, =x
    ldr r0, [r0]

    // r1 <- y
    ldr r1, =y
    ldr r1, [r1]

    // r0 <- r0 + r1
    add r0, r0, r1

    // Return
    pop {ip, pc}
