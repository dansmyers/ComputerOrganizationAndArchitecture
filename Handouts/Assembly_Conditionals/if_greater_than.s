// Branching on a greater-than condition

// Basic code fragment:
//
// if (x >= 1) {
//     x = 1;
// }

// Key idea: compare x to 0 and branch on the OPPOSITE
// if x < 0, jump AROUND the body of the if statement

.global main

/*** Data section ***/
.data

x: .word 0


/*** Text section ***/
.text

main:
    push {ip, lr}

    // r0 <- x
    ldr r0, =x
    ldr r0, [r0]

    // Compare r0 to 1
    // Calculates r0 - 1
    cmp r0, #1

    // Branch on opposite quality
    // if x < 0, jump around if body
    blt done

    // Body: x <- 0
    mov r0, #1
    ldr r1, =x
    str r0,[r1] 

  done:

    // Return
    ldr r0, =x
    ldr r0, [r0]

    pop {ip, pc}

