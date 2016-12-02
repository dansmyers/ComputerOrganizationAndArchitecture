// A function with an argument and a return value

.global main


/*** Data section ***/
.data

format: .asciz "%d\n"


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
main:
    push {ip, lr}

    mov r0, #10

    // "Branch and link" to double function
    // Address of NEXT instruction is saved in lr
    bl double

    // Result is now in r0

    // Print
    mov r1, r0
    ldr r0, =format
    bl printf

    // What's in r0 now?
    // The return value from printf!

    // Return
    pop {ip, pc}
