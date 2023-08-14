// A while loop

// while (a > 0) {
//     a--;
// }

.global _start


/*** Data section ***/
.data

a: .word 10
format: .asciz "%d\n"


/*** Text section ***/
.text

_start:
    push {ip, lr}

  while:

    // Check if a > 0
    ldr r1, =a
    ldr r0, [r1]
    cmp r0, #0

    // Question: could you rewrite this program
    // to avoid reloading a on every iteration?

    // Branch on opposite quality
    // if a <= 0, jump around while body
    ble done

    // while body

    // a--
    sub r0, r0, #1
    ldr r1, =a
    str r0, [r1]

    // Jump back to the top of the loop
    b while

  done:
    pop {ip, pc}
