// if-else statement

// if (a > b) {
//     c = a;
// } else {
//     c = b;
// }


.global _start


/*** Data section ***/
.data

a: .word 4
b: .word 14
c: .word 0


/*** Text section ***/
.text

_start:
    push {ip, lr}

    // r0 <- a
    ldr r2, =a
    ldr r0, [r2]

    // r1 <- b
    ldr r3, =b
    ldr r1, [r3]

    // Pre-load c's address
    ldr r4, =c

    // Compare
    cmp r0, r1

    // Branch on opposite quality
    // if a <= b, jump to else
    ble else

  if:
    // c <- a
    str r0, [r4]

    // Done with if body, branch AROUND else
   b done

  else:
    // c <- b
    str r1, [r4]

  done:
    // return c;
    ldr r0, [r4]

    pop {ip, pc}
