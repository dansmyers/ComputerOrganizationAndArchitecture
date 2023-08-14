// Comparing two variables

.global _start

// if (a > b) {
//     a = b;
// }

/*** Data section ***/
.data

a: .word 10
b: .word 4


/*** Text section ***/
.text

_start:
    push {ip, lr}

    // r0 <- a
    ldr r0, =a
    ldr r0, [r0]

    // r1 <- b
    ldr r1, =b
    ldr r1, [r1]

    // Compare
    cmp r0, r1

    // Branch on opposite quality
    ble end

    // Body: set a = b
    // Note: r1 already has b's value
    ldr r0, =a
    str r1, [r0]

  end:
    ldr r0, =a
    ldr r0, [r0]

    pop {ip, pc}
