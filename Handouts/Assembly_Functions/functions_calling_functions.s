// A function with an argument and a return value

.global _start


/*** Text section ***/
.text


/*** Double an input argument ***/
//
// Input is passed in r0
// Return value is also in r0
double:
    push {ip, lr}

    add r0, r0, r0

    pop {ip, pc}


/*** Quadruple an input argument ***/
//
// Calls double twice
//
// Input is in r0
// Return value is also in r0
quadruple:
    push {ip, lr}

    // Double twice
    // Arg and returns stay in r0
    bl double
    bl double

    pop {ip, pc}


/*** Main ***/
_start:
    push {ip, lr}

    mov r0, #10
    bl quadruple

    // Result is in r0

    // Return
    pop {ip, pc}
