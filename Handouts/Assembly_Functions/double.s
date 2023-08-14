// A function with an argument and a return value

.global _start


/*** Text section ***/
.text


/*** Double an input argument ***/
//
// Input is passed in r0
// Return value is also in r0
double:
    // Save ip and lr to stack
    push {ip, lr}

    // Double r0
    add r0, r0, r0

    // Pop saved lr back into pc to return
    pop {ip, pc}


/*** Main ***/
_start:
    push {ip, lr}

    mov r0, #10

    // "Branch and link" to double function
    // Address of NEXT instruction is saved in lr
    bl double

    // Result is now in r0

    // Return
    pop {ip, pc}
