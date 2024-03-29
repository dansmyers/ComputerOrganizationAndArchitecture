
// An unconditional branch

// Influenced by thinkingeek's ARM assembler in
// Raspberry pi tutorial

.global _start

/*** Text section ***/
.text

_start:
    push {ip, lr}

    mov r0, #10

    // Unconditional branch jumps to a label
    b done

    // This load doesn't execute -- it's skipped
    // by the unconditional branch
    mov r0, #100

  done:

    // Return
    pop {ip, pc}
