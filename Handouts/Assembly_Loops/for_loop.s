// A for loop

// int i;
// for (i = 1; i <= 100; i++) {
//     sum += i;
// }


.global _start


/*** Data section ***/
.data

sum: .word 0


/*** Text section ***/
.text

_start:
    push {ip, lr}

    // r0 <- sum
    ldr r0, =sum
    ldr r0, [r0]

    // Treat r1 as the value of i
    // Not all variables need global allocation!
    mov r1, #1

  for:
    // Test if i <= 100
    cmp r1, #100

    // Branch on opposite condition of loop test
    // if i > 100, skip loop body
    bgt done

    // for loop body
    add r0, r0, r1  // sum += i
    add r1, r1, #1  // i++

    // Branch back to top
    b for

  done:
    // Save sum
    ldr r1, =sum
    str r0, [r1]

    // Return
    pop {ip, pc}
